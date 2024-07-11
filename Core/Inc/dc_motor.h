/*
 * dc_motor.h
 *
 *  Created on: Jul 10, 2024
 *      Author: jw621
 */

#ifndef INC_DC_MOTOR_H_
#define INC_DC_MOTOR_H_

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"

class DC_motor{
    private:
        // motor system characteristic
        double resolution;
        double reduction_ratio;
        float timespan;

        // STM config
        TIM_HandleTypeDef* timer_enc;
        TIM_HandleTypeDef* timer_pwm;
        GPIO_TypeDef* INAport;
        uint16_t INApin;
        GPIO_TypeDef* INBport;
        uint16_t INBpin;

        //for system identification
        float response[1000];
        int arraycnt;

        //basic functions
        short cnt_enc; //mrmr: why npt int16_t?
        void encoder(); //read wheel speed

    public:
        double rps_cmd;
        double rps_enc;

        double Kp;
        double Ki;
        double Kd;
        double PWM;

        //constructor
        DC_motor(double res, double ratio, float span, TIM_HandleTypeDef* timer); //without PID
        DC_motor(double p, double i, double d, double res, double ratio, float span, 
                    TIM_HandleTypeDef* tim_enc, TIM_HandleTypeDef* tim_pwm, 
                    GPIO_TypeDef* inaPort, GPIO_TypeDef* inbPort, uint16_t inaPin, uint16_t inbPin)
        void sample_clr();
        void sample_bag();
        void PIDControl();
        void PWM();
        void performance(float* response); //use the response data to carry out analysis
};

extern DC_motor Eu22;

void DC_motor_setup();

#endif /* INC_DC_MOTOR_H_ */
