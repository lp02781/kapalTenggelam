#include "ros/ros.h"
#include "mavros_msgs/OverrideRCIn.h"
#include <iostream>
#include <stdio.h>
#include "groundserver/statusSub.h"
#include <std_msgs/Int16.h>
#include <std_msgs/Float32.h>
//#include "groundserver/inputRemote.h"
//#include <std_msgs/String.h>
//#include "groundserver/arduinoInput.h"
//z#include "mavros_msgs/SetMode.h"
//#include "mavros_msgs/State.h"
//#include "mavros_msgs/RCOut.h"

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
#define middleRoll  	1520
#define middleThrottle  1350
#define middleYaw  		1320

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

void throttleCallback(const std_msgs::Float32::ConstPtr& msg);
void steeringCallback(const std_msgs::Float32::ConstPtr& msg);
void altitudeCallback(const std_msgs::Float32::ConstPtr& msg);
void gripOnCallback(const std_msgs::Int16::ConstPtr& msg);
void gripOffCallback(const std_msgs::Int16::ConstPtr& msg);
void stabilizeCallback(const std_msgs::Int16::ConstPtr& msg);
void armedCallback(const std_msgs::Int16::ConstPtr& msg);

//void remoteCallback(const groundserver::inputRemote::ConstPtr& remote);	
//void arduCb(const std_msgs::String::ConstPtr& ardu);	

mavros_msgs::OverrideRCIn rovRcIn;
groundserver::statusSub rovStatus;
//mavros_msgs::RCOut rovGrip;
//mavros_msgs::State armedRov;
//mavros_msgs::SetMode flight;
//groundserver::arduinoInput arduControl;
//std_msgs::String arduFeedback;

int main(int argc, char** argv){
	ros::init(argc, argv, "subPixhawk");
	ros::NodeHandle n;
	
	ros::Publisher pub_override_rc 	= n.advertise<mavros_msgs::OverrideRCIn>("/mavros/rc/override", 20);
	ros::Publisher pub_sub_status 	= n.advertise<groundserver::statusSub>("/rov/mode/status", 1);
	
	ros::Subscriber sub_rov_throttle 	= n.subscribe<std_msgs::Float32>("/rov/input/throttle", 6, throttleCallback);
	ros::Subscriber sub_rov_steering 	= n.subscribe<std_msgs::Float32>("/rov/input/steering", 6, steeringCallback);
	ros::Subscriber sub_rov_altitude	= n.subscribe<std_msgs::Float32>("/rov/input/altitude", 6, altitudeCallback);
	ros::Subscriber sub_rov_gripOn 		= n.subscribe<std_msgs::Int16>("/rov/input/gripOn", 6, gripOnCallback);
	ros::Subscriber sub_rov_gripOff 	= n.subscribe<std_msgs::Int16>("/rov/input/gripOff", 6, gripOffCallback);
	ros::Subscriber sub_rov_armed 		= n.subscribe<std_msgs::Int16>("/rov/input/armed", 6, armedCallback);
	ros::Subscriber sub_rov_stabilize 	= n.subscribe<std_msgs::Int16>("/rov/input/stabilize", 6, stabilizeCallback);
	
	//ros::Subscriber sub_rov_remote 	= n.subscribe<groundserver::inputRemote>("/rov/input", 20, remoteCallback);
	//ros::Publisher pub_state_armed 	= n.advertise<mavros_msgs::State>("/mavros/state", 20);
	//ros::Publisher pub_ardu_control 	= n.advertise<groundserver::arduinoInput>("/rov/ardu/input", 20);
	//ros::Publisher pub_rov_grip 		= n.advertise<mavros_msgs::RCOut>("/mavros/rc/out", 20);
	//ros::Subscriber sub_rov_cb 		= n.subscribe<std_msgs::String> ("/rov/ardu/cb", arduCb);
	//ros::ServiceClient client 		= n.serviceClient<mavros_msgs::SetMode>("/mavros/set_mode");

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
		
		/*
		if (rovRemoteArmed > 0){lastArmed = true;}
		else if(rovRemoteArmed < 0){lastArmed = false;}
		
		if(rovManualMode > 0){
			flight.request.base_mode = 0;
			flight.request.custom_mode = "MANUAL";
			client.call(flight);
			ROS_INFO("manual");
		}
		if(rovHoldMode > 0){
			flight.request.base_mode = 0;
			flight.request.custom_mode = "ALT_HOLD";
			client.call(flight);
			ROS_INFO("depth hold");
		}
		if(rovStabilizeMode > 0){
			flight.request.base_mode = 0;
			flight.request.custom_mode = "STABILIZE";
			client.call(flight);
			ROS_INFO("stabilize");
		}
		
		armedRov.armed = lastArmed;
		
		arduControl.arduArmGripOn 	= rovArmGripOn;
		arduControl.arduArmGripOff 	= rovArmGripOff;		
		*/
		
		//pub_ardu_control.publish(arduControl);
		//pub_rov_grip.publish(rovGrip);
		//pub_state_armed.publish(armedRov);
		pub_sub_status.publish(rovStatus);
		pub_override_rc.publish(rovRcIn);	
	}
}

void throttleCallback(const std_msgs::Float32::ConstPtr& msg){	
	b = msg->data;
	rovThrottle = b;
}

void steeringCallback(const std_msgs::Float32::ConstPtr& msg){	
	d = msg->data;
	rovRoll = d;
}

void altitudeCallback(const std_msgs::Float32::ConstPtr& msg){	
	c = msg->data;
	rovPitch = c;
}

void gripOnCallback(const std_msgs::Int16::ConstPtr& msg){	
	l = msg->data;
	rovArmGripOn = l;
}

void gripOffCallback(const std_msgs::Int16::ConstPtr& msg){	
	m = msg->data;
	rovArmGripOff = m;
}

void stabilizeCallback(const std_msgs::Int16::ConstPtr& msg){	
	i = msg->data;
	rovStabilizeMode = i;
}

void armedCallback(const std_msgs::Int16::ConstPtr& msg){	
	k = msg->data;
	rovStabilizeMode = k;
}
/*
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
*/

/*
void arduCb(const std_msgs::String::ConstPtr& ardu){
	arduFeedback.data = ardu.data;
}


*/
void checkInput(){
	cout<<"++++++++yaw :"<<rovYaw<<"\t"<<"throttle :"<<rovThrottle<<"\t"<<"pitch :"<<rovPitch<<"\t"<<"roll :"<<rovRoll<<endl;
	cout<<"++++++++stabilize :"<<rovStabilizeMode<<"\t"<<"Armed :"<<rovRemoteArmed<<endl;
	cout<<"++++++++armGripOn :"<<rovArmGripOn<<"\t"<<"armGripOff :"<<rovArmGripOff<<"\t"<<endl;
	cout<<endl<<endl<<endl;
}

