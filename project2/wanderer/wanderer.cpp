#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>

// these global variables are what you will set to complete the project
double front_dist;  // if set correctly, this will be the closest obstacle to the front of the robot
double left_dist; // if set correctly, this will be the closest obstacle to the left of the robot
double right_dist; // if set correctly, this will be the closest obstacle to the right of the robot

void laserCallback(const sensor_msgs::LaserScan::ConstPtr& msg)
{
	// set front, left, and right distances to be really large

	front_dist = 99999999999999999;
	left_dist  = 99999999999999999;
	right_dist = 99999999999999999;

	// loop through the ranges in the sensor scan, one at a time
	// answer for each range point

	for( int i = 0; i < msg->ranges.size(); i++ )
	{
		float angle = msg->angle_min + i*msg->angle_increment;
		double xdist = msg->ranges[i] * sin(angle);
		double ydist = msg->ranges[i] * cos(angle);

			// place your code here
		/*********************************/

			// is the x/y coordinate for this range point
			// closer than the closest front point so far?
			if( xdist > -0.3 && xdist < 0.3 && ydist < front_dist )
			{
				// if so, set the front_distance to be
				// the current distance
				front_dist = ydist;
			}

			// is the x/y coordinate for this range point
			// closer than the closest right point so far?
			if( ydist > 0.25 && xdist > 0 )
			{
				// if so, set the right_distance to be
				// the current distance
				double dist = sqrt (ydist*ydist + xdist*xdist);
				if( dist < right_dist )
					right_dist = dist;
			}
			// is the x/y coordinate for this range point
			// closer than the closest left point so far?
			if( ydist > 0.25 && xdist < 0 )
			{
				// if so, set the left_distance to be
				// the current distance
				double dist = sqrt (ydist*ydist + xdist*xdist);
				if( dist < left_dist )
					left_dist = dist;
			}


		/*********************************/
	}
}

int main( int argc, char* argv[] )
{
	// this code initializes a connection to the robot
	ros::init(argc,argv,"wanderer");
	ros::NodeHandle nh;
	ros::Rate loop_rate(10);

	ros::Subscriber laser_sub = nh.subscribe("/base_scan", 1000, laserCallback);
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
		printf( "front_dist: %0.2f left_dist: %0.2f right_dist: %0.2f\n", front_dist, left_dist, right_dist );

			//place your code here
		/***************************************/

			// if an obstacle is to the front of the robot
				// the robot should slow down.
			if( front_dist < 0.75 )
				lvel = front_dist - 0.35;
			// If the robot has an obstacle closer to the left of the robot
				// the robot should turn right.
			if( left_dist < right_dist + 0.1 )
				rvel = 0.5;
			// If the robot detects an obstacle closer to the right of the robot
				// the robot should turn left.
			if( right_dist < left_dist + 0.1 )
				rvel = -0.5;

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
