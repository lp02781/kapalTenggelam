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
	image_transport::Publisher pub = it.advertise("/camera/image", 1, true);

	VideoCapture cap(0); 
	cap.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	cap.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
	if(!cap.isOpened()){
		ROS_ERROR ("Error opening camera.");	  
		return 1;
	}
	while (nh.ok()) {
		cap.read(image);
		if(!image.empty()){
			Mat dst;//dst image
			Size size(200,200);//the dst image size,e.g.100x100
			//resize(image,dst,size);//resize image
			
			resize(image, dst, size, 0, 0, INTER_LANCZOS4);
			
			sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "mono8", dst).toImageMsg();
			pub.publish(msg);
		}
		ros::spinOnce();
	}
}


