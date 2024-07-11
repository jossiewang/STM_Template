/*
 * ros_port.cpp
 *
 *  Created on: Jul 11, 2024
 *      Author: user
 */

#include "ros_port.h"

int count;
// ros variables
geometry_msgs::Twist speed; 
ros::NodeHandle nh;
ros::Subscriber<std_msgs::Int64> sub("counting", vel_callback);
ros::Publisher pub_vel("/realspeed", &speed);

void vel_callback(const std_msgs::Int64 &msg)
{
   count = msg.data;
}

void ros_setup(void)
{
    nh.initNode();
    nh.subscribe(sub);
    nh.advertise(pub_vel);
}

void ros_sub(void)
{
    nh.spinOnce();
}

void ros_pub(void)
{
//    speed.linear.x = rVx;
    //....
    pub_vel.publish(&speed);
}



///* UART Communication */
//void Error_Handler(void)
//{
//  /* USER CODE BEGIN Error_Handler_Debug */
//  /* User can add his own implementation to report the HAL error return state */
//  __disable_irq();
//  while (1)
//  {
//  }
//  /* USER CODE END Error_Handler_Debug */
//}
//
//static void MX_USART3_UART_Init(void)
//{
//
//  /* USER CODE BEGIN USART3_Init 0 */
//
//  /* USER CODE END USART3_Init 0 */
//
//  /* USER CODE BEGIN USART3_Init 1 */
//
//  /* USER CODE END USART3_Init 1 */
//  huart3.Instance = USART3;
//  huart3.Init.BaudRate = 115200;
//  huart3.Init.WordLength = UART_WORDLENGTH_8B;
//  huart3.Init.StopBits = UART_STOPBITS_1;
//  huart3.Init.Parity = UART_PARITY_NONE;
//  huart3.Init.Mode = UART_MODE_TX_RX;
//  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
//  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
//  huart3.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
//  huart3.Init.ClockPrescaler = UART_PRESCALER_DIV1;
//  huart3.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
//  if (HAL_UART_Init(&huart3) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  if (HAL_UARTEx_SetTxFifoThreshold(&huart3, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  if (HAL_UARTEx_SetRxFifoThreshold(&huart3, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  if (HAL_UARTEx_DisableFifoMode(&huart3) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  /* USER CODE BEGIN USART3_Init 2 */
//
//  /* USER CODE END USART3_Init 2 */
//
//}
//
//void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart){
//    if(huart == &huart3){
//    // set velocity 0 before uart reinitialization
//    	count = 0;
//
//		HAL_UART_DeInit(&huart3);
//		MX_USART3_UART_Init();
//		nh.getHardware()->init();
//    }
//}
//
//void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
//{
//    nh.getHardware()->flush();
//}
//
//
//
