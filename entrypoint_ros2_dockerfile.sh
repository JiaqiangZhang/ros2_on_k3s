#!/bin/bash
set -e
# arg 
ROS_DISTRO=$1 
ROS_DOMAIN_ID=$2
IMAGE_TOPIC=$3
YOLO_MODEL=$4

# set ros environment
source /opt/ros/${ROS_DISTRO}/setup.bash
source ./install/setup.bash
export ROS_DOMAIN_ID=${ROS_DOMAIN_ID}

ros2 run yolov5_ros2 yolo_detect --ros-args -p image_topic:=/${IMAGE_TOPIC} -p model:=${YOLO_MODEL}
