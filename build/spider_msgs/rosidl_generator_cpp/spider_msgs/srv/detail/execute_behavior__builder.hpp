// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from spider_msgs:srv/ExecuteBehavior.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "spider_msgs/srv/execute_behavior.hpp"


#ifndef SPIDER_MSGS__SRV__DETAIL__EXECUTE_BEHAVIOR__BUILDER_HPP_
#define SPIDER_MSGS__SRV__DETAIL__EXECUTE_BEHAVIOR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "spider_msgs/srv/detail/execute_behavior__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace spider_msgs
{

namespace srv
{

namespace builder
{

class Init_ExecuteBehavior_Request_speed_multiplier
{
public:
  explicit Init_ExecuteBehavior_Request_speed_multiplier(::spider_msgs::srv::ExecuteBehavior_Request & msg)
  : msg_(msg)
  {}
  ::spider_msgs::srv::ExecuteBehavior_Request speed_multiplier(::spider_msgs::srv::ExecuteBehavior_Request::_speed_multiplier_type arg)
  {
    msg_.speed_multiplier = std::move(arg);
    return std::move(msg_);
  }

private:
  ::spider_msgs::srv::ExecuteBehavior_Request msg_;
};

class Init_ExecuteBehavior_Request_repetitions
{
public:
  explicit Init_ExecuteBehavior_Request_repetitions(::spider_msgs::srv::ExecuteBehavior_Request & msg)
  : msg_(msg)
  {}
  Init_ExecuteBehavior_Request_speed_multiplier repetitions(::spider_msgs::srv::ExecuteBehavior_Request::_repetitions_type arg)
  {
    msg_.repetitions = std::move(arg);
    return Init_ExecuteBehavior_Request_speed_multiplier(msg_);
  }

private:
  ::spider_msgs::srv::ExecuteBehavior_Request msg_;
};

class Init_ExecuteBehavior_Request_behavior_name
{
public:
  Init_ExecuteBehavior_Request_behavior_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteBehavior_Request_repetitions behavior_name(::spider_msgs::srv::ExecuteBehavior_Request::_behavior_name_type arg)
  {
    msg_.behavior_name = std::move(arg);
    return Init_ExecuteBehavior_Request_repetitions(msg_);
  }

private:
  ::spider_msgs::srv::ExecuteBehavior_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::spider_msgs::srv::ExecuteBehavior_Request>()
{
  return spider_msgs::srv::builder::Init_ExecuteBehavior_Request_behavior_name();
}

}  // namespace spider_msgs


namespace spider_msgs
{

namespace srv
{

namespace builder
{

class Init_ExecuteBehavior_Response_message
{
public:
  explicit Init_ExecuteBehavior_Response_message(::spider_msgs::srv::ExecuteBehavior_Response & msg)
  : msg_(msg)
  {}
  ::spider_msgs::srv::ExecuteBehavior_Response message(::spider_msgs::srv::ExecuteBehavior_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::spider_msgs::srv::ExecuteBehavior_Response msg_;
};

class Init_ExecuteBehavior_Response_success
{
public:
  Init_ExecuteBehavior_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteBehavior_Response_message success(::spider_msgs::srv::ExecuteBehavior_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_ExecuteBehavior_Response_message(msg_);
  }

private:
  ::spider_msgs::srv::ExecuteBehavior_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::spider_msgs::srv::ExecuteBehavior_Response>()
{
  return spider_msgs::srv::builder::Init_ExecuteBehavior_Response_success();
}

}  // namespace spider_msgs


namespace spider_msgs
{

namespace srv
{

namespace builder
{

class Init_ExecuteBehavior_Event_response
{
public:
  explicit Init_ExecuteBehavior_Event_response(::spider_msgs::srv::ExecuteBehavior_Event & msg)
  : msg_(msg)
  {}
  ::spider_msgs::srv::ExecuteBehavior_Event response(::spider_msgs::srv::ExecuteBehavior_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::spider_msgs::srv::ExecuteBehavior_Event msg_;
};

class Init_ExecuteBehavior_Event_request
{
public:
  explicit Init_ExecuteBehavior_Event_request(::spider_msgs::srv::ExecuteBehavior_Event & msg)
  : msg_(msg)
  {}
  Init_ExecuteBehavior_Event_response request(::spider_msgs::srv::ExecuteBehavior_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ExecuteBehavior_Event_response(msg_);
  }

private:
  ::spider_msgs::srv::ExecuteBehavior_Event msg_;
};

class Init_ExecuteBehavior_Event_info
{
public:
  Init_ExecuteBehavior_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteBehavior_Event_request info(::spider_msgs::srv::ExecuteBehavior_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ExecuteBehavior_Event_request(msg_);
  }

private:
  ::spider_msgs::srv::ExecuteBehavior_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::spider_msgs::srv::ExecuteBehavior_Event>()
{
  return spider_msgs::srv::builder::Init_ExecuteBehavior_Event_info();
}

}  // namespace spider_msgs

#endif  // SPIDER_MSGS__SRV__DETAIL__EXECUTE_BEHAVIOR__BUILDER_HPP_
