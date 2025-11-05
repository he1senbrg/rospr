// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from spider_msgs:msg/ServoArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "spider_msgs/msg/servo_array.hpp"


#ifndef SPIDER_MSGS__MSG__DETAIL__SERVO_ARRAY__BUILDER_HPP_
#define SPIDER_MSGS__MSG__DETAIL__SERVO_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "spider_msgs/msg/detail/servo_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace spider_msgs
{

namespace msg
{

namespace builder
{

class Init_ServoArray_servos
{
public:
  Init_ServoArray_servos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::spider_msgs::msg::ServoArray servos(::spider_msgs::msg::ServoArray::_servos_type arg)
  {
    msg_.servos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::spider_msgs::msg::ServoArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::spider_msgs::msg::ServoArray>()
{
  return spider_msgs::msg::builder::Init_ServoArray_servos();
}

}  // namespace spider_msgs

#endif  // SPIDER_MSGS__MSG__DETAIL__SERVO_ARRAY__BUILDER_HPP_
