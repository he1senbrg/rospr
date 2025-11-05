# Hardware Setup Guide

## Servo Motor Connections

Connect 12 servo motors to Raspberry Pi GPIO pins as follows:

### Pin Layout
- **Leg 0 (Front-Right)**: GPIO pins 2, 3, 4
- **Leg 1 (Front-Left)**: GPIO pins 5, 6, 7
- **Leg 2 (Back-Right)**: GPIO pins 8, 9, 10
- **Leg 3 (Back-Left)**: GPIO pins 11, 12, 13

### Joint Assignment per Leg
- Pin 0: Shoulder (alpha) - Vertical rotation
- Pin 1: Elbow (beta) - Upper/lower leg angle  
- Pin 2: Wrist (gamma) - Horizontal rotation

## Power Requirements

- 12V power supply recommended for servo motors
- Ensure common ground between Pi and servo power
- Use level shifters if needed for 5V servo control signals

## Calibration

1. Run calibration mode to adjust servo offsets
2. Measure actual leg positions vs expected
3. Update parameters in launch files

For troubleshooting, see system logs: `ros2 topic echo /robot_state`