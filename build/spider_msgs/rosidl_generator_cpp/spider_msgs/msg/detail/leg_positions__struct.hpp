// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from spider_msgs:msg/LegPositions.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "spider_msgs/msg/leg_positions.hpp"


#ifndef SPIDER_MSGS__MSG__DETAIL__LEG_POSITIONS__STRUCT_HPP_
#define SPIDER_MSGS__MSG__DETAIL__LEG_POSITIONS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'legs'
#include "spider_msgs/msg/detail/leg_position__struct.hpp"
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__spider_msgs__msg__LegPositions __attribute__((deprecated))
#else
# define DEPRECATED__spider_msgs__msg__LegPositions __declspec(deprecated)
#endif

namespace spider_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LegPositions_
{
  using Type = LegPositions_<ContainerAllocator>;

  explicit LegPositions_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->legs.fill(spider_msgs::msg::LegPosition_<ContainerAllocator>{_init});
    }
  }

  explicit LegPositions_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : legs(_alloc),
    header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->legs.fill(spider_msgs::msg::LegPosition_<ContainerAllocator>{_alloc, _init});
    }
  }

  // field types and members
  using _legs_type =
    std::array<spider_msgs::msg::LegPosition_<ContainerAllocator>, 4>;
  _legs_type legs;
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;

  // setters for named parameter idiom
  Type & set__legs(
    const std::array<spider_msgs::msg::LegPosition_<ContainerAllocator>, 4> & _arg)
  {
    this->legs = _arg;
    return *this;
  }
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    spider_msgs::msg::LegPositions_<ContainerAllocator> *;
  using ConstRawPtr =
    const spider_msgs::msg::LegPositions_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<spider_msgs::msg::LegPositions_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<spider_msgs::msg::LegPositions_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      spider_msgs::msg::LegPositions_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<spider_msgs::msg::LegPositions_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      spider_msgs::msg::LegPositions_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<spider_msgs::msg::LegPositions_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<spider_msgs::msg::LegPositions_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<spider_msgs::msg::LegPositions_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__spider_msgs__msg__LegPositions
    std::shared_ptr<spider_msgs::msg::LegPositions_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__spider_msgs__msg__LegPositions
    std::shared_ptr<spider_msgs::msg::LegPositions_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LegPositions_ & other) const
  {
    if (this->legs != other.legs) {
      return false;
    }
    if (this->header != other.header) {
      return false;
    }
    return true;
  }
  bool operator!=(const LegPositions_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LegPositions_

// alias to use template instance with default allocator
using LegPositions =
  spider_msgs::msg::LegPositions_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace spider_msgs

#endif  // SPIDER_MSGS__MSG__DETAIL__LEG_POSITIONS__STRUCT_HPP_
