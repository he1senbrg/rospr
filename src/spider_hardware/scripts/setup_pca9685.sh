#!/bin/bash
# Installation script for PCA9685 servo controller dependencies
# Run this script on your Raspberry Pi 5

echo "=== Spider Hardware PCA9685 Setup ==="
echo "Installing dependencies for PCA9685 servo controller..."

# Update package lists
echo "Updating package lists..."
sudo apt update

# Install Python development tools
echo "Installing Python development tools..."
sudo apt install -y python3-pip python3-dev python3-setuptools

# Install I2C tools
echo "Installing I2C tools..."
sudo apt install -y i2c-tools

# Install Adafruit CircuitPython libraries
echo "Installing Adafruit CircuitPython libraries..."
sudo pip3 install adafruit-circuitpython-servokit
sudo pip3 install adafruit-blinka

# Enable I2C interface
echo "Enabling I2C interface..."
sudo raspi-config nonint do_i2c 0

# Add user to i2c group
echo "Adding user to i2c group..."
sudo usermod -a -G i2c $USER

# Create udev rule for I2C permissions
echo "Creating I2C udev rule..."
echo 'KERNEL=="i2c-[0-9]*", GROUP="i2c"' | sudo tee /etc/udev/rules.d/90-i2c.rules

# Check I2C devices
echo "Checking I2C interface..."
if command -v i2cdetect &> /dev/null; then
    echo "Scanning I2C bus 1..."
    sudo i2cdetect -y 1
    echo ""
    echo "Look for device at address 0x40 (PCA9685 default)"
else
    echo "i2cdetect not available - install i2c-tools manually"
fi

echo ""
echo "=== Setup Complete ==="
echo "Please reboot your system to ensure all changes take effect:"
echo "  sudo reboot"
echo ""
echo "After reboot, verify I2C setup:"
echo "  i2cdetect -y 1"
echo ""
echo "Then build and run the ROS2 package:"
echo "  cd ~/ros2_ws"
echo "  colcon build --packages-select spider_hardware"
echo "  source install/setup.bash"
echo "  ros2 launch spider_hardware servo_controller.launch.py"