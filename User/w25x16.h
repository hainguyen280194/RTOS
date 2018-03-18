#ifndef __w25x16_H
#define __w25x16_H
#include "stm32f10x.h"

#define FLASH_CS     (1<<4) //PA4
#define SPI_FLASH_CS(x)  x ?GPIO_SetBits(GPIOA,GPIO_Pin_4):GPIO_ResetBits(GPIOA,GPIO_Pin_4)
//GPIOA->ODR=(GPIOA->ODR&~FLASH_CS)|(x ? FLASH_CS:0)		 //命令片选
#define SPI_FLASH_PageSize 256
// SPI总线速度设置
#define SPI_SPEED_2 0
#define SPI_SPEED_8 1
#define SPI_SPEED_16 2
#define SPI_SPEED_256 3
////////////////////////////////////////////////////////////////////////////
//W25X16读写
#define FLASH_ID 0XEF14
//指令表
#define W25X_WriteEnable 0x06  	//写使能
#define W25X_WriteDisable 0x04	//写禁能
#define W25X_ReadStatusReg 0x05	 //读状态寄存器
#define W25X_WriteStatusReg 0x01  //写状态寄存器
#define W25X_ReadData 0x03		 //读数据
#define W25X_FastReadData 0x0B	 //快读数据
#define W25X_FastReadDual 0x3B	 //快读双输出
#define W25X_PageProgram 0x02	 //页编程
#define W25X_BlockErase 0xD8	 //块擦除
#define W25X_SectorErase 0x20	 //扇区擦除
#define W25X_ChipErase 0xC7		 //整个芯片擦除
#define W25X_PowerDown 0xB9		 //掉电
#define W25X_ReleasePowerDown 0xAB //释放掉电
#define W25X_ManufactDeviceID 0x90//ID
#define W25X_JedecDeviceID 0x9F	//JEDEC ID

u8 SPIx_ReadWriteByte(u8 TxData);

void SPI_Flash_Init(void);
u16 SPI_Flash_ReadID(void); //读取FLASH ID
u8 SPI_Flash_ReadSR(void); //读取状态寄存器
void SPI_FLASH_Write_SR(u8 sr); //写状态寄存器
void SPI_FLASH_Write_Enable(void); //写使能
void SPI_FLASH_Write_Disable(void); //写保护
void SPI_Flash_Read(u8* pBuffer,u32 ReadAddr,u16 NumByteToRead); //读取flash
void SPI_Flash_Write(u8* pBuffer,u32 WriteAddr,u16 NumByteToWrite);//写入flash
void SPI_Flash_Erase_Chip(void); //整片擦除
void SPI_Flash_Erase_Sector(u32 Dst_Addr);//扇区擦除
void SPI_Flash_Wait_Busy(void); //等待空闲
void SPI_Flash_PowerDown(void); //进入掉电模式
void SPI_Flash_WAKEUP(void); //唤醒

void SPI_FLASH_WaitForWriteEnd(void);
void SPI_FLASH_BufferWrite(u8* pBuffer, u32 WriteAddr, u16 NumByteToWrite);
#endif

