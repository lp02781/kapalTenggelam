#include <iostream>
#include <stdio.h>
#include <std_msgs/String.h>
#include <std_msgs/Int16.h>
#include "mavros_msgs/State.h"
#include <ros/ros.h>

void messageCB						(const std_msgs::String& msg);

using namespace std;

std_msgs::String receiver;
std_msgs::String feedback;

int main( int argc, char** argv )
{
	ros::init(argc, argv, "testArduino");
	ros::NodeHandle nh;

	ros::Publisher 	pub_pc 	= nh.advertise<std_msgs::String>("pc", 16,true);
	ros::Subscriber sub_pc 	= nh.subscribe("ardu", 10, messageCB);
	
	while( ros::ok() ){
		ros::spinOnce();
		cout<<receiver.data<<endl;
		feedback.data = "dari pc";
		pub_pc.publish(feedback);	
		sleep(1);
	}
}

void messageCB(const std_msgs::String& msg)
{
	receiver.data = msg.data;
}
