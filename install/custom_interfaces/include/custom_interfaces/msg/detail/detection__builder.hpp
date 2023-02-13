// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/Detection.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__DETECTION__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__DETECTION__BUILDER_HPP_

#include "custom_interfaces/msg/detail/detection__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_Detection_bound
{
public:
  explicit Init_Detection_bound(::custom_interfaces::msg::Detection & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::msg::Detection bound(::custom_interfaces::msg::Detection::_bound_type arg)
  {
    msg_.bound = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::Detection msg_;
};

class Init_Detection_name
{
public:
  Init_Detection_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Detection_bound name(::custom_interfaces::msg::Detection::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_Detection_bound(msg_);
  }

private:
  ::custom_interfaces::msg::Detection msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::Detection>()
{
  return custom_interfaces::msg::builder::Init_Detection_name();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__DETECTION__BUILDER_HPP_
