// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from spider_msgs:msg/LegPosition.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "spider_msgs/msg/leg_position.h"


#ifndef SPIDER_MSGS__MSG__DETAIL__LEG_POSITION__STRUCT_H_
#define SPIDER_MSGS__MSG__DETAIL__LEG_POSITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/LegPosition in the package spider_msgs.
/**
  * 3D position of a leg end effector
 */
typedef struct spider_msgs__msg__LegPosition
{
  /// Cartesian coordinates (x, y, z)
  geometry_msgs__msg__Point position;
  /// Speed multiplier for this leg
  float movement_speed;
} spider_msgs__msg__LegPosition;

// Struct for a sequence of spider_msgs__msg__LegPosition.
typedef struct spider_msgs__msg__LegPosition__Sequence
{
  spider_msgs__msg__LegPosition * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} spider_msgs__msg__LegPosition__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SPIDER_MSGS__MSG__DETAIL__LEG_POSITION__STRUCT_H_
