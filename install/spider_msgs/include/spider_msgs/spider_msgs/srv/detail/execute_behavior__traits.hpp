// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from spider_msgs:srv/ExecuteBehavior.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "spider_msgs/srv/execute_behavior.hpp"


#ifndef SPIDER_MSGS__SRV__DETAIL__EXECUTE_BEHAVIOR__TRAITS_HPP_
#define SPIDER_MSGS__SRV__DETAIL__EXECUTE_BEHAVIOR__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "spider_msgs/srv/detail/execute_behavior__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace spider_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const ExecuteBehavior_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: behavior_name
  {
    out << "behavior_name: ";
    rosidl_generator_traits::value_to_yaml(msg.behavior_name, out);
    out << ", ";
  }

  // member: repetitions
  {
    out << "repetitions: ";
    rosidl_generator_traits::value_to_yaml(msg.repetitions, out);
    out << ", ";
  }

  // member: speed_multiplier
  {
    out << "speed_multiplier: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_multiplier, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ExecuteBehavior_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: behavior_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "behavior_name: ";
    rosidl_generator_traits::value_to_yaml(msg.behavior_name, out);
    out << "\n";
  }

  // member: repetitions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "repetitions: ";
    rosidl_generator_traits::value_to_yaml(msg.repetitions, out);
    out << "\n";
  }

  // member: speed_multiplier
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed_multiplier: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_multiplier, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ExecuteBehavior_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace spider_msgs

namespace rosidl_generator_traits
{

[[deprecated("use spider_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const spider_msgs::srv::ExecuteBehavior_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  spider_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use spider_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const spider_msgs::srv::ExecuteBehavior_Request & msg)
{
  return spider_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<spider_msgs::srv::ExecuteBehavior_Request>()
{
  return "spider_msgs::srv::ExecuteBehavior_Request";
}

template<>
inline const char * name<spider_msgs::srv::ExecuteBehavior_Request>()
{
  return "spider_msgs/srv/ExecuteBehavior_Request";
}

template<>
struct has_fixed_size<spider_msgs::srv::ExecuteBehavior_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<spider_msgs::srv::ExecuteBehavior_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<spider_msgs::srv::ExecuteBehavior_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace spider_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const ExecuteBehavior_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ExecuteBehavior_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ExecuteBehavior_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace spider_msgs

namespace rosidl_generator_traits
{

[[deprecated("use spider_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const spider_msgs::srv::ExecuteBehavior_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  spider_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use spider_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const spider_msgs::srv::ExecuteBehavior_Response & msg)
{
  return spider_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<spider_msgs::srv::ExecuteBehavior_Response>()
{
  return "spider_msgs::srv::ExecuteBehavior_Response";
}

template<>
inline const char * name<spider_msgs::srv::ExecuteBehavior_Response>()
{
  return "spider_msgs/srv/ExecuteBehavior_Response";
}

template<>
struct has_fixed_size<spider_msgs::srv::ExecuteBehavior_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<spider_msgs::srv::ExecuteBehavior_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<spider_msgs::srv::ExecuteBehavior_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace spider_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const ExecuteBehavior_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ExecuteBehavior_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ExecuteBehavior_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace spider_msgs

namespace rosidl_generator_traits
{

[[deprecated("use spider_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const spider_msgs::srv::ExecuteBehavior_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  spider_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use spider_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const spider_msgs::srv::ExecuteBehavior_Event & msg)
{
  return spider_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<spider_msgs::srv::ExecuteBehavior_Event>()
{
  return "spider_msgs::srv::ExecuteBehavior_Event";
}

template<>
inline const char * name<spider_msgs::srv::ExecuteBehavior_Event>()
{
  return "spider_msgs/srv/ExecuteBehavior_Event";
}

template<>
struct has_fixed_size<spider_msgs::srv::ExecuteBehavior_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<spider_msgs::srv::ExecuteBehavior_Event>
  : std::integral_constant<bool, has_bounded_size<service_msgs::msg::ServiceEventInfo>::value && has_bounded_size<spider_msgs::srv::ExecuteBehavior_Request>::value && has_bounded_size<spider_msgs::srv::ExecuteBehavior_Response>::value> {};

template<>
struct is_message<spider_msgs::srv::ExecuteBehavior_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<spider_msgs::srv::ExecuteBehavior>()
{
  return "spider_msgs::srv::ExecuteBehavior";
}

template<>
inline const char * name<spider_msgs::srv::ExecuteBehavior>()
{
  return "spider_msgs/srv/ExecuteBehavior";
}

template<>
struct has_fixed_size<spider_msgs::srv::ExecuteBehavior>
  : std::integral_constant<
    bool,
    has_fixed_size<spider_msgs::srv::ExecuteBehavior_Request>::value &&
    has_fixed_size<spider_msgs::srv::ExecuteBehavior_Response>::value
  >
{
};

template<>
struct has_bounded_size<spider_msgs::srv::ExecuteBehavior>
  : std::integral_constant<
    bool,
    has_bounded_size<spider_msgs::srv::ExecuteBehavior_Request>::value &&
    has_bounded_size<spider_msgs::srv::ExecuteBehavior_Response>::value
  >
{
};

template<>
struct is_service<spider_msgs::srv::ExecuteBehavior>
  : std::true_type
{
};

template<>
struct is_service_request<spider_msgs::srv::ExecuteBehavior_Request>
  : std::true_type
{
};

template<>
struct is_service_response<spider_msgs::srv::ExecuteBehavior_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SPIDER_MSGS__SRV__DETAIL__EXECUTE_BEHAVIOR__TRAITS_HPP_
