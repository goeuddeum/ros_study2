#ifndef MY_TURTLE_H
#define MY_TURTLE_H

#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "std_srvs/Empty.h"

class MyTurtle
{
public:
    MyTurtle();
    void msgCallback(const geometry_msgs::Twist::ConstPtr& msg);
    void call(void);
private:
    ros::NodeHandle nh;
    ros::Publisher pub;
    ros::Subscriber sub;
    ros::ServiceClient client;
    geometry_msgs::Twist msg;
    std_srvs::Empty srv;
};

#endif //MY_TURTLE_H