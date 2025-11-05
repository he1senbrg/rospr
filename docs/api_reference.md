# API Reference

## Messages

### ServoPosition
```
uint8 servo_id       # Servo ID (0-11)
float32 angle        # Target angle in degrees
float32 speed        # Movement speed multiplier
```

### LegPosition
```
geometry_msgs/Point position     # Cartesian coordinates (x, y, z)
float32 movement_speed          # Speed multiplier for this leg
```

### RobotState
```
std_msgs/Header header
string current_behavior          # Current executing behavior
bool is_moving                   # True if robot is in motion
float32 battery_level           # Battery percentage (0-100)
LegPositions current_pose        # Current leg positions
```

## Services

### ExecuteBehavior
Execute a named behavior pattern.

**Request:**
```
string behavior_name             # Name of behavior to execute
int32 repetitions               # Number of times to repeat (-1 = infinite)
float32 speed_multiplier        # Speed adjustment (1.0 = normal)
```

**Response:**
```
bool success                    # True if behavior started successfully
string message                  # Status or error message
```

### SetPose
Set robot to specific leg positions.

**Request:**
```
LegPositions target_pose         # Desired leg positions
float32 movement_speed          # Speed to reach target
```

**Response:**
```
bool success                    # True if pose was set
string message                  # Status message
```

## Available Behaviors

- `stand` - Stand up from sitting position
- `sit` - Sit down 
- `step_forward` - Walk forward (specify repetitions)
- `step_back` - Walk backward (specify repetitions)
- `turn_left` - Turn left in place (specify repetitions)
- `turn_right` - Turn right in place (specify repetitions)
- `hand_wave` - Wave gesture (specify repetitions)
- `hand_shake` - Shake gesture (specify repetitions)  
- `body_dance` - Dance routine (specify repetitions)