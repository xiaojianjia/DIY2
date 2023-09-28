#include "delay.h"
#include "sys.h"
#include "usart.h"	 
#include "led.h"	
#include "key.h"	
#include "hc.h"	
#include "exti.h"

	
//����������
int main(void)
 {	 
	 float length;
	 
	 LED_Init();
	 delay_init();	    	 //��ʱ������ʼ��	  
	 NVIC_Configuration(); 	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	 uart_init(9600);	 	//���ڳ�ʼ��Ϊ9600
	 Hcsr04Init();
	 printf("���ڲ���\r\n");  
     Hcsr04Init();    
     printf("��������ʼ���ɹ�!\n");
	 PAout (4) = 0;
	 PAout (5) = 1;
	 
  	 while(1) 
	 {		 
//     length = Hcsr04GetLength();
//     printf("����Ϊ:%.3fcm\n",length);
//		 delay_ms(50);    
		 PCout(13)=!PCout(13);
		 delay_ms(100);
	 }
	 
	 
 }

