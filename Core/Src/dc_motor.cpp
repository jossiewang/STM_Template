/*
 * dc_motor.cpp
 *
 *  Created on: Jul 10, 2024
 *      Author: jw621
 */

#include "dc_motor.h"
#include "stm32f4xx_hal.h"

extern TIM_HandleTypeDef htim3; //encoder for Eu22
extern TIM_HandleTypeDef htim4; //encoder for odom
extern TIM_HandleTypeDef htimN; //PWM timer

DC_motor Eu22(44, 103, 0.001, &htim3);

void DC_motor_setup(){
    HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_1); //PA6
    HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_2); //PC7
    HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_1); //PD12
    HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_2); //PD13
}

DC_motor::DC_motor(double p, double i, double d, double res, double ratio, float span, TIM_HandleTypeDef* htimN){
	this->Kp = p;
	this->Ki = i;
	this->Kd = d;
	this->resolution = res;
	this->reduction_ratio = ratio;
    this->timespan = span;
    this->timer = htimN;
}

DC_motor::DC_motor(double res, double ratio, float span, TIM_HandleTypeDef* htimN){
	this->resolution = res;
	this->reduction_ratio = ratio;
    this->timespan = span;
    this->timer = htimN;
}

void DC_motor::encoder(){
    cnt_enc = __HAL_TIM_GetCounter(timer);
    rps_enc = (double) cnt_enc / (4*resolution * reduction_ratio * timespan);
    __HAL_TIM_SetCounter(timer, 0);

}

void DC_motor::sample_clr(){
    for(int i=0; i<1000; i++){
        this->response[i] = 0;
    }
}

void DC_motor::sample_bag(){

    encoder();
    if(rps_enc!=0){
        if(arraycnt<1000) response[arraycnt] = rps_enc;
        arraycnt++;
    }

}

