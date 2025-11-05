# Raspberry Pi 5 Setup Guide

## Hardware Requirements

- Raspberry Pi 5 (4GB+ RAM recommended)
- MicroSD card (32GB+ Class 10)
- 12x servo motors (SG90 or equivalent)
- Servo expansion board or PWM HAT
- 5V power supply for servos (2A+)
- Jumper wires for connections

## Operating System Setup

### Install Ubuntu 24.04 LTS

1. Download Ubuntu 24.04 Server for Raspberry Pi
2. Flash to SD card using Raspberry Pi Imager
3. Enable SSH and configure WiFi during imaging

### Initial Configuration

```bash
# Update system
sudo apt update && sudo apt upgrade -y

# Install essential packages
sudo apt install -y python3-pip git curl wget

# Configure GPIO permissions
sudo usermod -a -G gpio $USER
sudo usermod -a -G dialout $USER
```

## ROS2 Kilted Kaiju Installation

### Install ROS2

```bash
# Add ROS2 repository
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg

echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null

# Update and install ROS2
sudo apt update
sudo apt install -y ros-kilted-desktop

# Install development tools
sudo apt install -y python3-colcon-common-extensions python3-rosdep

# Initialize rosdep
sudo rosdep init
rosdep update
```

### Install Python Dependencies

```bash
# GPIO and servo control libraries
pip3 install RPi.GPIO gpiozero

# Additional Python packages
pip3 install numpy scipy
```

## Hardware Connections

### Servo Wiring

| Leg | Joint    | GPIO Pin | Servo Wire Colors |
|-----|----------|----------|-------------------|
| 0   | Shoulder | GPIO 2   | Red(5V), Black(GND), Yellow(Signal) |
| 0   | Elbow    | GPIO 3   | Red(5V), Black(GND), Yellow(Signal) |
| 0   | Wrist    | GPIO 4   | Red(5V), Black(GND), Yellow(Signal) |
| 1   | Shoulder | GPIO 5   | Red(5V), Black(GND), Yellow(Signal) |
| 1   | Elbow    | GPIO 6   | Red(5V), Black(GND), Yellow(Signal) |
| 1   | Wrist    | GPIO 7   | Red(5V), Black(GND), Yellow(Signal) |
| 2   | Shoulder | GPIO 8   | Red(5V), Black(GND), Yellow(Signal) |
| 2   | Elbow    | GPIO 9   | Red(5V), Black(GND), Yellow(Signal) |
| 2   | Wrist    | GPIO 10  | Red(5V), Black(GND), Yellow(Signal) |
| 3   | Shoulder | GPIO 11  | Red(5V), Black(GND), Yellow(Signal) |
| 3   | Elbow    | GPIO 12  | Red(5V), Black(GND), Yellow(Signal) |
| 3   | Wrist    | GPIO 13  | Red(5V), Black(GND), Yellow(Signal) |

### Power Distribution

**Important:** Servos require external 5V power supply
- Connect servo power rails to external 5V supply
- Share ground between Pi and servo power supply
- Keep signal wires connected to Pi GPIO pins only

## System Configuration

### Environment Setup

```bash
# Add to ~/.bashrc
echo "source /opt/ros/kilted/setup.bash" >> ~/.bashrc
echo "source /home/loki/ros2_ws/install/setup.bash" >> ~/.bashrc

# Reload bash configuration
source ~/.bashrc
```

### Permissions

```bash
# Create udev rule for GPIO access
sudo tee /etc/udev/rules.d/99-gpio.rules << EOF
SUBSYSTEM=="gpio*", PROGRAM="/bin/sh -c 'chown -R root:gpio /sys/class/gpio && chmod -R 770 /sys/class/gpio; chown -R root:gpio /sys/devices/virtual/gpio && chmod -R 770 /sys/devices/virtual/gpio'"
EOF

# Reload udev rules
sudo udevadm control --reload-rules
sudo udevadm trigger
```

## Installation Steps

### Clone and Build

```bash
# Navigate to workspace
cd /home/loki/ros2_ws

# Install dependencies
rosdep install --from-paths src --ignore-src -r -y

# Build the workspace
colcon build

# Source the workspace
source install/setup.bash
```

### Verification

```bash
# Test servo hardware access (should not show errors)
python3 -c "import RPi.GPIO; import gpiozero; print('Hardware access OK')"

# Check ROS2 installation
ros2 --help

# Verify packages
ros2 pkg list | grep spider
```

## Running the System

### Initial Test

```bash
# Start system in simulation mode (no hardware)
ros2 launch spider_bringup spider_robot.launch.py

# In another terminal, test basic command
ros2 service call /execute_behavior spider_msgs/srv/ExecuteBehavior "{behavior_name: 'stand', repetitions: 1, speed_multiplier: 1.0}"
```

### Hardware Test

```bash
# Ensure servos are connected and powered
# Run with hardware
ros2 launch spider_bringup spider_robot.launch.py

# Start demo sequence
ros2 launch spider_bringup spider_demo.launch.py
```

## Troubleshooting

### GPIO Permission Issues
```bash
# Check user groups
groups $USER
# Should include: gpio, dialout

# Manual GPIO permissions (if needed)
sudo chgrp gpio /dev/gpiomem
sudo chmod g+rw /dev/gpiomem
```

### Servo Issues
```bash
# Test individual servo
python3 -c "
from gpiozero import Servo
s = Servo(2)
s.mid()
"
```

### ROS2 Issues
```bash
# Check environment
env | grep ROS

# Rebuild workspace
cd /home/loki/ros2_ws
colcon build --cmake-clean-cache
```

## Performance Optimization

### System Configuration

```bash
# Increase GPU memory split
sudo raspi-config
# Advanced Options > Memory Split > 64

# Disable unnecessary services
sudo systemctl disable bluetooth.service
sudo systemctl disable avahi-daemon.service
```

### Real-time Performance

```bash
# Set CPU governor to performance
echo 'performance' | sudo tee /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor
```

This completes the Raspberry Pi 5 setup for the spider robot system.