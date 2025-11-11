#!/usr/bin/env python3
"""
Test script for PCA9685 servo controller
Tests basic servo movement patterns
"""

import rclpy
from rclpy.node import Node
from spider_msgs.msg import ServoArray, ServoPosition
import time
import math


class ServoTester(Node):
    def __init__(self):
        super().__init__('servo_tester')
        
        # Publisher for servo commands
        self.servo_pub = self.create_publisher(
            ServoArray,
            '/servo_positions',
            10
        )
        
        # Wait for publisher to be ready
        time.sleep(1.0)
        
        self.get_logger().info("Servo Tester initialized")
    
    def send_servo_command(self, servo_id, angle, speed=1.0):
        """Send command to a single servo"""
        msg = ServoArray()
        servo_cmd = ServoPosition()
        servo_cmd.servo_id = servo_id
        servo_cmd.angle = float(angle)
        servo_cmd.speed = float(speed)
        msg.servos = [servo_cmd]
        
        self.servo_pub.publish(msg)
        self.get_logger().info(f"Servo {servo_id} -> {angle}° (speed: {speed})")
    
    def send_all_servos(self, angles, speed=1.0):
        """Send commands to all 12 servos"""
        msg = ServoArray()
        msg.servos = []
        
        for i in range(12):
            servo_cmd = ServoPosition()
            servo_cmd.servo_id = i
            servo_cmd.angle = float(angles[i] if i < len(angles) else 90.0)
            servo_cmd.speed = float(speed)
            msg.servos.append(servo_cmd)
        
        self.servo_pub.publish(msg)
        self.get_logger().info(f"All servos set to: {angles}")
    
    def test_center_position(self):
        """Test: Move all servos to center position (90°)"""
        self.get_logger().info("=== Test: Center Position ===")
        angles = [90.0] * 12
        self.send_all_servos(angles)
        time.sleep(2.0)
    
    def test_range_of_motion(self):
        """Test: Sweep each servo through its range"""
        self.get_logger().info("=== Test: Range of Motion ===")
        
        for servo_id in range(12):
            self.get_logger().info(f"Testing servo {servo_id}")
            
            # Move to 0°
            self.send_servo_command(servo_id, 0.0)
            time.sleep(1.0)
            
            # Move to 180°
            self.send_servo_command(servo_id, 180.0)
            time.sleep(1.0)
            
            # Return to center
            self.send_servo_command(servo_id, 90.0)
            time.sleep(0.5)
    
    def test_wave_pattern(self):
        """Test: Create a wave pattern across all servos"""
        self.get_logger().info("=== Test: Wave Pattern ===")
        
        for t in range(60):  # 3 seconds at 20Hz
            angles = []
            for servo_id in range(12):
                # Create sine wave with phase offset
                angle = 90.0 + 30.0 * math.sin(t * 0.1 + servo_id * 0.5)
                angles.append(angle)
            
            self.send_all_servos(angles, speed=2.0)
            time.sleep(0.05)  # 20Hz
    
    def test_leg_pattern(self):
        """Test: Move each leg independently"""
        self.get_logger().info("=== Test: Leg Pattern ===")
        
        # Default position
        default_angles = [90.0] * 12
        
        for leg in range(4):
            self.get_logger().info(f"Moving leg {leg}")
            
            # Move leg up
            angles = default_angles.copy()
            angles[leg*3 + 0] = 60.0   # Coxa
            angles[leg*3 + 1] = 120.0  # Femur  
            angles[leg*3 + 2] = 60.0   # Tibia
            self.send_all_servos(angles)
            time.sleep(1.0)
            
            # Move leg down
            angles[leg*3 + 0] = 120.0  # Coxa
            angles[leg*3 + 1] = 60.0   # Femur
            angles[leg*3 + 2] = 120.0  # Tibia
            self.send_all_servos(angles)
            time.sleep(1.0)
            
            # Return to default
            self.send_all_servos(default_angles)
            time.sleep(0.5)


def main():
    rclpy.init()
    
    tester = ServoTester()
    
    try:
        input("Press Enter to start servo tests...")
        
        # Run test sequence
        tester.test_center_position()
        
        input("Press Enter for range of motion test...")
        tester.test_range_of_motion()
        
        input("Press Enter for wave pattern test...")
        tester.test_wave_pattern()
        
        input("Press Enter for leg pattern test...")
        tester.test_leg_pattern()
        
        # Return to center
        tester.test_center_position()
        
        tester.get_logger().info("=== All tests completed ===")
        
    except KeyboardInterrupt:
        tester.get_logger().info("Test interrupted by user")
    finally:
        tester.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()