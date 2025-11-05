// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from spider_msgs:msg/LegPositions.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "spider_msgs/msg/leg_positions.h"


#ifndef SPIDER_MSGS__MSG__DETAIL__LEG_POSITIONS__STRUCT_H_
#define SPIDER_MSGS__MSG__DETAIL__LEG_POSITIONS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'legs'
#include "spider_msgs/msg/detail/leg_position__struct.h"
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/LegPositions in the package spider_msgs.
/**
  * Positions for all 4 legs
 */
typedef struct spider_msgs__msg__LegPositions
{
  /// leg[0] = front-right, leg[1] = front-left,
  /// leg[2] = back-right, leg[3] = back-left
  spider_msgs__msg__LegPosition legs[4];
  std_msgs__msg__Header header;
} spider_msgs__msg__LegPositions;

// Struct for a sequence of spider_msgs__msg__LegPositions.
typedef struct spider_msgs__msg__LegPositions__Sequence
{
  spider_msgs__msg__LegPositions * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} spider_msgs__msg__LegPositions__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SPIDER_MSGS__MSG__DETAIL__LEG_POSITIONS__STRUCT_H_
