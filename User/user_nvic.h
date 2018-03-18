/*****************************************************************************
  *Ten Tep          :     user_timer.h
  *Ngay             :     18/06/2014
  *Tac Gia          :     MinhHa R&D Team
  *Cong Ty          :     MinhHaGroup
  *Webside          :     mcu.banlinhkien.vn
  *Phien Ban        :     V1.0
  *Tom Tat          :     Khai bao cac ham cau hinh bo NVIC cho STM32F103x8
  ******************************************************************************
  * Chu Y:
  * Cac buoc cau hinh ngat trong NVIC:
  *		- Cau hinh nhom uu tien ngat: co 5 nhom
  *			NVIC_PriorityGroup_0 (pre-emption priority - sub priority : 0 - 4 Bit) 
  *			NVIC_PriorityGroup_1 (pre-emption priority - sub priority : 1 - 3 Bit) 
  *			NVIC_PriorityGroup_2 (pre-emption priority - sub priority : 2 - 2 Bit) 
  *			NVIC_PriorityGroup_3 (pre-emption priority - sub priority : 3 - 1 Bit) 
  *			NVIC_PriorityGroup_4 (pre-emption priority - sub priority : 4 - 0 Bit) 
  *		- Cau hinh kenh ngat: tham khao trong stm32f10x.h
  *		- Cau hinh muc uu tien trong mot nhom
  *		- Kich hoat kenh ngat
  ******************************************************************************
**/  
  
#ifndef __USER_NVIC_H
#define __USER_NVIC_H    18062014

#include "main.h"

/*******************************************************************************
Noi Dung    : Cau hinh bo NVIC.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void NVIC_Configuration(void);

#endif
/*------------------------------KET THUC FILE-------------------------------
 ______________________________MinhHa R&D Team______________________________*/
 
