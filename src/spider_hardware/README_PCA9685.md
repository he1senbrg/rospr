# Spider Hardware - ServoKit PCA9685 Servo Controller

This package provides ROS2 control for the spider robot's 12 servo motors using Adafruit's ServoKit library with a PCA9685 PWM driver board.

## Hardware Requirements

- Raspberry Pi 5 (or compatible)
- PCA9685 16-channel PWM driver board
- 12 servo motors (SG90 or similar)
- I2C connection between Pi and PCA9685

## Wiring

### I2C Connection (PCA9685 to Raspberry Pi)
- VCC → 3.3V or 5V
- GND → GND  
- SCL → GPIO 3 (SCL)
- SDA → GPIO 2 (SDA)

### Servo Channel Assignment
- Leg 0 (front-right): channels 0, 1, 2 (coxa, femur, tibia)
- Leg 1 (front-left):  channels 3, 4, 5 (coxa, femur, tibia)
- Leg 2 (back-right):  channels 6, 7, 8 (coxa, femur, tibia)  
- Leg 3 (back-left):   channels 9, 10, 11 (coxa, femur, tibia)

## Installation

### 1. Install Required Python Libraries

```bash
# Install Adafruit CircuitPython ServoKit library
sudo pip3 install adafruit-circuitpython-servokit

# Enable I2C on Raspberry Pi
sudo raspi-config
# Navigate to Interface Options > I2C > Enable
```

### 2. Build the Package

```bash
cd ~/ros2_ws
colcon build --packages-select spider_hardware
source install/setup.bash
```

## Usage

### Launch the Servo Controller

```bash
# Launch with default configuration
ros2 launch spider_hardware servo_controller.launch.py

# Launch with custom config file
ros2 launch spider_hardware servo_controller.launch.py config_file:=/path/to/custom_config.yaml
```

### Send Servo Commands

The node subscribes to `/servo_positions` topic with message type `spider_msgs/ServoArray`:

```bash
# Example: Move servo 0 to 90 degrees at speed 1.0
ros2 topic pub /servo_positions spider_msgs/ServoArray "{servos: [{servo_id: 0, angle: 90.0, speed: 1.0}]}"
```

### Monitor Servo Status

```bash
# Check node status
ros2 node info /servo_controller_node

# View servo commands
ros2 topic echo /servo_positions
```

## Configuration

Edit `config/servo_config.yaml` to customize:

- I2C address (`i2c_address`)
- Servo channel mapping (`servo_channels`)
- Angle limits (`min_angle`, `max_angle`)
- Control frequency (`servo_rate`)

## Troubleshooting

### I2C Issues
```bash
# Check I2C devices
sudo i2cdetect -y 1

# Should show device at 0x40 (default PCA9685 address)
```

### Permission Issues
```bash
# Add user to i2c group
sudo usermod -a -G i2c $USER
# Logout and login again
```

### Import Errors
Make sure you installed the libraries system-wide:
```bash
sudo pip3 install adafruit-circuitpython-servokit
```

## API Reference

### Parameters
- `servo_channels`: List of 12 PCA9685 channel numbers (0-15)
- `i2c_address`: PCA9685 I2C address (default: 0x40)
- `min_angle`/`max_angle`: Servo angle limits in degrees
- `servo_rate`: Control loop frequency in Hz

### Topics
- `/servo_positions` (spider_msgs/ServoArray): Input servo commands
- Node publishes status and debug info to ROS2 logging system

### Services
None currently implemented.

## Hardware Notes

- PCA9685 supports up to 16 servos (we use 12)
- Standard servo PWM: 50Hz, 1-2ms pulse width
- Servo angles: 0-180 degrees
- Multiple PCA9685 boards can be chained for more servos