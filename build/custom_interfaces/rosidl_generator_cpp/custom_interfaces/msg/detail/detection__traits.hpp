// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_interfaces:msg/Detection.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__DETECTION__TRAITS_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__DETECTION__TRAITS_HPP_

#include "custom_interfaces/msg/detail/detection__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const custom_interfaces::msg::Detection & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    value_to_yaml(msg.name, out);
    out << "\n";
  }

  // member: bound
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bound: ";
    value_to_yaml(msg.bound, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const custom_interfaces::msg::Detection & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<custom_interfaces::msg::Detection>()
{
  return "custom_interfaces::msg::Detection";
}

template<>
inline const char * name<custom_interfaces::msg::Detection>()
{
  return "custom_interfaces/msg/Detection";
}

template<>
struct has_fixed_size<custom_interfaces::msg::Detection>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_interfaces::msg::Detection>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_interfaces::msg::Detection>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__DETECTION__TRAITS_HPP_
