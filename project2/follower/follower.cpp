#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Twist.h>

#include <tf/transform_datatypes.h>


/************************************/
  // place your functions here

  /*
    double get_distance( double rx, double ry, double bx, double by )

    returns: the distance between the red and blue robots
  */

  double get_distance( double rx, double ry, double bx, double by )
  {
    return sqrt((rx-bx)*(rx-bx)+(ry-by)*(ry-by));
  }


  /*
    double get_bearing( double rx, double ry, double bx, double by, double bt )
    
    returns: the bearing (from the blue robot's perspective) of the red robot
  */

  double get_bearing( double rx, double ry, double bx, double by, double bt )
  {
    double bear = atan2( ry-by, rx-bx ) -bt;
    while( bear > M_PI ) bear -= 2*M_PI;
    while( bear < -M_PI ) bear += 2*M_PI;

    return bear;
  }


/************************************/


/***
  ignore these functions

***/
double red_x, red_y, blue_x, blue_y;
double red_theta, blue_theta;

double getRotationFromMsg( geometry_msgs::Quaternion q )
{

  double yaw;
  yaw = tf::getYaw(q);
  return yaw;
}

void odomCallback(const nav_msgs::Odometry::ConstPtr& msg)
{
  red_x = msg->pose.pose.position.x;
  red_y = msg->pose.pose.position.y;
  red_theta = getRotationFromMsg(msg->pose.pose.orientation);
}

void odom2Callback(const nav_msgs::Odometry::ConstPtr& msg)
{
  blue_x = msg->pose.pose.position.x;
  blue_y = msg->pose.pose.position.y;
  blue_theta = getRotationFromMsg(msg->pose.pose.orientation);
}


int main( int argc, char* argv[] )
{
	// this code initializes a connection to the robot
	ros::init(argc,argv,"follower");
	ros::NodeHandle nh;
	ros::Rate loop_rate(10);

	ros::Publisher cmd_vel = nh.advertise<geometry_msgs::Twist>("/robot_1/cmd_vel",1000);
  ros::Subscriber odom_sub = nh.subscribe("/robot_0/base_pose_ground_truth",1000,odomCallback);
  ros::Subscriber odom2_sub = nh.subscribe("/robot_1/base_pose_ground_truth",1000,odom2Callback);

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

    double bearing = get_bearing( red_x, red_y, blue_x, blue_y, blue_theta ) ;
    double range = get_distance( red_x, red_y, blue_x, blue_y );
  


    printf( "range: %0.2f bearing: %0.2f blue_theta: %0.2f\n", range, bearing, blue_theta );
    
    rvel = bearing;

    //if( bearing < 0 ) rvel = bearing;
    //else if( bearing > 0 ) rvel = -bearing;

    lvel = range;
    if( range < 1.0 ) lvel = 0;
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
