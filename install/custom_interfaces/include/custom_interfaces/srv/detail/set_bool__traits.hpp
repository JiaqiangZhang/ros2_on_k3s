// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_interfaces:srv/SetBool.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__SET_BOOL__TRAITS_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__SET_BOOL__TRAITS_HPP_

#include "custom_interfaces/srv/detail/set_bool__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const custom_interfaces::srv::SetBool_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "data: ";
    value_to_yaml(msg.data, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const custom_interfaces::srv::SetBool_Request & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<custom_interfaces::srv::SetBool_Request>()
{
  return "custom_interfaces::srv::SetBool_Request";
}

template<>
inline const char * name<custom_interfaces::srv::SetBool_Request>()
{
  return "custom_interfaces/srv/SetBool_Request";
}

template<>
struct has_fixed_size<custom_interfaces::srv::SetBool_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<custom_interfaces::srv::SetBool_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<custom_interfaces::srv::SetBool_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

inline void to_yaml(
  const custom_interfaces::srv::SetBool_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const custom_interfaces::srv::SetBool_Response & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<custom_interfaces::srv::SetBool_Response>()
{
  return "custom_interfaces::srv::SetBool_Response";
}

template<>
inline const char * name<custom_interfaces::srv::SetBool_Response>()
{
  return "custom_interfaces/srv/SetBool_Response";
}

template<>
struct has_fixed_size<custom_interfaces::srv::SetBool_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_interfaces::srv::SetBool_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_interfaces::srv::SetBool_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_interfaces::srv::SetBool>()
{
  return "custom_interfaces::srv::SetBool";
}

template<>
inline const char * name<custom_interfaces::srv::SetBool>()
{
  return "custom_interfaces/srv/SetBool";
}

template<>
struct has_fixed_size<custom_interfaces::srv::SetBool>
  : std::integral_constant<
    bool,
    has_fixed_size<custom_interfaces::srv::SetBool_Request>::value &&
    has_fixed_size<custom_interfaces::srv::SetBool_Response>::value
  >
{
};

template<>
struct has_bounded_size<custom_interfaces::srv::SetBool>
  : std::integral_constant<
    bool,
    has_bounded_size<custom_interfaces::srv::SetBool_Request>::value &&
    has_bounded_size<custom_interfaces::srv::SetBool_Response>::value
  >
{
};

template<>
struct is_service<custom_interfaces::srv::SetBool>
  : std::true_type
{
};

template<>
struct is_service_request<custom_interfaces::srv::SetBool_Request>
  : std::true_type
{
};

template<>
struct is_service_response<custom_interfaces::srv::SetBool_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__SET_BOOL__TRAITS_HPP_
