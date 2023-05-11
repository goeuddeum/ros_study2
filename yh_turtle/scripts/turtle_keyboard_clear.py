#!/usr/bin/python
#-*- coding: utf-8 -*-

import rospy
from geometry_msgs.msg import Twist
from turtle_clear import TurtleClear

class MyTurtle(TurtleClear):
    def __init__(self):
        super().__init__()
        self.pub = rospy.Publisher("turtle1/cmd_vel",Twist,queue_size=20)
        self.sub = rospy.Subscriber("turtle1/cmd_vel",Twist,self.msgCallback)

    def msgCallback(self,msg):
        if msg.linear.z > 0:
            self.call()
        else:
            self.pub.publish(msg)

rospy.init_node("turtle_keyboard_clear")
my_turtle = MyTurtle()
rospy.spin()