#include "ros/ros.h"
#include <iostream>
#include <stdio.h>
#include "groundserver/inputRemote.h"
#include "groundserver/statusSub.h"
#include "mavros_msgs/RCOut.h"

using namespace std;

#define MOTOR1 		0
#define MOTOR2		1
#define MOTOR3	 	2
#define MOTOR4  	3
#define SERVO		1

#define maxPWM 		1900
#define minPWM 		1200
#define middlePWM 	1500

#define maxGrip 	1900
#define minGrip 	1200

void throttleUp();
void throttleDown();

void rollUp();
void rollDown();

void yawUp();
void yawDown();

void pitchUp();
void pitchDown();

void throttleIdle();
void rollIdle();

float rovYaw, rovThrottle, rovPitch, rovRoll;
int rovArmGripOn, rovArmGripOff;
int rovStabilizeMode, rovRemoteArmed;
float a, b, c, d;
int h, i, j, k;
int l, m, n;
void checkInput();
void motorController();
void remoteCallback(const groundserver::inputRemote::ConstPtr& remote);	

groundserver::statusSub rovStatus;
mavros_msgs::RCOut rovGrip;

int main(int argc, char** argv){
	ros::init(argc, argv, "subPixhawk");
	ros::NodeHandle n;
	
	ros::Publisher pub_sub_status 	= n.advertise<groundserver::statusSub>("/rov/mode/status", 1);
	ros::Publisher pub_rov_grip 	= n.advertise<mavros_msgs::RCOut>("/mavros/rc/out", 20);
	ros::Subscriber sub_rov_remote 	= n.subscribe<groundserver::inputRemote>("/rov/input", 20, remoteCallback);
	
	while( ros::ok() ){	
		ros::spinOnce();
		
		//for(int i=0; i < 8; i++) rovRcIn.channels[i] = 0;	//Releases all Channels First
		for(int j=0; j < 8; j++) rovGrip.channels[j] = 0;
		
		if (rovThrottle > 0){throttleUp();}
		else if(rovThrottle < 0){throttleDown();}
		else{throttleIdle();}
		
		if (rovRoll > 0){rollUp();}
		else if(rovRoll < 0){rollDown();}	
		else{rollIdle();}
		
		sleep(0.1);
		
		if (rovRemoteArmed > 0){rovStatus.armDisarm = 1;}
		else if(rovRemoteArmed < 0){rovStatus.armDisarm = 2;}
		
		if(rovStabilizeMode > 0){rovStatus.mode = 3;}
		
		//pub_ardu_control.publish(arduControl);
		pub_rov_grip.publish(rovGrip);
		//pub_state_armed.publish(armedRov);
		pub_sub_status.publish(rovStatus);
	}
}

void remoteCallback(const groundserver::inputRemote::ConstPtr& remote){	
	//a	= remote->codeYaw;
	b	= remote->codeThrottle;
	//c 	= remote->codePitch;
	d 	= remote->codeRoll;
	i	= remote->codeStabilizeMode;
	k 	= remote->codeRemoteArmed;
	l	= remote->codeArmGripOn;
	m	= remote->codeArmGripOff;
	
	rovYaw				= a;
	rovThrottle			= b;
	rovPitch 			= c;
	rovRoll 			= d;
	rovStabilizeMode	= i;
	rovRemoteArmed 		= k;
	
	rovArmGripOn		= l;
	rovArmGripOff		= m;
	
	//checkInput(); 
}

void checkInput(){
	cout<<"++++++++yaw :"<<rovYaw<<"\t"<<"throttle :"<<rovThrottle<<"\t"<<"pitch :"<<rovPitch<<"\t"<<"roll :"<<rovRoll<<endl;
	cout<<"++++++++stabilize :"<<rovStabilizeMode<<"\t"<<"Armed :"<<rovRemoteArmed<<endl;
	cout<<"++++++++armGripOn :"<<rovArmGripOn<<"\t"<<"armGripOff :"<<rovArmGripOff<<endl;
	cout<<endl<<endl<<endl;
}

void throttleIdle(){
	rovGrip.channels[MOTOR1] = middlePWM;
	rovGrip.channels[MOTOR2] = middlePWM;
}

void rollIdle(){
	rovGrip.channels[MOTOR3] = middlePWM;
	rovGrip.channels[MOTOR4] = middlePWM;
}


void throttleUp(){
	rovGrip.channels[MOTOR1] = maxPWM;
	rovGrip.channels[MOTOR2] = maxPWM;
}

void throttleDown(){
	rovGrip.channels[MOTOR1] = minPWM;
	rovGrip.channels[MOTOR2] = minPWM;
}

void rollUp(){
	rovGrip.channels[MOTOR3] = maxPWM;
	rovGrip.channels[MOTOR4] = minPWM;
}

void rollDown(){
	rovGrip.channels[MOTOR3] = minPWM;
	rovGrip.channels[MOTOR4] = maxPWM;
}


