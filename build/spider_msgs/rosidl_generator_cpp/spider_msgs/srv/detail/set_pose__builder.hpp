// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from spider_msgs:srv/SetPose.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "spider_msgs/srv/set_pose.hpp"


#ifndef SPIDER_MSGS__SRV__DETAIL__SET_POSE__BUILDER_HPP_
#define SPIDER_MSGS__SRV__DETAIL__SET_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "spider_msgs/srv/detail/set_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace spider_msgs
{

namespace srv
{

namespace builder
{

class Init_SetPose_Request_movement_speed
{
public:
  explicit Init_SetPose_Request_movement_speed(::spider_msgs::srv::SetPose_Request & msg)
  : msg_(msg)
  {}
  ::spider_msgs::srv::SetPose_Request movement_speed(::spider_msgs::srv::SetPose_Request::_movement_speed_type arg)
  {
    msg_.movement_speed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::spider_msgs::srv::SetPose_Request msg_;
};

class Init_SetPose_Request_target_pose
{
public:
  Init_SetPose_Request_target_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetPose_Request_movement_speed target_pose(::spider_msgs::srv::SetPose_Request::_target_pose_type arg)
  {
    msg_.target_pose = std::move(arg);
    return Init_SetPose_Request_movement_speed(msg_);
  }

private:
  ::spider_msgs::srv::SetPose_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::spider_msgs::srv::SetPose_Request>()
{
  return spider_msgs::srv::builder::Init_SetPose_Request_target_pose();
}

}  // namespace spider_msgs


namespace spider_msgs
{

namespace srv
{

namespace builder
{

class Init_SetPose_Response_message
{
public:
  explicit Init_SetPose_Response_message(::spider_msgs::srv::SetPose_Response & msg)
  : msg_(msg)
  {}
  ::spider_msgs::srv::SetPose_Response message(::spider_msgs::srv::SetPose_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::spider_msgs::srv::SetPose_Response msg_;
};

class Init_SetPose_Response_success
{
public:
  Init_SetPose_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetPose_Response_message success(::spider_msgs::srv::SetPose_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_SetPose_Response_message(msg_);
  }

private:
  ::spider_msgs::srv::SetPose_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::spider_msgs::srv::SetPose_Response>()
{
  return spider_msgs::srv::builder::Init_SetPose_Response_success();
}

}  // namespace spider_msgs


namespace spider_msgs
{

namespace srv
{

namespace builder
{

class Init_SetPose_Event_response
{
public:
  explicit Init_SetPose_Event_response(::spider_msgs::srv::SetPose_Event & msg)
  : msg_(msg)
  {}
  ::spider_msgs::srv::SetPose_Event response(::spider_msgs::srv::SetPose_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::spider_msgs::srv::SetPose_Event msg_;
};

class Init_SetPose_Event_request
{
public:
  explicit Init_SetPose_Event_request(::spider_msgs::srv::SetPose_Event & msg)
  : msg_(msg)
  {}
  Init_SetPose_Event_response request(::spider_msgs::srv::SetPose_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_SetPose_Event_response(msg_);
  }

private:
  ::spider_msgs::srv::SetPose_Event msg_;
};

class Init_SetPose_Event_info
{
public:
  Init_SetPose_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetPose_Event_request info(::spider_msgs::srv::SetPose_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_SetPose_Event_request(msg_);
  }

private:
  ::spider_msgs::srv::SetPose_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::spider_msgs::srv::SetPose_Event>()
{
  return spider_msgs::srv::builder::Init_SetPose_Event_info();
}

}  // namespace spider_msgs

#endif  // SPIDER_MSGS__SRV__DETAIL__SET_POSE__BUILDER_HPP_
