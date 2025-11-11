#!/usr/bin/env python3
"""
Diagnostic script for PCA9685 servo controller
Checks hardware connectivity and basic functionality
"""

import sys
import time

def check_imports():
    """Check if required libraries are installed"""
    print("=== Checking Python Libraries ===")
    
    try:
        import board
        print("✓ board module available")
    except ImportError:
        print("✗ board module not found - install adafruit-blinka")
        return False
    
    try:
        import busio
        print("✓ busio module available") 
    except ImportError:
        print("✗ busio module not found - install adafruit-blinka")
        return False
    
    try:
        from adafruit_servokit import ServoKit
        print("✓ ServoKit module available")
    except ImportError:
        print("✗ ServoKit module not found - install adafruit-circuitpython-servokit")
        return False
    
    return True

def check_i2c():
    """Check I2C connectivity"""
    print("\n=== Checking I2C Connectivity ===")
    
    try:
        import board
        import busio
        
        # Try to initialize I2C bus
        i2c = busio.I2C(board.SCL, board.SDA)
        print("✓ I2C bus initialized successfully")
        
        # Scan for devices
        print("Scanning for I2C devices...")
        while not i2c.try_lock():
            pass
        
        devices = i2c.scan()
        i2c.unlock()
        
        if devices:
            print(f"✓ Found I2C devices at addresses: {[hex(d) for d in devices]}")
            if 0x40 in devices:
                print("✓ PCA9685 found at default address 0x40")
                return True
            else:
                print("⚠ PCA9685 not found at 0x40 - check connections")
                return False
        else:
            print("✗ No I2C devices found - check wiring")
            return False
            
    except Exception as e:
        print(f"✗ I2C check failed: {e}")
        return False

def check_servokit():
    """Check ServoKit functionality"""
    print("\n=== Checking ServoKit Functionality ===")
    
    try:
        from adafruit_servokit import ServoKit
        
        # Initialize ServoKit
        kit = ServoKit(channels=16, address=0x40)
        print("✓ ServoKit initialized at address 0x40")
        
        # Test servo on channel 0
        print("Testing servo on channel 0...")
        
        # Move servo through positions
        positions = [0, 90, 180, 90]
        for pos in positions:
            print(f"  Moving to {pos}°...")
            kit.servo[0].angle = pos
            time.sleep(1.0)
        
        print("✓ ServoKit test completed successfully")
        return True
        
    except Exception as e:
        print(f"✗ ServoKit test failed: {e}")
        return False

def check_ros2():
    """Check ROS2 environment"""
    print("\n=== Checking ROS2 Environment ===")
    
    try:
        import rclpy
        print("✓ rclpy available")
    except ImportError:
        print("✗ rclpy not found - check ROS2 installation")
        return False
    
    try:
        from spider_msgs.msg import ServoArray, ServoPosition
        print("✓ spider_msgs available")
    except ImportError:
        print("✗ spider_msgs not found - build spider_msgs package")
        return False
    
    return True

def main():
    print("PCA9685 Servo Controller Diagnostics")
    print("=====================================")
    
    # Run all checks
    checks = [
        ("Python Libraries", check_imports),
        ("I2C Connectivity", check_i2c),
        ("ServoKit Hardware", check_servokit),
        ("ROS2 Environment", check_ros2),
    ]
    
    results = []
    for name, check_func in checks:
        try:
            result = check_func()
            results.append((name, result))
        except KeyboardInterrupt:
            print("\nDiagnostics interrupted by user")
            sys.exit(1)
        except Exception as e:
            print(f"\n✗ {name} check crashed: {e}")
            results.append((name, False))
    
    # Summary
    print("\n=== Diagnostics Summary ===")
    all_passed = True
    for name, passed in results:
        status = "✓ PASS" if passed else "✗ FAIL"
        print(f"{name}: {status}")
        if not passed:
            all_passed = False
    
    if all_passed:
        print("\n🎉 All diagnostics passed! System ready for use.")
        return 0
    else:
        print("\n⚠ Some diagnostics failed. Check the errors above.")
        return 1

if __name__ == "__main__":
    sys.exit(main())