// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from spider_msgs:msg/LegPosition.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "spider_msgs/msg/leg_position.hpp"


#ifndef SPIDER_MSGS__MSG__DETAIL__LEG_POSITION__STRUCT_HPP_
#define SPIDER_MSGS__MSG__DETAIL__LEG_POSITION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__spider_msgs__msg__LegPosition __attribute__((deprecated))
#else
# define DEPRECATED__spider_msgs__msg__LegPosition __declspec(deprecated)
#endif

namespace spider_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LegPosition_
{
  using Type = LegPosition_<ContainerAllocator>;

  explicit LegPosition_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : position(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->movement_speed = 0.0f;
    }
  }

  explicit LegPosition_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : position(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->movement_speed = 0.0f;
    }
  }

  // field types and members
  using _position_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _position_type position;
  using _movement_speed_type =
    float;
  _movement_speed_type movement_speed;

  // setters for named parameter idiom
  Type & set__position(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->position = _arg;
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
    spider_msgs::msg::LegPosition_<ContainerAllocator> *;
  using ConstRawPtr =
    const spider_msgs::msg::LegPosition_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<spider_msgs::msg::LegPosition_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<spider_msgs::msg::LegPosition_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      spider_msgs::msg::LegPosition_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<spider_msgs::msg::LegPosition_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      spider_msgs::msg::LegPosition_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<spider_msgs::msg::LegPosition_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<spider_msgs::msg::LegPosition_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<spider_msgs::msg::LegPosition_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__spider_msgs__msg__LegPosition
    std::shared_ptr<spider_msgs::msg::LegPosition_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__spider_msgs__msg__LegPosition
    std::shared_ptr<spider_msgs::msg::LegPosition_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LegPosition_ & other) const
  {
    if (this->position != other.position) {
      return false;
    }
    if (this->movement_speed != other.movement_speed) {
      return false;
    }
    return true;
  }
  bool operator!=(const LegPosition_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LegPosition_

// alias to use template instance with default allocator
using LegPosition =
  spider_msgs::msg::LegPosition_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace spider_msgs

#endif  // SPIDER_MSGS__MSG__DETAIL__LEG_POSITION__STRUCT_HPP_
