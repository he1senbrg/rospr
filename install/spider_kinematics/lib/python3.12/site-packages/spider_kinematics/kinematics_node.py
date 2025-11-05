#!/usr/bin/env python3
"""
Kinematics Node for Spider Robot
Handles coordinate transformations and inverse kinematics
Converts between Cartesian leg positions and servo angles
"""

import rclpy
from rclpy.node import Node
from spider_msgs.msg import LegPositions, ServoArray, ServoPosition
from geometry_msgs.msg import Point
import math


class KinematicsNode(Node):
    def __init__(self):
        super().__init__('kinematics_node')
        
        # Robot physical dimensions (from Arduino sketch)
        self.length_a = 55.0    # Upper leg segment
        self.length_b = 77.5    # Lower leg segment  
        self.length_c = 27.5    # Offset from body to shoulder joint
        self.length_side = 71.0 # Distance between legs
        
        # Default positions and limits
        self.z_absolute = -28.0
        self.z_default = -50.0
        self.z_up = -30.0
        self.z_boot = self.z_absolute
        self.x_default = 62.0
        self.x_offset = 0.0
        self.y_start = 0.0
        self.y_step = 40.0
        self.y_default = self.x_default
        
        # ROS2 interfaces
        self.leg_subscriber = self.create_subscription(
            LegPositions,
            '/leg_positions',
            self.leg_positions_callback,
            10
        )
        
        self.servo_publisher = self.create_publisher(
            ServoArray,
            '/servo_positions',
            10
        )
        
        self.get_logger().info("Kinematics Node initialized")
    
    def leg_positions_callback(self, msg):
        """Convert leg positions to servo angles"""
        servo_array = ServoArray()
        servo_array.servos = []
        
        for leg_idx in range(4):
            if leg_idx < len(msg.legs):
                leg_pos = msg.legs[leg_idx]
                x = leg_pos.position.x
                y = leg_pos.position.y
                z = leg_pos.position.z
                speed = leg_pos.movement_speed
                
                # Compute inverse kinematics for this leg
                alpha, beta, gamma = self.cartesian_to_polar(x, y, z)
                
                # Apply leg-specific transformations
                alpha, beta, gamma = self.polar_to_servo_angles(leg_idx, alpha, beta, gamma)
                
                # Create servo commands for this leg (3 servos per leg)
                servo_base_id = leg_idx * 3
                
                # Shoulder servo (gamma - rotation around Z axis)
                shoulder_servo = ServoPosition()
                shoulder_servo.servo_id = servo_base_id
                shoulder_servo.angle = gamma
                shoulder_servo.speed = speed
                servo_array.servos.append(shoulder_servo)
                
                # Elbow servo (alpha - upper leg angle)
                elbow_servo = ServoPosition()
                elbow_servo.servo_id = servo_base_id + 1
                elbow_servo.angle = alpha
                elbow_servo.speed = speed
                servo_array.servos.append(elbow_servo)
                
                # Wrist servo (beta - lower leg angle)
                wrist_servo = ServoPosition()
                wrist_servo.servo_id = servo_base_id + 2
                wrist_servo.angle = beta
                wrist_servo.speed = speed
                servo_array.servos.append(wrist_servo)
        
        # Publish servo commands
        self.servo_publisher.publish(servo_array)
        self.get_logger().debug(f"Published {len(servo_array.servos)} servo commands")
    
    def cartesian_to_polar(self, x, y, z):
        """
        Convert Cartesian coordinates to polar coordinates
        Based on the mathematical model from Arduino sketch
        """
        # Calculate w-z degree
        w = (1 if x >= 0 else -1) * math.sqrt(x**2 + y**2)
        v = w - self.length_c
        
        # Compute alpha (upper leg angle)
        numerator = (self.length_a**2 - self.length_b**2 + v**2 + z**2)
        denominator = (2 * self.length_a * math.sqrt(v**2 + z**2))
        
        if denominator == 0:
            alpha = 0
        else:
            try:
                alpha = math.atan2(z, v) + math.acos(numerator / denominator)
            except ValueError:
                # Handle acos domain error
                alpha = math.atan2(z, v)
        
        # Compute beta (lower leg angle) 
        numerator = (self.length_a**2 + self.length_b**2 - v**2 - z**2)
        denominator = (2 * self.length_a * self.length_b)
        
        if denominator == 0:
            beta = 0
        else:
            try:
                beta = math.acos(numerator / denominator)
            except ValueError:
                beta = 0
        
        # Calculate x-y-z degree (rotation around vertical axis)
        gamma = math.atan2(y, x) if w >= 0 else math.atan2(-y, -x)
        
        # Convert from radians to degrees
        alpha = math.degrees(alpha)
        beta = math.degrees(beta)
        gamma = math.degrees(gamma)
        
        return alpha, beta, gamma
    
    def polar_to_servo_angles(self, leg, alpha, beta, gamma):
        """
        Transform polar coordinates to actual servo angles
        Based on leg-specific mounting orientations from Arduino sketch
        """
        if leg == 0:  # Front-right leg
            alpha = 90 - alpha
            beta = beta
            gamma += 90
        elif leg == 1:  # Front-left leg
            alpha += 90
            beta = 180 - beta
            gamma = 90 - gamma
        elif leg == 2:  # Back-right leg
            alpha += 90
            beta = 180 - beta
            gamma = 90 - gamma
        elif leg == 3:  # Back-left leg
            alpha = 90 - alpha
            beta = beta
            gamma += 90
        
        # Ensure angles are within servo limits
        alpha = max(0, min(180, alpha))
        beta = max(0, min(180, beta))
        gamma = max(0, min(180, gamma))
        
        return alpha, beta, gamma
    
    def forward_kinematics(self, leg, alpha, beta, gamma):
        """
        Convert servo angles back to Cartesian coordinates
        Useful for validation and feedback
        """
        # Convert degrees to radians
        alpha_rad = math.radians(alpha)
        beta_rad = math.radians(beta)
        gamma_rad = math.radians(gamma)
        
        # Reverse the leg-specific transformations
        if leg == 0:  # Front-right leg
            alpha_rad = math.radians(90 - alpha)
            gamma_rad = math.radians(gamma - 90)
        elif leg == 1:  # Front-left leg
            alpha_rad = math.radians(alpha - 90)
            beta_rad = math.radians(180 - beta)
            gamma_rad = math.radians(90 - gamma)
        elif leg == 2:  # Back-right leg
            alpha_rad = math.radians(alpha - 90)
            beta_rad = math.radians(180 - beta)
            gamma_rad = math.radians(90 - gamma)
        elif leg == 3:  # Back-left leg
            alpha_rad = math.radians(90 - alpha)
            gamma_rad = math.radians(gamma - 90)
        
        # Calculate end effector position
        r = self.length_a * math.cos(alpha_rad) + self.length_b * math.cos(alpha_rad + beta_rad)
        z = self.length_a * math.sin(alpha_rad) + self.length_b * math.sin(alpha_rad + beta_rad)
        
        w = r + self.length_c
        x = w * math.cos(gamma_rad)
        y = w * math.sin(gamma_rad)
        
        return x, y, z


def main(args=None):
    rclpy.init(args=args)
    node = KinematicsNode()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()