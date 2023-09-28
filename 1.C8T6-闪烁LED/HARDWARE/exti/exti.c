#include "exti.h"
#include "led.h"
#include "delay.h"
#include "key.h"
#include "stm32f10x_exti.h"
//#include "beep.h"
//用的中断2和3          1不能用
/*******************************************************************************
* 函 数 名         : My_EXTI_Init
* 函数功能		   : 外部中断初始化
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void My_EXTI_Init(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	EXTI_InitTypeDef  EXTI_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource2);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource3);
	

	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =0;		
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;		
	NVIC_Init(&NVIC_InitStructure);
	
	
	
	//EXTI3 NVIC 配置
	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;//EXTI3中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;//抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =0;		//子优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器


	
	EXTI_InitStructure.EXTI_Line=EXTI_Line2; 
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	//--------------------------************************
	EXTI_InitStructure.EXTI_Line=EXTI_Line3;
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Rising;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_Init(&EXTI_InitStructure);

}


void EXTI2_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line2)==1)
	{
//		LED1=0;
		PAout(2)=0;   
	  PAout(3)=0;
		PAout(4)=0;   
	  PAout(5)=0;
		//BEEP=1;
	}
	EXTI_ClearITPendingBit(EXTI_Line2);
}


void EXTI3_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line3)==1)
	{
//		LED1=1;
		PAout(2)=1;   
	  PAout(3)=0;
		PAout(4)=1;   
	  PAout(5)=0;
		//BEEP=0;
	}
	EXTI_ClearITPendingBit(EXTI_Line3);
}
