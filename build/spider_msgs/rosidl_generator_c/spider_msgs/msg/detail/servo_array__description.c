// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from spider_msgs:msg/ServoArray.idl
// generated code does not contain a copyright notice

#include "spider_msgs/msg/detail/servo_array__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_spider_msgs
const rosidl_type_hash_t *
spider_msgs__msg__ServoArray__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xba, 0x84, 0x5b, 0x7b, 0x46, 0x9e, 0x41, 0xf4,
      0x83, 0x11, 0x51, 0x90, 0x7b, 0x3b, 0xa6, 0x52,
      0xfa, 0x30, 0x7d, 0x0b, 0x3e, 0x87, 0x0e, 0xee,
      0x4a, 0x4b, 0x69, 0x4d, 0xc7, 0x3d, 0x5b, 0x71,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "spider_msgs/msg/detail/servo_position__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t spider_msgs__msg__ServoPosition__EXPECTED_HASH = {1, {
    0xd6, 0xa9, 0x94, 0xf9, 0x95, 0x42, 0xc1, 0x38,
    0x69, 0x66, 0xd4, 0xb4, 0x45, 0x37, 0x7d, 0x26,
    0xd1, 0x00, 0xbc, 0x01, 0x27, 0x56, 0x28, 0xce,
    0x71, 0xd7, 0x15, 0x60, 0xb5, 0x0a, 0x81, 0xc5,
  }};
#endif

static char spider_msgs__msg__ServoArray__TYPE_NAME[] = "spider_msgs/msg/ServoArray";
static char spider_msgs__msg__ServoPosition__TYPE_NAME[] = "spider_msgs/msg/ServoPosition";

// Define type names, field names, and default values
static char spider_msgs__msg__ServoArray__FIELD_NAME__servos[] = "servos";

static rosidl_runtime_c__type_description__Field spider_msgs__msg__ServoArray__FIELDS[] = {
  {
    {spider_msgs__msg__ServoArray__FIELD_NAME__servos, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {spider_msgs__msg__ServoPosition__TYPE_NAME, 29, 29},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription spider_msgs__msg__ServoArray__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {spider_msgs__msg__ServoPosition__TYPE_NAME, 29, 29},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
spider_msgs__msg__ServoArray__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {spider_msgs__msg__ServoArray__TYPE_NAME, 26, 26},
      {spider_msgs__msg__ServoArray__FIELDS, 1, 1},
    },
    {spider_msgs__msg__ServoArray__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&spider_msgs__msg__ServoPosition__EXPECTED_HASH, spider_msgs__msg__ServoPosition__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = spider_msgs__msg__ServoPosition__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Array of servo position commands\n"
  "ServoPosition[] servos";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
spider_msgs__msg__ServoArray__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {spider_msgs__msg__ServoArray__TYPE_NAME, 26, 26},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 57, 57},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
spider_msgs__msg__ServoArray__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *spider_msgs__msg__ServoArray__get_individual_type_description_source(NULL),
    sources[1] = *spider_msgs__msg__ServoPosition__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
