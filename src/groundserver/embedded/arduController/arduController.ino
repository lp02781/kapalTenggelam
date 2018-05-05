/* 
 * rosserial Subscriber Example
 * Blinks an LED on callback
 */

#include <ros.h>
#include <groundServer/usbIp>

ros::NodeHandle  nh;

void messageCb( const groundServer::usbIp& toggle_msg){
  digitalWrite(13, HIGH-digitalRead(13));   // blink the led
}

ros::Subscriber<groundServer::usbIp> sub("/rov/usb/controller", &messageCb );

void setup(){ 
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
}

void loop(){  
  nh.spinOnce();
  delay(1);
}

