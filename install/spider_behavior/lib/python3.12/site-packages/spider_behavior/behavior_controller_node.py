#!/usr/bin/env python3
"""
Behavior Controller Node for Spider Robot
Implements high-level movement behaviors and gaits
Translates behaviors into leg position sequences
"""

import rclpy
from rclpy.node import Node
from spider_msgs.msg import LegPositions, LegPosition, RobotState
from spider_msgs.srv import ExecuteBehavior, SetPose
from geometry_msgs.msg import Point
from std_msgs.msg import Header
import math
import time
import threading


class BehaviorControllerNode(Node):
    def __init__(self):
        super().__init__('behavior_controller_node')
        
        # Robot configuration (from Arduino sketch)
        self.z_absolute = -28.0
        self.z_default = -50.0
        self.z_up = -30.0
        self.z_boot = self.z_absolute
        self.x_default = 62.0
        self.x_offset = 0.0
        self.y_start = 0.0
        self.y_step = 40.0
        self.y_default = self.x_default
        
        # Movement speeds
        self.spot_turn_speed = 4.0
        self.leg_move_speed = 8.0
        self.body_move_speed = 3.0
        self.stand_seat_speed = 1.0
        
        # Current robot state
        self.current_behavior = "idle"
        self.is_moving = False
        self.current_pose = self.get_default_pose()
        
        # Behavior execution
        self.behavior_thread = None
        self.stop_behavior = False
        
        # ROS2 interfaces
        self.leg_publisher = self.create_publisher(
            LegPositions,
            '/leg_positions',
            10
        )
        
        self.state_publisher = self.create_publisher(
            RobotState,
            '/robot_state',
            10
        )
        
        self.behavior_service = self.create_service(
            ExecuteBehavior,
            '/execute_behavior',
            self.execute_behavior_callback
        )
        
        self.pose_service = self.create_service(
            SetPose,
            '/set_robot_pose',
            self.set_pose_callback
        )
        
        # Status publishing timer
        self.status_timer = self.create_timer(0.1, self.publish_status)
        
        # Initialize to standing position
        self.set_pose(self.get_default_pose(), self.stand_seat_speed)
        
        self.get_logger().info("Behavior Controller Node initialized")
    
    def get_default_pose(self):
        """Get default standing pose"""
        pose = LegPositions()
        pose.header = Header()
        pose.header.stamp = self.get_clock().now().to_msg()
        
        # Initialize 4 legs
        pose.legs = []
        for i in range(4):
            leg = LegPosition()
            leg.position = Point()
            leg.movement_speed = 1.0
            pose.legs.append(leg)
        
        # Set default positions for each leg
        pose.legs[0].position.x = self.x_default - self.x_offset  # Front-right
        pose.legs[0].position.y = self.y_start + self.y_step
        pose.legs[0].position.z = self.z_default
        
        pose.legs[1].position.x = self.x_default - self.x_offset  # Front-left
        pose.legs[1].position.y = self.y_start + self.y_step
        pose.legs[1].position.z = self.z_default
        
        pose.legs[2].position.x = self.x_default + self.x_offset  # Back-right
        pose.legs[2].position.y = self.y_start
        pose.legs[2].position.z = self.z_default
        
        pose.legs[3].position.x = self.x_default + self.x_offset  # Back-left
        pose.legs[3].position.y = self.y_start
        pose.legs[3].position.z = self.z_default
        
        return pose
    
    def execute_behavior_callback(self, request, response):
        """Handle behavior execution service requests"""
        behavior_name = request.behavior_name
        repetitions = request.repetitions
        speed_multiplier = request.speed_multiplier
        
        # Stop current behavior if running
        self.stop_current_behavior()
        
        # Start new behavior in separate thread
        if behavior_name in ['stand', 'sit', 'step_forward', 'step_back', 
                           'turn_left', 'turn_right', 'hand_wave', 'hand_shake', 'body_dance']:
            self.behavior_thread = threading.Thread(
                target=self.execute_behavior,
                args=(behavior_name, repetitions, speed_multiplier)
            )
            self.behavior_thread.start()
            response.success = True
            response.message = f"Started behavior: {behavior_name}"
        else:
            response.success = False
            response.message = f"Unknown behavior: {behavior_name}"
        
        return response
    
    def set_pose_callback(self, request, response):
        """Handle direct pose setting service requests"""
        try:
            self.stop_current_behavior()
            self.set_pose(request.target_pose, request.movement_speed)
            response.success = True
            response.message = "Pose set successfully"
        except Exception as e:
            response.success = False
            response.message = f"Failed to set pose: {str(e)}"
        
        return response
    
    def stop_current_behavior(self):
        """Stop currently executing behavior"""
        self.stop_behavior = True
        if self.behavior_thread and self.behavior_thread.is_alive():
            self.behavior_thread.join(timeout=2.0)
        self.stop_behavior = False
    
    def execute_behavior(self, behavior_name, repetitions, speed_multiplier):
        """Execute specified behavior"""
        self.current_behavior = behavior_name
        self.is_moving = True
        
        try:
            if behavior_name == "stand":
                self.stand()
            elif behavior_name == "sit":
                self.sit()
            elif behavior_name == "step_forward":
                for _ in range(repetitions):
                    if self.stop_behavior:
                        break
                    self.step_forward(speed_multiplier)
            elif behavior_name == "step_back":
                for _ in range(repetitions):
                    if self.stop_behavior:
                        break
                    self.step_back(speed_multiplier)
            elif behavior_name == "turn_left":
                for _ in range(repetitions):
                    if self.stop_behavior:
                        break
                    self.turn_left(speed_multiplier)
            elif behavior_name == "turn_right":
                for _ in range(repetitions):
                    if self.stop_behavior:
                        break
                    self.turn_right(speed_multiplier)
            elif behavior_name == "hand_wave":
                for _ in range(repetitions):
                    if self.stop_behavior:
                        break
                    self.hand_wave()
            elif behavior_name == "hand_shake":
                for _ in range(repetitions):
                    if self.stop_behavior:
                        break
                    self.hand_shake()
            elif behavior_name == "body_dance":
                self.body_dance(repetitions)
                
        except Exception as e:
            self.get_logger().error(f"Error executing behavior {behavior_name}: {str(e)}")
        
        self.current_behavior = "idle"
        self.is_moving = False
    
    def set_pose(self, pose, speed):
        """Set robot pose and publish to leg controller"""
        for leg in pose.legs:
            leg.movement_speed = speed
        
        pose.header.stamp = self.get_clock().now().to_msg()
        self.current_pose = pose
        self.leg_publisher.publish(pose)
        
        # Wait for movement to complete
        time.sleep(1.0 / speed)
    
    def stand(self):
        """Stand up behavior"""
        pose = self.get_default_pose()
        self.set_pose(pose, self.stand_seat_speed)
        self.get_logger().info("Standing")
    
    def sit(self):
        """Sit down behavior"""
        pose = self.current_pose
        for leg in pose.legs:
            leg.position.z = self.z_boot
        self.set_pose(pose, self.stand_seat_speed)
        self.get_logger().info("Sitting")
    
    def step_forward(self, speed_mult=1.0):
        """Step forward gait"""
        speed = self.leg_move_speed * speed_mult
        
        # Determine which legs to move based on current state
        if abs(self.current_pose.legs[2].position.y - self.y_start) < 0.1:
            # Move legs 2 & 1
            self.move_leg_sequence([2, 1], "forward", speed)
        else:
            # Move legs 0 & 3  
            self.move_leg_sequence([0, 3], "forward", speed)
    
    def step_back(self, speed_mult=1.0):
        """Step backward gait"""
        speed = self.leg_move_speed * speed_mult
        
        # Determine which legs to move based on current state
        if abs(self.current_pose.legs[3].position.y - self.y_start) < 0.1:
            # Move legs 3 & 0
            self.move_leg_sequence([3, 0], "backward", speed)
        else:
            # Move legs 1 & 2
            self.move_leg_sequence([1, 2], "backward", speed)
    
    def turn_left(self, speed_mult=1.0):
        """Turn left behavior"""
        speed = self.spot_turn_speed * speed_mult
        self.get_logger().info("Turning left")
        # Implement turn left pattern similar to Arduino version
        # This is a simplified version - full implementation would match Arduino exactly
        time.sleep(1.0)
    
    def turn_right(self, speed_mult=1.0):
        """Turn right behavior"""
        speed = self.spot_turn_speed * speed_mult
        self.get_logger().info("Turning right")
        # Implement turn right pattern similar to Arduino version
        time.sleep(1.0)
    
    def hand_wave(self):
        """Hand waving gesture"""
        self.get_logger().info("Waving hand")
        # Lift and wave one leg
        time.sleep(2.0)
    
    def hand_shake(self):
        """Hand shaking gesture"""
        self.get_logger().info("Shaking hand")
        # Vertical hand movement
        time.sleep(2.0)
    
    def body_dance(self, repetitions):
        """Body dancing behavior"""
        self.get_logger().info("Dancing")
        for i in range(repetitions):
            if self.stop_behavior:
                break
            # Dance movement pattern
            time.sleep(0.5)
    
    def move_leg_sequence(self, legs, direction, speed):
        """Move specified legs in sequence"""
        pose = self.current_pose
        
        # First leg up
        if not self.stop_behavior:
            pose.legs[legs[0]].position.z = self.z_up
            self.set_pose(pose, speed)
        
        # Move first leg forward/backward
        if not self.stop_behavior:
            if direction == "forward":
                pose.legs[legs[0]].position.y += 2 * self.y_step
            else:
                pose.legs[legs[0]].position.y -= 2 * self.y_step
            self.set_pose(pose, speed)
        
        # First leg down
        if not self.stop_behavior:
            pose.legs[legs[0]].position.z = self.z_default
            self.set_pose(pose, speed)
        
        # Body shift
        if not self.stop_behavior:
            self.shift_body(direction)
        
        # Second leg movement
        if len(legs) > 1 and not self.stop_behavior:
            pose.legs[legs[1]].position.z = self.z_up
            self.set_pose(pose, speed)
            
            if direction == "forward":
                pose.legs[legs[1]].position.y -= 2 * self.y_step
            else:
                pose.legs[legs[1]].position.y += 2 * self.y_step
            self.set_pose(pose, speed)
            
            pose.legs[legs[1]].position.z = self.z_default
            self.set_pose(pose, speed)
    
    def shift_body(self, direction):
        """Shift body during walking"""
        pose = self.current_pose
        
        # Adjust all leg positions for body shift
        for leg in pose.legs:
            if direction == "forward":
                leg.position.x -= 10  # Shift body backward relative to legs
            else:
                leg.position.x += 10  # Shift body forward relative to legs
        
        self.set_pose(pose, self.body_move_speed)
    
    def publish_status(self):
        """Publish current robot state"""
        state = RobotState()
        state.header = Header()
        state.header.stamp = self.get_clock().now().to_msg()
        state.current_behavior = self.current_behavior
        state.is_moving = self.is_moving
        state.battery_level = 100.0  # Placeholder
        state.current_pose = self.current_pose
        
        self.state_publisher.publish(state)


def main(args=None):
    rclpy.init(args=args)
    node = BehaviorControllerNode()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.stop_current_behavior()
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()