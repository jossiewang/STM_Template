/*
 * TIM_IT.h
 *
 *  Created on: Jul 11, 2024
 *      Author: jw621
 */

#ifndef INC_TIM_IT_H_
#define INC_TIM_IT_H_

#include "stm32f4xx_hal.h"

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;

int t_ms;

void timer_setup();

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

#endif /* INC_TIM_IT_H_ */
