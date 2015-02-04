#!/bin/bash

ROS_DISTRO=
UBUNTU_MAJOR_VERSION=`cat /etc/issue | cut -c 8-9`
UBUNTU_MINOR_VERSION=`cat /etc/issue | cut -c 11-12`
if [ "$UBUNTU_MAJOR_VERSION" -eq "12" ]
then ROS_DISTRO=hydro
elif [ "$UBUNTU_MAJOR_VERSION" -eq "13" -a "$UBUNTU_MINOR_VERSION" -eq "04" ]
then ROS_DISTRO=hydro
else ROS_DISTRO=indigo
fi

echo "ROS_DISTRO: $ROS_DISTRO"
echo "source /opt/ros/$ROS_DISTRO/setup.bash" >> ~/.bashrc
echo $ROS_PACKAGE_PATH
source ~/.bashrc
exec bash
