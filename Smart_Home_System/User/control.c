#include "control.h"
#include "usart.h"
#include "menu.h"
#include "Stepper.h"
#include "adc.h"

uint8_t delayFlag = 0;
uint16_t ADC_Value;
uint16_t ADC_Volt;
ADC_HandleTypeDef hadc;
ADC_ChannelConfTypeDef sConfig;
uint16_t a;
/*  ASR PRO串口指令*/
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART2) {
        switch (rx) {

            case 'A':
                Step_MOTOR_Stop1();
                break;
            case 'B':
                delayFlag = 1;
                break;
            case 'C':
                delayFlag = 2;
                break;
            case 'D':
                delayFlag = 3;
                break;
            case 'E':
                delayFlag = 4;
                break;
            case 'F':
                LED_H;
                break;
            case 'G':
                LED_L;
                break;
            case 'H':
                delayFlag = 5;
                break;
            case 'I':
                delayFlag = 6;
                break;
            case 'J':
                FAN_GO;
                break;
            case 'K':
                FAN_STOP;
                break;
            default:
                Step_MOTOR_Stop1();
                break;
        }

        HAL_UART_Receive_IT(&huart2, &rx, 1);
    }
}

/*  pm2.5模块adc*/

void GP2Y_Adc_Init(void)
{
    ADC_ChannelConfTypeDef sConfig = {0};

    // 初始化GPIO和ADC时钟
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_ADC1_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin              = GPIO_PIN_0;
    GPIO_InitStruct.Mode             = GPIO_MODE_ANALOG;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    // 初始化ADC
    hadc.Instance                = ADC1;
    hadc.Init.ScanConvMode       = ADC_SCAN_DISABLE;
    hadc.Init.ContinuousConvMode = DISABLE;
    hadc.Init.ExternalTrigConv   = ADC_SOFTWARE_START;
    hadc.Init.DataAlign          = ADC_DATAALIGN_RIGHT;
    hadc.Init.NbrOfConversion    = 1;
    HAL_ADC_Init(&hadc);

    // 配置ADC通道
    sConfig.Channel      = ADC_CHANNEL_0;
    sConfig.Rank         = 1;
    sConfig.SamplingTime = ADC_SAMPLETIME_239CYCLES_5;
    HAL_ADC_ConfigChannel(&hadc, &sConfig);

    HAL_ADC_Start(&hadc);
    HAL_ADCEx_Calibration_Start(&hadc);
}

uint16_t GP2Y_Get_Adc(void)
{
    HAL_ADC_Start(&hadc);
    HAL_ADC_PollForConversion(&hadc, HAL_MAX_DELAY);
    return HAL_ADC_GetValue(&hadc);
}

short GetGP2Y(void)
{
    uint32_t AD_PM;
    short result;
    double pm;

    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); // 打开红外二极管
    HAL_Delay(1);                                         // 延时1ms，延时时间到才进行采样

    AD_PM = GP2Y_Get_Adc(); // 采样，读取AD值

    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); // 关闭红外二极管
    HAL_Delay(10);                                      // 延时10ms，一个周期的最短时间

    pm     = (0.17 * AD_PM - 0.1) * 1000; // 电压-灰尘转换公式乘以1000单位换成ug/m3
    result = pm * 100;

    return result;
}

uint16_t GPY2_Get_Adc_Average(uint8_t times)
{
    uint32_t pm_val = 0;
    uint8_t t;

    for (t = 0; t < times; t++) {
        pm_val += GP2Y_Get_Adc();
        HAL_Delay(5);
    }

    return pm_val / times;
}

void asr_control()
{

    switch (delayFlag) {
        case 1:
            Step_MOTOR_Start1(180, 0);
            Step_MOTOR_Stop1();
            break;
        case 2:
            Step_MOTOR_Start1(180, 1);
            Step_MOTOR_Stop1();
            break;
        case 3:
            Step_MOTOR_Start2(180, 0);
            Step_MOTOR_Stop1();
            break;
        case 4:
            Step_MOTOR_Start2(180, 1);
            Step_MOTOR_Stop1();
            break;
        case 5:
            Clothesline_GO;
            HAL_Delay(1000);
            Clothesline_STOP;
            break;
        case 6:
            Clothesline_BACK;
            HAL_Delay(1000);
            Clothesline_STOP;
            break;
        default:
            Step_MOTOR_Stop1();
            break;
    }
    delayFlag = 0;
}

void RCCdelay_us(uint32_t udelay)
{
    __IO uint32_t Delay = udelay * 72 / 8; //(SystemCoreClock / 8U / 1000000U)
                                           // 见stm32f1xx_hal_rcc.c -- static void RCC_Delay(uint32_t mdelay)
    do {
        __nop();
    } while (Delay--);
}

uint32_t getAverageADCValue(void)
{
    uint32_t sum = 0;

    for (int i = 0; i < NUM_SAMPLES; i++) {
        PM_LED_L;
        RCCdelay_us(280);

        HAL_ADC_Start(&hadc1);
        HAL_ADC_PollForConversion(&hadc1, 50);
        RCCdelay_us(40);
        PM_LED_H;
        RCCdelay_us(9680);

        if (HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc1), HAL_ADC_STATE_REG_EOC)) {
            sum += HAL_ADC_GetValue(&hadc1);
        }
    }
    a = sum / NUM_SAMPLES;
    return a;
}
