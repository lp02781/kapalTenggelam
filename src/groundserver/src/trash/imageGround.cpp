#include <ros/ros.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>

using namespace std;
using namespace cv;

void imageCallback(const sensor_msgs::CompressedImageConstPtr& msg)
{
  try
  {
    Mat image = cv::imdecode(cv::Mat(msg->data),1);//convert compressed image data to cv::Mat
    imshow("view", image);

    waitKey(10);
  }
  catch (cv_bridge::Exception& e)
  {
    ROS_ERROR("Could not convert to image!");
  }
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "image_listener");
  ros::NodeHandle nh;
  namedWindow("view");
  startWindowThread();
  ros::Subscriber sub = nh.subscribe("camera/image/compressed", 1, imageCallback);
  ros::spin();
  destroyWindow("view");
}
