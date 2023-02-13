// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_interfaces:msg/Detection.idl
// generated code does not contain a copyright notice
#include "custom_interfaces/msg/detail/detection__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `name`
// Member `bound`
#include "rosidl_runtime_c/string_functions.h"

bool
custom_interfaces__msg__Detection__init(custom_interfaces__msg__Detection * msg)
{
  if (!msg) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    custom_interfaces__msg__Detection__fini(msg);
    return false;
  }
  // bound
  if (!rosidl_runtime_c__String__init(&msg->bound)) {
    custom_interfaces__msg__Detection__fini(msg);
    return false;
  }
  return true;
}

void
custom_interfaces__msg__Detection__fini(custom_interfaces__msg__Detection * msg)
{
  if (!msg) {
    return;
  }
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // bound
  rosidl_runtime_c__String__fini(&msg->bound);
}

bool
custom_interfaces__msg__Detection__are_equal(const custom_interfaces__msg__Detection * lhs, const custom_interfaces__msg__Detection * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  // bound
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->bound), &(rhs->bound)))
  {
    return false;
  }
  return true;
}

bool
custom_interfaces__msg__Detection__copy(
  const custom_interfaces__msg__Detection * input,
  custom_interfaces__msg__Detection * output)
{
  if (!input || !output) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  // bound
  if (!rosidl_runtime_c__String__copy(
      &(input->bound), &(output->bound)))
  {
    return false;
  }
  return true;
}

custom_interfaces__msg__Detection *
custom_interfaces__msg__Detection__create()
{
  custom_interfaces__msg__Detection * msg = (custom_interfaces__msg__Detection *)malloc(sizeof(custom_interfaces__msg__Detection));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_interfaces__msg__Detection));
  bool success = custom_interfaces__msg__Detection__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
custom_interfaces__msg__Detection__destroy(custom_interfaces__msg__Detection * msg)
{
  if (msg) {
    custom_interfaces__msg__Detection__fini(msg);
  }
  free(msg);
}


bool
custom_interfaces__msg__Detection__Sequence__init(custom_interfaces__msg__Detection__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  custom_interfaces__msg__Detection * data = NULL;
  if (size) {
    data = (custom_interfaces__msg__Detection *)calloc(size, sizeof(custom_interfaces__msg__Detection));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_interfaces__msg__Detection__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_interfaces__msg__Detection__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_interfaces__msg__Detection__Sequence__fini(custom_interfaces__msg__Detection__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_interfaces__msg__Detection__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_interfaces__msg__Detection__Sequence *
custom_interfaces__msg__Detection__Sequence__create(size_t size)
{
  custom_interfaces__msg__Detection__Sequence * array = (custom_interfaces__msg__Detection__Sequence *)malloc(sizeof(custom_interfaces__msg__Detection__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = custom_interfaces__msg__Detection__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
custom_interfaces__msg__Detection__Sequence__destroy(custom_interfaces__msg__Detection__Sequence * array)
{
  if (array) {
    custom_interfaces__msg__Detection__Sequence__fini(array);
  }
  free(array);
}

bool
custom_interfaces__msg__Detection__Sequence__are_equal(const custom_interfaces__msg__Detection__Sequence * lhs, const custom_interfaces__msg__Detection__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_interfaces__msg__Detection__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_interfaces__msg__Detection__Sequence__copy(
  const custom_interfaces__msg__Detection__Sequence * input,
  custom_interfaces__msg__Detection__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_interfaces__msg__Detection);
    custom_interfaces__msg__Detection * data =
      (custom_interfaces__msg__Detection *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_interfaces__msg__Detection__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          custom_interfaces__msg__Detection__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_interfaces__msg__Detection__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
