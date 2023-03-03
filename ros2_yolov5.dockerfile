ARG ROS_DISTRO=galactic
FROM ros:${ROS_DISTRO}
# shaderobotics/yolov5:${ROS_DISTRO}
# The ARG using before FROM only works on FROM. Define a new ENV or ARG after FROM.
# ARG 指令有生效范围，如果在 FROM 指令之前指定，那么只能用于 FROM 指令中。
ENV ROS_DISTRO galactic
ENV ROS_DOMAIN_ID 7
ENV IMAGE_TOPIC image_raw
ENV YOLO_MODEL yolov5s
# yolov5s yolov5m yolov5l

RUN apt-get update && \
    apt-get install -y \
        python3-pip \
        git \
        ros-${ROS_DISTRO}-cv-bridge \
        ros-${ROS_DISTRO}-vision-msgs \
        ros-${ROS_DISTRO}-vision-opencv \
        ros-${ROS_DISTRO}-usb-cam && \
    rm -rf /var/lib/apt/lists/*  && \
    python3 -m pip install -qr https://raw.githubusercontent.com/ultralytics/yolov5/master/requirements.txt && \
    python3 -m pip install yolov5 && \
    python3 -m pip install python-dateutil

WORkDIR /app     
RUN ["/bin/bash", "-c", "mkdir -p /app/yolo_ws/src"]

# inject yolov5_ros2 to docker image
WORkDIR /app/yolo_ws/src
COPY src/yolov5_ros2 /app/yolo_ws/src/yolov5_ros2

# build and copy yolo model and camerainfo
WORkDIR /app/yolo_ws
RUN colcon build
COPY config /app/yolo_ws/install/yolov5_ros2/share/yolov5_ros2/config

# use a shell script to do source and export
COPY entrypoint_ros2_dockerfile.sh /app/yolo_ws/entrypoint_ros2_dockerfile.sh

# ENTRYPOINT ["/bin/bash", "-c", "source /opt/ros/${ROS_DISTRO}/setup.bash && source ./install/setup.bash && export ROS_DOMAIN_ID=${ROS_DOMAIN_ID} && ros2 run yolov5_ros2 yolo_detect --ros-args -p image_topic:=/${IMAGE_TOPIC} -p model:=${YOLO_MODEL}"]
ENTRYPOINT ["/entrypoint_ros2_dockerfile.sh"]
CMD ["${ROS_DISTRO} ${ROS_DOMAIN_ID} ${IMAGE_TOPIC} ${YOLO_MODEL}"]