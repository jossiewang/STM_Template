/*
 * TIM_IT.cpp
 *
 *  Created on: Jul 11, 2024
 *      Author: jw621
 */

#include "TIM_IT.h"
#include "dc_motor.h"

int t_ms;

void timer_setup(){
    HAL_TIM_Base_Start_IT(&htim2);

}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance == TIM2){
		t_ms++; //for debugging
        Eu22.sample_bag();
	}
}



