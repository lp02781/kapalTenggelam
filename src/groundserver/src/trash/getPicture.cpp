#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>

using namespace cv;

Mat image;

int main(int argc, char** argv)
{
	ros::init(argc, argv, "videoFront");
	ros::NodeHandle nh;
	image_transport::ImageTransport it(nh);
	image_transport::Publisher pub = it.advertise("camera/image", 1, true);

	//cv::Mat image = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);
	VideoCapture cap(0); 
	//cap.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	//cap.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
	//sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();
	if(!cap.isOpened()){
		ROS_ERROR ("Error opening camera.");	  
		return 1;
	}
	//ros::Rate loop_rate(5);
	while (nh.ok()) {
		cap.read(image);
		if(!image.empty()){	
			sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();
			pub.publish(msg);
		}
		ros::spinOnce();
		//loop_rate.sleep();
	}
}
