#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <cv_bridge/cv_bridge.h>
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

int redLowH 	= 170;
int redHighH 	= 179;
int blueLowH 	= 75;
int blueHighH 	= 130;
int yellowLowH 	= 22;
int yellowHighH = 38;
int iLowS 		= 150; 
int iHighS 		= 255;
int iLowV 		= 60;
int iHighV 		= 255;
int redIndex, blueIndex, yellowIndex;
int redX = 0; 
int redY = 0; 
int blueX = 0; 
int blueY = 0; 
int yellowX = 0; 
int yellowY = 0;
int textX = 450;
int textY = 30;
double redArea, blueArea, yellowArea;
bool bSuccess;

string redTriangle 		= "RED TRIANGLE";
string redTrapesium 	= "RED TRAPESIUM";
string blueTriangle 	= "BLUE TRIANGLE";
string blueTrapesium 	= "BLUE TRAPESIUM";
string yellowTriangle 	= "YELLOW TRIANGLE";
string yellowTrapesium 	= "YELLOW TRAPESIUM";

Moments redMoments, blueMoments, yellowMoments;
vector<Point> redApprox, blueApprox, yellowApprox;
		
Mat Original, imgHSV, allColour, allContour; 
Mat redThreshold, blueThreshold, yellowThreshold;
Mat redBW, yellowBW, blueBW;

void imageProcessing();

void imageCallback(const sensor_msgs::CompressedImageConstPtr& msg)
{
  try
  {
    Original = cv::imdecode(cv::Mat(msg->data),1);//convert compressed image data to cv::Mat
    waitKey(10);
    imageProcessing();
    
  }
  catch (cv_bridge::Exception& e)
  {
    ROS_ERROR("Could not convert to image!");
  }
}

int main(int argc, char **argv){
	ros::init(argc, argv, "videoRec");
	ros::NodeHandle nh;
	//cv::namedWindow("view");
	cv::startWindowThread();
	image_transport::ImageTransport it(nh);
	image_transport::Publisher pub = it.advertise("camera/ground", 1, true);
	ros::Subscriber sub = nh.subscribe("camera/image/compressed", 1, imageCallback);
	
	namedWindow("setting", CV_WINDOW_AUTOSIZE);//nama window
	createTrackbar("redHighH", "setting", &redHighH, 255);
	createTrackbar("redLowH", "setting", &redLowH, 255);
	createTrackbar("blueHighH", "setting", &blueHighH, 255);
	createTrackbar("blueLowH", "setting", &blueLowH, 255);
	createTrackbar("yellowHighH", "setting", &yellowHighH, 255);
	createTrackbar("yellowLowH", "setting", &yellowLowH, 255);
	
	createTrackbar("iHighS", "setting", &iHighS, 255);
	createTrackbar("iLowS", "setting", &iLowS, 255);
	createTrackbar("iHighV", "setting", &iHighV, 255);
	createTrackbar("iLowV", "setting", &iLowV, 255);
	
	createTrackbar("x", "setting", &textX, 500);
	createTrackbar("y", "setting", &textY, 500);
	
	ros::spin();
	sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", Original).toImageMsg();
	pub.publish(msg);
}

void imageProcessing(){
	
	cvtColor(Original, imgHSV, COLOR_BGR2HSV);
			
	erode(imgHSV, imgHSV, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
	dilate( imgHSV, imgHSV, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 

	dilate( imgHSV, imgHSV, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 
	erode(imgHSV, imgHSV, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
		
	inRange(imgHSV, Scalar(redLowH, iLowS, iLowV), Scalar(redHighH, iHighS, iHighV), redThreshold); //Threshold the image
	inRange(imgHSV, Scalar(blueLowH, iLowS, iLowV), Scalar(blueHighH, iHighS, iHighV), blueThreshold); //Threshold the image
	inRange(imgHSV, Scalar(yellowLowH, iLowS, iLowV), Scalar(yellowHighH, iHighS, iHighV), yellowThreshold); //Threshold the image
		
	Canny(redThreshold, redBW, 0, 50, 5);
	Canny(blueThreshold, blueBW, 0, 50, 5);	
	Canny(yellowThreshold, yellowBW, 0, 50, 5);
		
	vector<vector<Point> > redContours;
	vector<vector<Point> > yellowContours;
	vector<vector<Point> > blueContours;
		
	findContours(redBW, redContours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);
	findContours(blueBW, blueContours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);
	findContours(yellowBW, yellowContours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);
		
	for (redIndex = 0; redIndex < redContours.size(); redIndex++){
		approxPolyDP(Mat(redContours[redIndex]), redApprox, arcLength(Mat(redContours[redIndex]), true)*0.02, true);
		
		if (fabs(contourArea(redContours[redIndex])) < 5000 || !isContourConvex(redApprox))
		continue;

		if (redApprox.size() == 3){
			redMoments = moments(redBW);
			redArea = redMoments.m00;  
			redX = redMoments.m10/redArea;
			redY = redMoments.m01/redArea;
			circle( Original, Point(redX, redY), 10, Scalar( 0, 0, 255 ), 2);//red circle
			rectangle(Original,Rect(redX-50,redY-50,100,100),Scalar(0,0,255),3,8,0);
			putText(Original, redTriangle, Point(textX,textY), FONT_HERSHEY_DUPLEX, 1, Scalar(0,0,255), 2);
			//cout<<"red X = "<<redX<<"\t\t"<<"red Y = "<<blueY<<endl;
		}
		
		if (redApprox.size() == 4){
			redMoments = moments(redBW);
			redArea = redMoments.m00;  
			redX = redMoments.m10/redArea;
			redY = redMoments.m01/redArea;
			circle( Original, Point(redX, redY), 10, Scalar( 0, 0, 255 ), 2);//red circle
			rectangle(Original,Rect(redX-50,redY-50,100,100),Scalar(0,0,255),3,8,0);
			putText(Original, redTrapesium, Point(textX,textY), FONT_HERSHEY_DUPLEX, 1, Scalar(0,0,255), 2);
			//cout<<"red X = "<<redX<<"\t\t"<<"red Y = "<<blueY<<endl;
		}
		else{
			redX = 0;
			redY = 0;
			//cout<<"red triangle not found"<<endl;
		}
	}
		
	for (blueIndex = 0; blueIndex < blueContours.size(); blueIndex++){
		approxPolyDP(Mat(blueContours[blueIndex]), blueApprox, arcLength(Mat(blueContours[blueIndex]), true)*0.02, true);

		if (fabs(contourArea(blueContours[blueIndex])) < 5000 || !isContourConvex(blueApprox))
		continue;

		if (blueApprox.size() == 3){
			blueMoments = moments(blueBW);
			blueArea = blueMoments.m00; 
			blueX = blueMoments.m10/blueArea;
			blueY = blueMoments.m01/blueArea;
			circle( Original, Point(blueX, blueY), 10, Scalar( 255, 0, 0 ), 2);//yellow circle      
			rectangle(Original,Rect(blueX-50,blueY-50,100,100),Scalar(255,0,0),3,8,0);
			putText(Original, blueTriangle, Point(textX, textY), FONT_HERSHEY_DUPLEX, 1, Scalar(255,255,0), 2);
			//cout<<"blue X = "<<blueX<<"\t\t"<<"blue Y = "<<blueY<<endl;
		}
		
		else if (blueApprox.size() == 4){
			blueMoments = moments(blueBW);
			blueArea = blueMoments.m00; 
			blueX = blueMoments.m10/blueArea;
			blueY = blueMoments.m01/blueArea;
			circle( Original, Point(blueX, blueY), 10, Scalar( 255, 0, 0 ), 2);//yellow circle      
			rectangle(Original,Rect(blueX-50,blueY-50,100,100),Scalar(255,0,0),3,8,0);
			putText(Original, blueTrapesium, Point(blueX+50,blueY+50), FONT_HERSHEY_DUPLEX, 1, Scalar(255,255,0), 2);
			//cout<<"blue X = "<<blueX<<"\t\t"<<"blue Y = "<<blueY<<endl;
		}
		
		else{
			blueX = 0;
			blueY = 0;
			//cout<<"blue triangle not found"<<endl;
		}
	}
		
	for (yellowIndex = 0; yellowIndex < yellowContours.size(); yellowIndex++)
	{
		approxPolyDP(Mat(yellowContours[yellowIndex]), yellowApprox, arcLength(Mat(yellowContours[yellowIndex]), true)*0.02, true);

		if (fabs(contourArea(yellowContours[yellowIndex])) < 5000 || !isContourConvex(yellowApprox))
		continue;

		if (yellowApprox.size() == 3){
			yellowMoments = moments(yellowBW);
			yellowArea = yellowMoments.m00;
			yellowX = yellowMoments.m10/yellowArea;
			yellowY = yellowMoments.m01/yellowArea;
			circle( Original, Point(yellowX, yellowY), 10, Scalar( 0, 255, 255 ), 2);//yellow circle
			rectangle(Original,Rect(yellowX-50,yellowY-50,100,100),Scalar(0,255,255),3,8,0);
			putText(Original, yellowTriangle, Point(yellowX+50,yellowY+50), FONT_HERSHEY_DUPLEX, 1, Scalar(0,255,255), 2);
			//cout<<"yellow X = "<<yellowX<<"\t\t"<<"yellow Y = "<<yellowY<<endl;
		}
		
		else if (yellowApprox.size() == 4){
			yellowMoments = moments(yellowBW);
			yellowArea = yellowMoments.m00;
			yellowX = yellowMoments.m10/yellowArea;
			yellowY = yellowMoments.m01/yellowArea;
			circle( Original, Point(yellowX, yellowY), 10, Scalar( 0, 255, 255 ), 2);//yellow circle
			rectangle(Original,Rect(yellowX-50,yellowY-50,100,100),Scalar(0,255,255),3,8,0);
			putText(Original, yellowTrapesium, Point(yellowX+50,yellowY+50), FONT_HERSHEY_DUPLEX, 1, Scalar(0,255,255), 2);
			//cout<<"yellow X = "<<yellowX<<"\t\t"<<"yellow Y = "<<yellowY<<endl;
		}
		
		else{
			yellowX = 0;
			yellowY = 0;
			//cout<<"yellow triangle not found"<<endl;
		}
	}
}

