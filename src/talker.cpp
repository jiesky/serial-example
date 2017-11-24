#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
int main(int argc, char **argv)
{
 ros::init(argc, argv, "talker");
 ros::NodeHandle n;

 ros::Publisher command_pub = n.advertise<std_msgs::String>("write", 10);
 sleep(2);
 ros::Rate loop_rate(5);
 int count = 10;
 while (ros::ok())
 {
   loop_rate.sleep();
   std_msgs::String msg;
   std::stringstream ss_data;
   ss_data << "talker publish command " << count;
   msg.data = ss_data.str();
   ROS_INFO("%s", msg.data.c_str());
   command_pub.publish(msg);
   ros::spinOnce();
   ++count;
  }
  return 0;
}