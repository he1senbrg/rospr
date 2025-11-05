#!/usr/bin/env python3
"""
Servo Controller Node for Spider Robot
Manages 12 servo motors with hardware abstraction layer
Compatible with Raspberry Pi 5 using standard servo libraries
"""

import rclpy
from rclpy.node import Node
from spider_msgs.msg import ServoArray, ServoPosition
import math
import time
try:
    # For Raspberry Pi hardware
    import RPi.GPIO as GPIO
    from gpiozero import Servo
    HW_AVAILABLE = True
except ImportError:
    # For simulation/testing without hardware
    HW_AVAILABLE = False
    print("Hardware libraries not available - running in simulation mode")


class ServoControllerNode(Node):
    def __init__(self):
        super().__init__('servo_controller_node')
        
        # Declare parameters
        self.declare_parameter('servo_pins', [2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13])
        self.declare_parameter('min_angle', 0.0)
        self.declare_parameter('max_angle', 180.0)
        self.declare_parameter('servo_rate', 50.0)
        
        # Servo configuration - GPIO pins for 12 servos (4 legs x 3 servos each)
        servo_pin_list = self.get_parameter('servo_pins').get_parameter_value().integer_array_value
        self.servo_pins = [
            [servo_pin_list[0], servo_pin_list[1], servo_pin_list[2]],    # Leg 0 (front-right)
            [servo_pin_list[3], servo_pin_list[4], servo_pin_list[5]],    # Leg 1 (front-left)
            [servo_pin_list[6], servo_pin_list[7], servo_pin_list[8]],    # Leg 2 (back-right)  
            [servo_pin_list[9], servo_pin_list[10], servo_pin_list[11]]   # Leg 3 (back-left)
        ]
        
        # Servo limits and calibration
        self.servo_limits = {
            'min_angle': self.get_parameter('min_angle').get_parameter_value().double_value,
            'max_angle': self.get_parameter('max_angle').get_parameter_value().double_value,
            'default_speed': 1.0
        }
        
        # Initialize hardware
        self.servos = {}
        self.current_angles = {}
        self.target_angles = {}
        self.movement_speeds = {}
        self.initialized = False
        self.init_hardware()
        
        # ROS2 interfaces
        self.servo_subscriber = self.create_subscription(
            ServoArray,
            '/servo_positions',
            self.servo_callback,
            10
        )
        
        # Control loop timer (50Hz like Arduino original)
        # Create timer for servo control loop
        servo_rate = self.get_parameter('servo_rate').get_parameter_value().double_value
        self.timer = self.create_timer(1.0/servo_rate, self.control_loop)
        
        # Target positions for smooth interpolation
        self.target_angles = {}
        self.movement_speeds = {}
        
        self.get_logger().info("Servo Controller Node initialized")
    
    def init_hardware(self):
        """Initialize servo hardware or simulation"""
        for leg in range(4):
            for joint in range(3):
                servo_id = leg * 3 + joint
                pin = self.servo_pins[leg][joint]
                
                if HW_AVAILABLE:
                    try:
                        # Create servo object with gpiozero
                        servo = Servo(pin, min_pulse_width=0.5/1000, max_pulse_width=2.5/1000)
                        self.servos[servo_id] = servo
                        self.get_logger().info(f"Initialized servo {servo_id} on GPIO {pin}")
                    except Exception as e:
                        self.get_logger().error(f"Failed to initialize servo {servo_id}: {str(e)}")
                        self.servos[servo_id] = None
                else:
                    # Simulation mode
                    self.servos[servo_id] = None
                
                # Initialize positions
                self.current_angles[servo_id] = 90.0  # Default center position
                self.target_angles[servo_id] = 90.0
                self.movement_speeds[servo_id] = 1.0
                
        self.initialized = True
        servo_ids = list(self.target_angles.keys())
        self.get_logger().info(f"Initialized {len(self.servos)} servos with IDs: {servo_ids}")
    
    def servo_callback(self, msg):
        """Handle incoming servo position commands"""
        for servo_cmd in msg.servos:
            servo_id = int(servo_cmd.servo_id)
            
            if servo_id < 0 or servo_id > 11:
                self.get_logger().warn(f"Invalid servo ID: {servo_id}")
                continue
            
            # Clamp angle to valid range
            angle = max(self.servo_limits['min_angle'], 
                       min(self.servo_limits['max_angle'], servo_cmd.angle))
            
            self.target_angles[servo_id] = angle
            self.movement_speeds[servo_id] = max(0.1, servo_cmd.speed)
            
            self.get_logger().debug(f"Servo {servo_id} target: {angle}°")
    
    def control_loop(self):
        """Main control loop - smooth servo interpolation"""
        if not self.initialized:
            return
            
        for servo_id in range(12):
            if servo_id not in self.target_angles:
                self.get_logger().error(f"Servo ID {servo_id} not found in target_angles!")
                continue
                
            current = self.current_angles[servo_id]
            target = self.target_angles[servo_id]
            speed = self.movement_speeds[servo_id]
            
            # Calculate movement step
            diff = target - current
            if abs(diff) > 0.1:  # Minimum movement threshold
                # Smooth interpolation
                step = min(abs(diff), 2.0 * speed) * (1 if diff > 0 else -1)
                new_angle = current + step
                
                self.current_angles[servo_id] = new_angle
                self.set_servo_angle(servo_id, new_angle)
    
    def set_servo_angle(self, servo_id, angle):
        """Set physical servo to specified angle"""
        if self.servos[servo_id] is not None and HW_AVAILABLE:
            try:
                # Convert angle (0-180°) to servo value (-1 to +1)
                servo_value = (angle - 90.0) / 90.0
                servo_value = max(-1.0, min(1.0, servo_value))
                
                self.servos[servo_id].value = servo_value
                
            except Exception as e:
                self.get_logger().error(f"Error setting servo {servo_id}: {str(e)}")
        else:
            # Simulation mode - just log
            self.get_logger().debug(f"SIM: Servo {servo_id} -> {angle:.1f}°")
    
    def destroy_node(self):
        """Cleanup when node shuts down"""
        if HW_AVAILABLE:
            for servo in self.servos.values():
                if servo is not None:
                    servo.close()
            GPIO.cleanup()
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = ServoControllerNode()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()