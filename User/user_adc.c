/*****************************************************************************
  *Ten Tep          :     user_adc.h
  *Ngay             :     19/06/2014
  *Tac Gia          :     MinhHa R&D Team
  *Cong Ty          :     MinhHaGroup
  *Webside          :     mcu.banlinhkien.vn
  *Phien Ban        :     V1.0
  *Tom Tat          :     Khai bao cac ham cau hinh va chuyen doi ADC cho STM32F10x
  ******************************************************************************/

#include "user_adc.h"
#if (__USER_ADC_H!=19062014)
    #error "Include Sai #File user_adc.h"
#endif

/*******************************************************************************
Noi Dung    : Cau hinh bo ADC1.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void ADC1_Configuration(void)
{
	ADC_InitTypeDef  ADC_InitStructure;

	RCC_ADCCLKConfig(RCC_PCLK2_Div6);    // ADCCLKmax = 14MHZ --> ADCCLK = PCLK/6 = 72/6 = 12MHz
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);

	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;    // Cau hinh che do hoat dong cho bo ADC(Single)
                                                          // ADC_Mode_Independent                 
                                                          // ADC_Mode_RegInjecSimult                    
                                                          // ADC_Mode_RegSimult_AlterTrig               
                                                          // ADC_Mode_InjecSimult_FastInterl           
                                                          // ADC_Mode_InjecSimult_SlowInterl            
                                                          // ADC_Mode_InjecSimult                     
                                                          // ADC_Mode_RegSimult                         
                                                          // ADC_Mode_FastInterl                        
                                                          // ADC_Mode_SlowInterl                        
                                                          //ADC_Mode_AlterTrig                         
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;         // ENABLE - DISABLE che do Scan (multichannels)
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;   // ENABLE - DISABLE che do Continuous
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;    // Dinh nghia Trigger ben ngoai de bat dau qua trinh chuyen doi tren kenh Regular
                                                                           // ADC_ExternalTrigConv_T1_CC1 
                                                                           // ADC_ExternalTrigConv_T1_CC2
                                                                           // ADC_ExternalTrigConv_T2_CC2
                                                                           // ADC_ExternalTrigConv_T3_TRGO
                                                                           // ADC_ExternalTrigConv_T4_CC4
                                                                           // ADC_ExternalTrigConv_Ext_IT11_TIM8_TRGO
                                                                           // ADC_ExternalTrigConv_T1_CC3                  
                                                                           // ADC_ExternalTrigConv_None																   
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;    // Cau hinh kieu luu tru du lieu
	                                                          // ADC_DataAlign_Right
	                                                          // ADC_DataAlign_Left
	ADC_InitStructure.ADC_NbrOfChannel = 1;    // Cau hinh so kenh ADC regular su dung
	                                           // 1 - 16
	ADC_Init(ADC1, &ADC_InitStructure);    // Cau hinh ADC1
	ADC_Cmd(ADC1, ENABLE);                 // Kich hoat ADC1

	ADC_ResetCalibration(ADC1);                    // Reset thanh ghi hieu chinh ADC1
	while(ADC_GetResetCalibrationStatus(ADC1));    // Cho qua trinh Reset ket thuc
	ADC_StartCalibration(ADC1);                    // Bat dau hieu chinh ADC1
	while(ADC_GetCalibrationStatus(ADC1));         // Cho qua trinh hieu chinh ket thuc
}

/*******************************************************************************
Noi Dung    : Cau hinh bo ADC2.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void ADC2_Configuration(void)
{
	ADC_InitTypeDef  ADC_InitStructure;

	RCC_ADCCLKConfig(RCC_PCLK2_Div6);    // ADCCLKmax = 14MHZ --> ADCCLK = PCLK/6 = 72/6 = 12MHz
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC2, ENABLE);

	ADC_DeInit(ADC2);

	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;    // Cau hinh che do hoat dong cho bo ADC(Single)
                                                          // ADC_Mode_Independent                 
                                                          // ADC_Mode_RegInjecSimult                    
                                                          // ADC_Mode_RegSimult_AlterTrig               
                                                          // ADC_Mode_InjecSimult_FastInterl           
                                                          // ADC_Mode_InjecSimult_SlowInterl            
                                                          // ADC_Mode_InjecSimult                     
                                                          // ADC_Mode_RegSimult                         
                                                          // ADC_Mode_FastInterl                        
                                                          // ADC_Mode_SlowInterl                        
                                                          //ADC_Mode_AlterTrig                         
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;         // ENABLE - DISABLE che do Scan (multichannels)
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;   // ENABLE - DISABLE che do Continuous
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;    // Dinh nghia Trigger ben ngoai de bat dau qua trinh chuyen doi tren kenh Regular
                                                                           // ADC_ExternalTrigConv_T1_CC1 
                                                                           // ADC_ExternalTrigConv_T1_CC2
                                                                           // ADC_ExternalTrigConv_T2_CC2
                                                                           // ADC_ExternalTrigConv_T3_TRGO
                                                                           // ADC_ExternalTrigConv_T4_CC4
                                                                           // ADC_ExternalTrigConv_Ext_IT11_TIM8_TRGO
                                                                           // ADC_ExternalTrigConv_T1_CC3                  
                                                                           // ADC_ExternalTrigConv_None																   
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;    // Cau hinh kieu luu tru du lieu
	                                                          // ADC_DataAlign_Right
	                                                          // ADC_DataAlign_Left
	ADC_InitStructure.ADC_NbrOfChannel = 1;    // Cau hinh so kenh ADC regular su dung
	                                           // 1 - 16
	ADC_Init(ADC2, &ADC_InitStructure);    // Cau hinh ADC2
	ADC_Cmd(ADC2, ENABLE);                 // Kich hoat ADC2

	ADC_ResetCalibration(ADC2);                    // Reset thanh ghi hieu chinh ADC2
	while(ADC_GetResetCalibrationStatus(ADC2));    // Cho qua trinh Reset ket thuc
	ADC_StartCalibration(ADC2);                    // Bat dau hieu chinh ADC2
	while(ADC_GetCalibrationStatus(ADC2));         // Cho qua trinh hieu chinh ket thuc
}

/*******************************************************************************
Noi Dung    : Doc gia tri ADC.
Tham Bien   : ADCx       : Bo ADC su dung.
              ADC_Channel: Kenh ADC su dung.
Tra Ve      : Khong.
********************************************************************************/

uint16_t Read_ADC(ADC_TypeDef *ADCx,uint8_t ADC_Channel)
{
	ADC_RegularChannelConfig(ADCx,ADC_Channel,1,ADC_SampleTime_55Cycles5);    // Cau hinh kenh chuyen doi Regular
	ADC_SoftwareStartConvCmd(ADCx, ENABLE);                                   // Bat dau qua trinh chuyen doi
	while(ADC_GetFlagStatus(ADCx, ADC_FLAG_EOC) == RESET);                    // Cho qua trinh chuyen doi ket thuc
	ADC_ClearFlag(ADCx, ADC_FLAG_EOC);
	ADC_SoftwareStartConvCmd(ADCx, DISABLE);                                  // Khong cho phep chuyen doi
	return ADC_GetConversionValue(ADCx);                                      // Tra ve gia tri ADC 
}

/*------------------------------KET THUC FILE-------------------------------
 ______________________________MinhHa R&D Team______________________________*/

