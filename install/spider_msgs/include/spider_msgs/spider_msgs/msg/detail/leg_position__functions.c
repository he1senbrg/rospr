// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from spider_msgs:msg/LegPosition.idl
// generated code does not contain a copyright notice
#include "spider_msgs/msg/detail/leg_position__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `position`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
spider_msgs__msg__LegPosition__init(spider_msgs__msg__LegPosition * msg)
{
  if (!msg) {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__init(&msg->position)) {
    spider_msgs__msg__LegPosition__fini(msg);
    return false;
  }
  // movement_speed
  return true;
}

void
spider_msgs__msg__LegPosition__fini(spider_msgs__msg__LegPosition * msg)
{
  if (!msg) {
    return;
  }
  // position
  geometry_msgs__msg__Point__fini(&msg->position);
  // movement_speed
}

bool
spider_msgs__msg__LegPosition__are_equal(const spider_msgs__msg__LegPosition * lhs, const spider_msgs__msg__LegPosition * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->position), &(rhs->position)))
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
spider_msgs__msg__LegPosition__copy(
  const spider_msgs__msg__LegPosition * input,
  spider_msgs__msg__LegPosition * output)
{
  if (!input || !output) {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__copy(
      &(input->position), &(output->position)))
  {
    return false;
  }
  // movement_speed
  output->movement_speed = input->movement_speed;
  return true;
}

spider_msgs__msg__LegPosition *
spider_msgs__msg__LegPosition__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_msgs__msg__LegPosition * msg = (spider_msgs__msg__LegPosition *)allocator.allocate(sizeof(spider_msgs__msg__LegPosition), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(spider_msgs__msg__LegPosition));
  bool success = spider_msgs__msg__LegPosition__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
spider_msgs__msg__LegPosition__destroy(spider_msgs__msg__LegPosition * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    spider_msgs__msg__LegPosition__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
spider_msgs__msg__LegPosition__Sequence__init(spider_msgs__msg__LegPosition__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_msgs__msg__LegPosition * data = NULL;

  if (size) {
    data = (spider_msgs__msg__LegPosition *)allocator.zero_allocate(size, sizeof(spider_msgs__msg__LegPosition), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = spider_msgs__msg__LegPosition__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        spider_msgs__msg__LegPosition__fini(&data[i - 1]);
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
spider_msgs__msg__LegPosition__Sequence__fini(spider_msgs__msg__LegPosition__Sequence * array)
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
      spider_msgs__msg__LegPosition__fini(&array->data[i]);
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

spider_msgs__msg__LegPosition__Sequence *
spider_msgs__msg__LegPosition__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_msgs__msg__LegPosition__Sequence * array = (spider_msgs__msg__LegPosition__Sequence *)allocator.allocate(sizeof(spider_msgs__msg__LegPosition__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = spider_msgs__msg__LegPosition__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
spider_msgs__msg__LegPosition__Sequence__destroy(spider_msgs__msg__LegPosition__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    spider_msgs__msg__LegPosition__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
spider_msgs__msg__LegPosition__Sequence__are_equal(const spider_msgs__msg__LegPosition__Sequence * lhs, const spider_msgs__msg__LegPosition__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!spider_msgs__msg__LegPosition__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
spider_msgs__msg__LegPosition__Sequence__copy(
  const spider_msgs__msg__LegPosition__Sequence * input,
  spider_msgs__msg__LegPosition__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(spider_msgs__msg__LegPosition);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    spider_msgs__msg__LegPosition * data =
      (spider_msgs__msg__LegPosition *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!spider_msgs__msg__LegPosition__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          spider_msgs__msg__LegPosition__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!spider_msgs__msg__LegPosition__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
