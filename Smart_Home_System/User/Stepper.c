#include "Stepper.h"


void MOTOR_CONTROL1(uint16_t direction)//对电机进行控制，使用八拍
{
	static uint8_t step=0;
	if(1== direction)//控制电机方向
	{
		if(0==step)
		{
			step=8;
		}
		step--;
	}	
	else if(0== direction)
	{
		step++;
		if(8==step)
		{
			step=0;
		}
	}
	if(0==step)
	{
		MOTOR_A_H;
		MOTOR_B_L;
		MOTOR_C_L;
		MOTOR_D_L;
	}
	else if(1==step)
	{
		MOTOR_A_H;
		MOTOR_B_H;
		MOTOR_C_L;
		MOTOR_D_L;
	}
	else if(2==step)
	{
		MOTOR_A_L;
		MOTOR_B_H;
		MOTOR_C_L;
		MOTOR_D_L;
	}
	else if(3==step)
	{
		MOTOR_A_L;
		MOTOR_B_H;
		MOTOR_C_H;
		MOTOR_D_L;
	}
	else if(4==step)
	{
		MOTOR_A_L;
		MOTOR_B_L;
		MOTOR_C_H;
		MOTOR_D_L;
	}
	else if(5==step)
	{
		MOTOR_A_L;
		MOTOR_B_L;
		MOTOR_C_H;
		MOTOR_D_H;
	}
	else if(6==step)
	{
		MOTOR_A_L;
		MOTOR_B_L;
		MOTOR_C_L;
		MOTOR_D_H;
	}
	else if(7==step)
	{
		MOTOR_A_H;
		MOTOR_B_L;
		MOTOR_C_L;
		MOTOR_D_H;
	}
}
 
 
void MOTOR_CONTROL2(uint16_t direction)//对电机进行控制，使用八拍
{
	static uint8_t step=0;
	if(1== direction)//控制电机方向
	{
		if(0==step)
		{
			step=8;
		}
		step--;
	}	
	else if(0== direction)
	{
		step++;
		if(8==step)
		{
			step=0;
		}
	}
	if(0==step)
	{
		MOTOR_E_H;
		MOTOR_F_L;
		MOTOR_G_L;
		MOTOR_H_L;
	}
	else if(1==step)
	{
		MOTOR_E_H;
		MOTOR_F_H;
		MOTOR_G_L;
		MOTOR_H_L;
	}
	else if(2==step)
	{
		MOTOR_E_L;
		MOTOR_F_H;
		MOTOR_G_L;
		MOTOR_H_L;
	}
	else if(3==step)
	{
		MOTOR_E_L;
		MOTOR_F_H;
		MOTOR_G_H;
		MOTOR_H_L;
	}
	else if(4==step)
	{
		MOTOR_E_L;
		MOTOR_F_L;
		MOTOR_G_H;
		MOTOR_H_L;
	}
	else if(5==step)
	{
		MOTOR_E_L;
		MOTOR_F_L;
		MOTOR_G_H;
		MOTOR_H_H;
	}
	else if(6==step)
	{
		MOTOR_E_L;
		MOTOR_F_L;
		MOTOR_G_L;
		MOTOR_H_H;
	}
	else if(7==step)
	{
		MOTOR_E_H;
		MOTOR_F_L;
		MOTOR_G_L;
		MOTOR_H_H;
	}
}
 
 
void Step_MOTOR_Start1(uint16_t angle,uint8_t direction)//电机启动
{
	int i=0;
	int pulse =(int)((float)(angle*128/5.625));//脉冲与步距角的关系
	for(i=0;i<pulse;i++)
	{
		MOTOR_CONTROL1(direction);
		HAL_Delay(1);
	}
}


void Step_MOTOR_Start2(uint16_t angle,uint8_t direction)//电机启动
{
	int i=0;
	int pulse =(int)((float)(angle*128/5.625));//脉冲与步距角的关系
	for(i=0;i<pulse;i++)
	{
		MOTOR_CONTROL2(direction);
		HAL_Delay(1);
	}
}
 
void Step_MOTOR_Stop1(void)//四相都是低电平代表电机停止
{
	MOTOR_A_L;
	MOTOR_B_L;
	MOTOR_C_L;
	MOTOR_D_L;
}
void Step_MOTOR_Stop2(void)//四相都是低电平代表电机停止
{
	MOTOR_E_L;
	MOTOR_F_L;
	MOTOR_G_L;
	MOTOR_H_L;
}

