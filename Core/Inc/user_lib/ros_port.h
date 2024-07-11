/*
 * ros_port.h
 *
 *  Created on: Jul 11, 2024
 *      Author: user
 */

#ifndef INC_ROS_PORT_H_
#define INC_ROS_PORT_H_

#include "ros.h"
#include "STM32Hardware.h"
#include "geometry_msgs/Twist.h"
#include "std_msgs/Int64.h"

extern geometry_msgs::Twist speed;

void vel_callback(const std_msgs::Int64 &msg);
//...

void ros_setup();
void ros_sub();
void ros_pub();

#endif /* INC_ROS_PORT_H_ */
