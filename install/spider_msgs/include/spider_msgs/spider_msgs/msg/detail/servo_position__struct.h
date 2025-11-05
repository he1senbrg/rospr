// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from spider_msgs:msg/ServoPosition.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "spider_msgs/msg/servo_position.h"


#ifndef SPIDER_MSGS__MSG__DETAIL__SERVO_POSITION__STRUCT_H_
#define SPIDER_MSGS__MSG__DETAIL__SERVO_POSITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/ServoPosition in the package spider_msgs.
/**
  * Individual servo position command
 */
typedef struct spider_msgs__msg__ServoPosition
{
  /// Servo ID (0-11)
  uint8_t servo_id;
  /// Target angle in degrees
  float angle;
  /// Movement speed multiplier
  float speed;
} spider_msgs__msg__ServoPosition;

// Struct for a sequence of spider_msgs__msg__ServoPosition.
typedef struct spider_msgs__msg__ServoPosition__Sequence
{
  spider_msgs__msg__ServoPosition * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} spider_msgs__msg__ServoPosition__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SPIDER_MSGS__MSG__DETAIL__SERVO_POSITION__STRUCT_H_
