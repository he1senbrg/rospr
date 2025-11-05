// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from spider_msgs:msg/ServoPosition.idl
// generated code does not contain a copyright notice
#include "spider_msgs/msg/detail/servo_position__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
spider_msgs__msg__ServoPosition__init(spider_msgs__msg__ServoPosition * msg)
{
  if (!msg) {
    return false;
  }
  // servo_id
  // angle
  // speed
  return true;
}

void
spider_msgs__msg__ServoPosition__fini(spider_msgs__msg__ServoPosition * msg)
{
  if (!msg) {
    return;
  }
  // servo_id
  // angle
  // speed
}

bool
spider_msgs__msg__ServoPosition__are_equal(const spider_msgs__msg__ServoPosition * lhs, const spider_msgs__msg__ServoPosition * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // servo_id
  if (lhs->servo_id != rhs->servo_id) {
    return false;
  }
  // angle
  if (lhs->angle != rhs->angle) {
    return false;
  }
  // speed
  if (lhs->speed != rhs->speed) {
    return false;
  }
  return true;
}

bool
spider_msgs__msg__ServoPosition__copy(
  const spider_msgs__msg__ServoPosition * input,
  spider_msgs__msg__ServoPosition * output)
{
  if (!input || !output) {
    return false;
  }
  // servo_id
  output->servo_id = input->servo_id;
  // angle
  output->angle = input->angle;
  // speed
  output->speed = input->speed;
  return true;
}

spider_msgs__msg__ServoPosition *
spider_msgs__msg__ServoPosition__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_msgs__msg__ServoPosition * msg = (spider_msgs__msg__ServoPosition *)allocator.allocate(sizeof(spider_msgs__msg__ServoPosition), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(spider_msgs__msg__ServoPosition));
  bool success = spider_msgs__msg__ServoPosition__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
spider_msgs__msg__ServoPosition__destroy(spider_msgs__msg__ServoPosition * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    spider_msgs__msg__ServoPosition__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
spider_msgs__msg__ServoPosition__Sequence__init(spider_msgs__msg__ServoPosition__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_msgs__msg__ServoPosition * data = NULL;

  if (size) {
    data = (spider_msgs__msg__ServoPosition *)allocator.zero_allocate(size, sizeof(spider_msgs__msg__ServoPosition), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = spider_msgs__msg__ServoPosition__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        spider_msgs__msg__ServoPosition__fini(&data[i - 1]);
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
spider_msgs__msg__ServoPosition__Sequence__fini(spider_msgs__msg__ServoPosition__Sequence * array)
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
      spider_msgs__msg__ServoPosition__fini(&array->data[i]);
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

spider_msgs__msg__ServoPosition__Sequence *
spider_msgs__msg__ServoPosition__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_msgs__msg__ServoPosition__Sequence * array = (spider_msgs__msg__ServoPosition__Sequence *)allocator.allocate(sizeof(spider_msgs__msg__ServoPosition__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = spider_msgs__msg__ServoPosition__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
spider_msgs__msg__ServoPosition__Sequence__destroy(spider_msgs__msg__ServoPosition__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    spider_msgs__msg__ServoPosition__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
spider_msgs__msg__ServoPosition__Sequence__are_equal(const spider_msgs__msg__ServoPosition__Sequence * lhs, const spider_msgs__msg__ServoPosition__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!spider_msgs__msg__ServoPosition__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
spider_msgs__msg__ServoPosition__Sequence__copy(
  const spider_msgs__msg__ServoPosition__Sequence * input,
  spider_msgs__msg__ServoPosition__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(spider_msgs__msg__ServoPosition);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    spider_msgs__msg__ServoPosition * data =
      (spider_msgs__msg__ServoPosition *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!spider_msgs__msg__ServoPosition__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          spider_msgs__msg__ServoPosition__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!spider_msgs__msg__ServoPosition__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
