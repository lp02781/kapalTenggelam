#include "ros/ros.h"
#include "mavros_msgs/SetMode.h"
#include "mavros_msgs/State.h"
#include <iostream>
#include <stdio.h>
#include "groundserver/statusSub.h"

using namespace std;

void statusCallback(const groundserver::statusSub::ConstPtr& subStatus);	

int rovArmed = 2;
int rovMode = 0;

mavros_msgs::State armedRov;
mavros_msgs::SetMode flight;

int main(int argc, char** argv){
	ros::init(argc, argv, "subPixhawk");
	ros::NodeHandle n;
	
	ros::Publisher pub_state_armed 	= n.advertise<mavros_msgs::State>("/mavros/state", 20);
	ros::Subscriber sub_rov_remote 	= n.subscribe<groundserver::statusSub>("/rov/mode/status", 1, statusCallback);
	ros::ServiceClient client 		= n.serviceClient<mavros_msgs::SetMode>("/mavros/set_mode");

	while( ros::ok() ){	
		ros::spinOnce();
		
		if (rovArmed = true){
			system("rosrun mavros mavsafety arm");
			//ROS_INFO("true");
			//flight.request.base_mode = 0;
			//flight.request.custom_mode = "STABILIZE";
			//flight.request.custom_mode = "GUIDED";
			//flight.request.custom_mode = "MANUAL";
			
			//flight.request.base_mode = 192;
			
			//client.call(flight);
			
			//flight.request.MAV_MODE_STABILIZE_ARMED = 208;
			//flight.request.MAV_MODE_MANUAL_ARMED = 192;
			
		}
		
		else if(rovArmed = false){
			//system("rosrun mavros mavsafety disarm");
			//ROS_INFO("false");
			//flight.request.base_mode = 0;
			
			//flight.request.custom_mode = "STABILIZE";
			//flight.request.custom_mode = "GUIDED";
			//flight.request.custom_mode = "MANUAL";
			
			//flight.request.base_mode = 64;
			
			//client.call(flight);
			
			//flight.request.MAV_MODE_STABILIZE_DISARMED = 80;
			//flight.request.MAV_MODE_MANUAL_DISARMED = 64;
		}
		
		
		if(rovMode = 3){
			
			//flight.request.base_mode = 192;
			//ROS_INFO("ya");
			flight.request.base_mode = 0;
			//flight.request.custom_mode = "STABILIZE";
			flight.request.custom_mode = "MANUAL";
			client.call(flight);
		}
		
		//cout<<rovMode<<"\t"<<rovArmed<<endl;
		
		pub_state_armed.publish(armedRov);
	}
}

void statusCallback(const groundserver::statusSub::ConstPtr& subStatus){
	rovMode = subStatus->mode;
	rovArmed = subStatus->armDisarm;
}	
