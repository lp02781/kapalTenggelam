#include <ros/ros.h>
#include <sensor_msgs/Imu.h>
#include <iostream>
#include <stdio.h>

using namespace std;
float accel_x = 0;
float accel_y = 0;
float accel_z = 0;
float ang_x = 0;
float ang_y = 0;
float ang_z = 0;
float a, b, c, d, e, f;

void imuCallback(const sensor_msgs::Imu::ConstPtr& imu);
void checkController();

int main(int argc, char** argv){
	ros::init(argc, argv, "testImu");
	ros::NodeHandle nh;
	
	ros::Subscriber imu_sub = nh.subscribe("/mavros/imu/data", 8, &imuCallback);
	
	while( ros::ok() ){
		ros::spinOnce();
		//checkController();
	}
}

void imuCallback(const sensor_msgs::Imu& imu)	{
	accel_x = imu.linear_acceleration.x;
	accel_y = imu.linear_acceleration.y;
	accel_z = imu.linear_acceleration.z; 
	
	ang_x = imu.angular_velocity.x;
	ang_y = imu.angular_velocity.y;
	ang_z = imu.angular_velocity.z;
	
	a = accel_x;
	b = accel_y;
	c = accel_z;
	
	d = ang_x;
	e = ang_y;
	f = ang_z;
	checkController();
}

void checkController(){	
	cout<<"++++++++x :"<<accel_x<<"\t"<<"y :"<<accel_y<<"\t"<<"z :"<<accel_z<<endl;
	cout<<"++++++++angX :"<<ang_x<<"\t"<<"angY :"<<ang_y<<"\t"<<"angZ :"<<ang_z<<endl;
	cout<<"++++++++x :"<<a<<"\t"<<"y :"<<b<<"\t"<<"z :"<<c<<endl;
	cout<<"++++++++angX :"<<d<<"\t"<<"angY :"<<d<<"\t"<<"angZ :"<<f<<endl;
	
	cout<<endl<<endl<<endl;
}

