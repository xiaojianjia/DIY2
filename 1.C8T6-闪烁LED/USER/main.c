#include "delay.h"
#include "sys.h"
#include "usart.h"	 
#include "led.h"	
#include "key.h"	
#include "hc.h"	
#include "exti.h"

	
//测试主函数
int main(void)
 {	 
	 float length;
	 
	 LED_Init();
	 delay_init();	    	 //延时函数初始化	  
	 NVIC_Configuration(); 	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	 uart_init(9600);	 	//串口初始化为9600
	 Hcsr04Init();
	 printf("串口测试\r\n");  
     Hcsr04Init();    
     printf("超声波初始化成功!\n");
	 PAout (4) = 0;
	 PAout (5) = 1;
	 
  	 while(1) 
	 {		 
//     length = Hcsr04GetLength();
//     printf("距离为:%.3fcm\n",length);
//		 delay_ms(50);    
		 PCout(13)=!PCout(13);
		 delay_ms(100);
	 }
	 
	 
 }

