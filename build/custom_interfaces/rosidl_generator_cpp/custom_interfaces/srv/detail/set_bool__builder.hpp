// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:srv/SetBool.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__SET_BOOL__BUILDER_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__SET_BOOL__BUILDER_HPP_

#include "custom_interfaces/srv/detail/set_bool__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetBool_Request_data
{
public:
  Init_SetBool_Request_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::srv::SetBool_Request data(::custom_interfaces::srv::SetBool_Request::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::SetBool_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::SetBool_Request>()
{
  return custom_interfaces::srv::builder::Init_SetBool_Request_data();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetBool_Response_message
{
public:
  explicit Init_SetBool_Response_message(::custom_interfaces::srv::SetBool_Response & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::srv::SetBool_Response message(::custom_interfaces::srv::SetBool_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::SetBool_Response msg_;
};

class Init_SetBool_Response_success
{
public:
  Init_SetBool_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetBool_Response_message success(::custom_interfaces::srv::SetBool_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_SetBool_Response_message(msg_);
  }

private:
  ::custom_interfaces::srv::SetBool_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::SetBool_Response>()
{
  return custom_interfaces::srv::builder::Init_SetBool_Response_success();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__SET_BOOL__BUILDER_HPP_
