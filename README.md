# Spider Robot ROS2 System

A ROS2 (Kilted Kaiju) implementation of a 4-legged spider robot, recreating the functionality of the original Arduino sketch with modern robotics architecture.

## Architecture

### System Components

**Nodes:**
- `servo_controller_node` - Hardware abstraction for 12 servo motors
- `kinematics_node` - Coordinate transformation and inverse kinematics  
- `behavior_controller_node` - High-level movement behaviors and gaits
- `demo_behaviors_node` - Automated demo sequence

**Topics:**
- `/servo_positions` (spider_msgs/ServoArray) - Individual servo commands
- `/leg_positions` (spider_msgs/LegPositions) - Cartesian leg end positions
- `/robot_state` (spider_msgs/RobotState) - Current robot status

**Services:**
- `/execute_behavior` (spider_msgs/ExecuteBehavior) - Trigger specific behaviors
- `/set_robot_pose` (spider_msgs/SetPose) - Direct pose control

### Hardware Configuration

**Servo Layout:**
- 12 servo motors (3 per leg)
- GPIO pin mapping: [[2,3,4], [5,6,7], [8,9,10], [11,12,13]]
- Leg numbering: 0=front-right, 1=front-left, 2=back-right, 3=back-left
- Joint order per leg: shoulder, elbow, wrist

**Robot Dimensions:**
- Upper leg segment: 55mm
- Lower leg segment: 77.5mm  
- Shoulder offset: 27.5mm
- Leg spacing: 71mm

## Building and Installation

### Prerequisites

```bash
# Install ROS2 Kilted Kaiju
# Install dependencies for Raspberry Pi
sudo apt install python3-pip
pip3 install RPi.GPIO gpiozero
```

### Build System

```bash
# Navigate to workspace
cd /home/loki/ros2_ws

# Build packages
colcon build --packages-select spider_msgs spider_hardware spider_kinematics spider_behavior spider_bringup

# Source the workspace
source install/setup.bash
```

## Running the System

### Basic Launch

```bash
# Start all nodes
ros2 launch spider_bringup spider_robot.launch.py

# Run demo sequence  
ros2 launch spider_bringup spider_demo.launch.py
```

### Manual Control

```bash
# Execute individual behaviors
ros2 service call /execute_behavior spider_msgs/srv/ExecuteBehavior "{behavior_name: 'stand', repetitions: 1, speed_multiplier: 1.0}"

ros2 service call /execute_behavior spider_msgs/srv/ExecuteBehavior "{behavior_name: 'step_forward', repetitions: 5, speed_multiplier: 1.0}"

ros2 service call /execute_behavior spider_msgs/srv/ExecuteBehavior "{behavior_name: 'hand_wave', repetitions: 3, speed_multiplier: 1.0}"
```

### Available Behaviors

- `stand` - Stand in default position
- `sit` - Sit down to boot position  
- `step_forward` - Walk forward
- `step_back` - Walk backward
- `turn_left` - Rotate left in place
- `turn_right` - Rotate right in place
- `hand_wave` - Wave gesture with front leg
- `hand_shake` - Vertical handshake gesture
- `body_dance` - Rhythmic dancing motion

## System Status

```bash
# Monitor robot state
ros2 topic echo /robot_state

# View servo positions
ros2 topic echo /servo_positions

# Check leg positions
ros2 topic echo /leg_positions
```

## Troubleshooting

### Hardware Issues
- Verify GPIO connections match pin configuration
- Check servo power supply (5V recommended)
- Ensure proper servo calibration

### Software Issues
- Confirm all packages built successfully
- Verify spider_msgs interfaces are available
- Check node startup sequence in launch files

### Performance Tuning
- Adjust movement speeds via service parameters
- Modify servo control frequency (default 50Hz)
- Tune kinematics parameters for your hardware

## Safety Notes

- Always test movements in a safe environment
- Verify servo limits before operation
- Monitor system for overheating during extended use
- Have emergency stop mechanism ready