#include <ros.h>
#include <std_msgs/String.h>

ros::NodeHandle  nh;

std_msgs::String str_msg;
std_msgs::String message_feedback;

ros::Publisher chatter("ardu", &str_msg);

char hello[13] = "from ardu";

void messageCb( const std_msgs::String& toggle_msg){
   message_feedback.data = toggle_msg.data; 
}

ros::Subscriber<std_msgs::String> sub("pc", &messageCb );

void setup(){
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.advertise(chatter);
  nh.subscribe(sub);
  Serial.begin(9600);
}

void loop(){
  str_msg.data = hello;
  chatter.publish( &str_msg );
  Serial.println(message_feedback.data);
  nh.spinOnce();
  delay(1000);
}
