#!/usr/bin/env python3
"""
Spider Controller Node

This node subscribes to joystick input from the joy_node and translates
Xbox controller commands into spider robot behaviors.

Author: loki
Date: November 11, 2025
"""

import rclpy
from rclpy.node import Node
from rclpy.parameter import Parameter
from rcl_interfaces.msg import ParameterDescriptor

import yaml
import os
import time
import threading
from ament_index_python.packages import get_package_share_directory

# ROS2 message types
from sensor_msgs.msg import Joy
from spider_msgs.srv import ExecuteBehavior
from spider_msgs.msg import RobotState

class SpiderControllerNode(Node):
    def __init__(self):
        super().__init__('spider_controller_node')
        
        self.get_logger().info("Starting Spider Controller Node")
        
        # Load configuration
        self.load_configuration()
        
        # Controller state
        self.last_button_time = {}
        self.last_axis_command = {}
        self.last_gesture_time = 0.0
        self.current_movement_behavior = None
        self.movement_thread = None
        self.stop_movement = False
        
        # ROS2 interfaces
        self.setup_ros_interfaces()
        
        # Initialize button states
        self.previous_buttons = []
        self.current_speed_factor = 1.0
        
        self.get_logger().info("Spider Controller Node initialized")
        self.get_logger().info("Controller mapping loaded successfully")
        self.log_controller_mapping()
    
    def load_configuration(self):
        """Load controller configuration from YAML file"""
        try:
            # Get package share directory
            pkg_share = get_package_share_directory('spider_controller')
            config_path = os.path.join(pkg_share, 'config', 'controller_mapping.yaml')
            
            with open(config_path, 'r') as file:
                self.config = yaml.safe_load(file)
            
            # Extract key configuration values
            self.dead_zone = self.config.get('dead_zone', 0.15)
            self.speed_scales = self.config.get('speed_scales', {})
            self.button_mappings = self.config.get('button_mappings', {})
            self.axis_mappings = self.config.get('axis_mappings', {})
            self.trigger_mappings = self.config.get('trigger_mappings', {})
            self.dpad_mappings = self.config.get('dpad_mappings', {})
            self.timing = self.config.get('timing', {})
            
            self.get_logger().info(f"Loaded controller configuration from: {config_path}")
            
        except Exception as e:
            self.get_logger().error(f"Failed to load controller configuration: {str(e)}")
            # Use default configuration
            self.setup_default_config()
    
    def setup_default_config(self):
        """Set up default configuration if config file loading fails"""
        self.dead_zone = 0.15
        self.speed_scales = {'walk': 2.0, 'turn': 1.5, 'gesture': 1.0}
        self.button_mappings = {
            0: "stand",      # A
            1: "sit",        # B  
            4: "hand_wave",  # LB
            5: "hand_shake", # RB
            10: "body_dance" # RS click
        }
        self.axis_mappings = {
            'left_stick_y': {'axis': 1, 'behaviors': {'positive': 'step_back', 'negative': 'step_forward'}},
            'right_stick_x': {'axis': 3, 'behaviors': {'positive': 'turn_right', 'negative': 'turn_left'}}
        }
        self.trigger_mappings = {
            'left_trigger': {'axis': 2, 'speed_factor': 0.3},
            'right_trigger': {'axis': 5, 'speed_factor': 2.0}
        }
        self.dpad_mappings = {}
        self.timing = {
            'button_repeat_rate': 0.1,
            'movement_update_rate': 20,
            'gesture_cooldown': 2.0
        }
        
        self.get_logger().warn("Using default controller configuration")
    
    def setup_ros_interfaces(self):
        """Set up ROS2 publishers, subscribers, and services"""
        # Subscribe to joystick input
        self.joy_subscriber = self.create_subscription(
            Joy,
            '/joy',
            self.joy_callback,
            10
        )
        
        # Service client for executing behaviors
        self.behavior_client = self.create_client(
            ExecuteBehavior,
            '/execute_behavior'
        )
        
        # Wait for behavior service to be available
        self.get_logger().info("Waiting for behavior service...")
        if not self.behavior_client.wait_for_service(timeout_sec=10.0):
            self.get_logger().error("Behavior service not available!")
        else:
            self.get_logger().info("Connected to behavior service")
        
        # Subscribe to robot state
        self.state_subscriber = self.create_subscription(
            RobotState,
            '/robot_state',
            self.robot_state_callback,
            10
        )
        
        # Timer for periodic updates
        update_rate = self.timing.get('movement_update_rate', 20)
        self.timer = self.create_timer(1.0 / update_rate, self.update_continuous_movement)
    
    def log_controller_mapping(self):
        """Log the current controller mapping for user reference"""
        self.get_logger().info("=== Xbox Controller Mapping ===")
        self.get_logger().info("Buttons:")
        for button_id, behavior in self.button_mappings.items():
            if behavior:
                button_name = self.get_button_name(int(button_id))
                self.get_logger().info(f"  {button_name}: {behavior}")
        
        self.get_logger().info("Analog Controls:")
        for stick_name, mapping in self.axis_mappings.items():
            behaviors = mapping.get('behaviors', {})
            if any(behaviors.values()):
                self.get_logger().info(f"  {stick_name}: {behaviors}")
        
        self.get_logger().info("Triggers:")
        for trigger_name, mapping in self.trigger_mappings.items():
            factor = mapping.get('speed_factor', 1.0)
            self.get_logger().info(f"  {trigger_name}: Speed factor {factor}")
    
    def get_button_name(self, button_id):
        """Get human-readable button name"""
        button_names = {
            0: "A", 1: "B", 2: "X", 3: "Y",
            4: "LB", 5: "RB", 6: "Back", 7: "Start",
            8: "Xbox", 9: "LS", 10: "RS"
        }
        return button_names.get(button_id, f"Button{button_id}")
    
    def joy_callback(self, msg):
        """Handle incoming joystick messages"""
        current_time = time.time()
        
        # Initialize previous buttons if needed
        if len(self.previous_buttons) != len(msg.buttons):
            self.previous_buttons = [0] * len(msg.buttons)
        
        # Handle button presses
        self.handle_button_presses(msg, current_time)
        
        # Handle analog inputs
        self.handle_analog_inputs(msg, current_time)
        
        # Update state
        self.previous_buttons = list(msg.buttons)
    
    def handle_button_presses(self, joy_msg, current_time):
        """Process button press events"""
        for button_id, pressed in enumerate(joy_msg.buttons):
            # Check for button press (transition from 0 to 1)
            if pressed and (button_id >= len(self.previous_buttons) or not self.previous_buttons[button_id]):
                self.handle_button_press(button_id, current_time)
    
    def handle_button_press(self, button_id, current_time):
        """Handle a single button press"""
        # Check if enough time has passed since last press
        if button_id in self.last_button_time:
            time_since_last = current_time - self.last_button_time[button_id]
            min_interval = self.timing.get('button_repeat_rate', 0.1)
            if time_since_last < min_interval:
                return
        
        # Get behavior mapping
        behavior = self.button_mappings.get(button_id)
        if behavior:
            button_name = self.get_button_name(button_id)
            self.get_logger().info(f"{button_name} pressed -> {behavior}")
            
            # Check gesture cooldown
            if behavior in ['hand_wave', 'hand_shake', 'body_dance']:
                time_since_gesture = current_time - self.last_gesture_time
                cooldown = self.timing.get('gesture_cooldown', 2.0)
                if time_since_gesture < cooldown:
                    self.get_logger().warn(f"Gesture cooldown active ({cooldown - time_since_gesture:.1f}s remaining)")
                    return
                self.last_gesture_time = current_time
            
            # Execute behavior
            self.execute_behavior(behavior, 1, self.current_speed_factor)
        
        self.last_button_time[button_id] = current_time
    
    def handle_analog_inputs(self, joy_msg, current_time):
        """Process analog stick and trigger inputs"""
        # Calculate speed factors from triggers
        self.update_speed_factor(joy_msg)
        
        # Handle axis movements
        for axis_name, mapping in self.axis_mappings.items():
            axis_id = mapping.get('axis')
            if axis_id is not None and axis_id < len(joy_msg.axes):
                axis_value = joy_msg.axes[axis_id]
                self.handle_axis_movement(axis_name, axis_value, mapping, current_time)
        
        # Handle D-pad
        self.handle_dpad_input(joy_msg, current_time)
    
    def update_speed_factor(self, joy_msg):
        """Update speed factor based on trigger inputs"""
        self.current_speed_factor = 1.0
        
        # Check triggers
        for trigger_name, mapping in self.trigger_mappings.items():
            axis_id = mapping.get('axis')
            if axis_id is not None and axis_id < len(joy_msg.axes):
                trigger_value = joy_msg.axes[axis_id]
                
                # Convert trigger value to 0-1 range (triggers are usually -1 to 1)
                if trigger_value > self.dead_zone:
                    normalized_value = (trigger_value + 1.0) / 2.0  # Convert -1,1 to 0,1
                    speed_factor = mapping.get('speed_factor', 1.0)
                    self.current_speed_factor = normalized_value * speed_factor
                    break
    
    def handle_axis_movement(self, axis_name, axis_value, mapping, current_time):
        """Handle continuous axis movement"""
        behaviors = mapping.get('behaviors', {})
        
        # Apply dead zone
        if abs(axis_value) < self.dead_zone:
            # Stop current movement if axis is in dead zone
            if self.current_movement_behavior:
                self.stop_continuous_movement()
            return
        
        # Determine behavior based on axis direction
        if axis_value > 0:
            behavior = behaviors.get('positive')
        else:
            behavior = behaviors.get('negative')
        
        if behavior and behavior != self.current_movement_behavior:
            self.start_continuous_movement(behavior, abs(axis_value))
    
    def handle_dpad_input(self, joy_msg, current_time):
        """Handle D-pad input"""
        for dpad_name, mapping in self.dpad_mappings.items():
            axis_id = mapping.get('axis')
            if axis_id is not None and axis_id < len(joy_msg.axes):
                axis_value = joy_msg.axes[axis_id]
                
                if abs(axis_value) > 0.5:  # D-pad usually gives full values
                    behaviors = mapping.get('behaviors', {})
                    if axis_value > 0:
                        behavior = behaviors.get('positive')
                    else:
                        behavior = behaviors.get('negative')
                    
                    if behavior:
                        speed_mult = self.current_speed_factor
                        self.execute_behavior(behavior, 1, speed_mult)
    
    def start_continuous_movement(self, behavior, intensity):
        """Start continuous movement behavior"""
        self.stop_continuous_movement()
        
        self.current_movement_behavior = behavior
        self.stop_movement = False
        
        # Calculate speed based on stick intensity and current speed factor
        speed_mult = intensity * self.current_speed_factor
        
        self.get_logger().info(f"Starting continuous movement: {behavior} (speed: {speed_mult:.2f})")
        
        # Start movement in separate thread
        self.movement_thread = threading.Thread(
            target=self.continuous_movement_loop, 
            args=(behavior, speed_mult)
        )
        self.movement_thread.start()
    
    def stop_continuous_movement(self):
        """Stop current continuous movement"""
        if self.current_movement_behavior:
            self.get_logger().info(f"Stopping continuous movement: {self.current_movement_behavior}")
            self.stop_movement = True
            self.current_movement_behavior = None
            
            if self.movement_thread and self.movement_thread.is_alive():
                self.movement_thread.join(timeout=1.0)
    
    def continuous_movement_loop(self, behavior, speed_mult):
        """Loop for continuous movement execution"""
        while not self.stop_movement and rclpy.ok():
            self.execute_behavior(behavior, 1, speed_mult)
            time.sleep(0.5)  # Adjust timing based on behavior
    
    def update_continuous_movement(self):
        """Timer callback for updating continuous movement"""
        # This is called periodically and can be used for fine movement control
        pass
    
    def execute_behavior(self, behavior_name, repetitions=1, speed_multiplier=1.0):
        """Execute a spider behavior via service call"""
        if not self.behavior_client.service_is_ready():
            self.get_logger().warn("Behavior service not ready")
            return
        
        # Create service request
        request = ExecuteBehavior.Request()
        request.behavior_name = behavior_name
        request.repetitions = repetitions
        request.speed_multiplier = float(speed_multiplier)
        
        # Call service asynchronously
        future = self.behavior_client.call_async(request)
        future.add_done_callback(
            lambda f: self.behavior_response_callback(f, behavior_name)
        )
    
    def behavior_response_callback(self, future, behavior_name):
        """Handle behavior service response"""
        try:
            response = future.result()
            if response.success:
                self.get_logger().debug(f"Behavior '{behavior_name}' executed successfully")
            else:
                self.get_logger().warn(f"Behavior '{behavior_name}' failed: {response.message}")
        except Exception as e:
            self.get_logger().error(f"Service call failed for '{behavior_name}': {str(e)}")
    
    def robot_state_callback(self, msg):
        """Handle robot state updates"""
        # This could be used to adjust controller behavior based on robot state
        pass
    
    def destroy_node(self):
        """Cleanup when shutting down"""
        self.stop_continuous_movement()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    
    node = SpiderControllerNode()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("Controller node interrupted by user")
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()