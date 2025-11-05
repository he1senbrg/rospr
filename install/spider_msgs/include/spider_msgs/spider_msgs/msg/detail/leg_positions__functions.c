// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from spider_msgs:msg/LegPositions.idl
// generated code does not contain a copyright notice
#include "spider_msgs/msg/detail/leg_positions__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `legs`
#include "spider_msgs/msg/detail/leg_position__functions.h"
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
spider_msgs__msg__LegPositions__init(spider_msgs__msg__LegPositions * msg)
{
  if (!msg) {
    return false;
  }
  // legs
  for (size_t i = 0; i < 4; ++i) {
    if (!spider_msgs__msg__LegPosition__init(&msg->legs[i])) {
      spider_msgs__msg__LegPositions__fini(msg);
      return false;
    }
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    spider_msgs__msg__LegPositions__fini(msg);
    return false;
  }
  return true;
}

void
spider_msgs__msg__LegPositions__fini(spider_msgs__msg__LegPositions * msg)
{
  if (!msg) {
    return;
  }
  // legs
  for (size_t i = 0; i < 4; ++i) {
    spider_msgs__msg__LegPosition__fini(&msg->legs[i]);
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
}

bool
spider_msgs__msg__LegPositions__are_equal(const spider_msgs__msg__LegPositions * lhs, const spider_msgs__msg__LegPositions * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // legs
  for (size_t i = 0; i < 4; ++i) {
    if (!spider_msgs__msg__LegPosition__are_equal(
        &(lhs->legs[i]), &(rhs->legs[i])))
    {
      return false;
    }
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  return true;
}

bool
spider_msgs__msg__LegPositions__copy(
  const spider_msgs__msg__LegPositions * input,
  spider_msgs__msg__LegPositions * output)
{
  if (!input || !output) {
    return false;
  }
  // legs
  for (size_t i = 0; i < 4; ++i) {
    if (!spider_msgs__msg__LegPosition__copy(
        &(input->legs[i]), &(output->legs[i])))
    {
      return false;
    }
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  return true;
}

spider_msgs__msg__LegPositions *
spider_msgs__msg__LegPositions__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_msgs__msg__LegPositions * msg = (spider_msgs__msg__LegPositions *)allocator.allocate(sizeof(spider_msgs__msg__LegPositions), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(spider_msgs__msg__LegPositions));
  bool success = spider_msgs__msg__LegPositions__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
spider_msgs__msg__LegPositions__destroy(spider_msgs__msg__LegPositions * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    spider_msgs__msg__LegPositions__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
spider_msgs__msg__LegPositions__Sequence__init(spider_msgs__msg__LegPositions__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_msgs__msg__LegPositions * data = NULL;

  if (size) {
    data = (spider_msgs__msg__LegPositions *)allocator.zero_allocate(size, sizeof(spider_msgs__msg__LegPositions), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = spider_msgs__msg__LegPositions__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        spider_msgs__msg__LegPositions__fini(&data[i - 1]);
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
spider_msgs__msg__LegPositions__Sequence__fini(spider_msgs__msg__LegPositions__Sequence * array)
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
      spider_msgs__msg__LegPositions__fini(&array->data[i]);
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

spider_msgs__msg__LegPositions__Sequence *
spider_msgs__msg__LegPositions__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_msgs__msg__LegPositions__Sequence * array = (spider_msgs__msg__LegPositions__Sequence *)allocator.allocate(sizeof(spider_msgs__msg__LegPositions__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = spider_msgs__msg__LegPositions__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
spider_msgs__msg__LegPositions__Sequence__destroy(spider_msgs__msg__LegPositions__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    spider_msgs__msg__LegPositions__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
spider_msgs__msg__LegPositions__Sequence__are_equal(const spider_msgs__msg__LegPositions__Sequence * lhs, const spider_msgs__msg__LegPositions__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!spider_msgs__msg__LegPositions__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
spider_msgs__msg__LegPositions__Sequence__copy(
  const spider_msgs__msg__LegPositions__Sequence * input,
  spider_msgs__msg__LegPositions__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(spider_msgs__msg__LegPositions);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    spider_msgs__msg__LegPositions * data =
      (spider_msgs__msg__LegPositions *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!spider_msgs__msg__LegPositions__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          spider_msgs__msg__LegPositions__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!spider_msgs__msg__LegPositions__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
