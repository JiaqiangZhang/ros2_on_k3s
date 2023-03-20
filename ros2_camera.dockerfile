ARG ROS_DISTRO=galactic
FROM ros:${ROS_DISTRO}
# -ros-base
# shaderobotics/yolov5:${ROS_DISTRO}
# The ARG using before FROM only works on FROM. Define a new ENV or ARG after FROM.
# ARG 指令有生效范围，如果在 FROM 指令之前指定，那么只能用于 FROM 指令中。
ENV ROS_DISTRO galactic

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        python-dateutil \
        ros-${ROS_DISTRO}-usb-cam && \
    rm -rf /var/lib/apt/lists/*