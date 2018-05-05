#include <iostream>
#include <stdio.h>
#include <std_msgs/Int16.h>
#include <ros/ros.h>

using namespace std;

std_msgs::Int16 number;
int index = 1;
void callback(const std_msgs::String::ConstPtr& msg);

int main( int argc, char** argv ){
	ros::init(argc, argv, "serialPublish");
	ros::NodeHandle nh;

	ros::Publisher pub_pc 	= nh.advertise<std_msgs::String>("talk", 16);
	ros::Subscriber sub_pc 	= nh.subscribe<std_msgs::String>("listen", 16, callback);
	
	while( ros::ok() ){	
		
		ros::spinOnce();
		
		number.data = index;
	
		sleep(1);
		pub_pc.publish(number);
	} 
}

void callback(const std_msgs::String::ConstPtr& msg){
	index = msg.data; 
}
