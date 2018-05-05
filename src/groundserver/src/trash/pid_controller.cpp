#include "ros/ros.h"
#include "pid/plant_msg.h"
#include "pid/controller_msg.h"
#include "pid/pid_const_msg.h"
#include "geometry_msgs/Point.h"
#include "geometry_msgs/TwistStamped.h"
#include "geometry_msgs/PoseStamped.h"
#include "std_msgs/Int16.h"
#include "mavros_msgs/State.h"
#include "sensor_msgs/Imu.h"
#include "std_msgs/Float64.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "mavros_msgs/CommandHome.h"
using namespace std;
void pidXReceiver(const pid::controller_msg& x_msg);
void pidYReceiver(const pid::controller_msg& y_msg);
void pidZReceiver(const pid::controller_msg& z_msg);
void cvReceiver(const geometry_msgs::Point& cv_msg); 
void posReceiver(const geometry_msgs::PoseStamped& local_msg);
void fmReceiver(const std_msgs::Int16& fm_recv);
void stateReceiver(const mavros_msgs::State& state_recv);
void altReceiver(const std_msgs::Float64& alt_msg);
void missionTimer(const ros::TimerEvent&);
void GoyangGoyangTimer(const ros::TimerEvent&);
void GoyangGoyangTimerBawah(const ros::TimerEvent&);
void pidConvert();
int stableMotion();
void imuReceiver(const sensor_msgs::Imu& imu_msg);
int mission_count = 0;
int mission_time_out = -1;
int goyang_time_out = -1;
int goyang_bawah_time_out = -1;
int fm_data = 0;
int position_lost = 0;
int x_pos_flag = 0;
int y_pos_flag = 0;
int home_flag = 0;
double cv_x = 0.0;
double cv_y = 0.0;
float pos_x = 0;
float pos_y = 0;
float pos_z = 0;
float accel_x = 0;
float accel_y = 0;
float accel_z = 9.8;
float rel_alt = 0;
double x_pid_out = 0.0;
double y_pid_out = 0.0;
double z_pid_out = 0.0;
char state_char = 'G';

int main(int argc, char **argv){
	
	float KpH = 0.003;
	float KiH = 0 ;
	float KdH = 0 ;
	
	float KpL = 0.002;
	float KiL = 0 ;
	float KdL = 0 ;

	double setpoint_x = 320;
	double setpoint_y = 260;
	double setpoint_z = 0.5; 
	
	int zero_area_y = 15; // pixel
	int zero_area_x = 15; // pixel
	
	int false_area_x = 20; // pixel
	int false_area_y = 20; // pixel
	int warna_area_x = 260;
	int warna_area_y = 180;
	int mission_time_out_second = 300;
	int goyang_time_out_second = 50;
	int goyang_bawah_time_out_second = 20;
	int positioning_bawah_flag = 0;
	int bawabarang = 1;
	int log=1;
	
	double t_IC = 0.0;
	double delta_t = 0.01;
	double zero_zone_x_l, zero_zone_y_l;
	double zero_zone_x_u, zero_zone_y_u;
	double false_detec_zone_y_u, false_detec_zone_x_u;
	double false_detec_zone_y_l, false_detec_zone_x_l;
	double warna_zone_x_l,warna_zone_x_u;
	double warna_zone_y_l,warna_zone_y_u;
	float x_warna = 0;
	float y_warna = 0;
	float x_warna_home = 0;
	float y_warna_home = 0;
	float const_cv_local = 0;
	int local_pos_cv_x = 0;
	int local_pos_cv_y = 0;
	
	
	ros::init(argc, argv, "pid_controller");
	  
	ros::NodeHandle pid_controller;
	
	ros::Timer timer_mission = pid_controller.createTimer(ros::Duration(1), missionTimer,true);
	ros::Timer timer_goyang_goyang = pid_controller.createTimer(ros::Duration(1), GoyangGoyangTimer,true);
	ros::Timer timer_goyang_goyang_bawah = pid_controller.createTimer(ros::Duration(1), GoyangGoyangTimerBawah,true);
	ros::Publisher pub_pid_x_in = pid_controller.advertise<pid::plant_msg>("/krti17/pid_x_in", 1);
	ros::Publisher pub_pid_y_in = pid_controller.advertise<pid::plant_msg>("/krti17/pid_y_in", 1);
	ros::Publisher pub_pid_z_in = pid_controller.advertise<pid::plant_msg>("/krti17/pid_z_in", 1);
	ros::Publisher pub_pid_const = pid_controller.advertise<pid::pid_const_msg>("/krti17/pid_const", 1,true);
	//ros::Publisher pub_pid_const_z = pid_controller.advertise<pid::pid_const_msg>("/krti17/pid_const_z", 1,true);
	ros::Publisher pub_quad_vel = pid_controller.advertise<geometry_msgs::TwistStamped>("mavros/setpoint_velocity/cmd_vel", 1000);
	ros::Publisher pub_quad_pos = pid_controller.advertise<geometry_msgs::PoseStamped>("mavros/setpoint_position/local", 1000);
	ros::Publisher pub_ext_mode = pid_controller.advertise<std_msgs::Int16>("krti17/ext_mode", 10,true);
	
	ros::Subscriber sub_pid_x_out = pid_controller.subscribe("/krti17/pid_x_out", 10, pidXReceiver );
	ros::Subscriber sub_pid_y_out = pid_controller.subscribe("/krti17/pid_y_out", 10, pidYReceiver );
	ros::Subscriber sub_pid_z_out = pid_controller.subscribe("/krti17/pid_z_out", 10, pidZReceiver );  
	ros::Subscriber sub_cv_point = pid_controller.subscribe("/krti17/cv_point", 10, cvReceiver );
	ros::Subscriber sub_pos = pid_controller.subscribe("mavros/local_position/pose", 100, posReceiver );
	ros::Subscriber sub_fm = pid_controller.subscribe("/krti17/flight_mode", 10, fmReceiver);
	ros::Subscriber sub_state = pid_controller.subscribe("mavros/state", 10, stateReceiver);
	ros::Subscriber sub_rel_alt = pid_controller.subscribe("mavros/global_position/rel_alt", 1, altReceiver );
	ros::Subscriber sub_imu = pid_controller.subscribe("/mavros/imu/data", 10, imuReceiver );
	ros::Rate loop_rate(1/delta_t); 
	pid_controller.getParam("barang", bawabarang);

	pid::plant_msg  pid_x_in;
	pid::plant_msg  pid_y_in;
	pid::plant_msg  pid_z_in;
	pid::pid_const_msg pid_const;
	//pid::pid_const_msg pid_const_z;
	geometry_msgs::TwistStamped quad_vel;

	geometry_msgs::PoseStamped quad_pos;
	std_msgs::Int16 ext_mode;
	  
	pid_const.p = KpH;
	pid_const.i = KiH;
	pid_const.d = KdH;
	pub_pid_const.publish(pid_const);
	
	//pid_const_z.p = KpZ;
	//pid_const_z.i = KiZ;
	//pid_const_z.d = KdZ;
	//pub_pid_const_z.publish(pid_const);
	
	pid_x_in.x = cv_x;
	pid_x_in.t = t_IC;

	pid_y_in.x = cv_y;
	pid_y_in.t = t_IC;
	
	pid_z_in.x = rel_alt;
	pid_z_in.t = t_IC;

	pid_x_in.setpoint = setpoint_x;
	pid_y_in.setpoint = setpoint_y;
	pid_z_in.setpoint = setpoint_z;

	zero_zone_x_l = setpoint_x - (zero_area_x/2);
	zero_zone_x_u = setpoint_x + (zero_area_x/2);
	zero_zone_y_l = setpoint_y - (zero_area_y/2);
	zero_zone_y_u = setpoint_y + (zero_area_y/2);
  
	warna_zone_x_l = 320 - (warna_area_x/2);
	warna_zone_x_u = 320 + (warna_area_x/2);
	warna_zone_y_l = 240 - (warna_area_y/2);
	warna_zone_y_u = 240 + (warna_area_y/2);
	
  
	ROS_INFO("Cakrawala Hexa! Fight!");
	setpoint_z = rel_alt + 0.5; //Biar setpoint_z nya bener2 4 meter

	// Codingan tidak akan berjalan jika ketinggian masih di bawah 3 meter
	while ( rel_alt < 3 && ros::ok()){

	  ros::spinOnce();
	}

	//Timer untuk keseluruhan misi
	timer_mission.setPeriod(ros::Duration(mission_time_out_second));
	timer_mission.start();
	ROS_INFO_STREAM("Waktu 5 menit mulai dihitung");
	ROS_INFO("Starting PID Controller.");

	while (ros::ok()){

		ros::spinOnce();		

		if ( fm_data == 1 && ros::ok() &&
				cv_x > warna_zone_x_l && 
				cv_x < warna_zone_x_u && 
				cv_y > warna_zone_y_l && 
				cv_y < warna_zone_y_u && home_flag == 0){
					
			x_warna_home = pos_x;
			y_warna_home = pos_y;
			ROS_INFO_STREAM( "Forced to Guided Mode") ;
			ext_mode.data = 4;
			pub_ext_mode.publish(ext_mode);
			while(state_char != 'G' && ros::ok()){
				ros::spinOnce();
			}
			
			quad_pos.header.stamp = ros::Time::now();
			quad_pos.header.frame_id = "1";
			quad_pos.pose.position.x = x_warna_home;	
			quad_pos.pose.position.y = y_warna_home; 	
			quad_pos.pose.position.z = rel_alt; 	
			pub_quad_pos.publish(quad_pos);
			ROS_INFO_STREAM( "Stay Here") ;
			ROS_INFO_STREAM( "Position Set") ;
			ROS_INFO_STREAM("X Homed at " << x_warna_home);
			ROS_INFO_STREAM("Y Homed at " << y_warna_home);
			usleep(3000000);
			while (!stableMotion() && ros::ok()){
				ros::spinOnce();
			}
			
			home_flag = 1;
			//Memasang timer saat copter mencari posisi X dan Y target
			timer_goyang_goyang.setPeriod(ros::Duration(goyang_time_out_second));
			timer_goyang_goyang.start();
			ROS_INFO_STREAM("Timer buat goyang-goyang menyala selama 50 detik.");
		}
		
		if (  fm_data == 0 && home_flag == 1 ){
			
			//Setelah 3 kali position lost dan copter kembali ke warna_home
			if(position_lost == 3)
			{
				ext_mode.data = 3;
				pub_ext_mode.publish(ext_mode);
				usleep(6000000);
				ext_mode.data = 1;
				pub_ext_mode.publish(ext_mode);
				position_lost = 0;
				mission_count ++;
				ROS_INFO_STREAM("Posisi warna hilang tiga kali.");
				ROS_INFO_STREAM("Flightmode kembali berubah ke AUTO");
				//tambahin langsung jatuhin barang jika bawabarang==1
			}
			
			ROS_INFO_STREAM( "Position Lost") ;	
			quad_pos.header.stamp = ros::Time::now();
			quad_pos.header.frame_id = "1";
			quad_pos.pose.position.x = x_warna_home;	
			quad_pos.pose.position.y = y_warna_home; 	
			quad_pos.pose.position.z = rel_alt; 	
			pub_quad_pos.publish(quad_pos);
			
			ROS_INFO_STREAM( "Position Set") ;
			ROS_INFO_STREAM( "X Homed at " << x_warna_home) ;
			ROS_INFO_STREAM( "Y Homed at " << y_warna_home) ;
			usleep(200000);

			while (!stableMotion() && ros::ok()){
				ros::spinOnce();
			}
			position_lost ++; 
		}
		
		if ( cv_x > zero_zone_x_l && cv_x < zero_zone_x_u && x_pos_flag == 0 && state_char == 'G' && stableMotion()){
			
			x_warna = pos_x;
			x_pos_flag = 1;
			
			false_detec_zone_x_l = x_warna - (false_area_x/2);
			false_detec_zone_x_u = x_warna + (false_area_x/2);			
			ROS_INFO_STREAM( "X Locked at " << x_warna) ;
		}
		
		if ( cv_y > zero_zone_y_l && cv_y < zero_zone_y_u && y_pos_flag == 0 && state_char == 'G' && stableMotion()){
		
			y_warna = pos_y;
			y_pos_flag = 1;
			
			false_detec_zone_y_l = y_warna - (false_area_y/2);
			false_detec_zone_y_u = y_warna + (false_area_y/2);
			ROS_INFO_STREAM( "Y Locked at " << y_warna) ;
		}
		
		if ( (pos_x < false_detec_zone_x_l || pos_x > false_detec_zone_x_u) && x_pos_flag == 1 ){
			
			ROS_INFO_STREAM( "X Position Reseted! ") ;
			x_pos_flag = 0;			
		}

		if ( (pos_y < false_detec_zone_y_l || pos_y > false_detec_zone_y_u) && y_pos_flag == 1 ){
			
			ROS_INFO_STREAM( "Y Position Reseted! ") ;
			y_pos_flag = 0;			
		}
				
		if ( x_pos_flag == 1 && y_pos_flag == 1 && state_char == 'G'){	
		
			goyang_time_out = goyang_time_out - 1;
			while (!stableMotion()){
				ros::spinOnce();
			}
			if (bawabarang==0)
			{
			while(rel_alt > setpoint_z+1.3 && ros::ok()){	
				while (!stableMotion()){
				ros::spinOnce();
			}
				ros::spinOnce();
				usleep(200000);
				quad_pos.header.stamp = ros::Time::now();
				quad_pos.header.frame_id = "1";
				quad_pos.pose.position.x = x_warna;	
				quad_pos.pose.position.y = y_warna; 	
				quad_pos.pose.position.z = setpoint_z+1; 	
				pub_quad_pos.publish(quad_pos);
				ROS_INFO_STREAM( "Publishing Position") ;
			}
			
			ROS_INFO_STREAM( "Goyang-goyang dibawah untuk menocoba mengambil barang!") ;				
		
			while (!stableMotion()){
				ros::spinOnce();
			}
			ROS_INFO_STREAM( "PID Ground Started!") ;
			
			pid_const.p = KpL;
			pid_const.i = KiL;
			pid_const.d = KdL;
			pub_pid_const.publish(pid_const);
			x_pos_flag = 0;
			y_pos_flag = 0;
			timer_goyang_goyang_bawah.setPeriod(ros::Duration(goyang_bawah_time_out_second));
			timer_goyang_goyang_bawah.start();
			ROS_INFO_STREAM("Timer buat goyang-goyang bawah menyala selama 30 detik.");
			ros::spinOnce();			
			ROS_INFO_STREAM("Sekarang copter akan goyang-goyang di 1.5 meter");
			while(fm_data == 1 && ros::ok() && goyang_bawah_time_out == 0){				
				//Mengecek apakah waktu 5 menit misi sudah habis
					if(mission_time_out == 1)
					{
						ext_mode.data = 2;
						pub_ext_mode.publish(ext_mode);
							while(ros::ok()){}
					}
					
			while (!stableMotion()){
				ros::spinOnce();
			}			
				pid_x_in.x = cv_x;
				pid_x_in.t = pid_x_in.t+delta_t;
			  
				pid_y_in.x = cv_y;
				pid_y_in.t = pid_y_in.t+delta_t;
					
				pub_pid_x_in.publish(pid_x_in);
				pub_pid_y_in.publish(pid_y_in);
				
				ros::spinOnce();
				
				pidConvert();
				
				quad_vel.header.stamp = ros::Time::now();
				quad_vel.header.frame_id = "1";
				quad_vel.twist.linear.x = y_pid_out;
				quad_vel.twist.linear.y = x_pid_out;
				
				pub_quad_vel.publish(quad_vel);
				
				loop_rate.sleep();				
				
			}
			if(goyang_bawah_time_out == 1)
			{
				ROS_INFO_STREAM("Waktu goyang bawah sudah habis. :)");
			}
			positioning_bawah_flag = 0;
			goyang_bawah_time_out -- ;
				
			ext_mode.data = 3;
			pub_ext_mode.publish(ext_mode);
			
			usleep(6000000); // Delay ini perlu disesuaikan dengan kecepatan wahana
				
			
			ROS_INFO_STREAM( "Job Complete!") ;
			position_lost = 0;
			x_pos_flag = 0;
			y_pos_flag = 0;
			home_flag = 0;
			bawabarang = 1;
			pid_const.p = KpH;
			pid_const.i = KiH;
			pid_const.d = KdH;
			pub_pid_const.publish(pid_const);
						
			ext_mode.data = 1; // ext_mode bernilai 1 maka tidak ke mode apapun
			pub_ext_mode.publish(ext_mode);	
			}
			
			if (bawabarang==1)
			{
			while(rel_alt > setpoint_z+0.3 && ros::ok()){	
				while (!stableMotion()){
				ros::spinOnce();
			}
				ros::spinOnce();
				usleep(200000);
				quad_pos.header.stamp = ros::Time::now();
				quad_pos.header.frame_id = "1";
				quad_pos.pose.position.x = x_warna;	
				quad_pos.pose.position.y = y_warna; 	
				quad_pos.pose.position.z = setpoint_z; 	
				pub_quad_pos.publish(quad_pos);
				ROS_INFO_STREAM( "Publishing Position") ;
			}
			
			ROS_INFO_STREAM( "Berhasil turun. Jatuhkan barang!") ;				
		
			while (!stableMotion()){
				ros::spinOnce();
			}
			
			//delay 5 detik untuk jatuhkan barang
			usleep(5000000);
			//harus nambahin publish ke image processing untuk ganti nilai hsv setelah log = 0
				
			ext_mode.data = 3;
			pub_ext_mode.publish(ext_mode);
			
			usleep(6000000); // Delay ini perlu disesuaikan dengan kecepatan wahana
				
			mission_count++;
			
			ROS_INFO_STREAM( "Job Complete!") ;
			position_lost = 0;
			x_pos_flag = 0;
			y_pos_flag = 0;
			home_flag = 0;
			bawabarang = 0;
			pid_const.p = KpH;
			pid_const.i = KiH;
			pid_const.d = KdH;
			pub_pid_const.publish(pid_const);
						
			ext_mode.data = 1; // ext_mode bernilai 1 maka tidak ke mode apapun
			pub_ext_mode.publish(ext_mode);	
			}	
			
			//3 barang telah dijatuhkan
			if (mission_count == 3){
			ROS_INFO_STREAM("Semua barang telah dijatuhkan. Saatnya pulang :)");
			ext_mode.data = 2;
			pub_ext_mode.publish(ext_mode);
			
				while(ros::ok())
					{}//Biar codingannya ga lanjut
					}
			
		}			
		
		if(goyang_time_out == 1)
		{
			ROS_INFO_STREAM("Waktu bergoyang diatas telah habis");
			ext_mode.data = 3;
			pub_ext_mode.publish(ext_mode);
			usleep(4500000);
			mission_count++;
			goyang_time_out = 0	;
		}
		
		if(mission_time_out == 1)
		{
			ROS_INFO_STREAM("Waktu 5 menit telah habis");
			ext_mode.data = 2;
			pub_ext_mode.publish(ext_mode);
			while(ros::ok())
			{}
			pub_ext_mode.publish(ext_mode);
		}
		
		pid_x_in.x = cv_x;
		pid_x_in.t = pid_x_in.t+delta_t;
	  
		pid_y_in.x = cv_y;
		pid_y_in.t = pid_y_in.t+delta_t;
		
		//pid_z_in.x = rel_alt;
		//pid_z_in.t = pid_z_in.t+delta_t;
	  
		
		pub_pid_x_in.publish(pid_x_in);
		pub_pid_y_in.publish(pid_y_in);
		//pub_pid_z_in.publish(pid_z_in);
		
		ros::spinOnce();
		
		pidConvert();		
		
		quad_vel.header.stamp = ros::Time::now();
		quad_vel.header.frame_id = "1";
		quad_vel.twist.linear.x = y_pid_out;
		quad_vel.twist.linear.y = x_pid_out;
		//if(rel_alt > setpoint_z +0.3)
		//{
		//quad_vel.twist.linear.z = z_pid_out;
		//}
		//else
		//{
		//quad_vel.twist.linear.z = 0;
		//}
		
		pub_quad_vel.publish(quad_vel);
		
		
		
		loop_rate.sleep();
	}
	
	return 0;
}

void pidXReceiver(const pid::controller_msg& x_msg){

	x_pid_out = x_msg.u;
}

void pidYReceiver(const pid::controller_msg& y_msg){
    y_pid_out = - y_msg.u;
}

void pidZReceiver(const pid::controller_msg& z_msg){

	z_pid_out = z_msg.u;
}

void cvReceiver(const geometry_msgs::Point& cv_msg){

	cv_x = cv_msg.x;
    cv_y = cv_msg.y;
}

void posReceiver(const geometry_msgs::PoseStamped& local_msg){
	
	pos_x = local_msg.pose.position.x;
	pos_y = local_msg.pose.position.y;
	pos_z = local_msg.pose.position.z;
}

void fmReceiver(const std_msgs::Int16& fm_recv){
	
	fm_data = fm_recv.data;
}

void stateReceiver(const mavros_msgs::State& state_recv){
	
	state_char = state_recv.mode[0];
}

void altReceiver(const std_msgs::Float64& alt_msg){

	rel_alt = alt_msg.data;
}

void pidConvert(){
	
	y_pid_out = 0 - y_pid_out;
}

void missionTimer(const ros::TimerEvent&){
  
  mission_time_out ++;
}

void GoyangGoyangTimer(const ros::TimerEvent&){
  position_lost = 0;
  goyang_time_out ++;
  home_flag = 0;
  x_pos_flag = 0;
  y_pos_flag = 0;
}

void GoyangGoyangTimerBawah(const ros::TimerEvent&){
  goyang_bawah_time_out ++;
  x_pos_flag = 0;
  y_pos_flag = 0;
}


void imuReceiver(const sensor_msgs::Imu& imu_msg)
{

  accel_x = imu_msg.linear_acceleration.x;
  accel_y = imu_msg.linear_acceleration.y;
  accel_z = imu_msg.linear_acceleration.z;
  
}

int stableMotion(){
	
	if (accel_z > 9.72 && accel_z < 9.88){
		return 1;
	}
	else{
		return 0;
	}
	
}