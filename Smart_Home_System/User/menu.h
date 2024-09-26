#ifndef __MENU_H__
#define __MENU_H__
#include "main.h"
#include "stm32f1xx_hal.h"

extern uint8_t rx;
extern uint8_t delayFlag;
extern uint16_t ADC_Value;
extern uint16_t a;

#define key0 							HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_11)
#define key1 							HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_10)
#define key2 							HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1)

/* LED开启和关闭 */
#define LED_H 						HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
#define LED_L 						HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);

/* 风扇开启和停止 */
#define FAN_GO					  do {HAL_GPIO_WritePin( GPIOB, GPIO_PIN_14, GPIO_PIN_SET);			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);}		while(0) 
#define FAN_STOP					do {HAL_GPIO_WritePin( GPIOB, GPIO_PIN_14, GPIO_PIN_SET) 	;		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15,  GPIO_PIN_SET);	}		while(0)

/* 晾衣杆上升 ，下降， 停止 */
#define Clothesline_GO    do {HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET) ;   	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);}		while(0)
#define Clothesline_BACK 	do {HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET) ;  	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);	}		while(0)
#define Clothesline_STOP	do {HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET) ;		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);}		while(0)

int menu1(void);
int menu2_win(void);
int menu2_led(void);
int menu2_air(void);
int menu2_fun(void);

#endif 
