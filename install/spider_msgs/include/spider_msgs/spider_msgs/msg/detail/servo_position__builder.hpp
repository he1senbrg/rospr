// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from spider_msgs:msg/ServoPosition.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "spider_msgs/msg/servo_position.hpp"


#ifndef SPIDER_MSGS__MSG__DETAIL__SERVO_POSITION__BUILDER_HPP_
#define SPIDER_MSGS__MSG__DETAIL__SERVO_POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "spider_msgs/msg/detail/servo_position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace spider_msgs
{

namespace msg
{

namespace builder
{

class Init_ServoPosition_speed
{
public:
  explicit Init_ServoPosition_speed(::spider_msgs::msg::ServoPosition & msg)
  : msg_(msg)
  {}
  ::spider_msgs::msg::ServoPosition speed(::spider_msgs::msg::ServoPosition::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::spider_msgs::msg::ServoPosition msg_;
};

class Init_ServoPosition_angle
{
public:
  explicit Init_ServoPosition_angle(::spider_msgs::msg::ServoPosition & msg)
  : msg_(msg)
  {}
  Init_ServoPosition_speed angle(::spider_msgs::msg::ServoPosition::_angle_type arg)
  {
    msg_.angle = std::move(arg);
    return Init_ServoPosition_speed(msg_);
  }

private:
  ::spider_msgs::msg::ServoPosition msg_;
};

class Init_ServoPosition_servo_id
{
public:
  Init_ServoPosition_servo_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ServoPosition_angle servo_id(::spider_msgs::msg::ServoPosition::_servo_id_type arg)
  {
    msg_.servo_id = std::move(arg);
    return Init_ServoPosition_angle(msg_);
  }

private:
  ::spider_msgs::msg::ServoPosition msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::spider_msgs::msg::ServoPosition>()
{
  return spider_msgs::msg::builder::Init_ServoPosition_servo_id();
}

}  // namespace spider_msgs

#endif  // SPIDER_MSGS__MSG__DETAIL__SERVO_POSITION__BUILDER_HPP_
