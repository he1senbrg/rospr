#!/usr/bin/env python3
"""
Virtual Xbox Controller Simulator

This script simulates Xbox controller input for testing the spider robot
controller system without requiring physical hardware.

Usage: python3 virtual_controller.py
"""

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
import time
import threading
import sys

class VirtualController(Node):
    def __init__(self):
        super().__init__('virtual_controller')
        
        # Publisher for joystick messages
        self.joy_publisher = self.create_publisher(Joy, '/joy', 10)
        
        # Timer for periodic publishing
        self.timer = self.create_timer(0.05, self.publish_joy_state)  # 20Hz
        
        # Controller state
        self.buttons = [0] * 11  # 11 buttons for Xbox controller
        self.axes = [0.0] * 8    # 8 axes for Xbox controller
        
        self.get_logger().info("=== Virtual Xbox Controller ===")
        self.get_logger().info("Publishing joystick messages on /joy topic")
        self.log_controls()
        
        # Start input thread
        self.input_thread = threading.Thread(target=self.input_loop, daemon=True)
        self.input_thread.start()
    
    def log_controls(self):
        """Log available controls"""
        self.get_logger().info("\nVirtual Controller Commands:")
        self.get_logger().info("Buttons:")
        self.get_logger().info("  a - A button (stand)")
        self.get_logger().info("  b - B button (sit)")  
        self.get_logger().info("  lb - Left Bumper (hand wave)")
        self.get_logger().info("  rb - Right Bumper (hand shake)")
        self.get_logger().info("  rs - Right Stick click (dance)")
        self.get_logger().info("\nAnalog Controls:")
        self.get_logger().info("  w/s - Left stick Y (walk forward/back)")
        self.get_logger().info("  a/d - Right stick X (turn left/right)")
        self.get_logger().info("  r - Reset all inputs")
        self.get_logger().info("  q - Quit")
        self.get_logger().info("\nPress Enter after each command...")
    
    def publish_joy_state(self):
        """Publish current joystick state"""
        msg = Joy()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.buttons = self.buttons[:]
        msg.axes = self.axes[:]
        
        self.joy_publisher.publish(msg)
    
    def input_loop(self):
        """Handle user input for virtual controller"""
        while rclpy.ok():
            try:
                command = input().strip().lower()
                self.process_command(command)
            except (EOFError, KeyboardInterrupt):
                break
    
    def process_command(self, command):
        """Process user input command"""
        # Reset all inputs first
        self.buttons = [0] * 11
        self.axes = [0.0] * 8
        
        if command == 'q':
            self.get_logger().info("Quitting virtual controller")
            rclpy.shutdown()
            return
        elif command == 'r':
            self.get_logger().info("Reset all inputs")
            return
        elif command == 'a':
            self.buttons[0] = 1  # A button
            self.get_logger().info("A button pressed (stand)")
        elif command == 'b':
            self.buttons[1] = 1  # B button
            self.get_logger().info("B button pressed (sit)")
        elif command == 'lb':
            self.buttons[4] = 1  # Left Bumper
            self.get_logger().info("Left Bumper pressed (hand wave)")
        elif command == 'rb':
            self.buttons[5] = 1  # Right Bumper
            self.get_logger().info("Right Bumper pressed (hand shake)")
        elif command == 'rs':
            self.buttons[10] = 1  # Right stick click
            self.get_logger().info("Right Stick clicked (dance)")
        elif command == 'w':
            self.axes[1] = -1.0  # Left stick Y forward
            self.get_logger().info("Left Stick Y forward (walk forward)")
        elif command == 's':
            self.axes[1] = 1.0   # Left stick Y back
            self.get_logger().info("Left Stick Y back (walk backward)")
        elif command == 'al':  # 'a' conflicts with A button, use 'al' for left
            self.axes[3] = -1.0  # Right stick X left
            self.get_logger().info("Right Stick X left (turn left)")
        elif command == 'd':
            self.axes[3] = 1.0   # Right stick X right
            self.get_logger().info("Right Stick X right (turn right)")
        else:
            self.get_logger().warn(f"Unknown command: {command}")
            return
        
        # Keep input active for a short time
        time.sleep(0.5)
        # Reset after action
        self.buttons = [0] * 11
        self.axes = [0.0] * 8

def main():
    print("=== Virtual Xbox Controller for Spider Robot ===")
    print("\nThis simulates Xbox controller input for testing.")
    print("Make sure the spider robot system is running:")
    print("  ros2 launch spider_bringup spider_robot.launch.py")
    print("\nAnd the spider controller is running:")
    print("  ros2 run spider_controller controller_node")
    print("\nOr launch both together:")
    print("  ros2 launch spider_controller spider_with_controller.launch.py")
    print("\nStarting virtual controller...\n")
    
    rclpy.init()
    
    controller = VirtualController()
    
    try:
        rclpy.spin(controller)
    except KeyboardInterrupt:
        print("\nVirtual controller stopped")
    finally:
        controller.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()