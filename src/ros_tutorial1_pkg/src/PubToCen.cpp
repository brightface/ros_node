#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int16.h"

void chaterCallback(const std_msgs::Int16 &msg)
{
  ROS_INFO("I heard: [%d]", msg.data);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "PubToCen");
  ros::NodeHandle nh;

  ros::Subscriber sub = nh.subscribe("chatter", 1000, chaterCallback);

  ros::spin();

  return 0;
}
