#include "ros/ros.h"
#include "ros_mscl/DeviceSettings.h"
#include <cstdlib>


int main(int argc, char **argv){

  ros::init(argc, argv, "device_settings_client");

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<ros_mscl::DeviceSettings>("DeviceSettings");
  ros_mscl::DeviceSettings srv;

  srv.request.function_selector = atoll(argv[1]);

  if (client.call(srv))
  {
      if (srv.response.success)
      {
        ROS_INFO("success");
      }
  }
  else
  {
    ROS_INFO("Failed to call service");
  }
  return 0;
}
