// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from spider_msgs:msg/RobotState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "spider_msgs/msg/robot_state.h"


#ifndef SPIDER_MSGS__MSG__DETAIL__ROBOT_STATE__STRUCT_H_
#define SPIDER_MSGS__MSG__DETAIL__ROBOT_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'current_behavior'
#include "rosidl_runtime_c/string.h"
// Member 'current_pose'
#include "spider_msgs/msg/detail/leg_positions__struct.h"

/// Struct defined in msg/RobotState in the package spider_msgs.
/**
  * Robot state information
 */
typedef struct spider_msgs__msg__RobotState
{
  std_msgs__msg__Header header;
  /// Current executing behavior
  rosidl_runtime_c__String current_behavior;
  /// True if robot is in motion
  bool is_moving;
  /// Battery percentage (0-100)
  float battery_level;
  /// Current leg positions
  spider_msgs__msg__LegPositions current_pose;
} spider_msgs__msg__RobotState;

// Struct for a sequence of spider_msgs__msg__RobotState.
typedef struct spider_msgs__msg__RobotState__Sequence
{
  spider_msgs__msg__RobotState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} spider_msgs__msg__RobotState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SPIDER_MSGS__MSG__DETAIL__ROBOT_STATE__STRUCT_H_
