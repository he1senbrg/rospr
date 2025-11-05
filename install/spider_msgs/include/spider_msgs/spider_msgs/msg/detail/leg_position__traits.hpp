// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from spider_msgs:msg/LegPosition.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "spider_msgs/msg/leg_position.hpp"


#ifndef SPIDER_MSGS__MSG__DETAIL__LEG_POSITION__TRAITS_HPP_
#define SPIDER_MSGS__MSG__DETAIL__LEG_POSITION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "spider_msgs/msg/detail/leg_position__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace spider_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const LegPosition & msg,
  std::ostream & out)
{
  out << "{";
  // member: position
  {
    out << "position: ";
    to_flow_style_yaml(msg.position, out);
    out << ", ";
  }

  // member: movement_speed
  {
    out << "movement_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.movement_speed, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LegPosition & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position:\n";
    to_block_style_yaml(msg.position, out, indentation + 2);
  }

  // member: movement_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "movement_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.movement_speed, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LegPosition & msg, bool use_flow_style = false)
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
  const spider_msgs::msg::LegPosition & msg,
  std::ostream & out, size_t indentation = 0)
{
  spider_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use spider_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const spider_msgs::msg::LegPosition & msg)
{
  return spider_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<spider_msgs::msg::LegPosition>()
{
  return "spider_msgs::msg::LegPosition";
}

template<>
inline const char * name<spider_msgs::msg::LegPosition>()
{
  return "spider_msgs/msg/LegPosition";
}

template<>
struct has_fixed_size<spider_msgs::msg::LegPosition>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value> {};

template<>
struct has_bounded_size<spider_msgs::msg::LegPosition>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value> {};

template<>
struct is_message<spider_msgs::msg::LegPosition>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SPIDER_MSGS__MSG__DETAIL__LEG_POSITION__TRAITS_HPP_
