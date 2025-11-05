// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from spider_msgs:msg/RobotState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "spider_msgs/msg/robot_state.hpp"


#ifndef SPIDER_MSGS__MSG__DETAIL__ROBOT_STATE__BUILDER_HPP_
#define SPIDER_MSGS__MSG__DETAIL__ROBOT_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "spider_msgs/msg/detail/robot_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace spider_msgs
{

namespace msg
{

namespace builder
{

class Init_RobotState_current_pose
{
public:
  explicit Init_RobotState_current_pose(::spider_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  ::spider_msgs::msg::RobotState current_pose(::spider_msgs::msg::RobotState::_current_pose_type arg)
  {
    msg_.current_pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::spider_msgs::msg::RobotState msg_;
};

class Init_RobotState_battery_level
{
public:
  explicit Init_RobotState_battery_level(::spider_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_current_pose battery_level(::spider_msgs::msg::RobotState::_battery_level_type arg)
  {
    msg_.battery_level = std::move(arg);
    return Init_RobotState_current_pose(msg_);
  }

private:
  ::spider_msgs::msg::RobotState msg_;
};

class Init_RobotState_is_moving
{
public:
  explicit Init_RobotState_is_moving(::spider_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_battery_level is_moving(::spider_msgs::msg::RobotState::_is_moving_type arg)
  {
    msg_.is_moving = std::move(arg);
    return Init_RobotState_battery_level(msg_);
  }

private:
  ::spider_msgs::msg::RobotState msg_;
};

class Init_RobotState_current_behavior
{
public:
  explicit Init_RobotState_current_behavior(::spider_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_is_moving current_behavior(::spider_msgs::msg::RobotState::_current_behavior_type arg)
  {
    msg_.current_behavior = std::move(arg);
    return Init_RobotState_is_moving(msg_);
  }

private:
  ::spider_msgs::msg::RobotState msg_;
};

class Init_RobotState_header
{
public:
  Init_RobotState_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotState_current_behavior header(::spider_msgs::msg::RobotState::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_RobotState_current_behavior(msg_);
  }

private:
  ::spider_msgs::msg::RobotState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::spider_msgs::msg::RobotState>()
{
  return spider_msgs::msg::builder::Init_RobotState_header();
}

}  // namespace spider_msgs

#endif  // SPIDER_MSGS__MSG__DETAIL__ROBOT_STATE__BUILDER_HPP_
