#include "ros/ros.h"
#include "mavros_msgs/OverrideRCIn.h"
#include <iostream>
#include <stdio.h>
#include "groundserver/statusSub.h"
#include <std_msgs/Int16.h>
#include "groundserver/inputRemote.h"

using namespace std;

#define PITCH 		1
#define ROLL 		0
#define THROTTLE 	2
#define YAW  		3
#define SERVO		5

#define maxPitch 	1700
#define maxRoll  	1700
#define maxThrottle 1700
#define maxYaw 		1700

#define minPitch 	1100
#define minRoll 	1100
#define minThrottle 1100
#define minYaw 		1100

#define middlePitch  	1320
#define middleRoll  	1320
#define middleThrottle  1350
#define middleYaw  		1520

float pwmServo =	1520;
float maxServo =	1700;
float minServo =	1200;

float rovYaw, rovThrottle, rovPitch, rovRoll;
int rovStabilizeMode, rovRemoteArmed;
int rovArmGripOn, rovArmGripOff;
float a, b, c, d;
int h, i, j, k;
int l, m;
int tempPwm;
bool lastArmed = false;
bool tempArmed = false;
void checkInput();
void motorController();

void remoteCallback(const groundserver::inputRemote::ConstPtr& remote);	
//void arduCb(const std_msgs::String::ConstPtr& ardu);	

mavros_msgs::OverrideRCIn rovRcIn;
groundserver::statusSub rovStatus;

int main(int argc, char** argv){
	ros::init(argc, argv, "subPixhawk");
	ros::NodeHandle n;
	
	ros::Publisher pub_override_rc 	= n.advertise<mavros_msgs::OverrideRCIn>("/mavros/rc/override", 20);
	ros::Publisher pub_sub_status 	= n.advertise<groundserver::statusSub>("/rov/mode/status", 1);
	
	ros::Subscriber sub_rov_remote 	= n.subscribe<groundserver::inputRemote>("/rov/input", 20, remoteCallback);
	
	while( ros::ok() ){	
		ros::spinOnce();
		
		for(int i=0; i < 8; i++) rovRcIn.channels[i] = 0;	//Releases all Channels First
		//for(int j=0; j < 8; j++) rovGrip.channels[j] = 0;
		
		//up or down
		if (rovPitch > 0){
			rovRcIn.channels[PITCH] = middlePitch;
			rovRcIn.channels[YAW] = middleYaw;
		}
		else if (rovPitch < 0){
			rovRcIn.channels[PITCH] = minPitch;
			rovRcIn.channels[YAW] = minYaw;
		}
		else {
			rovRcIn.channels[PITCH] = minPitch;
			rovRcIn.channels[YAW] = minYaw;
		}
	
		//steering
		if (rovRoll > 0){rovRcIn.channels[ROLL] = maxRoll;}
		else if (rovRoll < 0){rovRcIn.channels[ROLL] = minRoll;}
		else {rovRcIn.channels[ROLL] = middleRoll;}
	
		//throttle
		if (rovThrottle > 0){rovRcIn.channels[THROTTLE] = middleThrottle;}
		else if (rovThrottle < 0){rovRcIn.channels[THROTTLE] = minThrottle;}
		else {rovRcIn.channels[THROTTLE] = minThrottle;}
		
		sleep(0.1);
		
		if (rovRemoteArmed > 0){
			lastArmed = true;
			tempArmed = lastArmed;
		}
		else if(rovRemoteArmed < 0){
			lastArmed = false;
			tempArmed = lastArmed;
		}
		else{lastArmed =  tempArmed;}
		
		if (rovArmGripOn > 0){
			//rovRcIn.channels[SERVO] = pwmServo + 100;
			pwmServo = pwmServo + 0.1;
			tempPwm = pwmServo;
			if(pwmServo > maxServo){pwmServo = maxServo;}
		}
		else if(rovArmGripOff > 0){ 
			//rovRcIn.channels[SERVO] = pwmServo - 100;
			pwmServo = pwmServo - 0.1;
			tempPwm = pwmServo;
			if(pwmServo < minServo){pwmServo = minServo;}
		}
		else{
			//rovRcIn.channels[SERVO] = pwmServo + 0;
			pwmServo = pwmServo + 0;
		}
		
		if(rovStabilizeMode > 0){rovStatus.mode = 3;}
		
		rovRcIn.channels[SERVO] = pwmServo;
		rovStatus.armDisarm = lastArmed; 
		
		pub_sub_status.publish(rovStatus);
		pub_override_rc.publish(rovRcIn);	
	}
}

void remoteCallback(const groundserver::inputRemote::ConstPtr& remote){	
	a	= remote->codeYaw;
	b	= remote->codeThrottle;
	c 	= remote->codePitch;
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
	cout<<"++++++++armGripOn :"<<rovArmGripOn<<"\t"<<"armGripOff :"<<rovArmGripOff<<"\t"<<endl;
	cout<<endl<<endl<<endl;
}

