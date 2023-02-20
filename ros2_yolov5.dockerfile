ARG ROS_DISTRO=foxy
FROM ros:${ROS_DISTRO}
# shaderobotics/yolov5:${ROS_DISTRO}
ENV ROS_DISTRO $ROS_DISTRO

RUN ["/bin/bash", "-c", "mkdir -p /app/yolo_ws/src"]
WORkDIR /app/yolo_ws/src

RUN apt update && \
    apt install -y \
        python3-pip \
        git \
        ros-&{ROS-DISTRO}-cv-bridge \
        ros-&{ROS-DISTRO}-vision-msgs \
        ros-&{ROS-DISTRO}-vision-opencv \
        ros-&{ROS-DISTRO}-usb-cam \
        




