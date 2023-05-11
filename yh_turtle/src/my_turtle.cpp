#include "yh_turtle/my_turtle.h"

MyTurtle::MyTurtle()
{
    pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 10);
    sub = nh.subscribe("cmd_vel", 10, &MyTurtle::msgCallback, this);
}

void MyTurtle::msgCallback(const geometry_msgs::Twist::ConstPtr& msg)
{
    pub.publish(*msg);

}