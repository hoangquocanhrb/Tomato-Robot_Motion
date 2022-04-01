
#include <ros.h>
#include<std_msgs/String.h>
#include<Servo.h>
#include<std_msgs/UInt16.h>

#include<geometry_msgs/Twist.h>
#include"robot.h"

using namespace std;
String data;
ros::NodeHandle n;
Servo servo;

TomatoCar *car = new TomatoCar ;

const short chan_xung1 = 6;
const short chan_xung2 = 11;
const short id1 = 7;
const short id2 = 12;

const short trig = 4;
const short echo = 2;

geometry_msgs::Twist info;
void msgCallBack(const std_msgs::String& msg)
{
    data = msg.data;
}

ros::Subscriber<std_msgs::String> sub("activity", msgCallBack);
ros::Publisher chatter("chatter", &info);

void setup()
{
  n.initNode();
  n.subscribe(sub);
  n.advertise(chatter);
  car->configCar(id1, 195, chan_xung1, id2, 195, chan_xung2, 10, 10); //Cấu hình ban đầu cho xe 
  
  pinMode(id1,OUTPUT);
  pinMode(id2,OUTPUT);
  pinMode(chan_xung1,OUTPUT);
  pinMode(chan_xung2,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  servo.write(90);
}

void loop()
{
  unsigned long duration;
  int distance;
  digitalWrite(trig,0);   
  delayMicroseconds(2);
  digitalWrite(trig,1);   
  delayMicroseconds(5);   
  digitalWrite(trig,0);
  duration = pulseIn(echo,HIGH);
  distance = int(duration/2/29.412);
  
  if(data == "Right")
  {
    car->Turn_right();
  }
  else if(data == "Left")
  {
    car->Turn_left();
  }
  else if(data == "Straight")
  {
    car->ForWard();
  }
  else if(data == "Auto")
  {
    if(distance < 50) 
    {
      car->Turn_right();
      car->Move();
      delay(5000);
    }
    else 
    {
      car->ForWard();
    }
  }
  else if(data == "Back")
  {
    car->BackWard();
  }
  else if(data == "Slow")
  {
    car->GiamToc();
  }
   
  else if(data == "Stop")
  {
    car->Stop();
  }
  
  car->Move();

  info.linear.x = car->m1.getMSpeed();
  info.linear.y = car->m2.getMSpeed();
  info.linear.z = car->m1.getMDir();
  info.angular.z = distance;
  chatter.publish(&info);
  n.spinOnce();
  delay(500);
  
}
