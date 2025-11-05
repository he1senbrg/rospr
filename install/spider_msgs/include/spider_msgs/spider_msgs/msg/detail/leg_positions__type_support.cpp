// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from spider_msgs:msg/LegPositions.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "spider_msgs/msg/detail/leg_positions__functions.h"
#include "spider_msgs/msg/detail/leg_positions__struct.hpp"
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

void LegPositions_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) spider_msgs::msg::LegPositions(_init);
}

void LegPositions_fini_function(void * message_memory)
{
  auto typed_message = static_cast<spider_msgs::msg::LegPositions *>(message_memory);
  typed_message->~LegPositions();
}

size_t size_function__LegPositions__legs(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__LegPositions__legs(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<spider_msgs::msg::LegPosition, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__LegPositions__legs(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<spider_msgs::msg::LegPosition, 4> *>(untyped_member);
  return &member[index];
}

void fetch_function__LegPositions__legs(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const spider_msgs::msg::LegPosition *>(
    get_const_function__LegPositions__legs(untyped_member, index));
  auto & value = *reinterpret_cast<spider_msgs::msg::LegPosition *>(untyped_value);
  value = item;
}

void assign_function__LegPositions__legs(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<spider_msgs::msg::LegPosition *>(
    get_function__LegPositions__legs(untyped_member, index));
  const auto & value = *reinterpret_cast<const spider_msgs::msg::LegPosition *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember LegPositions_message_member_array[2] = {
  {
    "legs",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<spider_msgs::msg::LegPosition>(),  // members of sub message
    false,  // is key
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(spider_msgs::msg::LegPositions, legs),  // bytes offset in struct
    nullptr,  // default value
    size_function__LegPositions__legs,  // size() function pointer
    get_const_function__LegPositions__legs,  // get_const(index) function pointer
    get_function__LegPositions__legs,  // get(index) function pointer
    fetch_function__LegPositions__legs,  // fetch(index, &value) function pointer
    assign_function__LegPositions__legs,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(spider_msgs::msg::LegPositions, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers LegPositions_message_members = {
  "spider_msgs::msg",  // message namespace
  "LegPositions",  // message name
  2,  // number of fields
  sizeof(spider_msgs::msg::LegPositions),
  false,  // has_any_key_member_
  LegPositions_message_member_array,  // message members
  LegPositions_init_function,  // function to initialize message memory (memory has to be allocated)
  LegPositions_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t LegPositions_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &LegPositions_message_members,
  get_message_typesupport_handle_function,
  &spider_msgs__msg__LegPositions__get_type_hash,
  &spider_msgs__msg__LegPositions__get_type_description,
  &spider_msgs__msg__LegPositions__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace spider_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<spider_msgs::msg::LegPositions>()
{
  return &::spider_msgs::msg::rosidl_typesupport_introspection_cpp::LegPositions_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, spider_msgs, msg, LegPositions)() {
  return &::spider_msgs::msg::rosidl_typesupport_introspection_cpp::LegPositions_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
