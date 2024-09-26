#include "Stepper.h"


void MOTOR_CONTROL1(uint16_t direction)//�Ե�����п��ƣ�ʹ�ð���
{
	static uint8_t step=0;
	if(1== direction)//���Ƶ������
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
 
 
void MOTOR_CONTROL2(uint16_t direction)//�Ե�����п��ƣ�ʹ�ð���
{
	static uint8_t step=0;
	if(1== direction)//���Ƶ������
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
 
 
void Step_MOTOR_Start1(uint16_t angle,uint8_t direction)//�������
{
	int i=0;
	int pulse =(int)((float)(angle*128/5.625));//�����벽��ǵĹ�ϵ
	for(i=0;i<pulse;i++)
	{
		MOTOR_CONTROL1(direction);
		HAL_Delay(1);
	}
}


void Step_MOTOR_Start2(uint16_t angle,uint8_t direction)//�������
{
	int i=0;
	int pulse =(int)((float)(angle*128/5.625));//�����벽��ǵĹ�ϵ
	for(i=0;i<pulse;i++)
	{
		MOTOR_CONTROL2(direction);
		HAL_Delay(1);
	}
}
 
void Step_MOTOR_Stop1(void)//���඼�ǵ͵�ƽ������ֹͣ
{
	MOTOR_A_L;
	MOTOR_B_L;
	MOTOR_C_L;
	MOTOR_D_L;
}
void Step_MOTOR_Stop2(void)//���඼�ǵ͵�ƽ������ֹͣ
{
	MOTOR_E_L;
	MOTOR_F_L;
	MOTOR_G_L;
	MOTOR_H_L;
}

