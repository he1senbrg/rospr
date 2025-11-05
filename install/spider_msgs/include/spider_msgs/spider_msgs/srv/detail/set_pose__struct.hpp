// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from spider_msgs:srv/SetPose.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "spider_msgs/srv/set_pose.hpp"


#ifndef SPIDER_MSGS__SRV__DETAIL__SET_POSE__STRUCT_HPP_
#define SPIDER_MSGS__SRV__DETAIL__SET_POSE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'target_pose'
#include "spider_msgs/msg/detail/leg_positions__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__spider_msgs__srv__SetPose_Request __attribute__((deprecated))
#else
# define DEPRECATED__spider_msgs__srv__SetPose_Request __declspec(deprecated)
#endif

namespace spider_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetPose_Request_
{
  using Type = SetPose_Request_<ContainerAllocator>;

  explicit SetPose_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : target_pose(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->movement_speed = 0.0f;
    }
  }

  explicit SetPose_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : target_pose(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->movement_speed = 0.0f;
    }
  }

  // field types and members
  using _target_pose_type =
    spider_msgs::msg::LegPositions_<ContainerAllocator>;
  _target_pose_type target_pose;
  using _movement_speed_type =
    float;
  _movement_speed_type movement_speed;

  // setters for named parameter idiom
  Type & set__target_pose(
    const spider_msgs::msg::LegPositions_<ContainerAllocator> & _arg)
  {
    this->target_pose = _arg;
    return *this;
  }
  Type & set__movement_speed(
    const float & _arg)
  {
    this->movement_speed = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    spider_msgs::srv::SetPose_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const spider_msgs::srv::SetPose_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<spider_msgs::srv::SetPose_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<spider_msgs::srv::SetPose_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      spider_msgs::srv::SetPose_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<spider_msgs::srv::SetPose_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      spider_msgs::srv::SetPose_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<spider_msgs::srv::SetPose_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<spider_msgs::srv::SetPose_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<spider_msgs::srv::SetPose_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__spider_msgs__srv__SetPose_Request
    std::shared_ptr<spider_msgs::srv::SetPose_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__spider_msgs__srv__SetPose_Request
    std::shared_ptr<spider_msgs::srv::SetPose_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetPose_Request_ & other) const
  {
    if (this->target_pose != other.target_pose) {
      return false;
    }
    if (this->movement_speed != other.movement_speed) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetPose_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetPose_Request_

// alias to use template instance with default allocator
using SetPose_Request =
  spider_msgs::srv::SetPose_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace spider_msgs


#ifndef _WIN32
# define DEPRECATED__spider_msgs__srv__SetPose_Response __attribute__((deprecated))
#else
# define DEPRECATED__spider_msgs__srv__SetPose_Response __declspec(deprecated)
#endif

namespace spider_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetPose_Response_
{
  using Type = SetPose_Response_<ContainerAllocator>;

  explicit SetPose_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit SetPose_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    spider_msgs::srv::SetPose_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const spider_msgs::srv::SetPose_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<spider_msgs::srv::SetPose_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<spider_msgs::srv::SetPose_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      spider_msgs::srv::SetPose_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<spider_msgs::srv::SetPose_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      spider_msgs::srv::SetPose_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<spider_msgs::srv::SetPose_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<spider_msgs::srv::SetPose_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<spider_msgs::srv::SetPose_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__spider_msgs__srv__SetPose_Response
    std::shared_ptr<spider_msgs::srv::SetPose_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__spider_msgs__srv__SetPose_Response
    std::shared_ptr<spider_msgs::srv::SetPose_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetPose_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetPose_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetPose_Response_

// alias to use template instance with default allocator
using SetPose_Response =
  spider_msgs::srv::SetPose_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace spider_msgs


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__spider_msgs__srv__SetPose_Event __attribute__((deprecated))
#else
# define DEPRECATED__spider_msgs__srv__SetPose_Event __declspec(deprecated)
#endif

namespace spider_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetPose_Event_
{
  using Type = SetPose_Event_<ContainerAllocator>;

  explicit SetPose_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit SetPose_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<spider_msgs::srv::SetPose_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<spider_msgs::srv::SetPose_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<spider_msgs::srv::SetPose_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<spider_msgs::srv::SetPose_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<spider_msgs::srv::SetPose_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<spider_msgs::srv::SetPose_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<spider_msgs::srv::SetPose_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<spider_msgs::srv::SetPose_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    spider_msgs::srv::SetPose_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const spider_msgs::srv::SetPose_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<spider_msgs::srv::SetPose_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<spider_msgs::srv::SetPose_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      spider_msgs::srv::SetPose_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<spider_msgs::srv::SetPose_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      spider_msgs::srv::SetPose_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<spider_msgs::srv::SetPose_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<spider_msgs::srv::SetPose_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<spider_msgs::srv::SetPose_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__spider_msgs__srv__SetPose_Event
    std::shared_ptr<spider_msgs::srv::SetPose_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__spider_msgs__srv__SetPose_Event
    std::shared_ptr<spider_msgs::srv::SetPose_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetPose_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetPose_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetPose_Event_

// alias to use template instance with default allocator
using SetPose_Event =
  spider_msgs::srv::SetPose_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace spider_msgs

namespace spider_msgs
{

namespace srv
{

struct SetPose
{
  using Request = spider_msgs::srv::SetPose_Request;
  using Response = spider_msgs::srv::SetPose_Response;
  using Event = spider_msgs::srv::SetPose_Event;
};

}  // namespace srv

}  // namespace spider_msgs

#endif  // SPIDER_MSGS__SRV__DETAIL__SET_POSE__STRUCT_HPP_
