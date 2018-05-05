#include "ros/ros.h"
#include <iostream>
#include <stdio.h>
#include "std_msgs/Float32.h"

using namespace std;

float rovSteering, rovThrottle, rovAltitude, rovServoGrip;

std_msgs::Float32 throttle;
std_msgs::Float32 steering;
std_msgs::Float32 altitude;
std_msgs::Float32 gripServo;

int main(int argc, char** argv){
	ros::init(argc, argv, "receiverUsbIp");
	ros::NodeHandle n;
	
	ros::Publisher pub_ardu_throttle 	= n.advertise<std_msgs::Float32>("/rov/usb/throttle", 8);
	ros::Publisher pub_ardu_steering 	= n.advertise<std_msgs::Float32>("/rov/usb/steering", 8);
	ros::Publisher pub_ardu_altitude 	= n.advertise<std_msgs::Float32>("/rov/usb/altitude", 8);
	ros::Publisher pub_ardu_gripServo 	= n.advertise<std_msgs::Float32>("/rov/usb/gripServo", 8);
	
	while( ros::ok() ){	
		ros::spinOnce();
		
		throttle.data = rovThrottle;
		steering.data = rovSteering;
		altitude.data = rovAltitude;
		gripServo.data = rovServoGrip;
		
		pub_ardu_throttle.publish(throttle);
		pub_ardu_steering.publish(steering);
		pub_ardu_altitude.publish(altitude);
		pub_ardu_gripServo.publish(gripServo);	
	}
}
