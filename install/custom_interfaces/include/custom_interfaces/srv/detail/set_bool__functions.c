// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_interfaces:srv/SetBool.idl
// generated code does not contain a copyright notice
#include "custom_interfaces/srv/detail/set_bool__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool
custom_interfaces__srv__SetBool_Request__init(custom_interfaces__srv__SetBool_Request * msg)
{
  if (!msg) {
    return false;
  }
  // data
  return true;
}

void
custom_interfaces__srv__SetBool_Request__fini(custom_interfaces__srv__SetBool_Request * msg)
{
  if (!msg) {
    return;
  }
  // data
}

bool
custom_interfaces__srv__SetBool_Request__are_equal(const custom_interfaces__srv__SetBool_Request * lhs, const custom_interfaces__srv__SetBool_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // data
  if (lhs->data != rhs->data) {
    return false;
  }
  return true;
}

bool
custom_interfaces__srv__SetBool_Request__copy(
  const custom_interfaces__srv__SetBool_Request * input,
  custom_interfaces__srv__SetBool_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // data
  output->data = input->data;
  return true;
}

custom_interfaces__srv__SetBool_Request *
custom_interfaces__srv__SetBool_Request__create()
{
  custom_interfaces__srv__SetBool_Request * msg = (custom_interfaces__srv__SetBool_Request *)malloc(sizeof(custom_interfaces__srv__SetBool_Request));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_interfaces__srv__SetBool_Request));
  bool success = custom_interfaces__srv__SetBool_Request__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
custom_interfaces__srv__SetBool_Request__destroy(custom_interfaces__srv__SetBool_Request * msg)
{
  if (msg) {
    custom_interfaces__srv__SetBool_Request__fini(msg);
  }
  free(msg);
}


bool
custom_interfaces__srv__SetBool_Request__Sequence__init(custom_interfaces__srv__SetBool_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  custom_interfaces__srv__SetBool_Request * data = NULL;
  if (size) {
    data = (custom_interfaces__srv__SetBool_Request *)calloc(size, sizeof(custom_interfaces__srv__SetBool_Request));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_interfaces__srv__SetBool_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_interfaces__srv__SetBool_Request__fini(&data[i - 1]);
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
custom_interfaces__srv__SetBool_Request__Sequence__fini(custom_interfaces__srv__SetBool_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_interfaces__srv__SetBool_Request__fini(&array->data[i]);
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

custom_interfaces__srv__SetBool_Request__Sequence *
custom_interfaces__srv__SetBool_Request__Sequence__create(size_t size)
{
  custom_interfaces__srv__SetBool_Request__Sequence * array = (custom_interfaces__srv__SetBool_Request__Sequence *)malloc(sizeof(custom_interfaces__srv__SetBool_Request__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = custom_interfaces__srv__SetBool_Request__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
custom_interfaces__srv__SetBool_Request__Sequence__destroy(custom_interfaces__srv__SetBool_Request__Sequence * array)
{
  if (array) {
    custom_interfaces__srv__SetBool_Request__Sequence__fini(array);
  }
  free(array);
}

bool
custom_interfaces__srv__SetBool_Request__Sequence__are_equal(const custom_interfaces__srv__SetBool_Request__Sequence * lhs, const custom_interfaces__srv__SetBool_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_interfaces__srv__SetBool_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_interfaces__srv__SetBool_Request__Sequence__copy(
  const custom_interfaces__srv__SetBool_Request__Sequence * input,
  custom_interfaces__srv__SetBool_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_interfaces__srv__SetBool_Request);
    custom_interfaces__srv__SetBool_Request * data =
      (custom_interfaces__srv__SetBool_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_interfaces__srv__SetBool_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          custom_interfaces__srv__SetBool_Request__fini(&data[i]);
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
    if (!custom_interfaces__srv__SetBool_Request__copy(
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
custom_interfaces__srv__SetBool_Response__init(custom_interfaces__srv__SetBool_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    custom_interfaces__srv__SetBool_Response__fini(msg);
    return false;
  }
  return true;
}

void
custom_interfaces__srv__SetBool_Response__fini(custom_interfaces__srv__SetBool_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
custom_interfaces__srv__SetBool_Response__are_equal(const custom_interfaces__srv__SetBool_Response * lhs, const custom_interfaces__srv__SetBool_Response * rhs)
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
custom_interfaces__srv__SetBool_Response__copy(
  const custom_interfaces__srv__SetBool_Response * input,
  custom_interfaces__srv__SetBool_Response * output)
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

custom_interfaces__srv__SetBool_Response *
custom_interfaces__srv__SetBool_Response__create()
{
  custom_interfaces__srv__SetBool_Response * msg = (custom_interfaces__srv__SetBool_Response *)malloc(sizeof(custom_interfaces__srv__SetBool_Response));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_interfaces__srv__SetBool_Response));
  bool success = custom_interfaces__srv__SetBool_Response__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
custom_interfaces__srv__SetBool_Response__destroy(custom_interfaces__srv__SetBool_Response * msg)
{
  if (msg) {
    custom_interfaces__srv__SetBool_Response__fini(msg);
  }
  free(msg);
}


bool
custom_interfaces__srv__SetBool_Response__Sequence__init(custom_interfaces__srv__SetBool_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  custom_interfaces__srv__SetBool_Response * data = NULL;
  if (size) {
    data = (custom_interfaces__srv__SetBool_Response *)calloc(size, sizeof(custom_interfaces__srv__SetBool_Response));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_interfaces__srv__SetBool_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_interfaces__srv__SetBool_Response__fini(&data[i - 1]);
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
custom_interfaces__srv__SetBool_Response__Sequence__fini(custom_interfaces__srv__SetBool_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_interfaces__srv__SetBool_Response__fini(&array->data[i]);
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

custom_interfaces__srv__SetBool_Response__Sequence *
custom_interfaces__srv__SetBool_Response__Sequence__create(size_t size)
{
  custom_interfaces__srv__SetBool_Response__Sequence * array = (custom_interfaces__srv__SetBool_Response__Sequence *)malloc(sizeof(custom_interfaces__srv__SetBool_Response__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = custom_interfaces__srv__SetBool_Response__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
custom_interfaces__srv__SetBool_Response__Sequence__destroy(custom_interfaces__srv__SetBool_Response__Sequence * array)
{
  if (array) {
    custom_interfaces__srv__SetBool_Response__Sequence__fini(array);
  }
  free(array);
}

bool
custom_interfaces__srv__SetBool_Response__Sequence__are_equal(const custom_interfaces__srv__SetBool_Response__Sequence * lhs, const custom_interfaces__srv__SetBool_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_interfaces__srv__SetBool_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_interfaces__srv__SetBool_Response__Sequence__copy(
  const custom_interfaces__srv__SetBool_Response__Sequence * input,
  custom_interfaces__srv__SetBool_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_interfaces__srv__SetBool_Response);
    custom_interfaces__srv__SetBool_Response * data =
      (custom_interfaces__srv__SetBool_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_interfaces__srv__SetBool_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          custom_interfaces__srv__SetBool_Response__fini(&data[i]);
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
    if (!custom_interfaces__srv__SetBool_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
