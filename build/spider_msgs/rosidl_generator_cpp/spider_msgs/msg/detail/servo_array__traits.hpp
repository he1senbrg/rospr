// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from spider_msgs:msg/ServoArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "spider_msgs/msg/servo_array.hpp"


#ifndef SPIDER_MSGS__MSG__DETAIL__SERVO_ARRAY__TRAITS_HPP_
#define SPIDER_MSGS__MSG__DETAIL__SERVO_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "spider_msgs/msg/detail/servo_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'servos'
#include "spider_msgs/msg/detail/servo_position__traits.hpp"

namespace spider_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ServoArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: servos
  {
    if (msg.servos.size() == 0) {
      out << "servos: []";
    } else {
      out << "servos: [";
      size_t pending_items = msg.servos.size();
      for (auto item : msg.servos) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ServoArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: servos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.servos.size() == 0) {
      out << "servos: []\n";
    } else {
      out << "servos:\n";
      for (auto item : msg.servos) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ServoArray & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace spider_msgs

namespace rosidl_generator_traits
{

[[deprecated("use spider_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const spider_msgs::msg::ServoArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  spider_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use spider_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const spider_msgs::msg::ServoArray & msg)
{
  return spider_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<spider_msgs::msg::ServoArray>()
{
  return "spider_msgs::msg::ServoArray";
}

template<>
inline const char * name<spider_msgs::msg::ServoArray>()
{
  return "spider_msgs/msg/ServoArray";
}

template<>
struct has_fixed_size<spider_msgs::msg::ServoArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<spider_msgs::msg::ServoArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<spider_msgs::msg::ServoArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SPIDER_MSGS__MSG__DETAIL__SERVO_ARRAY__TRAITS_HPP_
