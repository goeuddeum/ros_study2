#!/usr/bin/python
#-*- coding: utf-8 -*-

import rospy
from std_srvs.srv import Empty

class TurtleClear:
    def __init__(self):
        self.client = rospy.ServiceProxy("clear", Empty)

    def call(self):
        try:
            self.client()
            rospy.loginfo("Clear")
        except rospy.ServiceException as e:
            rospy.loginfo("Failde : %s", e)

if __name__ == "__main__":
    rospy.init_node("turtle_clear")
    turtle_clear = TurtleClear()
    turtle_clear.call()
