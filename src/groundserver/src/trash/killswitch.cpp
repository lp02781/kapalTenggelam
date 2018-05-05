#include <iostream>
#include <stdio.h>
#include <std_msgs/String.h>
#include <std_msgs/Int16.h>
#include "mavros_msgs/State.h"
#include <ros/ros.h>

char keys;

void drone_killswitchCB						(const std_msgs::String& msg);

using namespace std;

std_msgs::String drone_killswitch;
std_msgs::String drone_killswitch_feedback;

int main( int argc, char** argv )
{
	ros::init(argc, argv, "killswitch");
	ros::NodeHandle nh;

	ros::Publisher pub_drone_killswitch 	= nh.advertise<std_msgs::String>("/auvsi17/drone/killswitch", 16,true);
	ros::Subscriber sub_drone_killswitch = nh.subscribe("/auvsi17/drone/killswitch", 10, drone_killswitchCB);

	cout<< "enter keys" << endl;
	cin >> keys ;
	
	if(keys == 'q')
	{
		drone_killswitch_feedback.data = "1";
		pub_drone_killswitch.publish(drone_killswitch_feedback);
	}
	
	else 
	{
		drone_killswitch_feedback.data = "2";
		pub_drone_killswitch.publish(drone_killswitch_feedback);
	}
		
	ros::shutdown();
	
}

void drone_killswitchCB(const std_msgs::String& msg)
{
	drone_killswitch.data = msg.data;
}
