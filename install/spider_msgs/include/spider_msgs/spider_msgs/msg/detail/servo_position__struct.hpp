// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from spider_msgs:msg/ServoPosition.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "spider_msgs/msg/servo_position.hpp"


#ifndef SPIDER_MSGS__MSG__DETAIL__SERVO_POSITION__STRUCT_HPP_
#define SPIDER_MSGS__MSG__DETAIL__SERVO_POSITION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__spider_msgs__msg__ServoPosition __attribute__((deprecated))
#else
# define DEPRECATED__spider_msgs__msg__ServoPosition __declspec(deprecated)
#endif

namespace spider_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ServoPosition_
{
  using Type = ServoPosition_<ContainerAllocator>;

  explicit ServoPosition_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->servo_id = 0;
      this->angle = 0.0f;
      this->speed = 0.0f;
    }
  }

  explicit ServoPosition_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->servo_id = 0;
      this->angle = 0.0f;
      this->speed = 0.0f;
    }
  }

  // field types and members
  using _servo_id_type =
    uint8_t;
  _servo_id_type servo_id;
  using _angle_type =
    float;
  _angle_type angle;
  using _speed_type =
    float;
  _speed_type speed;

  // setters for named parameter idiom
  Type & set__servo_id(
    const uint8_t & _arg)
  {
    this->servo_id = _arg;
    return *this;
  }
  Type & set__angle(
    const float & _arg)
  {
    this->angle = _arg;
    return *this;
  }
  Type & set__speed(
    const float & _arg)
  {
    this->speed = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    spider_msgs::msg::ServoPosition_<ContainerAllocator> *;
  using ConstRawPtr =
    const spider_msgs::msg::ServoPosition_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<spider_msgs::msg::ServoPosition_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<spider_msgs::msg::ServoPosition_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      spider_msgs::msg::ServoPosition_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<spider_msgs::msg::ServoPosition_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      spider_msgs::msg::ServoPosition_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<spider_msgs::msg::ServoPosition_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<spider_msgs::msg::ServoPosition_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<spider_msgs::msg::ServoPosition_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__spider_msgs__msg__ServoPosition
    std::shared_ptr<spider_msgs::msg::ServoPosition_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__spider_msgs__msg__ServoPosition
    std::shared_ptr<spider_msgs::msg::ServoPosition_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ServoPosition_ & other) const
  {
    if (this->servo_id != other.servo_id) {
      return false;
    }
    if (this->angle != other.angle) {
      return false;
    }
    if (this->speed != other.speed) {
      return false;
    }
    return true;
  }
  bool operator!=(const ServoPosition_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ServoPosition_

// alias to use template instance with default allocator
using ServoPosition =
  spider_msgs::msg::ServoPosition_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace spider_msgs

#endif  // SPIDER_MSGS__MSG__DETAIL__SERVO_POSITION__STRUCT_HPP_
