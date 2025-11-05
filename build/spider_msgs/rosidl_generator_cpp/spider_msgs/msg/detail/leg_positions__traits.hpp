// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from spider_msgs:msg/LegPositions.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "spider_msgs/msg/leg_positions.hpp"


#ifndef SPIDER_MSGS__MSG__DETAIL__LEG_POSITIONS__TRAITS_HPP_
#define SPIDER_MSGS__MSG__DETAIL__LEG_POSITIONS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "spider_msgs/msg/detail/leg_positions__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'legs'
#include "spider_msgs/msg/detail/leg_position__traits.hpp"
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace spider_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const LegPositions & msg,
  std::ostream & out)
{
  out << "{";
  // member: legs
  {
    if (msg.legs.size() == 0) {
      out << "legs: []";
    } else {
      out << "legs: [";
      size_t pending_items = msg.legs.size();
      for (auto item : msg.legs) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LegPositions & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: legs
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.legs.size() == 0) {
      out << "legs: []\n";
    } else {
      out << "legs:\n";
      for (auto item : msg.legs) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LegPositions & msg, bool use_flow_style = false)
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
  const spider_msgs::msg::LegPositions & msg,
  std::ostream & out, size_t indentation = 0)
{
  spider_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use spider_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const spider_msgs::msg::LegPositions & msg)
{
  return spider_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<spider_msgs::msg::LegPositions>()
{
  return "spider_msgs::msg::LegPositions";
}

template<>
inline const char * name<spider_msgs::msg::LegPositions>()
{
  return "spider_msgs/msg/LegPositions";
}

template<>
struct has_fixed_size<spider_msgs::msg::LegPositions>
  : std::integral_constant<bool, has_fixed_size<spider_msgs::msg::LegPosition>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<spider_msgs::msg::LegPositions>
  : std::integral_constant<bool, has_bounded_size<spider_msgs::msg::LegPosition>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<spider_msgs::msg::LegPositions>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SPIDER_MSGS__MSG__DETAIL__LEG_POSITIONS__TRAITS_HPP_
