# Spider Robot Xbox Controller

This package provides Xbox controller support for the spider robot, allowing real-time teleoperation control.

## Features

- **Real-time Control**: Direct control of spider robot using Xbox controller
- **Variable Speed**: Speed control via analog triggers
- **Dead Zone Support**: Configurable dead zones for precise control
- **Button Mapping**: Customizable button assignments for different behaviors
- **Gesture Support**: Quick access to spider gestures via controller buttons
- **Wireless/Wired Support**: Works with both wired and Bluetooth Xbox controllers

## Xbox Controller Mapping

### Buttons
- **A Button**: Stand up
- **B Button**: Sit down
- **Left Bumper (LB)**: Hand wave gesture
- **Right Bumper (RB)**: Handshake gesture
- **Right Stick Click**: Body dance

### Analog Controls
- **Left Stick Y**: Walk forward/backward
- **Right Stick X**: Turn left/right
- **Left Trigger**: Slow motion mode (0.3x speed)
- **Right Trigger**: Fast mode (2.0x speed)

### D-Pad
- **Up/Down**: Walk forward/backward (discrete)
- **Left/Right**: Turn left/right (discrete)

## Installation and Setup

### 1. Install Dependencies
```bash
# Install ROS2 joystick packages
sudo apt update
sudo apt install -y ros-kilted-joy ros-kilted-teleop-twist-joy joystick

# Install Xbox controller drivers (usually included in modern Linux)
sudo apt install -y xboxdrv  # Optional, for older controllers
```

### 2. Connect Xbox Controller

#### Wired Connection
1. Connect Xbox controller via USB cable
2. Controller should be auto-detected as `/dev/input/js0`

#### Wireless (Bluetooth) Connection
```bash
# Put controller in pairing mode (Xbox + Share buttons for 3 seconds)
sudo bluetoothctl
[bluetooth]# power on
[bluetooth]# agent on
[bluetooth]# default-agent
[bluetooth]# scan on
# Wait for controller to appear, then:
[bluetooth]# pair XX:XX:XX:XX:XX:XX
[bluetooth]# connect XX:XX:XX:XX:XX:XX
[bluetooth]# trust XX:XX:XX:XX:XX:XX
[bluetooth]# exit
```

### 3. Test Controller
```bash
# Test controller detection
ls /dev/input/js*

# Test joystick input
jstest /dev/input/js0

# Test with ROS2 joy node
ros2 run joy joy_node
ros2 topic echo /joy
```

## Usage

### Method 1: Complete Spider + Controller Launch
```bash
# Launch spider robot with controller support
ros2 launch spider_controller spider_with_controller.launch.py

# Or with custom joystick device
ros2 launch spider_controller spider_with_controller.launch.py joy_device:=/dev/input/js1
```

### Method 2: Add Controller to Main Launch
```bash
# Launch spider robot with controller enabled
ros2 launch spider_bringup spider_robot.launch.py enable_controller:=true

# Specify custom joystick device
ros2 launch spider_bringup spider_robot.launch.py enable_controller:=true joy_device:=/dev/input/js1
```

### Method 3: Controller Only (Robot already running)
```bash
# Launch just the controller interface
ros2 launch spider_controller spider_controller.launch.py
```

## Configuration

### Controller Mapping
Edit `/config/controller_mapping.yaml` to customize:

```yaml
# Dead zone for analog sticks
dead_zone: 0.15

# Speed scaling factors
speed_scales:
  walk: 2.0       # Walking speed multiplier
  turn: 1.5       # Turning speed multiplier  
  gesture: 1.0    # Gesture speed

# Button mappings
button_mappings:
  0: "stand"           # A button
  1: "sit"             # B button
  4: "hand_wave"       # Left Bumper
  5: "hand_shake"      # Right Bumper
  10: "body_dance"     # Right stick click
```

### Timing Settings
```yaml
timing:
  button_repeat_rate: 0.1    # Minimum time between button presses
  movement_update_rate: 20   # Hz for movement updates
  gesture_cooldown: 2.0      # Time between gestures
```

## Troubleshooting

### Controller Not Detected
```bash
# Check if controller is connected
lsusb | grep Xbox
ls /dev/input/js*

# Check permissions
ls -l /dev/input/js0
sudo chmod 666 /dev/input/js0  # If needed

# Test raw input
evtest /dev/input/event*
```

### ROS2 Joy Node Issues
```bash
# Check joy node status
ros2 node info /joy_node

# Verify joy messages
ros2 topic echo /joy --once

# Check service availability
ros2 service list | grep behavior
```

### Controller Lag/Responsiveness
- Reduce `coalesce_interval` in joy node parameters
- Increase `autorepeat_rate` for more frequent updates
- Check for wireless interference (2.4GHz devices)

### Button Mapping Issues
- Verify controller type (Xbox One, Xbox 360, etc.)
- Use `jstest` to check button/axis assignments
- Update `controller_mapping.yaml` if needed

## Advanced Features

### Custom Speed Profiles
Add speed profiles for different situations:
```yaml
speed_profiles:
  careful: 0.3    # Slow and precise
  normal: 1.0     # Default speed
  fast: 2.0       # Quick movements
```

### Multi-Controller Support
For multiple controllers, launch with different device paths:
```bash
ros2 launch spider_controller spider_controller.launch.py joy_device:=/dev/input/js1
```

### Emergency Stop
- Hold **Start + Back** buttons simultaneously to stop all movement
- Or quickly press **B button** to sit down

## Development Notes

### Adding New Behaviors
1. Define behavior in `spider_behavior` package
2. Add button mapping in `controller_mapping.yaml`
3. Update documentation

### Button ID Reference
```
Xbox Controller Button IDs:
A=0, B=1, X=2, Y=3, LB=4, RB=5, 
Back=6, Start=7, Xbox=8, LS=9, RS=10

Axis IDs:
LX=0, LY=1, LT=2, RX=3, RY=4, RT=5, DX=6, DY=7
```