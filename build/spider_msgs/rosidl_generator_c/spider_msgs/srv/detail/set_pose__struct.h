// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from spider_msgs:srv/SetPose.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "spider_msgs/srv/set_pose.h"


#ifndef SPIDER_MSGS__SRV__DETAIL__SET_POSE__STRUCT_H_
#define SPIDER_MSGS__SRV__DETAIL__SET_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'target_pose'
#include "spider_msgs/msg/detail/leg_positions__struct.h"

/// Struct defined in srv/SetPose in the package spider_msgs.
typedef struct spider_msgs__srv__SetPose_Request
{
  /// Desired leg positions
  spider_msgs__msg__LegPositions target_pose;
  /// Speed to reach target
  float movement_speed;
} spider_msgs__srv__SetPose_Request;

// Struct for a sequence of spider_msgs__srv__SetPose_Request.
typedef struct spider_msgs__srv__SetPose_Request__Sequence
{
  spider_msgs__srv__SetPose_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} spider_msgs__srv__SetPose_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SetPose in the package spider_msgs.
typedef struct spider_msgs__srv__SetPose_Response
{
  /// True if pose was set
  bool success;
  /// Status message
  rosidl_runtime_c__String message;
} spider_msgs__srv__SetPose_Response;

// Struct for a sequence of spider_msgs__srv__SetPose_Response.
typedef struct spider_msgs__srv__SetPose_Response__Sequence
{
  spider_msgs__srv__SetPose_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} spider_msgs__srv__SetPose_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  spider_msgs__srv__SetPose_Event__request__MAX_SIZE = 1
};
// response
enum
{
  spider_msgs__srv__SetPose_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/SetPose in the package spider_msgs.
typedef struct spider_msgs__srv__SetPose_Event
{
  service_msgs__msg__ServiceEventInfo info;
  spider_msgs__srv__SetPose_Request__Sequence request;
  spider_msgs__srv__SetPose_Response__Sequence response;
} spider_msgs__srv__SetPose_Event;

// Struct for a sequence of spider_msgs__srv__SetPose_Event.
typedef struct spider_msgs__srv__SetPose_Event__Sequence
{
  spider_msgs__srv__SetPose_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} spider_msgs__srv__SetPose_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SPIDER_MSGS__SRV__DETAIL__SET_POSE__STRUCT_H_
