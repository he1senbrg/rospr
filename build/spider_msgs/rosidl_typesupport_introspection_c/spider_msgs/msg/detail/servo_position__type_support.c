// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from spider_msgs:msg/ServoPosition.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "spider_msgs/msg/detail/servo_position__rosidl_typesupport_introspection_c.h"
#include "spider_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "spider_msgs/msg/detail/servo_position__functions.h"
#include "spider_msgs/msg/detail/servo_position__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void spider_msgs__msg__ServoPosition__rosidl_typesupport_introspection_c__ServoPosition_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  spider_msgs__msg__ServoPosition__init(message_memory);
}

void spider_msgs__msg__ServoPosition__rosidl_typesupport_introspection_c__ServoPosition_fini_function(void * message_memory)
{
  spider_msgs__msg__ServoPosition__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember spider_msgs__msg__ServoPosition__rosidl_typesupport_introspection_c__ServoPosition_message_member_array[3] = {
  {
    "servo_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(spider_msgs__msg__ServoPosition, servo_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "angle",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(spider_msgs__msg__ServoPosition, angle),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "speed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(spider_msgs__msg__ServoPosition, speed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers spider_msgs__msg__ServoPosition__rosidl_typesupport_introspection_c__ServoPosition_message_members = {
  "spider_msgs__msg",  // message namespace
  "ServoPosition",  // message name
  3,  // number of fields
  sizeof(spider_msgs__msg__ServoPosition),
  false,  // has_any_key_member_
  spider_msgs__msg__ServoPosition__rosidl_typesupport_introspection_c__ServoPosition_message_member_array,  // message members
  spider_msgs__msg__ServoPosition__rosidl_typesupport_introspection_c__ServoPosition_init_function,  // function to initialize message memory (memory has to be allocated)
  spider_msgs__msg__ServoPosition__rosidl_typesupport_introspection_c__ServoPosition_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t spider_msgs__msg__ServoPosition__rosidl_typesupport_introspection_c__ServoPosition_message_type_support_handle = {
  0,
  &spider_msgs__msg__ServoPosition__rosidl_typesupport_introspection_c__ServoPosition_message_members,
  get_message_typesupport_handle_function,
  &spider_msgs__msg__ServoPosition__get_type_hash,
  &spider_msgs__msg__ServoPosition__get_type_description,
  &spider_msgs__msg__ServoPosition__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_spider_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, spider_msgs, msg, ServoPosition)() {
  if (!spider_msgs__msg__ServoPosition__rosidl_typesupport_introspection_c__ServoPosition_message_type_support_handle.typesupport_identifier) {
    spider_msgs__msg__ServoPosition__rosidl_typesupport_introspection_c__ServoPosition_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &spider_msgs__msg__ServoPosition__rosidl_typesupport_introspection_c__ServoPosition_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
