#! /usr/bin/python
import base64
import cv2 as cv
import numpy as np

# import imutils
import yolov5

import rclpy
from rclpy.node import Node
import sys
from sensor_msgs.msg import Image
from custom_interfaces.msg import Detection
from vision_msgs.msg import Detection2DArray
from cv_bridge import CvBridge


class CamSubscriber(Node):
    def __init__(self):
        super().__init__('image_detection')
        self.cnt = 0

        # self.yolov5 = yolov5.YOLOv5()

        self.image_sub = self.create_subscription(Image, '/image_raw', self.image_sub_callback, 10)  # /camera/color/image_raw
        self.image_pub = self.create_publisher(Detection2DArray, '/object_found_yolov5', 10)
        self.result_msg = Detection2DArray()
        
        self.bridge = CvBridge()

        return


    def image_sub_callback(self, msg: Image):

        # Convert ROS Image message to OpenCV2
        cv2_img = self.imgmsg_to_cv2(msg)
        cv2_img = self.bridge.imgmsg_to_cv2(msg)

        # load model
        model = yolov5.load('yolov5s.pt')
        model.conf = 0.25
        model.iou = 0.45
        model.agnostic = False
        model.multi_label = False
        model.max_det = 1000

        rlt = model(cv2_img)
        # rlt.save(save_dir='rlt/rlt')

        self.result_msg.detections.clear()
        self.result_msg.header.frame_id = "camera"
        self.result_msg.header.stamp = self.get_clock().now().to_msg()

        predictions = rlt.pred[0]
        boxes = predictions[:, :4]
        scores = predictions[:, 4]
        categories = predictions[:, 5]
        print(rlt.pandas().xyxy[0])
        print(rlt.pred[0])
        print(boxes, scores, categories)
        pub_dimg = rlt.pandas().xyxy[0]
        # rlt.show()

        for index in range(len(categories)):
            name = rlt.names[int(categories[index])]
            detection2d = Detection2DArray()
            detection2d.id = name
            
            

        dmsg = Detection()
        dmsg.name = str(self.results_parser2(rlt))
        #dmsg.name = results
        print("self.results-----", self.results_parser2(rlt))
        dmsg.bound = str(boxes)
        print("dmsg: ", dmsg)

        print("dimsg is  " , pub_dimg)
        #dmsg.radius = boxes
        self.image_pub.publish(dmsg)

        self.cnt += 1
        # Save OpenCV2 image as a jpeg
        # cv.imwrite('camera_image_{}.jpeg'.format(self.cnt), cv2_img)
        print("Received an image!_{}".format(self.cnt))

    def image_pub_callback():

        pass

    def imgmsg_to_cv2(self, img_msg):
        n_channels = len(img_msg.data) // (img_msg.height * img_msg.width)
        dtype = np.uint8

        img_buf = np.asarray(img_msg.data, dtype=dtype) if isinstance(img_msg.data, list) else img_msg.data

        if n_channels == 1:
            cv2_img = np.ndarray(shape=(img_msg.height, img_msg.width),
                            dtype=dtype, buffer=img_buf)
        else:
            cv2_img = np.ndarray(shape=(img_msg.height, img_msg.width, n_channels),
                            dtype=dtype, buffer=img_buf)

        # If the byte order is different between the message and the system.
        if img_msg.is_bigendian == (sys.byteorder == 'little'):
            cv2_img = cv2_img.byteswap().newbyteorder()

        return cv2_img

    def results_parser2(self, results):
        s = ""
        if results.pred[0].shape[0]:
            for c in results.pred[0][:, -1].unique():
                n = (results.pred[0][:, -1] == c).sum()  # detections per class
                s += f"{n} {results.names[int(c)]}{'s' * (n > 1)}, "  # add to string
        return s


def main():
    rclpy.init()
    cam_subscriber = CamSubscriber()

    # Spin until ctrl + c
    rclpy.spin(cam_subscriber)

    cam_subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()