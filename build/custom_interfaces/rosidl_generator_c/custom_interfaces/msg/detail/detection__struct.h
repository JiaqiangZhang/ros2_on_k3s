// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/Detection.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__DETECTION__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__DETECTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
// Member 'bound'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/Detection in the package custom_interfaces.
typedef struct custom_interfaces__msg__Detection
{
  rosidl_runtime_c__String name;
  rosidl_runtime_c__String bound;
} custom_interfaces__msg__Detection;

// Struct for a sequence of custom_interfaces__msg__Detection.
typedef struct custom_interfaces__msg__Detection__Sequence
{
  custom_interfaces__msg__Detection * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__Detection__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__DETECTION__STRUCT_H_
