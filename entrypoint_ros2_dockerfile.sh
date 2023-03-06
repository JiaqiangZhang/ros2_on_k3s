#!/bin/bash
set -e
# arg 
ROS_DISTRO="galactic" #$1 
ROS_DOMAIN_ID=7 #$2
IMAGE_TOPIC="image_raw" #$3
YOLO_MODEL="yolov5s" #$4

usage()
{
    echo "Usage: entrypoint yolov5 ros2 [ -R foxy or galactic ] 
                                [ -I default 7 ] 
                                [ -T default image_raw] 
                                [ -M default yolov5s ]"
    echo $@
}

# PARSED_ARGUMENTS=$(getopt -a -n entrypoint_ros2_dockerfile --long ROS_DISTRO:,ROS_DOMAIN_ID:,IMAGE_TOPIC:,YOLO_MODEL: -- "$@")
PARSED_ARGUMENTS=$(getopt -n entrypoint_ros2_dockerfile -o R:I:T:M: -- "$@")

VALID_ARGUMENTS=$?
if [ "$VALID_ARGUMENTS" != "0" ]; then
    usage
fi

echo "PARSED_ARGUMENTS IS $PARSED_ARGUMENTS"
eval set -- "$PARSED_ARGUMENTS"

while :
do
    case "$1" in
        # --ROS_DISTRO) ROS_DISTRO="$2" ; shift 2 ;;
        # --ROS_DOMAIN_ID) ROS_DOMAIN_ID="$2" ; shift 2 ;;
        # --IMAGE_TOPIC) IMAGE_TOPIC="$2" ; shift 2 ;;
        # --YOLO_MODEL) YOLO_MODEL="$2" ; shift 2 ;;

        -R) ROS_DISTRO="$2" ; shift 2 ;;
        -I) ROS_DOMAIN_ID="$2" ; shift 2 ;;
        -T) IMAGE_TOPIC="$2" ; shift 2 ;;
        -M) YOLO_MODEL="$2" ; shift 2 ;;
        --) shift; break ;;
        *) echo "Unexpected option"
            usage ;;
    esac
done

# set ros environment
source /opt/ros/${ROS_DISTRO}/setup.bash
source ./install/setup.bash
export ROS_DOMAIN_ID=${ROS_DOMAIN_ID}

ros2 run yolov5_ros2 yolo_detect --ros-args -p image_topic:=/${IMAGE_TOPIC} -p model:=${YOLO_MODEL}

exec "$@"