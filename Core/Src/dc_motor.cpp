/*
 * dc_motor.cpp
 *
 *  Created on: Jul 10, 2024
 *      Author: jw621
 */

#include "dc_motor.h"
#include "math.h"
#define pi 3.1415926535897932384

//motor Instance
DC_motor::DC_motor( TIM_HandleTypeDef *htim_enc, double res ,double ratio ,
		double p, double i, double d, TIM_HandleTypeDef *htim_motor, uint32_t Channel_motor ){
	/*encoder parameter*/
	this->encoder_TIM = htim_enc;
	this->reduction_ratio = ratio;
	this->resolution = res;
	/*PID parameter*/
	this->kp = p;
	this->ki = i;
	this->kd = d;
	/*output parameter*/
	this->PWM_TIM = htim_motor;
	this->PWM_Channel = Channel_motor;
}
// step 1
/*return angular velocity*/
void DC_motor::encoder(){
	enc = __HAL_TIM_GetCounter(encoder_TIM);
	__HAL_TIM_SetCounter(encoder_TIM,0);
	PV = (double) enc/(4*resolution*reduction_ratio*freq*2*pi);
}
// step 2
/*return pulse*/
void DC_motor::PID_PWM_Convertor( double set_point, double present_var ){
	double error, differential, u = 0;
	static double integral, prev_u = 0;
	//Proportion
	error = set_point - present_var;
	//integral
	integral += error / freq;
	if (ki * integral > 1) integral = 1/ki;
	else if (ki * integral < -1) integral = -1/ki;
	//differential
	differential = (u - prev_u) * freq;
	prev_u = u;
	//PWM_Ratio
	u = kp * error + ki * integral + kd * differential;
	if (u > 1) u = 1;
	else if (u < -1) u = -1;

	pulse = (int) u*PWM_TIM->Instance->ARR;
}
// step 3
/*GPIO output*/
void DC_motor::output(int Pulse, GPIO_TypeDef *GPIO_A, uint16_t GPIO_Pin_A, GPIO_TypeDef *GPIO_B, uint16_t GPIO_Pin_B){
	__HAL_TIM_SET_COMPARE(PWM_TIM, PWM_Channel, abs(Pulse));
	if(Pulse >= 0){
		HAL_GPIO_WritePin(GPIO_A, GPIO_Pin_A, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIO_B, GPIO_Pin_B, GPIO_PIN_RESET);
	}
	else{
		HAL_GPIO_WritePin(GPIO_A, GPIO_Pin_A, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIO_B, GPIO_Pin_B, GPIO_PIN_SET);
	}
}