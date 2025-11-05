// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from spider_msgs:msg/LegPositions.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "spider_msgs/msg/detail/leg_positions__rosidl_typesupport_introspection_c.h"
#include "spider_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "spider_msgs/msg/detail/leg_positions__functions.h"
#include "spider_msgs/msg/detail/leg_positions__struct.h"


// Include directives for member types
// Member `legs`
#include "spider_msgs/msg/leg_position.h"
// Member `legs`
#include "spider_msgs/msg/detail/leg_position__rosidl_typesupport_introspection_c.h"
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void spider_msgs__msg__LegPositions__rosidl_typesupport_introspection_c__LegPositions_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  spider_msgs__msg__LegPositions__init(message_memory);
}

void spider_msgs__msg__LegPositions__rosidl_typesupport_introspection_c__LegPositions_fini_function(void * message_memory)
{
  spider_msgs__msg__LegPositions__fini(message_memory);
}

size_t spider_msgs__msg__LegPositions__rosidl_typesupport_introspection_c__size_function__LegPositions__legs(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * spider_msgs__msg__LegPositions__rosidl_typesupport_introspection_c__get_const_function__LegPositions__legs(
  const void * untyped_member, size_t index)
{
  const spider_msgs__msg__LegPosition * member =
    (const spider_msgs__msg__LegPosition *)(untyped_member);
  return &member[index];
}

void * spider_msgs__msg__LegPositions__rosidl_typesupport_introspection_c__get_function__LegPositions__legs(
  void * untyped_member, size_t index)
{
  spider_msgs__msg__LegPosition * member =
    (spider_msgs__msg__LegPosition *)(untyped_member);
  return &member[index];
}

void spider_msgs__msg__LegPositions__rosidl_typesupport_introspection_c__fetch_function__LegPositions__legs(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const spider_msgs__msg__LegPosition * item =
    ((const spider_msgs__msg__LegPosition *)
    spider_msgs__msg__LegPositions__rosidl_typesupport_introspection_c__get_const_function__LegPositions__legs(untyped_member, index));
  spider_msgs__msg__LegPosition * value =
    (spider_msgs__msg__LegPosition *)(untyped_value);
  *value = *item;
}

void spider_msgs__msg__LegPositions__rosidl_typesupport_introspection_c__assign_function__LegPositions__legs(
  void * untyped_member, size_t index, const void * untyped_value)
{
  spider_msgs__msg__LegPosition * item =
    ((spider_msgs__msg__LegPosition *)
    spider_msgs__msg__LegPositions__rosidl_typesupport_introspection_c__get_function__LegPositions__legs(untyped_member, index));
  const spider_msgs__msg__LegPosition * value =
    (const spider_msgs__msg__LegPosition *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember spider_msgs__msg__LegPositions__rosidl_typesupport_introspection_c__LegPositions_message_member_array[2] = {
  {
    "legs",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(spider_msgs__msg__LegPositions, legs),  // bytes offset in struct
    NULL,  // default value
    spider_msgs__msg__LegPositions__rosidl_typesupport_introspection_c__size_function__LegPositions__legs,  // size() function pointer
    spider_msgs__msg__LegPositions__rosidl_typesupport_introspection_c__get_const_function__LegPositions__legs,  // get_const(index) function pointer
    spider_msgs__msg__LegPositions__rosidl_typesupport_introspection_c__get_function__LegPositions__legs,  // get(index) function pointer
    spider_msgs__msg__LegPositions__rosidl_typesupport_introspection_c__fetch_function__LegPositions__legs,  // fetch(index, &value) function pointer
    spider_msgs__msg__LegPositions__rosidl_typesupport_introspection_c__assign_function__LegPositions__legs,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(spider_msgs__msg__LegPositions, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers spider_msgs__msg__LegPositions__rosidl_typesupport_introspection_c__LegPositions_message_members = {
  "spider_msgs__msg",  // message namespace
  "LegPositions",  // message name
  2,  // number of fields
  sizeof(spider_msgs__msg__LegPositions),
  false,  // has_any_key_member_
  spider_msgs__msg__LegPositions__rosidl_typesupport_introspection_c__LegPositions_message_member_array,  // message members
  spider_msgs__msg__LegPositions__rosidl_typesupport_introspection_c__LegPositions_init_function,  // function to initialize message memory (memory has to be allocated)
  spider_msgs__msg__LegPositions__rosidl_typesupport_introspection_c__LegPositions_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t spider_msgs__msg__LegPositions__rosidl_typesupport_introspection_c__LegPositions_message_type_support_handle = {
  0,
  &spider_msgs__msg__LegPositions__rosidl_typesupport_introspection_c__LegPositions_message_members,
  get_message_typesupport_handle_function,
  &spider_msgs__msg__LegPositions__get_type_hash,
  &spider_msgs__msg__LegPositions__get_type_description,
  &spider_msgs__msg__LegPositions__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_spider_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, spider_msgs, msg, LegPositions)() {
  spider_msgs__msg__LegPositions__rosidl_typesupport_introspection_c__LegPositions_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, spider_msgs, msg, LegPosition)();
  spider_msgs__msg__LegPositions__rosidl_typesupport_introspection_c__LegPositions_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!spider_msgs__msg__LegPositions__rosidl_typesupport_introspection_c__LegPositions_message_type_support_handle.typesupport_identifier) {
    spider_msgs__msg__LegPositions__rosidl_typesupport_introspection_c__LegPositions_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &spider_msgs__msg__LegPositions__rosidl_typesupport_introspection_c__LegPositions_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
