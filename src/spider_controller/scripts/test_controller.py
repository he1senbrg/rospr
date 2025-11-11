#!/usr/bin/env python3
"""
Xbox Controller Test Script for Spider Robot

This script helps test Xbox controller connectivity and functionality
without requiring the full spider robot system to be running.

Usage: python3 test_controller.py
"""

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
import sys
import time

class ControllerTester(Node):
    def __init__(self):
        super().__init__('controller_tester')
        
        # Subscribe to joystick input
        self.joy_subscriber = self.create_subscription(
            Joy,
            '/joy',
            self.joy_callback,
            10
        )
        
        self.get_logger().info("=== Xbox Controller Tester ===")
        self.get_logger().info("Waiting for controller input...")
        self.get_logger().info("Press buttons and move sticks to test")
        self.get_logger().info("Press Ctrl+C to exit")
        
        # Button names for reference
        self.button_names = {
            0: "A", 1: "B", 2: "X", 3: "Y",
            4: "LB", 5: "RB", 6: "Back", 7: "Start", 
            8: "Xbox", 9: "LS", 10: "RS"
        }
        
        self.axis_names = {
            0: "Left Stick X", 1: "Left Stick Y", 2: "Left Trigger",
            3: "Right Stick X", 4: "Right Stick Y", 5: "Right Trigger",
            6: "D-pad X", 7: "D-pad Y"
        }
        
        self.last_joy_time = 0.0
        
    def joy_callback(self, msg):
        """Process joystick input and display information"""
        current_time = time.time()
        
        # Don't spam output - limit to 10Hz
        if current_time - self.last_joy_time < 0.1:
            return
        self.last_joy_time = current_time
        
        # Check for button presses
        pressed_buttons = []
        for i, pressed in enumerate(msg.buttons):
            if pressed:
                button_name = self.button_names.get(i, f"Button{i}")
                pressed_buttons.append(f"{button_name}({i})")
        
        # Check for significant axis movements (outside dead zone)
        active_axes = []
        dead_zone = 0.15
        for i, value in enumerate(msg.axes):
            if abs(value) > dead_zone:
                axis_name = self.axis_names.get(i, f"Axis{i}")
                active_axes.append(f"{axis_name}({i})={value:.2f}")
        
        # Display active inputs
        if pressed_buttons or active_axes:
            output = []
            if pressed_buttons:
                output.append(f"Buttons: {', '.join(pressed_buttons)}")
            if active_axes:
                output.append(f"Axes: {', '.join(active_axes)}")
            
            self.get_logger().info(" | ".join(output))

def check_controller_device():
    """Check if controller device exists"""
    import os
    import glob
    
    js_devices = glob.glob('/dev/input/js*')
    if not js_devices:
        print("❌ No joystick devices found in /dev/input/")
        print("   Make sure Xbox controller is connected")
        return False
    
    print(f"✅ Found joystick device(s): {', '.join(js_devices)}")
    
    # Try to test the first device
    try:
        import subprocess
        result = subprocess.run(['jstest', '--version'], 
                              capture_output=True, text=True)
        if result.returncode == 0:
            print("✅ jstest utility available for testing")
        else:
            print("⚠️  jstest not available, install with: sudo apt install joystick")
    except FileNotFoundError:
        print("⚠️  jstest not available, install with: sudo apt install joystick")
    
    return True

def test_raw_input():
    """Test raw controller input using jstest if available"""
    print("\n=== Testing Raw Controller Input ===")
    try:
        import subprocess
        js_devices = ['/dev/input/js0']  # Test first device
        
        for device in js_devices:
            print(f"Testing {device}...")
            result = subprocess.run(['timeout', '3', 'jstest', '--normal', device], 
                                  capture_output=True, text=True)
            
            if result.returncode == 0 or result.returncode == 124:  # 124 = timeout
                print("✅ Raw controller input working")
                if result.stdout:
                    lines = result.stdout.split('\n')[:3]  # Show first few lines
                    for line in lines:
                        if line.strip():
                            print(f"   {line}")
                break
            else:
                print(f"❌ Error testing {device}: {result.stderr}")
                
    except Exception as e:
        print(f"⚠️  Could not test raw input: {e}")

def check_ros_joy():
    """Check if ROS2 joy package is available"""
    print("\n=== Checking ROS2 Joy Package ===")
    try:
        import subprocess
        result = subprocess.run(['ros2', 'pkg', 'list', '|', 'grep', 'joy'], 
                              shell=True, capture_output=True, text=True)
        
        if 'joy' in result.stdout:
            print("✅ ROS2 joy package is available")
        else:
            print("❌ ROS2 joy package not found")
            print("   Install with: sudo apt install ros-kilted-joy")
            
    except Exception as e:
        print(f"⚠️  Could not check ROS2 packages: {e}")

def main():
    print("=== Spider Robot Xbox Controller Test ===\n")
    
    # Pre-flight checks
    if not check_controller_device():
        sys.exit(1)
    
    check_ros_joy()
    test_raw_input()
    
    print("\n=== Starting ROS2 Controller Test ===")
    print("Make sure joy_node is running:")
    print("  ros2 run joy joy_node")
    print("\nOr launch the full controller stack:")
    print("  ros2 launch spider_controller spider_controller.launch.py")
    print("\nStarting controller input tester...\n")
    
    # Initialize ROS2
    rclpy.init()
    
    tester = ControllerTester()
    
    try:
        rclpy.spin(tester)
    except KeyboardInterrupt:
        print("\n=== Test Complete ===")
        print("Controller testing finished.")
    finally:
        tester.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()