// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from spider_msgs:msg/RobotState.idl
// generated code does not contain a copyright notice

#include "spider_msgs/msg/detail/robot_state__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_spider_msgs
const rosidl_type_hash_t *
spider_msgs__msg__RobotState__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x11, 0x2b, 0xdf, 0xed, 0x15, 0xc9, 0xca, 0x4d,
      0x8a, 0x3b, 0x4c, 0x43, 0xb4, 0xf6, 0xf5, 0x26,
      0xa0, 0xfa, 0x9d, 0x4b, 0x9b, 0x90, 0x55, 0x75,
      0xbf, 0x54, 0x3a, 0xaa, 0xb3, 0xbc, 0x71, 0xf8,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "geometry_msgs/msg/detail/point__functions.h"
#include "spider_msgs/msg/detail/leg_position__functions.h"
#include "spider_msgs/msg/detail/leg_positions__functions.h"
#include "std_msgs/msg/detail/header__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__Point__EXPECTED_HASH = {1, {
    0x69, 0x63, 0x08, 0x48, 0x42, 0xa9, 0xb0, 0x44,
    0x94, 0xd6, 0xb2, 0x94, 0x1d, 0x11, 0x44, 0x47,
    0x08, 0xd8, 0x92, 0xda, 0x2f, 0x4b, 0x09, 0x84,
    0x3b, 0x9c, 0x43, 0xf4, 0x2a, 0x7f, 0x68, 0x81,
  }};
static const rosidl_type_hash_t spider_msgs__msg__LegPosition__EXPECTED_HASH = {1, {
    0x95, 0x54, 0x0a, 0x67, 0xb0, 0xf8, 0x65, 0xfe,
    0x24, 0xaf, 0xdd, 0x34, 0x09, 0xb5, 0xfb, 0xab,
    0xb7, 0x54, 0xb3, 0xf4, 0x6d, 0x95, 0x32, 0xa0,
    0x07, 0xfe, 0x38, 0x4c, 0x65, 0x9a, 0x52, 0xb5,
  }};
static const rosidl_type_hash_t spider_msgs__msg__LegPositions__EXPECTED_HASH = {1, {
    0x2c, 0x9d, 0x56, 0xd0, 0x5e, 0x22, 0xa1, 0x15,
    0xa0, 0x52, 0xb5, 0xc4, 0xce, 0x9c, 0xb3, 0xd6,
    0x1c, 0x2b, 0x32, 0x46, 0x81, 0xcd, 0x96, 0x53,
    0x69, 0xea, 0xb8, 0xc1, 0xa8, 0x14, 0x95, 0x9e,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
#endif

static char spider_msgs__msg__RobotState__TYPE_NAME[] = "spider_msgs/msg/RobotState";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char geometry_msgs__msg__Point__TYPE_NAME[] = "geometry_msgs/msg/Point";
static char spider_msgs__msg__LegPosition__TYPE_NAME[] = "spider_msgs/msg/LegPosition";
static char spider_msgs__msg__LegPositions__TYPE_NAME[] = "spider_msgs/msg/LegPositions";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";

// Define type names, field names, and default values
static char spider_msgs__msg__RobotState__FIELD_NAME__header[] = "header";
static char spider_msgs__msg__RobotState__FIELD_NAME__current_behavior[] = "current_behavior";
static char spider_msgs__msg__RobotState__FIELD_NAME__is_moving[] = "is_moving";
static char spider_msgs__msg__RobotState__FIELD_NAME__battery_level[] = "battery_level";
static char spider_msgs__msg__RobotState__FIELD_NAME__current_pose[] = "current_pose";

static rosidl_runtime_c__type_description__Field spider_msgs__msg__RobotState__FIELDS[] = {
  {
    {spider_msgs__msg__RobotState__FIELD_NAME__header, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    },
    {NULL, 0, 0},
  },
  {
    {spider_msgs__msg__RobotState__FIELD_NAME__current_behavior, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {spider_msgs__msg__RobotState__FIELD_NAME__is_moving, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {spider_msgs__msg__RobotState__FIELD_NAME__battery_level, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {spider_msgs__msg__RobotState__FIELD_NAME__current_pose, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {spider_msgs__msg__LegPositions__TYPE_NAME, 28, 28},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription spider_msgs__msg__RobotState__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
  {
    {spider_msgs__msg__LegPosition__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {spider_msgs__msg__LegPositions__TYPE_NAME, 28, 28},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
spider_msgs__msg__RobotState__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {spider_msgs__msg__RobotState__TYPE_NAME, 26, 26},
      {spider_msgs__msg__RobotState__FIELDS, 5, 5},
    },
    {spider_msgs__msg__RobotState__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Point__EXPECTED_HASH, geometry_msgs__msg__Point__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = geometry_msgs__msg__Point__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&spider_msgs__msg__LegPosition__EXPECTED_HASH, spider_msgs__msg__LegPosition__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = spider_msgs__msg__LegPosition__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&spider_msgs__msg__LegPositions__EXPECTED_HASH, spider_msgs__msg__LegPositions__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = spider_msgs__msg__LegPositions__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Robot state information\n"
  "std_msgs/Header header\n"
  "string current_behavior          # Current executing behavior\n"
  "bool is_moving                   # True if robot is in motion\n"
  "float32 battery_level           # Battery percentage (0-100)\n"
  "LegPositions current_pose        # Current leg positions";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
spider_msgs__msg__RobotState__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {spider_msgs__msg__RobotState__TYPE_NAME, 26, 26},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 290, 290},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
spider_msgs__msg__RobotState__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *spider_msgs__msg__RobotState__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *geometry_msgs__msg__Point__get_individual_type_description_source(NULL);
    sources[3] = *spider_msgs__msg__LegPosition__get_individual_type_description_source(NULL);
    sources[4] = *spider_msgs__msg__LegPositions__get_individual_type_description_source(NULL);
    sources[5] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
