#include "ros/ros.h"
#include <ros/console.h>
#include <visualization_msgs/Marker.h>
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"	
#include "std_msgs/Int16.h"
#include <iostream>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fstream>
#include <arpa/inet.h>
#include <vector>
#include <unistd.h>
#include <string>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>
#include "std_msgs/Float64.h"
using namespace std;
using namespace cv;

void *videoCapture ( void *ptr );   
void altReceiver(const std_msgs::Float64& alt_msg);

Mat imgOriginal,imgThresholded, imgTransmit;
VideoCapture cap(0);
int exit_loop = 0;
float rel_alt = 0;

int main (int argc, char** argv)
{
	
	double dM01,dM10,dArea;
	float posX,posY;
	geometry_msgs::Point cv;
	std_msgs::Int16 fm;
	int control_hsv= 0;

	ros::init (argc, argv, "image_processing");
	ros::NodeHandle nh;  
	ros::Publisher pub_cv = nh.advertise<geometry_msgs::Point>("/krti17/cv_point", 1000);
	ros::Publisher pub_flightmode = nh.advertise<std_msgs::Int16>("/krti17/flight_mode", 1000);
	ros::Subscriber sub_rel_alt = nh.subscribe("mavros/global_position/rel_alt", 1, altReceiver );
	image_transport::ImageTransport it(nh);
	image_transport::Publisher pub_video = it.advertise("/krti17/video",100);
	nh.getParam("hsv", control_hsv);
	sensor_msgs::ImagePtr image_msg;
	
    if ( !cap.isOpened() ){  // if not success, exit program
         cout << "Cannot open the web cam" << endl;
         return -1;
    }
    
    cap.read(imgOriginal);	
		
	pthread_t video_capture;		// Thread untuk mengambil gambar
	pthread_create (&video_capture, NULL , videoCapture, NULL);	// Thread untuk membuka kamera

    int hLow=0, hHigh=255,sLow=0, sHigh=255,vLow=0,vHigh=255; // nilai atas dan bawah hsv
    
    int noise = 0;
    int holes = 0;

	// Untuk mengaktifkan trackbar yang dapat mengatur batas atas dan bawah hsv
	if(control_hsv == 1){
	namedWindow("Trackbar",WINDOW_AUTOSIZE);
	
	createTrackbar("hLow","Trackbar",&hLow,255);
	createTrackbar("hHigh","Trackbar",&hHigh,255);
	createTrackbar("sLow","Trackbar",&sLow,255);
	createTrackbar("sHigh","Trackbar",&sHigh,255);
	createTrackbar("vLow","Trackbar",&vLow,255);
	createTrackbar("vHigh","Trackbar",&vHigh,255);

    createTrackbar("removes small noise", "Object", &noise, 20);
    createTrackbar("removes small holes", "Object", &holes, 20);    
	}
	
	// Codingan tidak akan jalan jika ketinggian masih di bawah 3 ter
	while ( rel_alt < 3 && ros::ok()){
	  ros::spinOnce();
	}

	
	ROS_INFO("Starting Image Processing.");
	usleep(4000000);
	while(ros::ok()){
	
			
		image_msg = cv_bridge::CvImage(std_msgs::Header(),"bgr8", imgOriginal).toImageMsg();
		pub_video.publish(image_msg);   
	    Mat imgGray;
        cvtColor(imgOriginal, imgGray, COLOR_BGR2HSV);

        inRange(imgGray, Scalar(hLow, sLow, vLow), Scalar(hHigh, sHigh, vHigh), imgThresholded);
        
        //imshow("hasil1",imgOriginal);
        //imshow("hasil2",imgThresholded);

        if(noise > 0) {
            erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(noise, noise)) );
            dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(noise, noise)) );
        }

        if(holes > 0) {
            dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(holes, holes)) );
            erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(holes, holes)) );
        }
        
        imgTransmit = imgThresholded;
        
        // Menghitung moment dari thresholded image
		Moments oMoments = moments(imgThresholded);

		dM01 = oMoments.m01;
		dM10 = oMoments.m10;
		dArea = oMoments.m00;

		// if the area <= 10000, I consider that the there are no object in the image and it's because of the noise, the area is not zero 
		if (dArea > 0){
			// Menghitung posisi X dan posisi Y target
			posX = dM10 / dArea;
			posY = dM01 / dArea;
			if (posX >= 0 && posY >= 0){
				
			cv.x = posX;
			cv.y = posY;
			pub_cv.publish(cv);
			
			// Jika berhasil mendeteksi halogen, maka flightmode berubah ke GUIDED (1)
			fm.data = 1;
			pub_flightmode.publish(fm);
			}	
		}
		
		else {
			// Jika tidak menemukan halogen, maka flightmode berubah ke AUTO (0)
			fm.data = 0;
			pub_flightmode.publish(fm);		
		}
		
        if (waitKey(30) == 27){ //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
            cout << "esc key is pressed by user" << endl;
            break; 
		}
        
       ros::spinOnce();
	}
	exit_loop = 1;
pthread_join(video_capture, NULL);
}

 //Thread untuk melakukan pengambilan gambar
void *videoCapture ( void *ptr ){

	while(exit_loop == 0){
		
		bool bSuccess = cap.read(imgOriginal); // Membaca frame baru dari webcam

       if (!bSuccess) // Jika gagal dalam pengambilan gambar
        {
			cout << "Cannot read a frame from video stream" << endl;
			break;
       }
	}
	pthread_exit(0); 
}

void altReceiver(const std_msgs::Float64& alt_msg){

	rel_alt = alt_msg.data; // Ketinggian relatif terhadap permukaan tanah
}