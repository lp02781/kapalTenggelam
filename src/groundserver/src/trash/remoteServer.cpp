#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <iostream>
#include <stdio.h>
#include <std_msgs/String.h>
#include <std_msgs/Int16.h>
//#include "groundserver/inputRemote.h"
#include "mavros_msgs/State.h"
#include <std_msgs/Float32.h>

using namespace std;

float a, b, c, d, e, f;
float remoteYaw, remoteThrottle, remotePitch, remoteRoll;
int g, h, i, j, k, l, m, n, o, p, q;
int remoteArmGripOn, remoteArmGripOff;
int remoteStabilizeMode;
int remoteArmed, remoteDisarmed;

void checkController();
void joyCallback(const sensor_msgs::Joy::ConstPtr& joy);

//groundserver::inputRemote inputRov;
std_msgs::Float32 throttle;
std_msgs::Float32 steering;
std_msgs::Float32 altitude;
std_msgs::Int16 gripOn;
std_msgs::Int16 gripOff;
std_msgs::Int16 armed;
std_msgs::Int16 stabilize;


int main(int argc, char** argv){
	ros::init(argc, argv, "remoteServer");
	ros::NodeHandle nh;
	
	//ros::Publisher pub_input_server	= nh.advertise<groundserver::inputRemote>("/rov/input", 20);
	ros::Publisher pub_input_throttle	= nh.advertise<std_msgs::Float32>("/rov/input/throttle", 1);
	ros::Publisher pub_input_steering	= nh.advertise<std_msgs::Float32>("/rov/input/steering", 1);
	ros::Publisher pub_input_altitude	= nh.advertise<std_msgs::Float32>("/rov/input/altitude", 1);
	ros::Publisher pub_input_gripOn		= nh.advertise<std_msgs::Int16>("/rov/input/gripOn", 1);
	ros::Publisher pub_input_gripOff	= nh.advertise<std_msgs::Int16>("/rov/input/gripOff", 1);
	ros::Publisher pub_input_armed		= nh.advertise<std_msgs::Int16>("/rov/input/armed", 1);
	ros::Publisher pub_input_stabilize	= nh.advertise<std_msgs::Int16>("/rov/input/stabilize", 1);
	ros::Subscriber joy_sub 			= nh.subscribe<sensor_msgs::Joy>("joy", 20, &joyCallback);
	
	while( ros::ok() ){
		ros::spinOnce();
		/*
		inputRov.codeYaw 			= remoteYaw;
		inputRov.codeThrottle 		= remoteThrottle;
		inputRov.codePitch 			= remotePitch;
		inputRov.codeRoll 			= remoteRoll;
		inputRov.codeArmGripOn 		= remoteArmGripOn;
		inputRov.codeArmGripOff 	= remoteArmGripOff;
		inputRov.codeStabilizeMode 	= remoteStabilizeMode;
		inputRov.codeRemoteArmed	= remoteArmed;
		
		pub_input_server.publish(inputRov);
		*/
		
		throttle.data 	= remoteThrottle;
		steering.data 	= remoteRoll;
		altitude.data 	= remotePitch;
		gripOn.data 	= remoteArmGripOn;
		gripOff.data 	= remoteArmGripOff;
		armed.data 	= remoteArmed;
		stabilize.data 	= remoteStabilizeMode;
		
		
		pub_input_throttle.publish(throttle);
		pub_input_steering.publish(steering);
		pub_input_altitude.publish(altitude);
		pub_input_gripOn.publish(gripOn);
		pub_input_gripOff.publish(gripOff);
		pub_input_armed.publish(armed);
		pub_input_stabilize.publish(stabilize);
	}
}
 

void joyCallback(const sensor_msgs::Joy::ConstPtr& joy)	{	
	a = joy->axes[0];		//-1	<	right left 	<	0	<	left left	<	1
    b = joy->axes[1];		//-1	<	down left	<	0	<	up left		<	1
    c = joy->axes[2];		//-1 	< 	down right	<	0	<	up right	<	1
    d = joy->axes[3];		//-1 	< 	right right < 	0 	< 	left right 	< 	1
    e = joy->axes[4];		//-1 	< 	right 		< 	0 	< 	left 		< 	1
    f = joy->axes[5];		//-1 	< 	down		<	0	<	up			<	1
    g = joy->buttons[0];	//triangle
    h = joy->buttons[1];	//circle
    i = joy->buttons[2];	//cross
    j = joy->buttons[3];	//square
    k = joy->buttons[4];	//l1
    l = joy->buttons[5];	//r1
    m = joy->buttons[6];	//l2
    n = joy->buttons[7];	//r2
  
    remoteYaw 			= a;
    remoteThrottle 		= b;
    remotePitch 		= c;
    remoteRoll	 		= d;
    remoteArmGripOn 	= l;
    remoteArmGripOff	= n;
    remoteStabilizeMode = i; 
    remoteArmed			= e;
    
	//checkController();
}

void checkController(){	
	cout<<"++++++++yaw :"<<remoteYaw<<"\t"<<"throttle :"<<remoteThrottle<<"\t"<<"pitch :"<<remotePitch<<"\t"<<"roll :"<<remoteRoll<<endl;
	cout<<"++++++++armGripOn :"<<remoteArmGripOn<<"\t"<<"armGripOff :"<<remoteArmGripOff<<"\t"<<"armedOn :"<<remoteArmed<<endl;
	cout<<"++++++++stabilizeMode :"<<remoteStabilizeMode<<endl;
	cout<<endl<<endl<<endl;
}

