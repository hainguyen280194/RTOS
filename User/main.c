
#include "stm32f10x.h"
//#include "user_gpio.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"



void vTaskLed1( void * pvParameters )
{
	while(1)
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_0);			  
		vTaskDelay( 100 );
		GPIO_ResetBits(GPIOB,GPIO_Pin_0);			  
		vTaskDelay( 100 );
	}
	
}


int main ( void )
{	
		/*定义一个GPIO_InitTypeDef类型的结构体*/
	GPIO_InitTypeDef GPIO_InitStructure;


	/* 配置 LED1 引脚 */
	RCC_APB2PeriphClockCmd ( RCC_APB2Periph_GPIOB, ENABLE ); 															   
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_Init ( GPIOB, & GPIO_InitStructure );	
	xTaskCreate( vTaskLed1, "Task Led1", 512, NULL, 1, NULL );
	
  vTaskStartScheduler();
	

}

/*********************************************END OF FILE**********************/












