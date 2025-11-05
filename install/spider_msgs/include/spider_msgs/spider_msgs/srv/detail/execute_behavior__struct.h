// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from spider_msgs:srv/ExecuteBehavior.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "spider_msgs/srv/execute_behavior.h"


#ifndef SPIDER_MSGS__SRV__DETAIL__EXECUTE_BEHAVIOR__STRUCT_H_
#define SPIDER_MSGS__SRV__DETAIL__EXECUTE_BEHAVIOR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'behavior_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ExecuteBehavior in the package spider_msgs.
typedef struct spider_msgs__srv__ExecuteBehavior_Request
{
  /// Name of behavior to execute
  rosidl_runtime_c__String behavior_name;
  /// Number of times to repeat (-1 = infinite)
  int32_t repetitions;
  /// Speed adjustment (1.0 = normal)
  float speed_multiplier;
} spider_msgs__srv__ExecuteBehavior_Request;

// Struct for a sequence of spider_msgs__srv__ExecuteBehavior_Request.
typedef struct spider_msgs__srv__ExecuteBehavior_Request__Sequence
{
  spider_msgs__srv__ExecuteBehavior_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} spider_msgs__srv__ExecuteBehavior_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ExecuteBehavior in the package spider_msgs.
typedef struct spider_msgs__srv__ExecuteBehavior_Response
{
  /// True if behavior started successfully
  bool success;
  /// Status or error message
  rosidl_runtime_c__String message;
} spider_msgs__srv__ExecuteBehavior_Response;

// Struct for a sequence of spider_msgs__srv__ExecuteBehavior_Response.
typedef struct spider_msgs__srv__ExecuteBehavior_Response__Sequence
{
  spider_msgs__srv__ExecuteBehavior_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} spider_msgs__srv__ExecuteBehavior_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  spider_msgs__srv__ExecuteBehavior_Event__request__MAX_SIZE = 1
};
// response
enum
{
  spider_msgs__srv__ExecuteBehavior_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/ExecuteBehavior in the package spider_msgs.
typedef struct spider_msgs__srv__ExecuteBehavior_Event
{
  service_msgs__msg__ServiceEventInfo info;
  spider_msgs__srv__ExecuteBehavior_Request__Sequence request;
  spider_msgs__srv__ExecuteBehavior_Response__Sequence response;
} spider_msgs__srv__ExecuteBehavior_Event;

// Struct for a sequence of spider_msgs__srv__ExecuteBehavior_Event.
typedef struct spider_msgs__srv__ExecuteBehavior_Event__Sequence
{
  spider_msgs__srv__ExecuteBehavior_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} spider_msgs__srv__ExecuteBehavior_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SPIDER_MSGS__SRV__DETAIL__EXECUTE_BEHAVIOR__STRUCT_H_
