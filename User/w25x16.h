#ifndef __w25x16_H
#define __w25x16_H
#include "stm32f10x.h"

#define FLASH_CS     (1<<4) //PA4
#define SPI_FLASH_CS(x)  x ?GPIO_SetBits(GPIOA,GPIO_Pin_4):GPIO_ResetBits(GPIOA,GPIO_Pin_4)
//GPIOA->ODR=(GPIOA->ODR&~FLASH_CS)|(x ? FLASH_CS:0)		 //����Ƭѡ
#define SPI_FLASH_PageSize 256
// SPI�����ٶ�����
#define SPI_SPEED_2 0
#define SPI_SPEED_8 1
#define SPI_SPEED_16 2
#define SPI_SPEED_256 3
////////////////////////////////////////////////////////////////////////////
//W25X16��д
#define FLASH_ID 0XEF14
//ָ���
#define W25X_WriteEnable 0x06  	//дʹ��
#define W25X_WriteDisable 0x04	//д����
#define W25X_ReadStatusReg 0x05	 //��״̬�Ĵ���
#define W25X_WriteStatusReg 0x01  //д״̬�Ĵ���
#define W25X_ReadData 0x03		 //������
#define W25X_FastReadData 0x0B	 //�������
#define W25X_FastReadDual 0x3B	 //���˫���
#define W25X_PageProgram 0x02	 //ҳ���
#define W25X_BlockErase 0xD8	 //�����
#define W25X_SectorErase 0x20	 //��������
#define W25X_ChipErase 0xC7		 //����оƬ����
#define W25X_PowerDown 0xB9		 //����
#define W25X_ReleasePowerDown 0xAB //�ͷŵ���
#define W25X_ManufactDeviceID 0x90//ID
#define W25X_JedecDeviceID 0x9F	//JEDEC ID

u8 SPIx_ReadWriteByte(u8 TxData);

void SPI_Flash_Init(void);
u16 SPI_Flash_ReadID(void); //��ȡFLASH ID
u8 SPI_Flash_ReadSR(void); //��ȡ״̬�Ĵ���
void SPI_FLASH_Write_SR(u8 sr); //д״̬�Ĵ���
void SPI_FLASH_Write_Enable(void); //дʹ��
void SPI_FLASH_Write_Disable(void); //д����
void SPI_Flash_Read(u8* pBuffer,u32 ReadAddr,u16 NumByteToRead); //��ȡflash
void SPI_Flash_Write(u8* pBuffer,u32 WriteAddr,u16 NumByteToWrite);//д��flash
void SPI_Flash_Erase_Chip(void); //��Ƭ����
void SPI_Flash_Erase_Sector(u32 Dst_Addr);//��������
void SPI_Flash_Wait_Busy(void); //�ȴ�����
void SPI_Flash_PowerDown(void); //�������ģʽ
void SPI_Flash_WAKEUP(void); //����

void SPI_FLASH_WaitForWriteEnd(void);
void SPI_FLASH_BufferWrite(u8* pBuffer, u32 WriteAddr, u16 NumByteToWrite);
#endif

