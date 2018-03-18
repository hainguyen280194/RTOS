/*****************************************************************************
  *Ten Tep          :     user_adc.h
  *Ngay             :     19/06/2014
  *Tac Gia          :     MinhHa R&D Team
  *Cong Ty          :     MinhHaGroup
  *Webside          :     mcu.banlinhkien.vn
  *Phien Ban        :     V1.0
  *Tom Tat          :     Khai bao cac ham cau hinh va chuyen doi ADC cho STM32F10x
  ******************************************************************************/
  
#ifndef __USER_ADC_H
#define __USER_ADC_H    19062014

#include 	"main.h"

/*******************************************************************************
Noi Dung    : Cau hinh bo ADC1.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void ADC1_Configuration(void);

/*******************************************************************************
Noi Dung    : Cau hinh bo ADC2.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void ADC2_Configuration(void);

/*******************************************************************************
Noi Dung    : Doc gia tri ADC.
Tham Bien   : ADCx       : Bo ADC su dung.
              ADC_Channel: Kenh ADC su dung.
Tra Ve      : Khong.
********************************************************************************/

uint16_t Read_ADC(ADC_TypeDef *ADCx,uint8_t ADC_Channel);

#endif
/*------------------------------KET THUC FILE-------------------------------
 ______________________________MinhHa R&D Team______________________________*/
