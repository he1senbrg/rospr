// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from spider_msgs:msg/LegPosition.idl
// generated code does not contain a copyright notice

#include "spider_msgs/msg/detail/leg_position__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_spider_msgs
const rosidl_type_hash_t *
spider_msgs__msg__LegPosition__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x95, 0x54, 0x0a, 0x67, 0xb0, 0xf8, 0x65, 0xfe,
      0x24, 0xaf, 0xdd, 0x34, 0x09, 0xb5, 0xfb, 0xab,
      0xb7, 0x54, 0xb3, 0xf4, 0x6d, 0x95, 0x32, 0xa0,
      0x07, 0xfe, 0x38, 0x4c, 0x65, 0x9a, 0x52, 0xb5,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "geometry_msgs/msg/detail/point__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t geometry_msgs__msg__Point__EXPECTED_HASH = {1, {
    0x69, 0x63, 0x08, 0x48, 0x42, 0xa9, 0xb0, 0x44,
    0x94, 0xd6, 0xb2, 0x94, 0x1d, 0x11, 0x44, 0x47,
    0x08, 0xd8, 0x92, 0xda, 0x2f, 0x4b, 0x09, 0x84,
    0x3b, 0x9c, 0x43, 0xf4, 0x2a, 0x7f, 0x68, 0x81,
  }};
#endif

static char spider_msgs__msg__LegPosition__TYPE_NAME[] = "spider_msgs/msg/LegPosition";
static char geometry_msgs__msg__Point__TYPE_NAME[] = "geometry_msgs/msg/Point";

// Define type names, field names, and default values
static char spider_msgs__msg__LegPosition__FIELD_NAME__position[] = "position";
static char spider_msgs__msg__LegPosition__FIELD_NAME__movement_speed[] = "movement_speed";

static rosidl_runtime_c__type_description__Field spider_msgs__msg__LegPosition__FIELDS[] = {
  {
    {spider_msgs__msg__LegPosition__FIELD_NAME__position, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    },
    {NULL, 0, 0},
  },
  {
    {spider_msgs__msg__LegPosition__FIELD_NAME__movement_speed, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription spider_msgs__msg__LegPosition__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
spider_msgs__msg__LegPosition__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {spider_msgs__msg__LegPosition__TYPE_NAME, 27, 27},
      {spider_msgs__msg__LegPosition__FIELDS, 2, 2},
    },
    {spider_msgs__msg__LegPosition__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&geometry_msgs__msg__Point__EXPECTED_HASH, geometry_msgs__msg__Point__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = geometry_msgs__msg__Point__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# 3D position of a leg end effector\n"
  "geometry_msgs/Point position     # Cartesian coordinates (x, y, z)\n"
  "float32 movement_speed          # Speed multiplier for this leg";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
spider_msgs__msg__LegPosition__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {spider_msgs__msg__LegPosition__TYPE_NAME, 27, 27},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 166, 166},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
spider_msgs__msg__LegPosition__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *spider_msgs__msg__LegPosition__get_individual_type_description_source(NULL),
    sources[1] = *geometry_msgs__msg__Point__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
