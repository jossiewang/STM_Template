/*
 * mainpp.cpp
 *
 *  Created on: Jul 10, 2024
 *      Author: jw621
 */

#include "mainpp.h"
#include "TIM_IT.h"
#include "ros_port.h"

void main_function(){
    /* setup */
    ros_setup();
    TIM_Start();

    while(1){
        /* loop */
        ros_sub();
    }
}



