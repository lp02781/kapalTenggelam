#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>

using namespace std;
using namespace cv;
void imageProcessing();
Mat image;

int thickness = 2;
int imageWidth;
int imageHeight; 
  
void imageCallback(const sensor_msgs::CompressedImageConstPtr& msg)
{
  try
  {
    image = cv::imdecode(cv::Mat(msg->data),1);//convert compressed image data to cv::Mat
    waitKey(10);
    imageProcessing();
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
 
  image_transport::ImageTransport it(nh);
  image_transport::Publisher pub = it.advertise("camera/image/grid", 1, true);
	
  ros::Subscriber sub = nh.subscribe("camera/image/compressed", 1, imageCallback);  
  
  while (nh.ok()) {
		if(!image.empty()){	
			sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();
			pub.publish(msg);
		}
		ros::spinOnce();
	}
}

void imageProcessing(){
	Size sz = image.size();
	imageWidth = sz.width;
	imageHeight = sz.height; 
  
	line( image, Point( imageWidth*1/3, 0 ), Point( imageWidth*1/3, imageHeight), Scalar( 255, 2255, 255 ),  thickness, 8 );		
	line( image, Point( imageWidth*2/3, 0 ), Point( imageWidth*2/3, imageHeight), Scalar( 255, 255, 255 ),  thickness, 8 );		
	
	line( image, Point( 0, imageHeight*1/3 ), Point( imageWidth, imageHeight*1/3), Scalar( 255, 255, 255 ),  thickness, 8 );		
	line( image, Point( 0, imageHeight*2/3 ), Point( imageWidth, imageHeight*2/3), Scalar( 255, 255, 255 ),  thickness, 8 );		
			
	imshow("pilot", image);
}
