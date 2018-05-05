#!/bin/sh

export ROS_IP=192.168.43.116
export ROS_MASTER_URI=http://192.168.43.116:11311
export ROSLAUNCH_SSH_UNKNOWN=1
. /home/msfikih15/kapalTenggelam/serverGabut/devel/setup.sh
exec "$@"
