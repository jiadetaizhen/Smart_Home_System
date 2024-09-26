#ifndef __CONTROL_H__
#define __CONTROL_H__
#include "main.h"


#define NUM_SAMPLES 10


/*  PM2.5µÆ¿ª¹Ø*/
#define PM_LED_H 					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
#define PM_LED_L 					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);

void asr_control(void);
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);
uint32_t getAverageADCValue(void);

#endif 

