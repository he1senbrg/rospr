// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from spider_msgs:msg/ServoPosition.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "spider_msgs/msg/detail/servo_position__functions.h"
#include "spider_msgs/msg/detail/servo_position__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace spider_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void ServoPosition_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) spider_msgs::msg::ServoPosition(_init);
}

void ServoPosition_fini_function(void * message_memory)
{
  auto typed_message = static_cast<spider_msgs::msg::ServoPosition *>(message_memory);
  typed_message->~ServoPosition();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ServoPosition_message_member_array[3] = {
  {
    "servo_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(spider_msgs::msg::ServoPosition, servo_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "angle",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(spider_msgs::msg::ServoPosition, angle),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "speed",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(spider_msgs::msg::ServoPosition, speed),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ServoPosition_message_members = {
  "spider_msgs::msg",  // message namespace
  "ServoPosition",  // message name
  3,  // number of fields
  sizeof(spider_msgs::msg::ServoPosition),
  false,  // has_any_key_member_
  ServoPosition_message_member_array,  // message members
  ServoPosition_init_function,  // function to initialize message memory (memory has to be allocated)
  ServoPosition_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ServoPosition_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ServoPosition_message_members,
  get_message_typesupport_handle_function,
  &spider_msgs__msg__ServoPosition__get_type_hash,
  &spider_msgs__msg__ServoPosition__get_type_description,
  &spider_msgs__msg__ServoPosition__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace spider_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<spider_msgs::msg::ServoPosition>()
{
  return &::spider_msgs::msg::rosidl_typesupport_introspection_cpp::ServoPosition_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, spider_msgs, msg, ServoPosition)() {
  return &::spider_msgs::msg::rosidl_typesupport_introspection_cpp::ServoPosition_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
