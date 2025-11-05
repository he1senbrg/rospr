// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from spider_msgs:srv/SetPose.idl
// generated code does not contain a copyright notice
#include "spider_msgs/srv/detail/set_pose__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `target_pose`
#include "spider_msgs/msg/detail/leg_positions__functions.h"

bool
spider_msgs__srv__SetPose_Request__init(spider_msgs__srv__SetPose_Request * msg)
{
  if (!msg) {
    return false;
  }
  // target_pose
  if (!spider_msgs__msg__LegPositions__init(&msg->target_pose)) {
    spider_msgs__srv__SetPose_Request__fini(msg);
    return false;
  }
  // movement_speed
  return true;
}

void
spider_msgs__srv__SetPose_Request__fini(spider_msgs__srv__SetPose_Request * msg)
{
  if (!msg) {
    return;
  }
  // target_pose
  spider_msgs__msg__LegPositions__fini(&msg->target_pose);
  // movement_speed
}

bool
spider_msgs__srv__SetPose_Request__are_equal(const spider_msgs__srv__SetPose_Request * lhs, const spider_msgs__srv__SetPose_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // target_pose
  if (!spider_msgs__msg__LegPositions__are_equal(
      &(lhs->target_pose), &(rhs->target_pose)))
  {
    return false;
  }
  // movement_speed
  if (lhs->movement_speed != rhs->movement_speed) {
    return false;
  }
  return true;
}

bool
spider_msgs__srv__SetPose_Request__copy(
  const spider_msgs__srv__SetPose_Request * input,
  spider_msgs__srv__SetPose_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // target_pose
  if (!spider_msgs__msg__LegPositions__copy(
      &(input->target_pose), &(output->target_pose)))
  {
    return false;
  }
  // movement_speed
  output->movement_speed = input->movement_speed;
  return true;
}

spider_msgs__srv__SetPose_Request *
spider_msgs__srv__SetPose_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_msgs__srv__SetPose_Request * msg = (spider_msgs__srv__SetPose_Request *)allocator.allocate(sizeof(spider_msgs__srv__SetPose_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(spider_msgs__srv__SetPose_Request));
  bool success = spider_msgs__srv__SetPose_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
spider_msgs__srv__SetPose_Request__destroy(spider_msgs__srv__SetPose_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    spider_msgs__srv__SetPose_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
spider_msgs__srv__SetPose_Request__Sequence__init(spider_msgs__srv__SetPose_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_msgs__srv__SetPose_Request * data = NULL;

  if (size) {
    data = (spider_msgs__srv__SetPose_Request *)allocator.zero_allocate(size, sizeof(spider_msgs__srv__SetPose_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = spider_msgs__srv__SetPose_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        spider_msgs__srv__SetPose_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
spider_msgs__srv__SetPose_Request__Sequence__fini(spider_msgs__srv__SetPose_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      spider_msgs__srv__SetPose_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

spider_msgs__srv__SetPose_Request__Sequence *
spider_msgs__srv__SetPose_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_msgs__srv__SetPose_Request__Sequence * array = (spider_msgs__srv__SetPose_Request__Sequence *)allocator.allocate(sizeof(spider_msgs__srv__SetPose_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = spider_msgs__srv__SetPose_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
spider_msgs__srv__SetPose_Request__Sequence__destroy(spider_msgs__srv__SetPose_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    spider_msgs__srv__SetPose_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
spider_msgs__srv__SetPose_Request__Sequence__are_equal(const spider_msgs__srv__SetPose_Request__Sequence * lhs, const spider_msgs__srv__SetPose_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!spider_msgs__srv__SetPose_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
spider_msgs__srv__SetPose_Request__Sequence__copy(
  const spider_msgs__srv__SetPose_Request__Sequence * input,
  spider_msgs__srv__SetPose_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(spider_msgs__srv__SetPose_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    spider_msgs__srv__SetPose_Request * data =
      (spider_msgs__srv__SetPose_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!spider_msgs__srv__SetPose_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          spider_msgs__srv__SetPose_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!spider_msgs__srv__SetPose_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
spider_msgs__srv__SetPose_Response__init(spider_msgs__srv__SetPose_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    spider_msgs__srv__SetPose_Response__fini(msg);
    return false;
  }
  return true;
}

void
spider_msgs__srv__SetPose_Response__fini(spider_msgs__srv__SetPose_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
spider_msgs__srv__SetPose_Response__are_equal(const spider_msgs__srv__SetPose_Response * lhs, const spider_msgs__srv__SetPose_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
spider_msgs__srv__SetPose_Response__copy(
  const spider_msgs__srv__SetPose_Response * input,
  spider_msgs__srv__SetPose_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

spider_msgs__srv__SetPose_Response *
spider_msgs__srv__SetPose_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_msgs__srv__SetPose_Response * msg = (spider_msgs__srv__SetPose_Response *)allocator.allocate(sizeof(spider_msgs__srv__SetPose_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(spider_msgs__srv__SetPose_Response));
  bool success = spider_msgs__srv__SetPose_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
spider_msgs__srv__SetPose_Response__destroy(spider_msgs__srv__SetPose_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    spider_msgs__srv__SetPose_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
spider_msgs__srv__SetPose_Response__Sequence__init(spider_msgs__srv__SetPose_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_msgs__srv__SetPose_Response * data = NULL;

  if (size) {
    data = (spider_msgs__srv__SetPose_Response *)allocator.zero_allocate(size, sizeof(spider_msgs__srv__SetPose_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = spider_msgs__srv__SetPose_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        spider_msgs__srv__SetPose_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
spider_msgs__srv__SetPose_Response__Sequence__fini(spider_msgs__srv__SetPose_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      spider_msgs__srv__SetPose_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

spider_msgs__srv__SetPose_Response__Sequence *
spider_msgs__srv__SetPose_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_msgs__srv__SetPose_Response__Sequence * array = (spider_msgs__srv__SetPose_Response__Sequence *)allocator.allocate(sizeof(spider_msgs__srv__SetPose_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = spider_msgs__srv__SetPose_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
spider_msgs__srv__SetPose_Response__Sequence__destroy(spider_msgs__srv__SetPose_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    spider_msgs__srv__SetPose_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
spider_msgs__srv__SetPose_Response__Sequence__are_equal(const spider_msgs__srv__SetPose_Response__Sequence * lhs, const spider_msgs__srv__SetPose_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!spider_msgs__srv__SetPose_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
spider_msgs__srv__SetPose_Response__Sequence__copy(
  const spider_msgs__srv__SetPose_Response__Sequence * input,
  spider_msgs__srv__SetPose_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(spider_msgs__srv__SetPose_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    spider_msgs__srv__SetPose_Response * data =
      (spider_msgs__srv__SetPose_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!spider_msgs__srv__SetPose_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          spider_msgs__srv__SetPose_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!spider_msgs__srv__SetPose_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "spider_msgs/srv/detail/set_pose__functions.h"

bool
spider_msgs__srv__SetPose_Event__init(spider_msgs__srv__SetPose_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    spider_msgs__srv__SetPose_Event__fini(msg);
    return false;
  }
  // request
  if (!spider_msgs__srv__SetPose_Request__Sequence__init(&msg->request, 0)) {
    spider_msgs__srv__SetPose_Event__fini(msg);
    return false;
  }
  // response
  if (!spider_msgs__srv__SetPose_Response__Sequence__init(&msg->response, 0)) {
    spider_msgs__srv__SetPose_Event__fini(msg);
    return false;
  }
  return true;
}

void
spider_msgs__srv__SetPose_Event__fini(spider_msgs__srv__SetPose_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  spider_msgs__srv__SetPose_Request__Sequence__fini(&msg->request);
  // response
  spider_msgs__srv__SetPose_Response__Sequence__fini(&msg->response);
}

bool
spider_msgs__srv__SetPose_Event__are_equal(const spider_msgs__srv__SetPose_Event * lhs, const spider_msgs__srv__SetPose_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!spider_msgs__srv__SetPose_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!spider_msgs__srv__SetPose_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
spider_msgs__srv__SetPose_Event__copy(
  const spider_msgs__srv__SetPose_Event * input,
  spider_msgs__srv__SetPose_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!spider_msgs__srv__SetPose_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!spider_msgs__srv__SetPose_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

spider_msgs__srv__SetPose_Event *
spider_msgs__srv__SetPose_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_msgs__srv__SetPose_Event * msg = (spider_msgs__srv__SetPose_Event *)allocator.allocate(sizeof(spider_msgs__srv__SetPose_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(spider_msgs__srv__SetPose_Event));
  bool success = spider_msgs__srv__SetPose_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
spider_msgs__srv__SetPose_Event__destroy(spider_msgs__srv__SetPose_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    spider_msgs__srv__SetPose_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
spider_msgs__srv__SetPose_Event__Sequence__init(spider_msgs__srv__SetPose_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_msgs__srv__SetPose_Event * data = NULL;

  if (size) {
    data = (spider_msgs__srv__SetPose_Event *)allocator.zero_allocate(size, sizeof(spider_msgs__srv__SetPose_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = spider_msgs__srv__SetPose_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        spider_msgs__srv__SetPose_Event__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
spider_msgs__srv__SetPose_Event__Sequence__fini(spider_msgs__srv__SetPose_Event__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      spider_msgs__srv__SetPose_Event__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

spider_msgs__srv__SetPose_Event__Sequence *
spider_msgs__srv__SetPose_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_msgs__srv__SetPose_Event__Sequence * array = (spider_msgs__srv__SetPose_Event__Sequence *)allocator.allocate(sizeof(spider_msgs__srv__SetPose_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = spider_msgs__srv__SetPose_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
spider_msgs__srv__SetPose_Event__Sequence__destroy(spider_msgs__srv__SetPose_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    spider_msgs__srv__SetPose_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
spider_msgs__srv__SetPose_Event__Sequence__are_equal(const spider_msgs__srv__SetPose_Event__Sequence * lhs, const spider_msgs__srv__SetPose_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!spider_msgs__srv__SetPose_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
spider_msgs__srv__SetPose_Event__Sequence__copy(
  const spider_msgs__srv__SetPose_Event__Sequence * input,
  spider_msgs__srv__SetPose_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(spider_msgs__srv__SetPose_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    spider_msgs__srv__SetPose_Event * data =
      (spider_msgs__srv__SetPose_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!spider_msgs__srv__SetPose_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          spider_msgs__srv__SetPose_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!spider_msgs__srv__SetPose_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
