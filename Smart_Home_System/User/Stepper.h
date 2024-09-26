#ifndef __Stepper_H
#define __Stepper_H 

#include "main.h"

#define MOTOR_A_H HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);
#define MOTOR_A_L HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
	
#define MOTOR_B_H HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
#define MOTOR_B_L HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
	
#define MOTOR_C_H HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET);
#define MOTOR_C_L HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET);
	
#define MOTOR_D_H HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_SET);
#define MOTOR_D_L HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);


#define MOTOR_E_H HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);
#define MOTOR_E_L HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);
	
#define MOTOR_F_H HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
#define MOTOR_F_L HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
	
#define MOTOR_G_H HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);
#define MOTOR_G_L HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
	
#define MOTOR_H_H HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);
#define MOTOR_H_L HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);


void MOTOR_CONTROL1(uint16_t direction);
void MOTOR_CONTROL2(uint16_t direction);
void Step_MOTOR_Start1(uint16_t angle,uint8_t direction);
void Step_MOTOR_Start2(uint16_t angle,uint8_t direction);
void Step_MOTOR_Stop1(void);
void Step_MOTOR_Stop2(void);


 


#endif
