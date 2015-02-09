#include <ros/ros.h>
#include <nav_msgs/Odometry.h>

float old_x = 0;
float old_y = 0;
float old_z = 0;

int plus_count = 0;
int minus_count = 0;

void posCallback(const nav_msgs::Odometry::ConstPtr &msg)
{
  float x = msg->pose.pose.position.x;
  float y = msg->pose.pose.position.y;
  float z = msg->pose.pose.orientation.z;

  float diffx = fabs( old_x - x );
  float diffy = fabs( old_y - y );
  float diffz = fabs( old_z - z );

  //ROS_INFO( "%0.2f %0.2f %0.2f", diffx, diffy, diffz );

  if( diffx > 0.01 || diffy > 0.01 || diffz > 0.001 )
  {
    //printf( "+" );
    plus_count++;
  }
  else
  {
    //printf( "-" );
    minus_count++;
  }

  fflush(stdout);

  old_x = x;
  old_y = y;
  old_z = z;
}

int main( int argc, char* argv[] )
{
  ros::init(argc,argv, "grader" );
  ros::NodeHandle nh;
  ros::Rate loop_rate(10);
  // subscribe to robot position data
  ros::Subscriber pos_sub = nh.subscribe("/odom", 1000, posCallback);

  // burn a little time
  loop_rate.sleep();
  ros::spinOnce();
  loop_rate.sleep();
  ros::spinOnce();
  loop_rate.sleep();
  ros::spinOnce();

  // loop for two minutes (no main control code)
  for( int i = 0; i < 1200; i++ )
  {
    loop_rate.sleep();
    ros::spinOnce();
  }
  FILE* outfile = fopen(".grade", "w" );
  if( !outfile )
  {
    fprintf( stderr, "error opening file for grading\n" );
  }
  fprintf( outfile, "%d %d\n", plus_count, minus_count );
  fclose(outfile);

  return 0;
}
