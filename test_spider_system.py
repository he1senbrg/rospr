#!/usr/bin/env python3
"""
Comprehensive Integration Test for Spider Robot System
Tests all nodes, packages, interfaces, and behaviors in a realistic scenario
"""

import rclpy
from rclpy.node import Node
from spider_msgs.msg import LegPositions, LegPosition, ServoArray, ServoPosition, RobotState
from spider_msgs.srv import ExecuteBehavior, SetPose
from geometry_msgs.msg import Point
from std_msgs.msg import Header
import time
import threading
import subprocess
import sys
import signal
import os
from typing import List, Dict, Any


class SpiderSystemTester(Node):
    def __init__(self):
        super().__init__('spider_system_tester')
        
        # Test state tracking
        self.test_results = {}
        self.servo_commands_received = []
        self.leg_positions_received = []
        self.robot_states_received = []
        
        # Service clients
        self.behavior_client = self.create_client(ExecuteBehavior, '/execute_behavior')
        self.pose_client = self.create_client(SetPose, '/set_robot_pose')
        
        # Topic subscribers for verification
        self.servo_subscriber = self.create_subscription(
            ServoArray, '/servo_positions', self.servo_callback, 10
        )
        self.leg_subscriber = self.create_subscription(
            LegPositions, '/leg_positions', self.leg_callback, 10
        )
        self.state_subscriber = self.create_subscription(
            RobotState, '/robot_state', self.state_callback, 10
        )
        
        # Topic publishers for testing
        self.leg_publisher = self.create_publisher(LegPositions, '/leg_positions', 10)
        
        self.get_logger().info("Spider System Tester initialized")
    
    def servo_callback(self, msg):
        """Record servo commands for verification"""
        self.servo_commands_received.append({
            'timestamp': time.time(),
            'servos': [(s.servo_id, s.angle, s.speed) for s in msg.servos]
        })
        
    def leg_callback(self, msg):
        """Record leg position commands for verification"""
        self.leg_positions_received.append({
            'timestamp': time.time(),
            'legs': [(leg.position.x, leg.position.y, leg.position.z, leg.movement_speed) 
                    for leg in msg.legs]
        })
        
    def state_callback(self, msg):
        """Record robot state updates"""
        self.robot_states_received.append({
            'timestamp': time.time(),
            'behavior': msg.current_behavior,
            'moving': msg.is_moving,
            'battery': msg.battery_level
        })
    
    def wait_for_services(self, timeout=10.0):
        """Wait for all required services to be available"""
        self.get_logger().info("Waiting for services...")
        
        services_ready = True
        if not self.behavior_client.wait_for_service(timeout_sec=timeout):
            self.get_logger().error("ExecuteBehavior service not available")
            services_ready = False
            
        if not self.pose_client.wait_for_service(timeout_sec=timeout):
            self.get_logger().error("SetPose service not available")
            services_ready = False
            
        return services_ready
    
    def execute_behavior(self, behavior_name: str, repetitions: int = 1, 
                        speed_multiplier: float = 1.0) -> bool:
        """Execute a behavior and return success status"""
        request = ExecuteBehavior.Request()
        request.behavior_name = behavior_name
        request.repetitions = repetitions
        request.speed_multiplier = speed_multiplier
        
        self.get_logger().info(f"Testing behavior: {behavior_name}")
        
        future = self.behavior_client.call_async(request)
        rclpy.spin_until_future_complete(self, future, timeout_sec=30.0)
        
        if future.result():
            success = future.result().success
            message = future.result().message
            self.get_logger().info(f"Behavior {behavior_name}: {'SUCCESS' if success else 'FAILED'} - {message}")
            return success
        else:
            self.get_logger().error(f"Service call failed for behavior: {behavior_name}")
            return False
    
    def set_custom_pose(self) -> bool:
        """Test direct pose setting service"""
        pose = LegPositions()
        pose.header = Header()
        pose.header.stamp = self.get_clock().now().to_msg()
        
        # Create 4 legs with custom positions
        pose.legs = []
        positions = [
            (50.0, 20.0, -40.0),   # Front-right
            (50.0, 20.0, -40.0),   # Front-left  
            (50.0, 0.0, -40.0),    # Back-right
            (50.0, 0.0, -40.0)     # Back-left
        ]
        
        for i, (x, y, z) in enumerate(positions):
            leg = LegPosition()
            leg.position = Point(x=x, y=y, z=z)
            leg.movement_speed = 2.0
            pose.legs.append(leg)
        
        request = SetPose.Request()
        request.target_pose = pose
        request.movement_speed = 2.0
        
        self.get_logger().info("Testing custom pose setting")
        
        future = self.pose_client.call_async(request)
        rclpy.spin_until_future_complete(self, future, timeout_sec=15.0)
        
        if future.result():
            success = future.result().success
            message = future.result().message
            self.get_logger().info(f"Custom pose: {'SUCCESS' if success else 'FAILED'} - {message}")
            return success
        else:
            self.get_logger().error("Custom pose service call failed")
            return False
    
    def test_data_flow_integrity(self) -> bool:
        """Test that data flows correctly through all nodes"""
        self.get_logger().info("Testing data flow integrity...")
        
        # Clear previous data
        self.servo_commands_received.clear()
        self.leg_positions_received.clear()
        self.robot_states_received.clear()
        
        # Publish a leg position to trigger the pipeline
        pose = LegPositions()
        pose.header = Header()
        pose.header.stamp = self.get_clock().now().to_msg()
        pose.legs = []
        
        for i in range(4):
            leg = LegPosition()
            leg.position = Point(x=60.0, y=20.0, z=-45.0)
            leg.movement_speed = 1.0
            pose.legs.append(leg)
        
        self.leg_publisher.publish(pose)
        
        # Wait for data to propagate
        time.sleep(2.0)
        rclpy.spin_once(self, timeout_sec=1.0)
        
        # Verify data flow
        leg_data_received = len(self.leg_positions_received) > 0
        servo_data_received = len(self.servo_commands_received) > 0
        state_data_received = len(self.robot_states_received) > 0
        
        self.get_logger().info(f"Data flow check - Legs: {leg_data_received}, "
                              f"Servos: {servo_data_received}, State: {state_data_received}")
        
        return leg_data_received and servo_data_received and state_data_received
    
    def verify_servo_commands(self) -> bool:
        """Verify that servo commands are within valid ranges"""
        if not self.servo_commands_received:
            return False
            
        for cmd_set in self.servo_commands_received:
            for servo_id, angle, speed in cmd_set['servos']:
                if not (0 <= servo_id <= 11):
                    self.get_logger().error(f"Invalid servo ID: {servo_id}")
                    return False
                if not (0.0 <= angle <= 180.0):
                    self.get_logger().error(f"Invalid servo angle: {angle}")
                    return False
                if speed <= 0:
                    self.get_logger().error(f"Invalid servo speed: {speed}")
                    return False
        
        self.get_logger().info("All servo commands are valid")
        return True
    
    def run_comprehensive_test(self) -> Dict[str, bool]:
        """Run the complete test suite"""
        results = {}
        
        self.get_logger().info("=" * 50)
        self.get_logger().info("Starting Comprehensive Spider Robot Test")
        self.get_logger().info("=" * 50)
        
        # Test 1: Service availability
        results['services_available'] = self.wait_for_services()
        if not results['services_available']:
            self.get_logger().error("Services not available - aborting tests")
            return results
        
        time.sleep(2.0)  # Allow system to stabilize
        
        # Test 2: Data flow integrity
        results['data_flow'] = self.test_data_flow_integrity()
        
        # Test 3: Basic behaviors
        results['stand'] = self.execute_behavior('stand', 1, 1.0)
        time.sleep(3.0)
        
        results['sit'] = self.execute_behavior('sit', 1, 1.0)
        time.sleep(3.0)
        
        # Test 4: Movement behaviors (core walking functionality)
        results['step_forward'] = self.execute_behavior('step_forward', 3, 1.5)
        time.sleep(2.0)
        
        results['step_back'] = self.execute_behavior('step_back', 3, 1.5)
        time.sleep(2.0)
        
        # Test 5: Turning behaviors
        results['turn_left'] = self.execute_behavior('turn_left', 2, 1.0)
        time.sleep(2.0)
        
        results['turn_right'] = self.execute_behavior('turn_right', 2, 1.0)
        time.sleep(2.0)
        
        # Test 6: Gesture behaviors
        results['hand_wave'] = self.execute_behavior('hand_wave', 2, 1.0)
        time.sleep(2.0)
        
        results['hand_shake'] = self.execute_behavior('hand_shake', 2, 1.0)
        time.sleep(2.0)
        
        # Test 7: Complex behavior
        results['body_dance'] = self.execute_behavior('body_dance', 5, 1.0)
        time.sleep(3.0)
        
        # Test 8: Custom pose setting
        results['custom_pose'] = self.set_custom_pose()
        time.sleep(2.0)
        
        # Test 9: Return to standing
        results['final_stand'] = self.execute_behavior('stand', 1, 1.0)
        time.sleep(2.0)
        
        # Test 10: Servo command validation
        results['servo_validation'] = self.verify_servo_commands()
        
        # Test 11: Invalid behavior handling
        results['invalid_behavior'] = not self.execute_behavior('invalid_behavior', 1, 1.0)
        
        return results
    
    def print_test_summary(self, results: Dict[str, bool]):
        """Print comprehensive test results"""
        self.get_logger().info("=" * 50)
        self.get_logger().info("TEST RESULTS SUMMARY")
        self.get_logger().info("=" * 50)
        
        passed = 0
        total = len(results)
        
        for test_name, success in results.items():
            status = "PASS" if success else "FAIL"
            self.get_logger().info(f"{test_name:20s}: {status}")
            if success:
                passed += 1
        
        self.get_logger().info("-" * 50)
        self.get_logger().info(f"Overall: {passed}/{total} tests passed ({passed/total*100:.1f}%)")
        
        if passed == total:
            self.get_logger().info("🎉 ALL TESTS PASSED! Spider robot system is fully functional.")
        else:
            self.get_logger().warn(f"⚠️  {total-passed} tests failed. Check logs for details.")
        
        # Print data statistics
        self.get_logger().info(f"Data collected:")
        self.get_logger().info(f"  - Servo commands: {len(self.servo_commands_received)}")
        self.get_logger().info(f"  - Leg positions: {len(self.leg_positions_received)}")
        self.get_logger().info(f"  - Robot states: {len(self.robot_states_received)}")


def get_workspace_path():
    """Auto-detect the ROS2 workspace path"""
    # Get the directory where this script is located
    script_dir = os.path.dirname(os.path.abspath(__file__))
    
    # Check if we're in a ROS2 workspace by looking for src/ directory
    if os.path.isdir(os.path.join(script_dir, 'src')):
        return script_dir
    
    # Check parent directories for a ROS2 workspace
    current_dir = script_dir
    while current_dir != '/':
        if os.path.isdir(os.path.join(current_dir, 'src')):
            return current_dir
        current_dir = os.path.dirname(current_dir)
    
    # Fallback to current working directory
    cwd = os.getcwd()
    if os.path.isdir(os.path.join(cwd, 'src')):
        return cwd
    
    # Final fallback to the original hardcoded path
    return '/home/loki/ros2_ws'


def detect_shell():
    """Auto-detect the current shell (bash, zsh, or sh)"""
    shell_path = os.environ.get('SHELL', '/bin/bash')
    shell_name = os.path.basename(shell_path)
    
    # Map shell names to supported types
    if 'zsh' in shell_name:
        return 'zsh'
    elif 'bash' in shell_name:
        return 'bash'
    else:
        return 'sh'  # Default fallback


def get_setup_command(workspace_path, shell):
    """Get the appropriate setup command for the detected shell"""
    if shell == 'zsh':
        return f"source /opt/ros/kilted/setup.zsh && source {workspace_path}/install/setup.zsh"
    elif shell == 'bash':
        return f"source /opt/ros/kilted/setup.bash && source {workspace_path}/install/setup.bash"
    else:  # sh fallback
        return f"source /opt/ros/kilted/setup.sh && source {workspace_path}/install/setup.sh"


class SystemLauncher:
    """Helper class to manage system startup and shutdown"""
    
    def __init__(self):
        self.process = None
        self.workspace_path = get_workspace_path()
    
    def launch_system(self) -> bool:
        """Launch the spider robot system"""
        try:
            # Auto-detect shell and create appropriate setup command
            shell = detect_shell()
            setup_cmd = get_setup_command(self.workspace_path, shell)
            
            # Source ROS2 and launch the system
            cmd = [
                shell, '-c',
                f'{setup_cmd} && '
                'ros2 launch spider_bringup spider_robot.launch.py'
            ]
            
            self.process = subprocess.Popen(
                cmd, 
                cwd=self.workspace_path,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE
            )
            
            # Give system time to start
            time.sleep(8.0)
            
            # Check if process is still running
            if self.process.poll() is None:
                print("✅ Spider robot system launched successfully")
                return True
            else:
                print("❌ Failed to launch spider robot system")
                return False
                
        except Exception as e:
            print(f"❌ Error launching system: {e}")
            return False
    
    def shutdown_system(self):
        """Shutdown the spider robot system"""
        if self.process:
            self.process.terminate()
            self.process.wait(timeout=10)
            print("🛑 Spider robot system shut down")


def signal_handler(sig, frame):
    """Handle Ctrl+C gracefully"""
    print("\n🛑 Test interrupted by user")
    sys.exit(0)


def main():
    # Setup signal handler
    signal.signal(signal.SIGINT, signal_handler)
    
    workspace_path = get_workspace_path()
    print("🚀 Starting Spider Robot System Integration Test")
    print("=" * 60)
    print(f"📁 Workspace: {workspace_path}")
    print("=" * 60)
    
    # Launch the robot system
    launcher = SystemLauncher()
    if not launcher.launch_system():
        print("❌ Could not start robot system. Exiting.")
        return 1
    
    try:
        # Initialize ROS2
        rclpy.init()
        
        # Create tester node
        tester = SpiderSystemTester()
        
        # Run the comprehensive test
        results = tester.run_comprehensive_test()
        
        # Print results
        tester.print_test_summary(results)
        
        # Determine exit code
        all_passed = all(results.values())
        exit_code = 0 if all_passed else 1
        
    except Exception as e:
        print(f"❌ Test execution failed: {e}")
        exit_code = 1
        
    finally:
        # Cleanup
        if 'tester' in locals():
            tester.destroy_node()
        rclpy.shutdown()
        launcher.shutdown_system()
        
    print(f"\n🏁 Test completed with exit code: {exit_code}")
    return exit_code


if __name__ == '__main__':
    exit_code = main()
    sys.exit(exit_code)