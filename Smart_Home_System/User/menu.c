#include "oled.h"
#include "menu.h"
#include "Stepper.h"
#include "usart.h"
#include "adc.h"
#include "control.h"

int menu1() // 一级菜单
{
    int flag = 1;
    // 窗户和窗帘
    OLED_ShowChinese(16, 0, 0, 16, 1);
    OLED_ShowChinese(32, 0, 1, 16, 1);
    OLED_ShowChinese(48, 0, 19, 16, 1);
    OLED_ShowChinese(64, 0, 2, 16, 1);
    OLED_ShowChinese(80, 0, 3, 16, 1);
    // 灯和晾晒衣服
    OLED_ShowChinese(16, 16, 20, 16, 1);
    OLED_ShowChinese(32, 16, 19, 16, 1);
    OLED_ShowChinese(48, 16, 8, 16, 1);
    OLED_ShowChinese(64, 16, 9, 16, 1);
    OLED_ShowChinese(80, 16, 10, 16, 1);
    OLED_ShowChinese(96, 16, 11, 16, 1);
    // 净化空气
    OLED_ShowChinese(16, 32, 13, 16, 1);
    OLED_ShowChinese(32, 32, 14, 16, 1);
    OLED_ShowChinese(48, 32, 15, 16, 1);
    OLED_ShowChinese(64, 32, 16, 16, 1);
    // 空气质量
    OLED_ShowChinese(16, 48, 15, 16, 1);
    OLED_ShowChinese(32, 48, 16, 16, 1);
    OLED_ShowChinese(48, 48, 17, 16, 1);
    OLED_ShowChinese(64, 48, 18, 16, 1);
    OLED_ShowString(0, 0, ">", 16, 1);
    OLED_Refresh();

    while (1) {

        asr_control();
        OLED_ShowChar(100, 1, rx, 16, 1);
        OLED_Refresh();
        if (key0 == 0) {
            HAL_Delay(10);
            while (key0 == 0);
            HAL_Delay(10);
            flag++;
            if (flag == 5) flag = 1;
        }

        if (key1 == 0) // 确认键
        {
            HAL_Delay(10);
            while (key1 == 0);
            HAL_Delay(10);
            OLED_Clear();
            return (flag);
        }
        if (key2 == 0) // 返回键
        {
            HAL_Delay(10);
            while (key2 == 0);
            HAL_Delay(10);
            OLED_Clear();
            return 0;
        }
        switch (flag) {
            case 1: {
                OLED_ShowString(0, 0, ">", 16, 1);
                OLED_ShowString(0, 16, " ", 16, 1);
                OLED_ShowString(0, 32, " ", 16, 1);
                OLED_ShowString(0, 48, " ", 16, 1);
                OLED_Refresh();

            } break;
            case 2: {
                OLED_ShowString(0, 0, " ", 16, 1);
                OLED_ShowString(0, 16, ">", 16, 1);
                OLED_ShowString(0, 32, " ", 16, 1);
                OLED_ShowString(0, 48, " ", 16, 1);
                OLED_Refresh();
            } break;
            case 3: {
                OLED_ShowString(0, 0, " ", 16, 1);
                OLED_ShowString(0, 16, " ", 16, 1);
                OLED_ShowString(0, 32, ">", 16, 1);
                OLED_ShowString(0, 48, " ", 16, 1);
                OLED_Refresh();
            } break;
            case 4: {
                OLED_ShowString(0, 0, " ", 16, 1);
                OLED_ShowString(0, 16, " ", 16, 1);
                OLED_ShowString(0, 32, " ", 16, 1);
                OLED_ShowString(0, 48, ">", 16, 1);
                OLED_Refresh();

            } break;
        }
    }
}

int menu2_win()
{
    int menu3 = 1;
    // 打开窗户
    OLED_ShowChinese(16, 0, 4, 16, 1);
    OLED_ShowChinese(32, 0, 5, 16, 1);
    OLED_ShowChinese(48, 0, 2, 16, 1);
    OLED_ShowChinese(64, 0, 1, 16, 1);
    OLED_ShowString(0, 0, ">", 16, 1);
    // 关窗户
    OLED_ShowChinese(16, 16, 6, 16, 1);
    OLED_ShowChinese(32, 16, 7, 16, 1);
    OLED_ShowChinese(48, 16, 0, 16, 1);
    OLED_ShowChinese(64, 16, 1, 16, 1);
    // 打开窗帘
    OLED_ShowChinese(16, 32, 4, 16, 1);
    OLED_ShowChinese(32, 32, 5, 16, 1);
    OLED_ShowChinese(48, 32, 2, 16, 1);
    OLED_ShowChinese(64, 32, 3, 16, 1);
    // 关闭窗帘
    OLED_ShowChinese(16, 48, 6, 16, 1);
    OLED_ShowChinese(32, 48, 7, 16, 1);
    OLED_ShowChinese(48, 48, 2, 16, 1);
    OLED_ShowChinese(64, 48, 3, 16, 1);
    OLED_Refresh();
    while (1) {
        asr_control();
        if (key0 == 0) {
            HAL_Delay(10);
            while (key0 == 0);
            HAL_Delay(10);
            menu3++;
            if (menu3 >= 5) menu3 = 1;
            switch (menu3) {
                case 1: {
                    OLED_ShowString(0, 0, ">", 16, 1);
                    OLED_ShowString(0, 16, " ", 16, 1);
                    OLED_ShowString(0, 32, " ", 16, 1);
                    OLED_ShowString(0, 48, " ", 16, 1);
                    OLED_Refresh();
                } break;
                case 2: {

                    OLED_ShowString(0, 0, " ", 16, 1);
                    OLED_ShowString(0, 16, ">", 16, 1);
                    OLED_ShowString(0, 32, " ", 16, 1);
                    OLED_ShowString(0, 48, " ", 16, 1);
                    OLED_Refresh();

                } break;
                case 3: {
                    OLED_ShowString(0, 0, " ", 16, 1);
                    OLED_ShowString(0, 16, " ", 16, 1);
                    OLED_ShowString(0, 32, ">", 16, 1);
                    OLED_ShowString(0, 48, " ", 16, 1);
                    OLED_Refresh();

                } break;
                case 4: {
                    OLED_ShowString(0, 0, " ", 16, 1);
                    OLED_ShowString(0, 16, " ", 16, 1);
                    OLED_ShowString(0, 32, " ", 16, 1);
                    OLED_ShowString(0, 48, ">", 16, 1);
                    OLED_Refresh();

                } break;
            }
        }

        if (key1 == 0) // 确认
        {
            HAL_Delay(10);
            while (key1 == 0);
            HAL_Delay(10);
            if (menu3 == 1) Step_MOTOR_Start1(180, 0);
            Step_MOTOR_Stop1();
            if (menu3 == 2) Step_MOTOR_Start1(180, 1);
            Step_MOTOR_Stop1();
            if (menu3 == 3) Step_MOTOR_Start2(180, 0);
            Step_MOTOR_Stop2();
            if (menu3 == 4) Step_MOTOR_Start2(180, 1);
            Step_MOTOR_Stop2();
        }
        if (key2 == 0) {
            HAL_Delay(10);
            while (key2 == 0);
            HAL_Delay(10);
            OLED_Clear();
            return 0;
        }
    }
}

int menu2_led()
{
    int menu3 = 1;
    // 打开灯光
    OLED_ShowChinese(16, 0, 4, 16, 1);
    OLED_ShowChinese(32, 0, 5, 16, 1);
    OLED_ShowChinese(48, 0, 20, 16, 1);
    OLED_ShowChinese(64, 0, 21, 16, 1);
    OLED_ShowString(0, 0, ">", 16, 1);
    // 关闭灯光
    OLED_ShowChinese(16, 16, 6, 16, 1);
    OLED_ShowChinese(32, 16, 7, 16, 1);
    OLED_ShowChinese(48, 16, 20, 16, 1);
    OLED_ShowChinese(64, 16, 21, 16, 1);
    // 降下衣杆
    OLED_ShowChinese(16, 32, 24, 16, 1);
    OLED_ShowChinese(32, 32, 25, 16, 1);
    OLED_ShowChinese(48, 32, 10, 16, 1);
    OLED_ShowChinese(64, 32, 12, 16, 1);
    // 升起衣杆
    OLED_ShowChinese(16, 48, 22, 16, 1);
    OLED_ShowChinese(32, 48, 23, 16, 1);
    OLED_ShowChinese(48, 48, 10, 16, 1);
    OLED_ShowChinese(64, 48, 12, 16, 1);
    OLED_Refresh();
    while (1) {
        asr_control();
        if (key0 == 0) {
            HAL_Delay(10);
            while (key0 == 0);
            HAL_Delay(10);
            menu3++;
            if (menu3 >= 5) menu3 = 1;
            switch (menu3) {
                case 1: {
                    OLED_ShowString(0, 0, ">", 16, 1);
                    OLED_ShowString(0, 16, " ", 16, 1);
                    OLED_ShowString(0, 32, " ", 16, 1);
                    OLED_ShowString(0, 48, " ", 16, 1);
                    OLED_Refresh();

                } break;
                case 2: {
                    OLED_ShowString(0, 0, " ", 16, 1);
                    OLED_ShowString(0, 16, ">", 16, 1);
                    OLED_ShowString(0, 32, " ", 16, 1);
                    OLED_ShowString(0, 48, " ", 16, 1);
                    OLED_Refresh();
                } break;
                case 3: {
                    OLED_ShowString(0, 0, " ", 16, 1);
                    OLED_ShowString(0, 16, " ", 16, 1);
                    OLED_ShowString(0, 32, ">", 16, 1);
                    OLED_ShowString(0, 48, " ", 16, 1);
                    OLED_Refresh();
                } break;
                case 4: {
                    OLED_ShowString(0, 0, " ", 16, 1);
                    OLED_ShowString(0, 16, " ", 16, 1);
                    OLED_ShowString(0, 32, " ", 16, 1);
                    OLED_ShowString(0, 48, ">", 16, 1);
                    OLED_Refresh();
                } break;
            }
        }

        if (key1 == 0) // 确认
        {
            HAL_Delay(10);
            while (key1 == 0);
            HAL_Delay(10);
            if (menu3 == 1) LED_H; // 开灯
            if (menu3 == 2) LED_L; // 关灯
            if (menu3 == 3) Clothesline_GO;
            HAL_Delay(1000);
            Clothesline_STOP; // 降下晾衣杆
            if (menu3 == 4) Clothesline_BACK;
            HAL_Delay(1000);
            Clothesline_STOP; // 升起晾衣杆
        }
        if (key2 == 0) {
            HAL_Delay(10);
            while (key2 == 0);
            HAL_Delay(10);
            OLED_Clear();
            return 0;
        }
    }
}

/* */

int menu2_fun()
{
    int menu3 = 1;
    // 打开空气净化
    OLED_ShowChinese(16, 0, 4, 16, 1);
    OLED_ShowChinese(32, 0, 5, 16, 1);
    OLED_ShowChinese(48, 0, 15, 16, 1);
    OLED_ShowChinese(64, 0, 16, 16, 1);
    OLED_ShowChinese(80, 0, 13, 16, 1);
    OLED_ShowChinese(96, 0, 14, 16, 1);
    // 关闭空气净化
    OLED_ShowChinese(16, 16, 6, 16, 1);
    OLED_ShowChinese(32, 16, 7, 16, 1);
    OLED_ShowChinese(48, 16, 15, 16, 1);
    OLED_ShowChinese(64, 16, 16, 16, 1);
    OLED_ShowChinese(80, 16, 13, 16, 1);
    OLED_ShowChinese(96, 16, 14, 16, 1);
    OLED_ShowString(0, 0, ">", 16, 1);
    OLED_Refresh();
    while (1) {
        asr_control();
        if (key0 == 0) {
            HAL_Delay(10);
            while (key0 == 0);
            HAL_Delay(10);
            menu3++;
            if (menu3 >= 3) menu3 = 1;
            switch (menu3) {
                case 1: {
                    OLED_ShowString(0, 0, ">", 16, 1);
                    OLED_ShowString(0, 16, " ", 16, 1);
                    OLED_ShowString(0, 32, " ", 16, 1);
                    OLED_ShowString(0, 48, " ", 16, 1);
                    OLED_Refresh();

                } break;
                case 2: {

                    OLED_ShowString(0, 0, " ", 16, 1);
                    OLED_ShowString(0, 16, ">", 16, 1);
                    OLED_ShowString(0, 32, " ", 16, 1);
                    OLED_ShowString(0, 48, " ", 16, 1);
                    OLED_Refresh();

                } break;
                case 3: {
                    OLED_ShowString(0, 0, " ", 16, 1);
                    OLED_ShowString(0, 16, " ", 16, 1);
                    OLED_ShowString(0, 32, ">", 16, 1);
                    OLED_ShowString(0, 48, " ", 16, 1);
                    OLED_Refresh();

                } break;
                case 4: {
                    OLED_ShowString(0, 0, " ", 16, 1);
                    OLED_ShowString(0, 16, " ", 16, 1);
                    OLED_ShowString(0, 32, " ", 16, 1);
                    OLED_ShowString(0, 48, ">", 16, 1);
                    OLED_Refresh();

                } break;
            }
        }

        if (key1 == 0) // 确认
        {
            HAL_Delay(10);
            while (key1 == 0);
            HAL_Delay(10);
            if (menu3 == 1) FAN_GO;
            if (menu3 == 2) FAN_STOP;
        }
        if (key2 == 0) {
            HAL_Delay(10);
            while (key2 == 0);
            HAL_Delay(10);
            OLED_Clear();
            return 0;
        }
    }
}
/* pm2.5菜单  空气质量*/
int menu2_air()

{

    OLED_ShowChinese(32, 0, 15, 16, 1);
    OLED_ShowChinese(48, 0, 16, 16, 1);
    OLED_ShowChinese(64, 0, 17, 16, 1);
    OLED_ShowChinese(82, 0, 18, 16, 1);
    OLED_ShowString(32, 32, "P", 16, 1);
    OLED_ShowString(40, 32, "M", 16, 1);
    OLED_ShowString(48, 32, "2", 16, 1);
    OLED_ShowString(56, 32, ".", 16, 1);
    OLED_ShowString(64, 32, "5", 16, 1);
    OLED_ShowString(72, 32, ":", 16, 1);
    OLED_Refresh();
    while (1) {

        getAverageADCValue();
        OLED_ShowNum(80, 32, (0.17 * a - 0.1) / 10, 3, 16, 1);
        OLED_Refresh();

        if (key2 == 0) {
            HAL_Delay(10);
            while (key2 == 0);
            HAL_Delay(10);
            OLED_Clear();
            return 0;
        }
    }
}
