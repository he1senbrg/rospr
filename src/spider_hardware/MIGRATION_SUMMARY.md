# PCA9685 Migration Summary

## Changes Made

### 1. Updated servo_controller_node.py
- **Replaced GPIO/gpiozero imports** with Adafruit CircuitPython libraries:
  - `board`, `busio` for I2C communication
  - `adafruit_pca9685.PCA9685` for PWM driver control
  - `adafruit_motor.servo` for servo control
  
- **Updated parameters**:
  - Changed `servo_pins` to `servo_channels` (PCA9685 channels 0-15)
  - Added `i2c_address` parameter for PCA9685 I2C address
  
- **Rewritten hardware initialization**:
  - Initialize I2C bus using board.SCL/SDA
  - Create PCA9685 instance with configurable address
  - Set PWM frequency to 50Hz for servos
  - Create servo objects using PCA9685 channels
  
- **Updated servo control**:
  - Simplified angle setting using `servo.angle = degrees` (0-180°)
  - Removed complex PWM value calculations
  
- **Updated cleanup**:
  - Proper PCA9685 deinitialization
  - Removed GPIO.cleanup() calls

### 2. Updated Package Dependencies
- **setup.py**: Added Adafruit library dependencies:
  - `adafruit-circuitpython-pca9685`
  - `adafruit-circuitpython-motor`

### 3. Added Configuration Files
- **config/servo_config.yaml**: 
  - PCA9685-specific parameters
  - Channel mapping documentation
  - I2C address configuration
  
- **launch/servo_controller.launch.py**:
  - Launch file for easy deployment
  - Configuration file integration
  - Simulation time parameter

### 4. Added Documentation
- **README_PCA9685.md**:
  - Hardware requirements and wiring
  - Installation instructions
  - Usage examples
  - Troubleshooting guide
  
### 5. Added Testing & Diagnostic Tools
- **scripts/test_servos.py**:
  - Comprehensive servo testing script
  - Various movement patterns
  - Individual and group servo control
  
- **scripts/diagnostics.py**:
  - Hardware connectivity checks
  - Library installation verification
  - I2C bus scanning
  - PCA9685 functionality test
  
- **scripts/setup_pca9685.sh**:
  - Automated dependency installation
  - I2C interface configuration
  - System setup automation

## Key Differences from GPIO Version

### Hardware Interface
- **Old**: Direct GPIO PWM control using gpiozero
- **New**: I2C communication to PCA9685 PWM driver

### Servo Control  
- **Old**: Manual PWM pulse width calculation (-1 to +1 values)
- **New**: Direct angle setting (0-180°) via Adafruit library

### Wiring
- **Old**: 12 individual GPIO pins for servo control
- **New**: 2 I2C pins (SDA/SCL) + PCA9685 board

### Advantages
1. **Reduced GPIO usage**: Only 2 pins vs 12 pins
2. **Better servo control**: Dedicated PWM hardware
3. **Expandability**: Up to 16 servos per board, chainable
4. **Isolation**: Servo power isolated from Pi
5. **Precision**: Hardware PWM vs software PWM

## Usage Instructions

### Installation on Raspberry Pi
```bash
# Run setup script
./src/spider_hardware/scripts/setup_pca9685.sh

# Or manual installation
sudo pip3 install adafruit-circuitpython-pca9685
sudo pip3 install adafruit-circuitpython-motor
sudo raspi-config nonint do_i2c 0  # Enable I2C
```

### Build and Launch
```bash
cd ~/ros2_ws
colcon build --packages-select spider_hardware
source install/setup.bash
ros2 launch spider_hardware servo_controller.launch.py
```

### Testing
```bash
# Run diagnostics
ros2 run spider_hardware servo_diagnostics

# Run servo tests  
ros2 run spider_hardware test_servos
```

### Configuration
Edit `config/servo_config.yaml` to customize:
- I2C address (if using multiple PCA9685 boards)
- Servo channel mapping
- Angle limits and control frequency

## Hardware Requirements
- Raspberry Pi 5 (or compatible)
- PCA9685 16-channel PWM driver board
- 12 servo motors (SG90 or similar) 
- Jumper wires for I2C connection
- External power supply for servos (5-6V, 2-3A recommended)