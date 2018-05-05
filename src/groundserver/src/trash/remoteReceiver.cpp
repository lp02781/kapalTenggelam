#include "ros/ros.h"
#include <iostream>
#include <stdio.h>
#include "groundserver/inputRemote.h"
#include "groundserver/arduinoInput.h"

using namespace std;

float rovYaw, rovThrottle, rovPitch, rovRoll;
int rovStabilizeMode, rovRemoteArmed;
int rovArmGripOn, rovArmGripOff;
float a, b, c, d;
int h, i, j, k;
int l, m;
void checkInput();
void remoteCallback(const groundserver::inputRemote::ConstPtr& remote);	

groundserver::arduinoInput arduRemote;

int main(int argc, char** argv){
	ros::init(argc, argv, "subPixhawk");
	ros::NodeHandle n;
	
	ros::Publisher pub_ardu_rc 	= n.advertise<groundserver::arduinoInput>("/rov/ardu/input", 20);
	ros::Subscriber sub_rov_remote 	= n.subscribe<groundserver::inputRemote>("/rov/input", 20, remoteCallback);
	
	while( ros::ok() ){	
		ros::spinOnce();
		
		arduRemote.arduYaw 				= rovYaw;
		arduRemote.arduThrottle 		= rovThrottle;
		arduRemote.arduPitch 			= rovPitch;
		arduRemote.arduRoll 			= rovRoll;
		arduRemote.arduStabilizeMode 	= rovStabilizeMode;
		arduRemote.arduRemoteArmed 		= rovRemoteArmed;
		arduRemote.arduArmGripOff 		= rovArmGripOff;
		arduRemote.arduArmGripOn 		= rovArmGripOn;
		
		pub_ardu_rc.publish(arduRemote);	
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
