#include <SPI.h>  
#include <SoftwareSerial.h>
#include <TimerOne.h>
#include <Wire.h>
#include <HMC5883L.h>
#include <math.h>
#include "compass.h"
#define SOP 'x'
#define EOP 'y'
  
float derajat;
char flag;

SoftwareSerial stmSerial(10,11);
HMC5883L compass;
Vector norm;
uint8_t ball = 0;
uint8_t readdata;
int a=0;

bool getball(){
	int i;
	uint16_t blocks;
	for(i=0;i<30;i++){
		if(blocks){
			return true;
		}
	}
	return false;
}


void compassSetup(){
	Wire.begin();
	compass_x_offset = 291.67;
	compass_y_offset = 118.69;
	compass_z_offset = -227.39;
	compass_x_gainError = 1.12;
	compass_y_gainError = 1.13;
	compass_z_gainError = 1.03;
  
	compass_init(2);
}

void compassLoop(){
	compass_scalled_reading();
	compass_heading();
}

void interruptHandler(){
	stmSerial.begin(9600);
	uint8_t xCoor;
	uint8_t yCoor;
	uint8_t heading;
	char sendBuffer[8];
	uint8_t ballXCoor=0;
	uint8_t ballYCoor=0;


    heading = bearing*0.7083;
    
	if(flag=='X'){
		ballXCoor = readdata;
		flag = 0;
	}
	else if(flag=='Y'){
		ballYCoor = readdata;
		flag = 0;
	}
	else{
		flag = readdata;
	}
    sendBuffer[0] = 'X';
    sendBuffer[1] = ballXCoor;
    a++;
    sendBuffer[2] = 'Y';
    sendBuffer[3] = 5;//ballYCoor;
    sendBuffer[4] = 'C';
    sendBuffer[5] = heading;
    sendBuffer[6] = 'B';
    sendBuffer[7] = ball;
    stmSerial.write(sendBuffer[0]);
    stmSerial.write(sendBuffer[1]);
    stmSerial.write(sendBuffer[2]);
    stmSerial.write(sendBuffer[3]);
    stmSerial.write(sendBuffer[4]);
    stmSerial.write(sendBuffer[5]);
    stmSerial.write(sendBuffer[6]);
    stmSerial.write(sendBuffer[7]);

    stmSerial.end();   
}

void serialEvent()
{
	Serial.println(bearing);
	stmSerial.begin(9600);
	uint8_t xCoor;
	uint8_t yCoor;
	uint8_t heading;
	char sendBuffer[8];
	uint8_t ballXCoor=0;
	uint8_t ballYCoor=0;


    heading = bearing*0.7083;
    
	if(flag=='X'){
		ballXCoor = readdata;
		flag = 0;
	}
	else if(flag=='Y'){
		ballYCoor = readdata;
		flag = 0;
	}
	else{
		flag = readdata;
	}
    sendBuffer[0] = 'X';
    sendBuffer[1] = ballXCoor;
    a++;
    sendBuffer[2] = 'Y';
    sendBuffer[3] = 5;//ballYCoor;
    sendBuffer[4] = 'C';
    sendBuffer[5] = heading;
    sendBuffer[6] = 'B';
    sendBuffer[7] = ball;
    stmSerial.write(sendBuffer[0]);
    stmSerial.write(sendBuffer[1]);
    stmSerial.write(sendBuffer[2]);
    stmSerial.write(sendBuffer[3]);
    stmSerial.write(sendBuffer[4]);
    stmSerial.write(sendBuffer[5]);
    stmSerial.write(sendBuffer[6]);
    stmSerial.write(sendBuffer[7]);

    stmSerial.end();
}

void setup(){
	compassSetup();
}

void loop(){ 
	Serial.begin(9600);
	static int i = 0;
	int j;
	int counter;
	uint16_t blocks;
	char buf[32]; 
	char printSerial[32];
	int counterBallDetection;
	int32_t panError, tiltError;
	while(1){
		counter++;
		if(counter == 2000){
			compassLoop();
			counter =0;
		}
		else{}  
		if(Serial.available()){
			readdata = Serial.read();
		}
		else{}
		Serial.end();
    
		if (blocks){
			ball = 1;
			counterBallDetection = 0;
		}
		else{
			counterBallDetection ++;
			if(counterBallDetection == 2000){
				counterBallDetection = 0;
				ball = 0;
			} 
		}
	}
}
