// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from spider_msgs:msg/ServoArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "spider_msgs/msg/detail/servo_array__rosidl_typesupport_introspection_c.h"
#include "spider_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "spider_msgs/msg/detail/servo_array__functions.h"
#include "spider_msgs/msg/detail/servo_array__struct.h"


// Include directives for member types
// Member `servos`
#include "spider_msgs/msg/servo_position.h"
// Member `servos`
#include "spider_msgs/msg/detail/servo_position__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void spider_msgs__msg__ServoArray__rosidl_typesupport_introspection_c__ServoArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  spider_msgs__msg__ServoArray__init(message_memory);
}

void spider_msgs__msg__ServoArray__rosidl_typesupport_introspection_c__ServoArray_fini_function(void * message_memory)
{
  spider_msgs__msg__ServoArray__fini(message_memory);
}

size_t spider_msgs__msg__ServoArray__rosidl_typesupport_introspection_c__size_function__ServoArray__servos(
  const void * untyped_member)
{
  const spider_msgs__msg__ServoPosition__Sequence * member =
    (const spider_msgs__msg__ServoPosition__Sequence *)(untyped_member);
  return member->size;
}

const void * spider_msgs__msg__ServoArray__rosidl_typesupport_introspection_c__get_const_function__ServoArray__servos(
  const void * untyped_member, size_t index)
{
  const spider_msgs__msg__ServoPosition__Sequence * member =
    (const spider_msgs__msg__ServoPosition__Sequence *)(untyped_member);
  return &member->data[index];
}

void * spider_msgs__msg__ServoArray__rosidl_typesupport_introspection_c__get_function__ServoArray__servos(
  void * untyped_member, size_t index)
{
  spider_msgs__msg__ServoPosition__Sequence * member =
    (spider_msgs__msg__ServoPosition__Sequence *)(untyped_member);
  return &member->data[index];
}

void spider_msgs__msg__ServoArray__rosidl_typesupport_introspection_c__fetch_function__ServoArray__servos(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const spider_msgs__msg__ServoPosition * item =
    ((const spider_msgs__msg__ServoPosition *)
    spider_msgs__msg__ServoArray__rosidl_typesupport_introspection_c__get_const_function__ServoArray__servos(untyped_member, index));
  spider_msgs__msg__ServoPosition * value =
    (spider_msgs__msg__ServoPosition *)(untyped_value);
  *value = *item;
}

void spider_msgs__msg__ServoArray__rosidl_typesupport_introspection_c__assign_function__ServoArray__servos(
  void * untyped_member, size_t index, const void * untyped_value)
{
  spider_msgs__msg__ServoPosition * item =
    ((spider_msgs__msg__ServoPosition *)
    spider_msgs__msg__ServoArray__rosidl_typesupport_introspection_c__get_function__ServoArray__servos(untyped_member, index));
  const spider_msgs__msg__ServoPosition * value =
    (const spider_msgs__msg__ServoPosition *)(untyped_value);
  *item = *value;
}

bool spider_msgs__msg__ServoArray__rosidl_typesupport_introspection_c__resize_function__ServoArray__servos(
  void * untyped_member, size_t size)
{
  spider_msgs__msg__ServoPosition__Sequence * member =
    (spider_msgs__msg__ServoPosition__Sequence *)(untyped_member);
  spider_msgs__msg__ServoPosition__Sequence__fini(member);
  return spider_msgs__msg__ServoPosition__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember spider_msgs__msg__ServoArray__rosidl_typesupport_introspection_c__ServoArray_message_member_array[1] = {
  {
    "servos",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(spider_msgs__msg__ServoArray, servos),  // bytes offset in struct
    NULL,  // default value
    spider_msgs__msg__ServoArray__rosidl_typesupport_introspection_c__size_function__ServoArray__servos,  // size() function pointer
    spider_msgs__msg__ServoArray__rosidl_typesupport_introspection_c__get_const_function__ServoArray__servos,  // get_const(index) function pointer
    spider_msgs__msg__ServoArray__rosidl_typesupport_introspection_c__get_function__ServoArray__servos,  // get(index) function pointer
    spider_msgs__msg__ServoArray__rosidl_typesupport_introspection_c__fetch_function__ServoArray__servos,  // fetch(index, &value) function pointer
    spider_msgs__msg__ServoArray__rosidl_typesupport_introspection_c__assign_function__ServoArray__servos,  // assign(index, value) function pointer
    spider_msgs__msg__ServoArray__rosidl_typesupport_introspection_c__resize_function__ServoArray__servos  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers spider_msgs__msg__ServoArray__rosidl_typesupport_introspection_c__ServoArray_message_members = {
  "spider_msgs__msg",  // message namespace
  "ServoArray",  // message name
  1,  // number of fields
  sizeof(spider_msgs__msg__ServoArray),
  false,  // has_any_key_member_
  spider_msgs__msg__ServoArray__rosidl_typesupport_introspection_c__ServoArray_message_member_array,  // message members
  spider_msgs__msg__ServoArray__rosidl_typesupport_introspection_c__ServoArray_init_function,  // function to initialize message memory (memory has to be allocated)
  spider_msgs__msg__ServoArray__rosidl_typesupport_introspection_c__ServoArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t spider_msgs__msg__ServoArray__rosidl_typesupport_introspection_c__ServoArray_message_type_support_handle = {
  0,
  &spider_msgs__msg__ServoArray__rosidl_typesupport_introspection_c__ServoArray_message_members,
  get_message_typesupport_handle_function,
  &spider_msgs__msg__ServoArray__get_type_hash,
  &spider_msgs__msg__ServoArray__get_type_description,
  &spider_msgs__msg__ServoArray__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_spider_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, spider_msgs, msg, ServoArray)() {
  spider_msgs__msg__ServoArray__rosidl_typesupport_introspection_c__ServoArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, spider_msgs, msg, ServoPosition)();
  if (!spider_msgs__msg__ServoArray__rosidl_typesupport_introspection_c__ServoArray_message_type_support_handle.typesupport_identifier) {
    spider_msgs__msg__ServoArray__rosidl_typesupport_introspection_c__ServoArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &spider_msgs__msg__ServoArray__rosidl_typesupport_introspection_c__ServoArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
