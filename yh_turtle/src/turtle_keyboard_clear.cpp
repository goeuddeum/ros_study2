#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "yh_turtle/my_turtle.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "turtle_keyboard_clear");
    MyTurtle my_turtle;

    ros::spin();

    return 0;
}
