#!/usr/bin/env python3
"""
Quick Spider Robot System Test Runner
A simplified test script that validates the core walking functionality
"""

import subprocess
import time
import sys
import os


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
    """Auto-detect the current shell"""
    # Try to get from SHELL environment variable
    shell_path = os.environ.get('SHELL', '/bin/bash')
    shell_name = os.path.basename(shell_path)
    
    # Verify shell is available
    available_shells = []
    for shell in ['bash', 'zsh', 'sh']:
        if os.path.exists(f'/bin/{shell}') or os.path.exists(f'/usr/bin/{shell}'):
            available_shells.append(shell)
    
    # Use detected shell if available, otherwise fallback
    if shell_name in available_shells:
        return shell_name
    elif 'bash' in available_shells:
        return 'bash'
    elif 'zsh' in available_shells:
        return 'zsh'
    else:
        return 'sh'


def get_setup_command(workspace_path, shell):
    """Get the appropriate setup command for the shell"""
    if shell == 'zsh':
        setup_file = 'setup.zsh'
    elif shell == 'bash':
        setup_file = 'setup.bash'
    else:  # sh or fallback
        setup_file = 'setup.sh'
    
    # Check if the specific setup file exists, fallback to .bash
    ros_setup = f"/opt/ros/kilted/setup.{setup_file.split('.')[1]}"
    if not os.path.exists(ros_setup):
        ros_setup = "/opt/ros/kilted/setup.bash"
    
    workspace_setup = f"{workspace_path}/install/setup.{setup_file.split('.')[1]}"
    if not os.path.exists(workspace_setup):
        workspace_setup = f"{workspace_path}/install/setup.bash"
    
    return f"source {ros_setup} && source {workspace_setup}"


def run_command(command, timeout=30):
    """Run a command and return success status"""
    workspace_path = get_workspace_path()
    shell = detect_shell()
    try:
        # Use detected shell for source commands
        full_command = [shell, '-c', command]
        result = subprocess.run(
            full_command, 
            capture_output=True, 
            text=True, 
            timeout=timeout,
            cwd=workspace_path
        )
        return result.returncode == 0, result.stdout, result.stderr
    except subprocess.TimeoutExpired:
        return False, "", "Command timed out"
    except Exception as e:
        return False, "", str(e)


def test_system_launch():
    """Test that the system can launch successfully"""
    print("🧪 Testing system launch...")
    
    workspace_path = get_workspace_path()
    shell = detect_shell()
    setup_cmd = get_setup_command(workspace_path, shell)
    
    # Source environment and build
    success, stdout, stderr = run_command(
        f"{setup_cmd} && colcon build", 
        timeout=60
    )
    
    if not success:
        print(f"❌ Build failed: {stderr}")
        return False
    
    print("✅ System builds successfully")
    return True


def test_service_interfaces():
    """Test that services are properly defined and available"""
    print("🧪 Testing service interfaces...")
    
    workspace_path = get_workspace_path()
    shell = detect_shell()
    setup_cmd = get_setup_command(workspace_path, shell)
    
    # Check if spider_msgs interfaces exist
    success, stdout, stderr = run_command(
        f"{setup_cmd} && ros2 interface list | grep spider_msgs"
    )
    
    if not success:
        print(f"❌ Spider messages not found: {stderr}")
        return False
    
    # Check for specific interfaces
    required_interfaces = [
        'spider_msgs/msg/ServoPosition',
        'spider_msgs/msg/ServoArray', 
        'spider_msgs/msg/LegPosition',
        'spider_msgs/msg/LegPositions',
        'spider_msgs/msg/RobotState',
        'spider_msgs/srv/ExecuteBehavior',
        'spider_msgs/srv/SetPose'
    ]
    
    for interface in required_interfaces:
        if interface not in stdout:
            print(f"❌ Missing interface: {interface}")
            return False
    
    print("✅ All required interfaces are available")
    return True


def test_node_executables():
    """Test that all node executables exist"""
    print("🧪 Testing node executables...")
    
    nodes = [
        'spider_hardware servo_controller_node',
        'spider_kinematics kinematics_node', 
        'spider_behavior behavior_controller_node',
        'spider_bringup demo_behaviors_node'
    ]
    
    workspace_path = get_workspace_path()
    shell = detect_shell()
    setup_cmd = get_setup_command(workspace_path, shell)
    
    for node in nodes:
        success, stdout, stderr = run_command(
            f"{setup_cmd} && "
            f"ros2 pkg executables {node.split()[0]} | grep {node.split()[1]}"
        )
        
        if not success:
            print(f"❌ Node executable not found: {node}")
            return False
    
    print("✅ All node executables are available")
    return True


def test_launch_files():
    """Test that launch files exist and are valid"""
    print("🧪 Testing launch files...")
    
    launch_files = [
        'spider_bringup spider_robot.launch.py',
        'spider_bringup spider_demo.launch.py'
    ]
    
    workspace_path = get_workspace_path()
    shell = detect_shell()
    setup_cmd = get_setup_command(workspace_path, shell)
    
    for launch_file in launch_files:
        package, file_name = launch_file.split()
        success, stdout, stderr = run_command(
            f"{setup_cmd} && "
            f"find install/{package}/share/{package}/launch -name '{file_name}' | head -1"
        )
        
        if not success or not stdout.strip():
            print(f"❌ Launch file not found: {launch_file}")
            return False
    
    print("✅ All launch files are available")
    return True


def test_basic_behavior_execution():
    """Test basic behavior execution through ros2 service calls"""
    print("🧪 Testing basic behavior execution...")
    
    # Start the system in background
    print("  📡 Starting robot system...")
    workspace_path = get_workspace_path()
    shell = detect_shell()
    setup_cmd = get_setup_command(workspace_path, shell)
    
    system_process = subprocess.Popen([
        shell, '-c',
        f'cd {workspace_path} && '
        f'{setup_cmd} && '
        'ros2 launch spider_bringup spider_robot.launch.py'
    ], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    
    # Wait for system to start
    time.sleep(10)
    
    try:
        # Test basic service calls
        behaviors_to_test = ['stand', 'sit']
        
        for behavior in behaviors_to_test:
            print(f"  🎭 Testing behavior: {behavior}")
            
            workspace_path = get_workspace_path()
            shell = detect_shell()
            setup_cmd = get_setup_command(workspace_path, shell)
            
            success, stdout, stderr = run_command(
                f"{setup_cmd} && "
                f"ros2 service call /execute_behavior spider_msgs/srv/ExecuteBehavior "
                f"\"{{behavior_name: '{behavior}', repetitions: 1, speed_multiplier: 1.0}}\"",
                timeout=15
            )
            
            if not success:
                print(f"❌ Behavior '{behavior}' failed: {stderr}")
                return False
            
            time.sleep(2)  # Wait between behaviors
        
        print("✅ Basic behaviors execute successfully")
        return True
        
    finally:
        # Clean up the system process
        system_process.terminate()
        system_process.wait(timeout=10)


def test_walking_sequence():
    """Test a complete walking sequence"""
    print("🧪 Testing walking sequence...")
    
    # Start the system in background  
    print("  📡 Starting robot system for walking test...")
    workspace_path = get_workspace_path()
    shell = detect_shell()
    setup_cmd = get_setup_command(workspace_path, shell)
    
    system_process = subprocess.Popen([
        shell, '-c', 
        f'cd {workspace_path} && '
        f'{setup_cmd} && '
        'ros2 launch spider_bringup spider_robot.launch.py'
    ], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    
    # Wait for system to start
    time.sleep(10)
    
    try:
        # Execute walking sequence
        walking_sequence = [
            ('stand', 1, 1.0),
            ('step_forward', 3, 1.0), 
            ('step_back', 2, 1.0),
            ('turn_left', 2, 1.0),
            ('turn_right', 2, 1.0),
            ('sit', 1, 1.0)
        ]
        
        for behavior, reps, speed in walking_sequence:
            print(f"  🚶 Executing: {behavior} (reps: {reps})")
            
            workspace_path = get_workspace_path()
            shell = detect_shell()
            setup_cmd = get_setup_command(workspace_path, shell)
            
            success, stdout, stderr = run_command(
                f"{setup_cmd} && "
                f"ros2 service call /execute_behavior spider_msgs/srv/ExecuteBehavior "
                f"\"{{behavior_name: '{behavior}', repetitions: {reps}, speed_multiplier: {speed}}}\"",
                timeout=20
            )
            
            if not success:
                print(f"❌ Walking behavior '{behavior}' failed: {stderr}")
                return False
            
            time.sleep(3)  # Wait between behaviors
        
        print("✅ Complete walking sequence executed successfully")
        return True
        
    finally:
        # Clean up
        system_process.terminate() 
        system_process.wait(timeout=10)


def main():
    """Run all tests"""
    workspace_path = get_workspace_path()
    print("🕷️  Spider Robot System Test Suite")
    print("=" * 50)
    print(f"📁 Workspace: {workspace_path}")
    print("=" * 50)
    
    tests = [
        ("System Build", test_system_launch),
        ("Service Interfaces", test_service_interfaces),
        ("Node Executables", test_node_executables),
        ("Launch Files", test_launch_files),
        ("Basic Behavior Execution", test_basic_behavior_execution),
        ("Walking Sequence", test_walking_sequence)
    ]
    
    passed = 0
    total = len(tests)
    failed_tests = []
    
    for test_name, test_func in tests:
        print(f"\n📋 Running: {test_name}")
        print("-" * 30)
        
        try:
            if test_func():
                passed += 1
                print(f"✅ {test_name}: PASSED")
            else:
                failed_tests.append(test_name)
                print(f"❌ {test_name}: FAILED")
        except Exception as e:
            failed_tests.append(test_name)
            print(f"❌ {test_name}: ERROR - {e}")
    
    # Summary
    print("\n" + "=" * 50)
    print("📊 TEST SUMMARY")
    print("=" * 50)
    print(f"Passed: {passed}/{total} ({passed/total*100:.1f}%)")
    
    if failed_tests:
        print(f"Failed: {', '.join(failed_tests)}")
        
    if passed == total:
        print("\n🎉 ALL TESTS PASSED! Spider robot system is ready for deployment.")
        return 0
    else:
        print(f"\n⚠️  {len(failed_tests)} test(s) failed. Please check the system configuration.")
        return 1


if __name__ == '__main__':
    exit_code = main()
    sys.exit(exit_code)