// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from spider_msgs:msg/RobotState.idl
// generated code does not contain a copyright notice
#include "spider_msgs/msg/detail/robot_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `current_behavior`
#include "rosidl_runtime_c/string_functions.h"
// Member `current_pose`
#include "spider_msgs/msg/detail/leg_positions__functions.h"

bool
spider_msgs__msg__RobotState__init(spider_msgs__msg__RobotState * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    spider_msgs__msg__RobotState__fini(msg);
    return false;
  }
  // current_behavior
  if (!rosidl_runtime_c__String__init(&msg->current_behavior)) {
    spider_msgs__msg__RobotState__fini(msg);
    return false;
  }
  // is_moving
  // battery_level
  // current_pose
  if (!spider_msgs__msg__LegPositions__init(&msg->current_pose)) {
    spider_msgs__msg__RobotState__fini(msg);
    return false;
  }
  return true;
}

void
spider_msgs__msg__RobotState__fini(spider_msgs__msg__RobotState * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // current_behavior
  rosidl_runtime_c__String__fini(&msg->current_behavior);
  // is_moving
  // battery_level
  // current_pose
  spider_msgs__msg__LegPositions__fini(&msg->current_pose);
}

bool
spider_msgs__msg__RobotState__are_equal(const spider_msgs__msg__RobotState * lhs, const spider_msgs__msg__RobotState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // current_behavior
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->current_behavior), &(rhs->current_behavior)))
  {
    return false;
  }
  // is_moving
  if (lhs->is_moving != rhs->is_moving) {
    return false;
  }
  // battery_level
  if (lhs->battery_level != rhs->battery_level) {
    return false;
  }
  // current_pose
  if (!spider_msgs__msg__LegPositions__are_equal(
      &(lhs->current_pose), &(rhs->current_pose)))
  {
    return false;
  }
  return true;
}

bool
spider_msgs__msg__RobotState__copy(
  const spider_msgs__msg__RobotState * input,
  spider_msgs__msg__RobotState * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // current_behavior
  if (!rosidl_runtime_c__String__copy(
      &(input->current_behavior), &(output->current_behavior)))
  {
    return false;
  }
  // is_moving
  output->is_moving = input->is_moving;
  // battery_level
  output->battery_level = input->battery_level;
  // current_pose
  if (!spider_msgs__msg__LegPositions__copy(
      &(input->current_pose), &(output->current_pose)))
  {
    return false;
  }
  return true;
}

spider_msgs__msg__RobotState *
spider_msgs__msg__RobotState__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_msgs__msg__RobotState * msg = (spider_msgs__msg__RobotState *)allocator.allocate(sizeof(spider_msgs__msg__RobotState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(spider_msgs__msg__RobotState));
  bool success = spider_msgs__msg__RobotState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
spider_msgs__msg__RobotState__destroy(spider_msgs__msg__RobotState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    spider_msgs__msg__RobotState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
spider_msgs__msg__RobotState__Sequence__init(spider_msgs__msg__RobotState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_msgs__msg__RobotState * data = NULL;

  if (size) {
    data = (spider_msgs__msg__RobotState *)allocator.zero_allocate(size, sizeof(spider_msgs__msg__RobotState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = spider_msgs__msg__RobotState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        spider_msgs__msg__RobotState__fini(&data[i - 1]);
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
spider_msgs__msg__RobotState__Sequence__fini(spider_msgs__msg__RobotState__Sequence * array)
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
      spider_msgs__msg__RobotState__fini(&array->data[i]);
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

spider_msgs__msg__RobotState__Sequence *
spider_msgs__msg__RobotState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_msgs__msg__RobotState__Sequence * array = (spider_msgs__msg__RobotState__Sequence *)allocator.allocate(sizeof(spider_msgs__msg__RobotState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = spider_msgs__msg__RobotState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
spider_msgs__msg__RobotState__Sequence__destroy(spider_msgs__msg__RobotState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    spider_msgs__msg__RobotState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
spider_msgs__msg__RobotState__Sequence__are_equal(const spider_msgs__msg__RobotState__Sequence * lhs, const spider_msgs__msg__RobotState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!spider_msgs__msg__RobotState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
spider_msgs__msg__RobotState__Sequence__copy(
  const spider_msgs__msg__RobotState__Sequence * input,
  spider_msgs__msg__RobotState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(spider_msgs__msg__RobotState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    spider_msgs__msg__RobotState * data =
      (spider_msgs__msg__RobotState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!spider_msgs__msg__RobotState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          spider_msgs__msg__RobotState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!spider_msgs__msg__RobotState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
