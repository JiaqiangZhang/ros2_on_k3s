ARG ROS_DISTRO=galactic
FROM ros:${ROS_DISTRO}
# -ros-base
# shaderobotics/yolov5:${ROS_DISTRO}
# The ARG using before FROM only works on FROM. Define a new ENV or ARG after FROM.
# ARG 指令有生效范围，如果在 FROM 指令之前指定，那么只能用于 FROM 指令中。
ENV ROS_DISTRO galactic

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        python3-pip \
        git \
        python-dateutil \
        ros-${ROS_DISTRO}-cv-bridge \
        ros-${ROS_DISTRO}-vision-msgs \
        ros-${ROS_DISTRO}-vision-opencv && \
    rm -rf /var/lib/apt/lists/*  && \
    python3 -m pip install -qr https://raw.githubusercontent.com/ultralytics/yolov5/master/requirements.txt && \
    python3 -m pip install yolov5 && \
    python3 -m pip install python-dateutil 
    # git clone 
# ros-${ROS_DISTRO}-usb-cam
WORkDIR /app
COPY src/yolov5_ros2 /app/yolov5_ros2
# COPY build_ros2_pkg.sh /app/build_ros2_pkg.sh
# RUN /app/build_ros2_pkg.sh

####### write a shell script
RUN ["/bin/bash", "-c", "mkdir -p /app/yolo_ws/src"]

# inject yolov5_ros2 to docker image
WORkDIR /app/yolo_ws/src
COPY src/yolov5_ros2 /app/yolo_ws/src/yolov5_ros2

# build and copy yolo model and camerainfo
WORkDIR /app/yolo_ws
RUN colcon build
#######

# WORkDIR /app/yolo_ws
COPY config /app/yolo_ws/install/yolov5_ros2/share/yolov5_ros2/config

# use a shell script to do source and export
# COPY entrypoint_ros2_dockerfile.sh /app/yolo_ws/entrypoint_ros2_dockerfile.sh

# RUN apt-get clean && apt-get autoclean && apt-get autoremove

# ENTRYPOINT ["/bin/bash", "-c", "source /opt/ros/${ROS_DISTRO}/setup.bash && source ./install/setup.bash && export ROS_DOMAIN_ID=${ROS_DOMAIN_ID} && ros2 run yolov5_ros2 yolo_detect --ros-args -p image_topic:=/${IMAGE_TOPIC} -p model:=${YOLO_MODEL}"]
# ENTRYPOINT ["/app/yolo_ws/entrypoint_ros2_dockerfile.sh"]
# CMD ["--ROS_DISTRO=galactic", "--ROS_DOMAIN_ID=7", "--IMAGE_TOPIC=image_raw", "--YOLO_MODEL=yolov5s"]
# CMD ["-R", "galactic", "-I", "7", "-T", "image_raw", "-M", "yolov5s", "-D", "cpu"]