#include <iostream>
#include "ros/ros.h"
#include "mavros_msgs/SetMode.h"
#include "mavros_msgs/State.h"
#include "mavros_msgs/OverrideRCIn.h"
#include "mavros_msgs/RCIn.h"
#include "std_msgs/Int16.h"
#include "std_msgs/Float64.h"
#include <unistd.h>

void flightmodeReceiver(const std_msgs::Int16& fm);
void extmodeReceiver(const std_msgs::Int16& ext_mode_recv);
void rcinReceiver(const mavros_msgs::RCIn& rc_in_data);
void altReceiver(const std_msgs::Float64& alt_msg);
int flightmode_data = 0;
int ext_mode = 0;
int rc_in_channel_7 = 0;
float rel_alt = 0;

int main(int argc, char **argv)
{	
	ros::init(argc, argv, "flightmode_changer");
	ros::NodeHandle n;
	ros::Subscriber fm_sub = n.subscribe("/krti17/flight_mode", 100, flightmodeReceiver);
	ros::Subscriber ext_mode_sub = n.subscribe("/krti17/ext_mode", 100, extmodeReceiver);
	ros::Subscriber rc_in_sub = n.subscribe("/mavros/rc/in", 100, rcinReceiver);
	ros::Subscriber sub_rel_alt = n.subscribe("/mavros/global_position/rel_alt", 1, altReceiver );
	ros::ServiceClient client = n.serviceClient<mavros_msgs::SetMode>("/mavros/set_mode");
	mavros_msgs::SetMode flight;
    	
	bool success;
	int last_flightmode_data;
	int rc_taken = 1;
	int rc_transit_delay = 2000000;
	int channel_7_mid = 1500;
	// channel_7_off = 900 | channel_7_on = 2000

	// Codingan tidak akan jalan jika ketinggian di bawah 4 meter
	while ( rel_alt < 4 && ros::ok()){
	  ros::spinOnce();
	}

	ROS_INFO("Starting Flight Mode Changer.");
	while (ros::ok()){

		ros::spinOnce();
	
		if(rc_taken == 1){
			
			if (flightmode_data == 0){
				last_flightmode_data = 1;
			}
			
			else if (flightmode_data == 1){
				last_flightmode_data = 0;
			}
			
		}

		if(rc_in_channel_7 > channel_7_mid){

			if ( ext_mode == 2){

				flight.request.base_mode = 0;
				flight.request.custom_mode = "RTL";
				client.call(flight);

				ROS_INFO("Misi Selesai! Saatnya memegang piala!");
				while (ros::ok() && rc_in_channel_7 > channel_7_mid){}  // Menunggu hingga program ditutup

			}
			
			else if ( ext_mode == 3) {
				
				flight.request.base_mode = 0;				//Set to 0 to use custom_mode
				flight.request.custom_mode = "AUTO";		//Set to '' to use base_mode
				client.call(flight);
							
				ROS_INFO("Cakrawala Time Out! Changed to Auto");
				while (ext_mode == 3 && ros::ok()){
					ros::spinOnce();
				}
			}
			
			else if ( ext_mode == 4) {
				
				flight.request.base_mode = 0;				//Set to 0 to use custom_mode
				flight.request.custom_mode = "GUIDED";		//Set to '' to use base_mode
				client.call(flight);
							
				ROS_INFO("Hexa menemukan lampu. Ubah flightmode ke GUIDED");
				while (ext_mode == 4 && ros::ok()){
					ros::spinOnce();
				}
					
			}
			
			else if(flightmode_data == 0 && last_flightmode_data == 1){
				
				flight.request.base_mode = 0;				//Set to 0 to use custom_mode
				flight.request.custom_mode = "AUTO";		//Set to '' to use base_mode
				success = client.call(flight);

				if(success){
					ROS_INFO_STREAM( "Flight Mode berubah menjadi "<< flight.request.custom_mode ) ;
				} 
				else {
					ROS_ERROR_STREAM( "Flightmode gagal untuk berubah." ) ;
				}
				last_flightmode_data = flightmode_data;
			}
			
			else if(flightmode_data == 1 && last_flightmode_data == 0){
				
				flight.request.base_mode = 0;
				flight.request.custom_mode = "LOITER"; // Ke mode LOITER dulu agar hexa tenang
				success = client.call(flight);

				if(success){
					ROS_INFO_STREAM( "Flight Mode berubah menjadi "<< flight.request.custom_mode ) ;
				} 
				else {
					ROS_ERROR_STREAM( "Flightmode gagal berubah." ) ;
				}
				
				usleep(rc_transit_delay);
				
				flight.request.base_mode = 0;				//Set to 0 to use custom_mode
				flight.request.custom_mode = "GUIDED";		//Set to '' to use base_mode
				success = client.call(flight);

				if(success){
					ROS_INFO_STREAM( "Flight Mode berubah menjadi "<< flight.request.custom_mode ) ;
				} 
				else {
					ROS_ERROR_STREAM( "Flightmode gagal berubah." ) ;
				}
				
				usleep(rc_transit_delay*4);
				last_flightmode_data = flightmode_data;

			}
			rc_taken = 0;
		}
		
		else if ( rc_in_channel_7 < channel_7_mid && rc_taken != 1) {
			
			ROS_INFO("RC Take Over!");
			rc_taken = 1;
		}
	}
  return 0;
}

void flightmodeReceiver(const std_msgs::Int16& fm){
	
	flightmode_data = fm.data;
}

void rcinReceiver(const mavros_msgs::RCIn& rc_in_data){
	
	rc_in_channel_7 = rc_in_data.channels[7];
}

void altReceiver(const std_msgs::Float64& alt_msg){

  rel_alt = alt_msg.data;
}

void extmodeReceiver(const std_msgs::Int16& ext_mode_recv){
	
	ext_mode = ext_mode_recv.data;
}