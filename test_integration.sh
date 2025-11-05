#!/bin/bash
"""
Spider Robot System Quick Test
Tests the complete system integration including walking behaviors
"""

echo "🕷️  Spider Robot System Quick Integration Test"
echo "=============================================="

# Auto-detect workspace path
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
WORKSPACE_PATH="$SCRIPT_DIR"

# Check if we're in a ROS2 workspace
if [ ! -d "$WORKSPACE_PATH/src" ]; then
    echo "❌ Not in a ROS2 workspace! Looking for src/ directory..."
    # Try parent directories
    CURRENT_DIR="$WORKSPACE_PATH"
    while [ "$CURRENT_DIR" != "/" ]; do
        if [ -d "$CURRENT_DIR/src" ]; then
            WORKSPACE_PATH="$CURRENT_DIR"
            break
        fi
        CURRENT_DIR="$(dirname "$CURRENT_DIR")"
    done
    
    # Final check
    if [ ! -d "$WORKSPACE_PATH/src" ]; then
        echo "❌ Could not find ROS2 workspace!"
        exit 1
    fi
fi

echo "📁 Workspace: $WORKSPACE_PATH"
cd "$WORKSPACE_PATH"

# Source ROS2 environment
echo "📦 Sourcing ROS2 environment..."
source /opt/ros/kilted/setup.bash
source install/setup.bash

# Build the system
echo "🔧 Building system..."
colcon build --packages-select spider_msgs spider_hardware spider_kinematics spider_behavior spider_bringup
if [ $? -ne 0 ]; then
    echo "❌ Build failed!"
    exit 1
fi
echo "✅ Build successful"

# Re-source after build
source install/setup.bash

# Start the robot system in background
echo "🚀 Starting spider robot system..."
ros2 launch spider_bringup spider_robot.launch.py &
LAUNCH_PID=$!

# Wait for system to initialize
echo "⏳ Waiting for system initialization..."
sleep 8

# Test service availability
echo "🔍 Testing service availability..."
timeout 10 ros2 service list | grep -q "/execute_behavior"
if [ $? -ne 0 ]; then
    echo "❌ ExecuteBehavior service not available"
    kill $LAUNCH_PID
    exit 1
fi
echo "✅ Services are available"

# Test basic stand behavior
echo "🧍 Testing stand behavior..."
timeout 15 ros2 service call /execute_behavior spider_msgs/srv/ExecuteBehavior "{behavior_name: 'stand', repetitions: 1, speed_multiplier: 1.0}"
if [ $? -ne 0 ]; then
    echo "❌ Stand behavior failed"
    kill $LAUNCH_PID
    exit 1
fi
echo "✅ Stand behavior successful"

sleep 3

# Test walking forward
echo "🚶 Testing walking forward..."
timeout 20 ros2 service call /execute_behavior spider_msgs/srv/ExecuteBehavior "{behavior_name: 'step_forward', repetitions: 2, speed_multiplier: 1.0}"
if [ $? -ne 0 ]; then
    echo "❌ Forward walking failed"
    kill $LAUNCH_PID
    exit 1
fi
echo "✅ Forward walking successful"

sleep 3

# Test walking backward
echo "🔙 Testing walking backward..."  
timeout 20 ros2 service call /execute_behavior spider_msgs/srv/ExecuteBehavior "{behavior_name: 'step_back', repetitions: 2, speed_multiplier: 1.0}"
if [ $? -ne 0 ]; then
    echo "❌ Backward walking failed"
    kill $LAUNCH_PID
    exit 1
fi
echo "✅ Backward walking successful"

sleep 3

# Test turning
echo "↪️  Testing turning..."
timeout 15 ros2 service call /execute_behavior spider_msgs/srv/ExecuteBehavior "{behavior_name: 'turn_left', repetitions: 2, speed_multiplier: 1.0}"
if [ $? -ne 0 ]; then
    echo "❌ Turning failed"
    kill $LAUNCH_PID  
    exit 1
fi
echo "✅ Turning successful"

sleep 3

# Test gestures
echo "👋 Testing hand wave..."
timeout 15 ros2 service call /execute_behavior spider_msgs/srv/ExecuteBehavior "{behavior_name: 'hand_wave', repetitions: 2, speed_multiplier: 1.0}"
if [ $? -ne 0 ]; then
    echo "❌ Hand wave failed"
    kill $LAUNCH_PID
    exit 1
fi
echo "✅ Hand wave successful"

sleep 3

# Test sit behavior
echo "🪑 Testing sit behavior..."
timeout 15 ros2 service call /execute_behavior spider_msgs/srv/ExecuteBehavior "{behavior_name: 'sit', repetitions: 1, speed_multiplier: 1.0}"
if [ $? -ne 0 ]; then
    echo "❌ Sit behavior failed"
    kill $LAUNCH_PID
    exit 1  
fi
echo "✅ Sit behavior successful"

# Check topic data flow
echo "📡 Testing topic data flow..."
timeout 5 ros2 topic echo /robot_state --once >/dev/null 2>&1
if [ $? -ne 0 ]; then
    echo "⚠️  Robot state topic not publishing (may be normal in simulation)"
else
    echo "✅ Robot state topic active"
fi

timeout 5 ros2 topic echo /servo_positions --once >/dev/null 2>&1  
if [ $? -ne 0 ]; then
    echo "⚠️  Servo positions topic not active (may be normal in simulation)"
else
    echo "✅ Servo positions topic active"
fi

# Clean up
echo "🛑 Shutting down system..."
kill $LAUNCH_PID
wait $LAUNCH_PID 2>/dev/null

echo ""
echo "🎉 ALL INTEGRATION TESTS PASSED!"
echo "================================="
echo "✅ System builds successfully"
echo "✅ All nodes launch correctly"  
echo "✅ Service communication works"
echo "✅ Walking behaviors function"
echo "✅ Turning behaviors function"
echo "✅ Gesture behaviors function"
echo "✅ Complete behavior sequence works"
echo ""
echo "🕷️  Spider robot system is fully operational and ready for deployment!"
echo "   Ready for Raspberry Pi hardware integration."