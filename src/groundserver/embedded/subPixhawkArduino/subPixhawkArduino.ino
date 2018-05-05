#include <ros.h>
#include <ArduinoHardware.h>
#include <stdlib.h>
#include <std_msgs/String.h>
#include <groundserver/arduinoInput.h>
#include <Servo.h>

int firstESC  = 9;
int secondESC = 8;
int thirdESC  = 7;
int fourthESC = 6;
int gripPin = 5;

bool gripFlag = false;

#define maxPWM    1900
#define minPWM    1200
#define middlePWM 1500

#define gripMaxPWM 1900
#define gripMinPWM 1200

void throttleUp();
void throttleDown();
void throttleIdle();

void rollUp();
void rollDown();
void rollIdle();

std_msgs::String str_msg;

Servo firstMotor, secondMotor, thirdMotor, fourthMotor;
Servo gripOnOff;

ros::NodeHandle  nh;
ros::Publisher pub_rov_cb("/rov/ardu/cb", &str_msg);

void remoteCb(const groundserver::arduinoInput& msg){ 
  if(msg.arduThrottle > 0){
    str_msg.data = "throttle up";
    throttleUp();  	
  }
  else if(msg.arduThrottle < 0){
    str_msg.data = "throttle down";
    throttleDown();
  }
  else{
    throttleIdle();
  }

  if(msg.arduRoll > 0){
    str_msg.data = "roll Up";
    rollUp();    
  }
  else if(msg.arduRoll < 0){
    str_msg.data = "roll down";
    rollDown();
  }
  else{
    rollIdle();
  }

  if(msg.arduArmGripOn > 0){
    gripFlag = true; 
    str_msg.data = "grip on";
    armGrip();
  }
  if(msg.arduArmGripOff > 0){
    gripFlag = false;
    str_msg.data = "grip off";
    armGrip();
  }
} 
ros::Subscriber<groundserver::arduinoInput> sub_rov_remote("/rov/ardu/input", &remoteCb);

void setup(){
	firstMotor.attach(firstESC);
  secondMotor.attach(secondESC);
  thirdMotor.attach(thirdESC);
  fourthMotor.attach(fourthESC);
  gripOnOff.attach(gripPin);

	str_msg.data = "no feedback";
  nh.initNode();
	nh.subscribe(sub_rov_remote);
	nh.advertise(pub_rov_cb);
}

void loop(){
	nh.spinOnce();
  pub_rov_cb.publish( &str_msg );
	delay(500);
}	

void throttleUp(){
  firstMotor.writeMicroseconds(maxPWM);
  secondMotor.writeMicroseconds(maxPWM);
}

void throttleDown(){
  firstMotor.writeMicroseconds(minPWM);
  secondMotor.writeMicroseconds(minPWM);
}

void throttleIdle(){
  firstMotor.writeMicroseconds(middlePWM);
  secondMotor.writeMicroseconds(middlePWM);
}

void rollUp(){
  thirdMotor.writeMicroseconds(maxPWM);
  fourthMotor.writeMicroseconds(minPWM);
}

void rollDown(){
  thirdMotor.writeMicroseconds(minPWM);
  fourthMotor.writeMicroseconds(maxPWM);  
}

void rollIdle(){
  thirdMotor.writeMicroseconds(middlePWM);
  fourthMotor.writeMicroseconds(middlePWM);
}

void armGrip(){
  if(gripFlag = true){
    gripOnOff.writeMicroseconds(gripMaxPWM);
  }
  else if (gripFlag = false){
    gripOnOff.writeMicroseconds(gripMinPWM);
  }
  else{
    gripOnOff.writeMicroseconds(gripMinPWM);
  }
}

