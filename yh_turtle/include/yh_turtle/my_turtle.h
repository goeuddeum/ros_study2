#ifndef MY_TURTLE_H
#define MY_TURTLE_H

#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

class MyTurtle
{
public:
    MyTurtle();
    void msgCallback(const geometry_msgs::Twist::ConstPtr& msg);
private:
    ros::NodeHandle nh;
    ros::Publisher pub;
    ros::Subscriber sub;
    geometry_msgs::Twist msg;
};

#endif //MY_TURTLE_H