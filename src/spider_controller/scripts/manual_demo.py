#!/usr/bin/env python3
"""
Spider Robot Manual Control Demo

This script demonstrates how to control the spider robot manually
before testing with Xbox controller.

Usage: python3 manual_demo.py
"""

import rclpy
from rclpy.node import Node
from spider_msgs.srv import ExecuteBehavior
import time
import sys

class SpiderDemo(Node):
    def __init__(self):
        super().__init__('spider_demo')
        
        # Service client for executing behaviors
        self.behavior_client = self.create_client(
            ExecuteBehavior,
            '/execute_behavior'
        )
        
        # Wait for behavior service
        self.get_logger().info("Waiting for behavior service...")
        if not self.behavior_client.wait_for_service(timeout_sec=10.0):
            self.get_logger().error("Behavior service not available!")
            sys.exit(1)
        
        self.get_logger().info("Connected to behavior service")
    
    def execute_behavior(self, behavior_name, repetitions=1, speed_multiplier=1.0):
        """Execute a spider behavior synchronously"""
        request = ExecuteBehavior.Request()
        request.behavior_name = behavior_name
        request.repetitions = repetitions
        request.speed_multiplier = float(speed_multiplier)
        
        self.get_logger().info(f"Executing: {behavior_name} (reps: {repetitions}, speed: {speed_multiplier})")
        
        future = self.behavior_client.call_async(request)
        rclpy.spin_until_future_complete(self, future, timeout_sec=30.0)
        
        if future.result():
            response = future.result()
            if response.success:
                self.get_logger().info(f"✅ {behavior_name} completed successfully")
                return True
            else:
                self.get_logger().error(f"❌ {behavior_name} failed: {response.message}")
                return False
        else:
            self.get_logger().error(f"❌ Service call timeout for {behavior_name}")
            return False
    
    def run_demo(self):
        """Run a demonstration sequence"""
        self.get_logger().info("=== Starting Spider Robot Demo ===")
        
        demo_sequence = [
            ("stand", 1, 1.0, "Stand up"),
            ("hand_wave", 2, 1.0, "Wave hello"),
            ("step_forward", 3, 1.0, "Walk forward"),
            ("turn_right", 2, 1.0, "Turn around"),
            ("step_back", 2, 1.0, "Walk back"),
            ("hand_shake", 2, 1.0, "Handshake gesture"),
            ("body_dance", 2, 1.0, "Dance moves"),
            ("sit", 1, 1.0, "Sit down"),
        ]
        
        for behavior, reps, speed, description in demo_sequence:
            self.get_logger().info(f"\n--- {description} ---")
            success = self.execute_behavior(behavior, reps, speed)
            
            if not success:
                self.get_logger().error("Demo stopped due to behavior failure")
                return False
            
            # Small pause between behaviors
            time.sleep(1.0)
        
        self.get_logger().info("\n=== Demo Complete! ===")
        return True
    
    def interactive_mode(self):
        """Interactive mode for manual control"""
        self.get_logger().info("=== Interactive Mode ===")
        print("\nAvailable behaviors:")
        behaviors = [
            "stand", "sit", "step_forward", "step_back",
            "turn_left", "turn_right", "hand_wave", 
            "hand_shake", "body_dance"
        ]
        
        for i, behavior in enumerate(behaviors, 1):
            print(f"  {i}. {behavior}")
        print("  0. Exit")
        
        while True:
            try:
                choice = input("\nEnter behavior number (or 0 to exit): ").strip()
                
                if choice == '0':
                    break
                
                if not choice.isdigit():
                    print("Please enter a valid number")
                    continue
                
                choice_num = int(choice)
                if choice_num < 1 or choice_num > len(behaviors):
                    print("Invalid choice")
                    continue
                
                behavior = behaviors[choice_num - 1]
                
                # Get optional parameters
                reps = 1
                speed = 1.0
                
                reps_input = input(f"Repetitions (default {reps}): ").strip()
                if reps_input:
                    try:
                        reps = int(reps_input)
                    except ValueError:
                        print("Invalid repetitions, using default")
                
                speed_input = input(f"Speed multiplier (default {speed}): ").strip()
                if speed_input:
                    try:
                        speed = float(speed_input)
                    except ValueError:
                        print("Invalid speed, using default")
                
                self.execute_behavior(behavior, reps, speed)
                
            except KeyboardInterrupt:
                break
            except Exception as e:
                print(f"Error: {e}")

def main():
    print("=== Spider Robot Manual Control Demo ===")
    print("\nThis demo requires the spider robot system to be running.")
    print("Start with: ros2 launch spider_bringup spider_robot.launch.py")
    print("\nPress Ctrl+C to exit at any time.\n")
    
    rclpy.init()
    
    demo = SpiderDemo()
    
    try:
        # Ask user what to do
        print("Choose demo mode:")
        print("1. Automatic demo sequence")
        print("2. Interactive manual control")
        
        choice = input("\nEnter choice (1 or 2): ").strip()
        
        if choice == '1':
            demo.run_demo()
        elif choice == '2':
            demo.interactive_mode()
        else:
            print("Invalid choice")
    
    except KeyboardInterrupt:
        print("\nDemo interrupted by user")
    finally:
        demo.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()