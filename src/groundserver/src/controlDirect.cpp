#include "ros/ros.h"
#include "mavros_msgs/OverrideRCIn.h"
#include <iostream>
#include <stdio.h>
#include "groundserver/statusSub.h"
#include <sensor_msgs/Joy.h>

using namespace std;

#define PITCH 		1
#define ROLL 		0
#define THROTTLE 	2
#define YAW  		3
#define SERVO		5
#define SERVO1		4
#define SERVO2		6

#define maxPitch 	1620
#define maxRoll  	1720
#define maxThrottle 1720
#define maxYaw 		1620

#define minPitch 	1120
#define minRoll 	1320
#define minThrottle 1120
#define minYaw 		1120

#define middlePitch  	1520
#define middleRoll  	1520
#define middleThrottle  1520
#define middleYaw  		1520

float pwmServo =	1500;
float maxServo =	1900;
float minServo =	1100;

float rovYaw, rovThrottle, rovPitch, rovRoll;
int rovStabilizeMode, rovRemoteArmed;
int rovArmGripOn, rovArmGripOff;
int a, b, c, d;
int h, i, j, k;
int l, m;
int tempPwm;
bool lastArmed = false;
bool tempArmed = false;
	
void joyCallback(const sensor_msgs::Joy::ConstPtr& joy);

mavros_msgs::OverrideRCIn rovRcIn;
groundserver::statusSub rovStatus;

int main(int argc, char** argv){
	ros::init(argc, argv, "subPixhawk");
	ros::NodeHandle n;
	
	ros::Publisher pub_override_rc 	= n.advertise<mavros_msgs::OverrideRCIn>("/mavros/rc/override", 8);
	ros::Publisher pub_sub_status 	= n.advertise<groundserver::statusSub>("/rov/mode/status", 1);
	ros::Subscriber joy_sub 		= n.subscribe<sensor_msgs::Joy>("joy", 8, &joyCallback);
		
	while( ros::ok() ){	
		ros::spinOnce();
		
		for(int i=0; i < 8; i++) rovRcIn.channels[i] = 0;	//Releases all Channels First
		
		//up 
		if (rovPitch > 0){
			rovRcIn.channels[PITCH] = minPitch;
			rovRcIn.channels[YAW] = minYaw;
		}
		//down
		else if (rovPitch < 0){
			rovRcIn.channels[PITCH] = maxPitch;
			rovRcIn.channels[YAW] = maxYaw;
		}
		else {
			rovRcIn.channels[PITCH] = middlePitch;
			rovRcIn.channels[YAW] = middleYaw;
		}
	
		//steering
		if (rovRoll > 0){rovRcIn.channels[ROLL] = maxRoll;}//right
		else if (rovRoll < 0){rovRcIn.channels[ROLL] = minRoll;}//left
		else {rovRcIn.channels[ROLL] = middleRoll;}
	
		//throttle
		if (rovThrottle > 0){rovRcIn.channels[THROTTLE] = maxThrottle;}
		else if (rovThrottle < 0){rovRcIn.channels[THROTTLE] = minThrottle;}
		else {rovRcIn.channels[THROTTLE] = middleThrottle;}
		
		sleep(0.2);
		
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
		rovRcIn.channels[SERVO1] = pwmServo;
		rovRcIn.channels[SERVO2] = pwmServo;
		rovStatus.armDisarm = lastArmed; 
	
		pub_sub_status.publish(rovStatus);
		pub_override_rc.publish(rovRcIn);	
	}
}

void joyCallback(const sensor_msgs::Joy::ConstPtr& joy){	
	a	= joy->axes[0];
	b	= joy->axes[1];
	c 	= joy->axes[2];
	d 	= joy->axes[3];
	i	= joy->buttons[2];
	k 	= joy->axes[4];
	l	= joy->buttons[5];
	m	= joy->buttons[7];
	
	
	rovYaw				= a;
	rovThrottle			= b;
	rovPitch 			= c;
	rovRoll 			= d;
	rovStabilizeMode	= i;
	rovRemoteArmed 		= k;
	
	rovArmGripOn		= m;
	rovArmGripOff		= l; 

	/*use itech
	  rovThrottle d;
	  rovRoll c;
	 */ 
}

/*
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
}
*/
