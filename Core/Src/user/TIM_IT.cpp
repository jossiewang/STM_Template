/*
 * TIM_IT.cpp
 *
 *  Created on: Jul 11, 2024
 *      Author: jw621
 */

#include "TIM_IT.h"
#include "dc_motor.h"

int t_ms = 0;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance == TIM2){
		t_ms++; //for debbugging
	}
}

void TIM_Start(){
    HAL_TIM_Base_Start_IT(&htim2);
//	HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_1); //PA6
//    HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_2); //PC7
//    HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_1); //PD12
//    HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_2); //PD13


	//construct dc motor
	// DC_motor Eu22(44, 103, 0.001, &htim3);
}


