#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int32.h"
#include "std_msgs/Int16.h"

void Callback(const std_msgs::Int16)
{
  std_msgs::Int16 return_msg;

  ROS_INFO("I heard: [%d]", return_msg.data);
}

int main(int argc, char **argv)
{
  ros::Publisher PubToCentralController;
  ros::Publisher PubToModeController;
  ros::Subscriber return_modeController;

  ros::init(argc, argv, "LineDetect_node");
  ros::NodeHandle nh;

  return_modeController = nh.subscribe("return_signal",1,Callback);

  PubToModeController = nh.advertise<std_msgs::Int16>("return_signal", 1);
  PubToCentralController = nh.advertise<std_msgs::Int16>("return_signal",1);


  ros::Rate loop_rate(10);
  while (ros::ok())
  {
    std_msgs::Int16 msg;
    PubToModeController.publish(msg);
    PubToCentralController.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
  }

  return 0;
}
