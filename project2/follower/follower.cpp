#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>


int main( int argc, char* argv[] )
{
	// this code initializes a connection to the robot
	ros::init(argc,argv,"wanderer");
	ros::NodeHandle nh;
	ros::Rate loop_rate(10);

	ros::Publisher cmd_vel = nh.advertise<geometry_msgs::Twist>("/cmd_vel",1000);
	geometry_msgs::Twist cmd_vel_msg;
	double des_vel = 1.0;

	// loop forever
	while( ros::ok() )
	{
		// by default, the robot will move forward at 1 meter / second
		double lvel = des_vel;
		
		// by default, the robot will not turn at all
		double rvel = 0;


			//place your code here
		/***************************************/

		/***************************************/

		// send the speeds to the robot
		cmd_vel_msg.linear.x = lvel;
		cmd_vel_msg.angular.z = rvel;
		cmd_vel.publish(cmd_vel_msg);
		ros::spinOnce();
		loop_rate.sleep();
	}

	return 0;
}
