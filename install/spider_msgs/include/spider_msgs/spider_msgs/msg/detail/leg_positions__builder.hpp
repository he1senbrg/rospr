// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from spider_msgs:msg/LegPositions.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "spider_msgs/msg/leg_positions.hpp"


#ifndef SPIDER_MSGS__MSG__DETAIL__LEG_POSITIONS__BUILDER_HPP_
#define SPIDER_MSGS__MSG__DETAIL__LEG_POSITIONS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "spider_msgs/msg/detail/leg_positions__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace spider_msgs
{

namespace msg
{

namespace builder
{

class Init_LegPositions_header
{
public:
  explicit Init_LegPositions_header(::spider_msgs::msg::LegPositions & msg)
  : msg_(msg)
  {}
  ::spider_msgs::msg::LegPositions header(::spider_msgs::msg::LegPositions::_header_type arg)
  {
    msg_.header = std::move(arg);
    return std::move(msg_);
  }

private:
  ::spider_msgs::msg::LegPositions msg_;
};

class Init_LegPositions_legs
{
public:
  Init_LegPositions_legs()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LegPositions_header legs(::spider_msgs::msg::LegPositions::_legs_type arg)
  {
    msg_.legs = std::move(arg);
    return Init_LegPositions_header(msg_);
  }

private:
  ::spider_msgs::msg::LegPositions msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::spider_msgs::msg::LegPositions>()
{
  return spider_msgs::msg::builder::Init_LegPositions_legs();
}

}  // namespace spider_msgs

#endif  // SPIDER_MSGS__MSG__DETAIL__LEG_POSITIONS__BUILDER_HPP_
