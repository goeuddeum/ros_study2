#include "yh_turtle/my_turtle.h"

MyTurtle::MyTurtle()
{
    pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 10);
    sub = nh.subscribe("cmd_vel", 10, &MyTurtle::msgCallback, this);
    client = nh.serviceClient<std_srvs::Empty>("clear");
}

void MyTurtle::msgCallback(const geometry_msgs::Twist::ConstPtr& msg)
{
    if(msg->linear.z > 0)
    {
        call();
    }
    else
    {
         pub.publish(*msg);
    }
}

void MyTurtle::call(void)
{
    if (client.call(srv))
    {
        ROS_INFO("clear");
    }
    else
    {
        ROS_ERROR("Failed to clear");
    }
}