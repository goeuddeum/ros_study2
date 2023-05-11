#!/usr/bin/python
# -*- coding : utf-8 -*-

import rospy
from geometry_msgs.msg import Twist

pub=rospy.Publisher("turtle1/cmd_vel", Twist,queue_size=20)

def msgCallback(msg):
    pub.publish(msg)

if __name__=="__main__":
    rospy.init_node("turtle_keyboard")
    rospy.Subscriber("cmd_vel", Twist,msgCallback,queue_size=10)

    rospy.spin()
