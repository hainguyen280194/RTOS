/*****************************************************************************
  *Ten Tep          :     user_timer.h
  *Ngay             :     18/06/2014
  *Tac Gia          :     MinhHa R&D Team
  *Cong Ty          :     MinhHaGroup
  *Webside          :     mcu.banlinhkien.vn
  *Phien Ban        :     V1.0
  *Tom Tat          :     Khai bao cac ham cau hinh TIM cho STM32F103x8
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
  
#ifndef __USER_TIMER_H
#define __USER_TIMER_H    18062014

#include "main.h"

/*******************************************************************************
Noi Dung    : Cau hinh TIM1.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void TIMER1_Configuration(void);

/*******************************************************************************
Noi Dung    : Cau hinh TIM2.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void TIMER2_Configuration(void);

/*******************************************************************************
Noi Dung    : Cau hinh TIM3.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void TIMER3_Configuration(void);

/*******************************************************************************
Noi Dung    : Cau hinh TIM4.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void TIMER4_Configuration(void);

#endif
/*------------------------------KET THUC FILE-------------------------------
 ______________________________MinhHa R&D Team______________________________*/
