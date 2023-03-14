#!/bin/bash
set -e

mkdir -p /app/yolo_ws/src
mv /app/yolov5_ros2 /app/yolo_ws/src/yolov5_ros2
cd /app/yolo_ws
colcon build

# set ros environment
source /opt/ros/galactic/setup.bash
source ./install/setup.bash
export ROS_DOMAIN_ID=7