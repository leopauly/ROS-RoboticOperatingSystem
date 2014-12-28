/* 
 * This program contains a rosserial subscriber node which makes the arduino a ROS node.
 * The node is subscribing to the rostopic "toggle_led"
 * The message name is toggle_msg of type std_msgs::Strings
 * Turns on the led13 if the recieved message is "ons" ,else turns it off
 * By: @leopauly (meetleopauly@yahoo.com)
 */

#include <ros.h>
#include <std_msgs/String.h>

ros::NodeHandle  nh;
String leodata;

void messageCb(const std_msgs::String& toggle_msg)
{  leodata=toggle_msg.data ;
  
}

ros::Subscriber<std_msgs::String> sub("toggle_led", &messageCb );

void setup()
{ 
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
  
}

void loop()
{  
  nh.spinOnce();
  if(leodata == "ons")
  {digitalWrite(13, HIGH);}
  else
  {digitalWrite(13,LOW);}
  delay(1);
}
