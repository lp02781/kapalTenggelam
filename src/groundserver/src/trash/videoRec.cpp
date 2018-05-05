#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <cv_bridge/cv_bridge.h>
#include <iostream>
#include <stdio.h>

using namespace cv;

Mat front_image;

void imageCallback(const sensor_msgs::ImageConstPtr& msg)
{
  try
  {	
	//cv::imshow("view", cv_bridge::toCvShare(msg, "bgr8")->image);
    cv::waitKey(10);
	front_image  = cv_bridge::toCvCopy(msg, "bgr8")->image;
	imshow("Original",front_image);
  }
  catch (cv_bridge::Exception& e)
  {
    ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
  }
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "videoRec");
  ros::NodeHandle nh;
  //cv::namedWindow("view");
  cv::startWindowThread();
  image_transport::ImageTransport it(nh);
  image_transport::Subscriber sub = it.subscribe("camera/image", 1, imageCallback);
  ros::spin();
  //cv::destroyWindow("view");
   /* while (ros::ok())
    {
		ros::spinOnce();
		imshow("Original", front_image); 
	}*/  
}
