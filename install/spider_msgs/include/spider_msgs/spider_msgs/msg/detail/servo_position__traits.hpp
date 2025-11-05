// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from spider_msgs:msg/ServoPosition.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "spider_msgs/msg/servo_position.hpp"


#ifndef SPIDER_MSGS__MSG__DETAIL__SERVO_POSITION__TRAITS_HPP_
#define SPIDER_MSGS__MSG__DETAIL__SERVO_POSITION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "spider_msgs/msg/detail/servo_position__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace spider_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ServoPosition & msg,
  std::ostream & out)
{
  out << "{";
  // member: servo_id
  {
    out << "servo_id: ";
    rosidl_generator_traits::value_to_yaml(msg.servo_id, out);
    out << ", ";
  }

  // member: angle
  {
    out << "angle: ";
    rosidl_generator_traits::value_to_yaml(msg.angle, out);
    out << ", ";
  }

  // member: speed
  {
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ServoPosition & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: servo_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "servo_id: ";
    rosidl_generator_traits::value_to_yaml(msg.servo_id, out);
    out << "\n";
  }

  // member: angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angle: ";
    rosidl_generator_traits::value_to_yaml(msg.angle, out);
    out << "\n";
  }

  // member: speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ServoPosition & msg, bool use_flow_style = false)
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
  const spider_msgs::msg::ServoPosition & msg,
  std::ostream & out, size_t indentation = 0)
{
  spider_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use spider_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const spider_msgs::msg::ServoPosition & msg)
{
  return spider_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<spider_msgs::msg::ServoPosition>()
{
  return "spider_msgs::msg::ServoPosition";
}

template<>
inline const char * name<spider_msgs::msg::ServoPosition>()
{
  return "spider_msgs/msg/ServoPosition";
}

template<>
struct has_fixed_size<spider_msgs::msg::ServoPosition>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<spider_msgs::msg::ServoPosition>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<spider_msgs::msg::ServoPosition>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SPIDER_MSGS__MSG__DETAIL__SERVO_POSITION__TRAITS_HPP_
