// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from spider_msgs:msg/ServoArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "spider_msgs/msg/servo_array.h"


#ifndef SPIDER_MSGS__MSG__DETAIL__SERVO_ARRAY__STRUCT_H_
#define SPIDER_MSGS__MSG__DETAIL__SERVO_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'servos'
#include "spider_msgs/msg/detail/servo_position__struct.h"

/// Struct defined in msg/ServoArray in the package spider_msgs.
/**
  * Array of servo position commands
 */
typedef struct spider_msgs__msg__ServoArray
{
  spider_msgs__msg__ServoPosition__Sequence servos;
} spider_msgs__msg__ServoArray;

// Struct for a sequence of spider_msgs__msg__ServoArray.
typedef struct spider_msgs__msg__ServoArray__Sequence
{
  spider_msgs__msg__ServoArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} spider_msgs__msg__ServoArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SPIDER_MSGS__MSG__DETAIL__SERVO_ARRAY__STRUCT_H_
