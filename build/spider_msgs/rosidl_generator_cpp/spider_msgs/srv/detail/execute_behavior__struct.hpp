// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from spider_msgs:srv/ExecuteBehavior.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "spider_msgs/srv/execute_behavior.hpp"


#ifndef SPIDER_MSGS__SRV__DETAIL__EXECUTE_BEHAVIOR__STRUCT_HPP_
#define SPIDER_MSGS__SRV__DETAIL__EXECUTE_BEHAVIOR__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__spider_msgs__srv__ExecuteBehavior_Request __attribute__((deprecated))
#else
# define DEPRECATED__spider_msgs__srv__ExecuteBehavior_Request __declspec(deprecated)
#endif

namespace spider_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ExecuteBehavior_Request_
{
  using Type = ExecuteBehavior_Request_<ContainerAllocator>;

  explicit ExecuteBehavior_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->behavior_name = "";
      this->repetitions = 0l;
      this->speed_multiplier = 0.0f;
    }
  }

  explicit ExecuteBehavior_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : behavior_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->behavior_name = "";
      this->repetitions = 0l;
      this->speed_multiplier = 0.0f;
    }
  }

  // field types and members
  using _behavior_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _behavior_name_type behavior_name;
  using _repetitions_type =
    int32_t;
  _repetitions_type repetitions;
  using _speed_multiplier_type =
    float;
  _speed_multiplier_type speed_multiplier;

  // setters for named parameter idiom
  Type & set__behavior_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->behavior_name = _arg;
    return *this;
  }
  Type & set__repetitions(
    const int32_t & _arg)
  {
    this->repetitions = _arg;
    return *this;
  }
  Type & set__speed_multiplier(
    const float & _arg)
  {
    this->speed_multiplier = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    spider_msgs::srv::ExecuteBehavior_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const spider_msgs::srv::ExecuteBehavior_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<spider_msgs::srv::ExecuteBehavior_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<spider_msgs::srv::ExecuteBehavior_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      spider_msgs::srv::ExecuteBehavior_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<spider_msgs::srv::ExecuteBehavior_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      spider_msgs::srv::ExecuteBehavior_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<spider_msgs::srv::ExecuteBehavior_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<spider_msgs::srv::ExecuteBehavior_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<spider_msgs::srv::ExecuteBehavior_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__spider_msgs__srv__ExecuteBehavior_Request
    std::shared_ptr<spider_msgs::srv::ExecuteBehavior_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__spider_msgs__srv__ExecuteBehavior_Request
    std::shared_ptr<spider_msgs::srv::ExecuteBehavior_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ExecuteBehavior_Request_ & other) const
  {
    if (this->behavior_name != other.behavior_name) {
      return false;
    }
    if (this->repetitions != other.repetitions) {
      return false;
    }
    if (this->speed_multiplier != other.speed_multiplier) {
      return false;
    }
    return true;
  }
  bool operator!=(const ExecuteBehavior_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ExecuteBehavior_Request_

// alias to use template instance with default allocator
using ExecuteBehavior_Request =
  spider_msgs::srv::ExecuteBehavior_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace spider_msgs


#ifndef _WIN32
# define DEPRECATED__spider_msgs__srv__ExecuteBehavior_Response __attribute__((deprecated))
#else
# define DEPRECATED__spider_msgs__srv__ExecuteBehavior_Response __declspec(deprecated)
#endif

namespace spider_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ExecuteBehavior_Response_
{
  using Type = ExecuteBehavior_Response_<ContainerAllocator>;

  explicit ExecuteBehavior_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit ExecuteBehavior_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    spider_msgs::srv::ExecuteBehavior_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const spider_msgs::srv::ExecuteBehavior_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<spider_msgs::srv::ExecuteBehavior_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<spider_msgs::srv::ExecuteBehavior_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      spider_msgs::srv::ExecuteBehavior_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<spider_msgs::srv::ExecuteBehavior_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      spider_msgs::srv::ExecuteBehavior_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<spider_msgs::srv::ExecuteBehavior_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<spider_msgs::srv::ExecuteBehavior_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<spider_msgs::srv::ExecuteBehavior_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__spider_msgs__srv__ExecuteBehavior_Response
    std::shared_ptr<spider_msgs::srv::ExecuteBehavior_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__spider_msgs__srv__ExecuteBehavior_Response
    std::shared_ptr<spider_msgs::srv::ExecuteBehavior_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ExecuteBehavior_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const ExecuteBehavior_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ExecuteBehavior_Response_

// alias to use template instance with default allocator
using ExecuteBehavior_Response =
  spider_msgs::srv::ExecuteBehavior_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace spider_msgs


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__spider_msgs__srv__ExecuteBehavior_Event __attribute__((deprecated))
#else
# define DEPRECATED__spider_msgs__srv__ExecuteBehavior_Event __declspec(deprecated)
#endif

namespace spider_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ExecuteBehavior_Event_
{
  using Type = ExecuteBehavior_Event_<ContainerAllocator>;

  explicit ExecuteBehavior_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit ExecuteBehavior_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<spider_msgs::srv::ExecuteBehavior_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<spider_msgs::srv::ExecuteBehavior_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<spider_msgs::srv::ExecuteBehavior_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<spider_msgs::srv::ExecuteBehavior_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<spider_msgs::srv::ExecuteBehavior_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<spider_msgs::srv::ExecuteBehavior_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<spider_msgs::srv::ExecuteBehavior_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<spider_msgs::srv::ExecuteBehavior_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    spider_msgs::srv::ExecuteBehavior_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const spider_msgs::srv::ExecuteBehavior_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<spider_msgs::srv::ExecuteBehavior_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<spider_msgs::srv::ExecuteBehavior_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      spider_msgs::srv::ExecuteBehavior_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<spider_msgs::srv::ExecuteBehavior_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      spider_msgs::srv::ExecuteBehavior_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<spider_msgs::srv::ExecuteBehavior_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<spider_msgs::srv::ExecuteBehavior_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<spider_msgs::srv::ExecuteBehavior_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__spider_msgs__srv__ExecuteBehavior_Event
    std::shared_ptr<spider_msgs::srv::ExecuteBehavior_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__spider_msgs__srv__ExecuteBehavior_Event
    std::shared_ptr<spider_msgs::srv::ExecuteBehavior_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ExecuteBehavior_Event_ & other) const
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
  bool operator!=(const ExecuteBehavior_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ExecuteBehavior_Event_

// alias to use template instance with default allocator
using ExecuteBehavior_Event =
  spider_msgs::srv::ExecuteBehavior_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace spider_msgs

namespace spider_msgs
{

namespace srv
{

struct ExecuteBehavior
{
  using Request = spider_msgs::srv::ExecuteBehavior_Request;
  using Response = spider_msgs::srv::ExecuteBehavior_Response;
  using Event = spider_msgs::srv::ExecuteBehavior_Event;
};

}  // namespace srv

}  // namespace spider_msgs

#endif  // SPIDER_MSGS__SRV__DETAIL__EXECUTE_BEHAVIOR__STRUCT_HPP_
