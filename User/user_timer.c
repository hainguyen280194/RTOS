/*****************************************************************************
  *Ten Tep          :     user_timer.c
  *Ngay             :     18/06/2014
  *Tac Gia          :     MinhHa R&D Team
  *Cong Ty          :     MinhHaGroup
  *Webside          :     mcu.banlinhkien.vn
  *Phien Ban        :     V1.0
  *Tom Tat          :     Dinh nghia cac ham cau hinh TIM cho STM32F103x8
  ******************************************************************************
  * Chu Y:
  *	De dinh thoi mot khoang thoi gian can cau hinh cac thong so:
  *		- TIM_Prescaler : Tan so bo TIMx = Tan so he thong / TIM_Prescaler (0 - 65535)
  *		- TIM_CounterMode : Che do dem cua bo TIMx
  *						  - TIM_CounterMode_Up : Dem len
  *						  - TIM_CounterMode_Down : Dem xuong
  *						  - TIM_CounterMode_CenterAligned1
  *						  - TIM_CounterMode_CenterAligned2
  *						  - TIM_CounterMode_CenterAligned3						  
  *		- TIM_Period : Gia tri nap vao thanh ghi auto-reload (0 - 65535)
  *		- TIM_ClockDivision:
  *						  - TIM_CKD_DIV1
  *						  - TIM_CKD_DIV2
  *						  - TIM_CKD_DIV4
  ******************************************************************************
**/

#include "user_timer.h"
#if (__USER_TIMER_H!=18062014)
    #error "Include Sai #File user_timer.h"
#endif
#include "stm32f10x_tim.h"
/*******************************************************************************
Noi Dung    : Cau hinh TIM1.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void TIMER1_Configuration(void)
{
}

/*******************************************************************************
Noi Dung    : Cau hinh TIM2.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void TIMER2_Configuration(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	TIM_DeInit(TIM2);	
	
	TIM_TimeBaseStructure.TIM_Prescaler = 36000;// lam bo chia cho timer
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;// dem tang
	TIM_TimeBaseStructure.TIM_Period = 1;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseStructure);	
	
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
	TIM_Cmd(TIM2,ENABLE);	
}

/*******************************************************************************
Noi Dung    : Cau hinh TIM3.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void TIMER3_Configuration(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
		
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	TIM_DeInit(TIM3);
	
	TIM_TimeBaseStructure.TIM_Prescaler = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period = 0;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseStructure);	
	
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
	TIM_Cmd(TIM3,ENABLE);	
}

/*******************************************************************************
Noi Dung    : Cau hinh TIM4.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void TIMER4_Configuration(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
		
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	TIM_DeInit(TIM4);
	
	TIM_TimeBaseStructure.TIM_Prescaler = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period = 0;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseStructure);	
	
	TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE);
	TIM_Cmd(TIM4,ENABLE);	
}

/*------------------------------KET THUC FILE-------------------------------
 ______________________________MinhHa R&D Team______________________________*/
