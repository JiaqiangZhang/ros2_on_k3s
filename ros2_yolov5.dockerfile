# ARG ROS_DISTRO=galactic
ENV ROS_DISTRO galactic
ENV ROS_DOMAIN_ID 7
ENV IMAGE_TOPIC image_raw
ENV YOLO_MODEL yolov5s
# yolov5s yolov5m yolov5l
FROM ros:${ROS_DISTRO}
# shaderobotics/yolov5:${ROS_DISTRO}

RUN apt update && \
    apt install -y \
        python3-pip \
        git \
        ros-&{ROS-DISTRO}-cv-bridge \
        ros-&{ROS-DISTRO}-vision-msgs \
        ros-&{ROS-DISTRO}-vision-opencv \
        ros-&{ROS-DISTRO}-usb-cam && \
    python3 -m pip install -qr https://raw.githubusercontent.com/ultralytics/yolov5/master/requirements.txt && \
    python3 -m pip install yolov5

WORkDIR /app     
RUN ["/bin/bash", "-c", "mkdir -p /app/yolo_ws/src"]

# inject yolov5_ros2 to docker image
WORkDIR /app/yolo_ws/src
COPY src/yolov5_ros2 /app/yolo_ws/src/yolov5_ros2

# build and copy yolo model and camerainfo
WORkDIR /app/yolo_ws
RUN colcon build
COPY config /app/yolo_ws/install/yolov5_ros2/share/yolov5_ros2/config

ENTRYPOINT ["/bin/bash", "-c", "source /opt/ros/${ROS_DISTRO}/setup.bash && source ./install/setup.bash && export ROS_DOMAIN_ID=${ROS_DOMAIN_ID} && ros2 run yolov5_ros2 yolo_detect --ros-args -p image_topic:=${IMAGE_TOPIC} -p model:=yolov5s"]