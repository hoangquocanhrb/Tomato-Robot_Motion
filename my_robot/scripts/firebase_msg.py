#!/usr/bin/env python
import rospy
from std_msgs.msg import String
from firebase import firebase



def talker():
    pub = rospy.Publisher('activity', String, queue_size=20)
    rospy.init_node('Mr_Nam', anonymous=True)
    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        Firebase =  firebase.FirebaseApplication('https://nhung-fa233.firebaseio.com/', None)
        msg = str(Firebase.get('/change', 'remote'))
        rospy.loginfo(msg)
        pub.publish(msg)
        rate.sleep()
	#Firebase.put('/change', 'remote', 'for_ward')
	if msg != 'None' and msg != 'Auto':
		Firebase.put('/change', 'remote', 'None')
        elif msg == 'Auto':
		Firebase.put('/change', 'remote', 'Auto')

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
#firebase = firebase.FirebaseApplication('https://nhung-fa233.firebaseio.com/', None)
#result = firebase.get('/change', 'up')
#print(result)

