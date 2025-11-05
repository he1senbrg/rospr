// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from spider_msgs:msg/RobotState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "spider_msgs/msg/robot_state.hpp"


#ifndef SPIDER_MSGS__MSG__DETAIL__ROBOT_STATE__TRAITS_HPP_
#define SPIDER_MSGS__MSG__DETAIL__ROBOT_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "spider_msgs/msg/detail/robot_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'current_pose'
#include "spider_msgs/msg/detail/leg_positions__traits.hpp"

namespace spider_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RobotState & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: current_behavior
  {
    out << "current_behavior: ";
    rosidl_generator_traits::value_to_yaml(msg.current_behavior, out);
    out << ", ";
  }

  // member: is_moving
  {
    out << "is_moving: ";
    rosidl_generator_traits::value_to_yaml(msg.is_moving, out);
    out << ", ";
  }

  // member: battery_level
  {
    out << "battery_level: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_level, out);
    out << ", ";
  }

  // member: current_pose
  {
    out << "current_pose: ";
    to_flow_style_yaml(msg.current_pose, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: current_behavior
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_behavior: ";
    rosidl_generator_traits::value_to_yaml(msg.current_behavior, out);
    out << "\n";
  }

  // member: is_moving
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_moving: ";
    rosidl_generator_traits::value_to_yaml(msg.is_moving, out);
    out << "\n";
  }

  // member: battery_level
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "battery_level: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_level, out);
    out << "\n";
  }

  // member: current_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_pose:\n";
    to_block_style_yaml(msg.current_pose, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotState & msg, bool use_flow_style = false)
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
  const spider_msgs::msg::RobotState & msg,
  std::ostream & out, size_t indentation = 0)
{
  spider_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use spider_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const spider_msgs::msg::RobotState & msg)
{
  return spider_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<spider_msgs::msg::RobotState>()
{
  return "spider_msgs::msg::RobotState";
}

template<>
inline const char * name<spider_msgs::msg::RobotState>()
{
  return "spider_msgs/msg/RobotState";
}

template<>
struct has_fixed_size<spider_msgs::msg::RobotState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<spider_msgs::msg::RobotState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<spider_msgs::msg::RobotState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SPIDER_MSGS__MSG__DETAIL__ROBOT_STATE__TRAITS_HPP_
