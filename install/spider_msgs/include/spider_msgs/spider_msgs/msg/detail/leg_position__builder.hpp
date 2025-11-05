// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from spider_msgs:msg/LegPosition.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "spider_msgs/msg/leg_position.hpp"


#ifndef SPIDER_MSGS__MSG__DETAIL__LEG_POSITION__BUILDER_HPP_
#define SPIDER_MSGS__MSG__DETAIL__LEG_POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "spider_msgs/msg/detail/leg_position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace spider_msgs
{

namespace msg
{

namespace builder
{

class Init_LegPosition_movement_speed
{
public:
  explicit Init_LegPosition_movement_speed(::spider_msgs::msg::LegPosition & msg)
  : msg_(msg)
  {}
  ::spider_msgs::msg::LegPosition movement_speed(::spider_msgs::msg::LegPosition::_movement_speed_type arg)
  {
    msg_.movement_speed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::spider_msgs::msg::LegPosition msg_;
};

class Init_LegPosition_position
{
public:
  Init_LegPosition_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LegPosition_movement_speed position(::spider_msgs::msg::LegPosition::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_LegPosition_movement_speed(msg_);
  }

private:
  ::spider_msgs::msg::LegPosition msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::spider_msgs::msg::LegPosition>()
{
  return spider_msgs::msg::builder::Init_LegPosition_position();
}

}  // namespace spider_msgs

#endif  // SPIDER_MSGS__MSG__DETAIL__LEG_POSITION__BUILDER_HPP_
