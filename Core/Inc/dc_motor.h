/*
 * dc_motor.h
 *
 *  Created on: Jul 10, 2024
 *      Author: jw621
 */

#ifndef INC_DC_MOTOR_H_
#define INC_DC_MOTOR_H_

#include "stm32f4xx_hal.h"

class DC_motor{
public:
	static double freq;

	DC_motor( TIM_HandleTypeDef *htim_enc, double res ,double ratio ,
			double p, double i, double d, TIM_HandleTypeDef *htim_motor, uint32_t Channel_motor );
	double SP = 0,PV = 0;
	int pulse;
	//encoder
	void encoder();
	TIM_HandleTypeDef *encoder_TIM;
	double reduction_ratio;
	int resolution;
	int enc;
	//PID
	void PID_PWM_Convertor(double set_point,double present_var);
	double kp, ki, kd;
	//output
	void output( int Pulse, GPIO_TypeDef *GPIO_A, uint16_t GPIO_Pin_A, GPIO_TypeDef *GPIO_B, uint16_t GPIO_Pin_B);
	TIM_HandleTypeDef *PWM_TIM;
	uint32_t PWM_Channel;
};

extern DC_motor Eu22;

#endif /* INC_DC_MOTOR_H_ */
