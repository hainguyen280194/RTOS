/*****************************************************************************
  *Ten Tep          :     user_interrupt.c
  *Ngay             :     18/06/2014
  *Tac Gia          :     MinhHa R&D Team
  *Cong Ty          :     MinhHaGroup
  *Webside          :     mcu.banlinhkien.vn
  *Phien Ban        :     V1.0
  *Tom Tat          :     Dinh nghia cac ham con trinh phuc vu ngat
  ******************************************************************************/

#include "user_interrupt.h"
#if (__USER_INTERRUPT_H!=18062014)
    #error "Include Sai File user_interrupt.h"
#endif

extern uint16_t Value_Display;
/*******************************************************************************
Noi Dung    : This function handles NMI exception.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void NMIException(void)
{
	
}

/*******************************************************************************
Noi Dung    : This function handles Hard Fault exception.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void HardFaultException(void)
{
	while(1)
	{
	}
}

/*******************************************************************************
Noi Dung    : This function handles Memory Manage exception.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void MemManageException(void)
{
	while(1)
	{
	}
}

/*******************************************************************************
Noi Dung    : This function handles Bus Fault exception.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void BusFaultException(void)
{
	while(1)
	{
	}
}

/*******************************************************************************
Noi Dung    : This function handles Usage Fault exception.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void UsageFaultException(void)
{
	while(1)
	{
	}
}

/*******************************************************************************
Noi Dung    : This function handles Debug Monitor exception.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void DebugMonitor(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles SVCall exception.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void SVCHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles PendSVC exception.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void PendSVC(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles SysTick Handler.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void SysTickHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles WWDG interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void WWDG_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles PVD interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void PVD_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles Tamper interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void TAMPER_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles Flash interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void FLASH_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles RCC interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void RCC_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles External interrupt Line 0 request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void EXTI0_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles External interrupt Line 1 request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void EXTI1_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles External interrupt Line 2 request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void EXTI2_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles External interrupt Line 3 request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void EXTI3_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles External interrupt Line 4 request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void EXTI4_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles DMA1 Channel 1 interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void DMAChannel1_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles DMA1 Channel 2 interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void DMAChannel2_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles DMA1 Channel 3 interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void DMAChannel3_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles DMA1 Channel 4 interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void DMAChannel4_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles DMA1 Channel 5 interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void DMAChannel5_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles DMA1 Channel 6 interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void DMAChannel6_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles DMA1 Channel 7 interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void DMAChannel7_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles ADC1 and ADC2 global interrupts requests.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void ADC_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles USB High Priority or CAN TX interrupts requests.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void USB_HP_CAN_TX_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    :  This function handles USB Low Priority or CAN RX0 interrupts requests.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void USB_LP_CAN_RX0_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles CAN RX1 interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void CAN_RX1_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles CAN SCE interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void CAN_SCE_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles External lines 9 to 5 interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void EXTI9_5_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles TIM1 Break interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void TIM1_BRK_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles TIM1 overflow and update interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void TIM1_UP_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles TIM1 Trigger and commutation interrupts requests.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void TIM1_TRG_COM_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles TIM1 capture compare interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void TIM1_CC_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles TIM2 global interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void TIM2_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM2,TIM_IT_Update))
	{
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
		LED7_Display(Value_Display);
	}
}

/*******************************************************************************
Noi Dung    : This function handles TIM3 global interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void TIM3_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles TIM4 global interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void TIM4_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles I2C1 Event interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void I2C1_EV_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles I2C1 Error interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void I2C1_ER_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles I2C2 Event interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void I2C2_EV_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles I2C2 Error interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void I2C2_ER_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles SPI1 global interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void SPI1_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles SPI2 global interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void SPI2_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles USART1 global interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void USART1_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles USART2 global interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void USART2_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles USART3 global interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void USART3_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles External lines 15 to 10 interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void EXTI15_10_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles RTC global interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void RTC_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles USB WakeUp interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void USBWakeUp_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles TIM8 Break interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void TIM8_BRK_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles TIM8 overflow and update interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void TIM8_UP_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles TIM8 Trigger and commutation interrupts requests.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void TIM8_TRG_COM_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles TIM8 capture compare interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void TIM8_CC_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles ADC3 global interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void ADC3_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles FSMC global interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void FSMC_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles SDIO global interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void SDIO_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles TIM5 global interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void TIM5_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles SPI3 global interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void SPI3_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles UART4 global interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void UART4_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles UART5 global interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void UART5_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles TIM6 global interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void TIM6_IRQHandler(void)
{
	
}

/*******************************************************************************
Noi Dung    : This function handles TIM7 global interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void TIM7_IRQHandler(void)
{
	
}

/*******************************************************************************
Noi Dung    : This function handles DMA2 Channel 1 interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void DMA2_Channel1_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles DMA2 Channel 2 interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void DMA2_Channel2_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles DMA2 Channel 3 interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void DMA2_Channel3_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles DMA2 Channel 4 and DMA2 Channel 5 interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void DMA2_Channel4_5_IRQHandler(void)
{

}

/*******************************************************************************
Noi Dung    : This function handles RTC Alarm interrupt request.
Tham Bien   : Khong.
Tra Ve      : Khong.
********************************************************************************/

void RTCAlarm_IRQHandler(void)
{

}

/*------------------------------KET THUC FILE-------------------------------
 ______________________________MinhHa R&D Team______________________________*/ 
