#include "w25x16.h"
#include "main.h"
//W25X16 驱动函数
//4Kbytes为一个Sector
//16个扇区为1个Block
//W25X16
//容量为2M字节,共有32个Block,512个Sector

/**********************************************************
** 函数名:SPIx_Init
** 功能描述:SPI1初始化
** 输入参数: 无
** 输出参数: 无
** 返    回：无
***********************************************************/
void SPIx_Init(void)
{
	RCC->APB2ENR|=1<<2; //PORTA时钟使能
	RCC->APB2ENR|=1<<12; //SPI1时钟使能
	//这里只针对SPI口初始化
	GPIOA->CRL&=0X000FFFFF;
	GPIOA->CRL|=0XBBB00000;//PA5.6.7复用
	GPIOA->ODR|=0X7<<5; //PA5.6.7上拉
	SPI1->CR1|=0<<10;//全双工模式
	SPI1->CR1|=1<<9; //软件nss管理
	SPI1->CR1|=1<<8;
	SPI1->CR1|=1<<2; //SPI主机
	SPI1->CR1|=0<<11;//8bit数据格式
	//W25X16有两种工作模式，但必须在CLK上升沿采样，即CPHA=1且CPOL=1或者CPHA=0且CPOL=0
	SPI1->CR1|=1<<1; //空闲模式下SCK为1 CPOL=1
	SPI1->CR1|=1<<0; //数据采样从第二个时间边沿开始,CPHA=1  
	SPI1->CR1|=7<<3; //Fsck=Fcpu/256
	SPI1->CR1|=0<<7; //MSBfirst
	SPI1->CR1|=1<<6; //SPI设备使能
	SPIx_ReadWriteByte(0xff);//启动传输
}
/**********************************************************
** 函数名:SPIx_SetSpeed
** 功能描述:SPI1时钟速度设置
** 输入参数: SpeedSet--SPI1时钟分频系数
** 输出参数: 无
** 返    回：无
***********************************************************/
void SPIx_SetSpeed(u8 SpeedSet)
{
	SPI1->CR1&=0XFFC7;//Fsck=Fcpu/256
	if(SpeedSet==SPI_SPEED_2)//二分频
	{
		SPI1->CR1|=0<<3;//Fsck=Fpclk/2=36Mhz
	}
	else if(SpeedSet==SPI_SPEED_8)//八分频
	{
		SPI1->CR1|=2<<3;//Fsck=Fpclk/8=9Mhz
	}
	else if(SpeedSet==SPI_SPEED_16)//十六分频
	{
	
		SPI1->CR1|=3<<3;//Fsck=Fpclk/16=4.5Mhz
	}
	else //256分频
	{
		SPI1->CR1|=7<<3; //Fsck=Fpclk/256=281.25Khz 低速模式
	}
	SPI1->CR1|=1<<6; //SPI设备使能
}

/**********************************************************
** 函数名:SPIx_ReadWriteByte
** 功能描述:SPI1读写一字节数据
** 输入参数: TxData--要写入的字节
** 输出参数: 无
** 返    回：SPI1->DR--读取到的字节
***********************************************************/
u8 SPIx_ReadWriteByte(u8 TxData)
{
	u8 retry=0;
	while((SPI1->SR&1<<1)==0)//等待发送区空
	{
		retry++;
		if(retry>200)return 0;//等待超时退出
	}
	SPI1->DR=TxData; //发送一个byte
	retry=0;
	while((SPI1->SR&1<<0)==0) //等待接收完一个byte
	{
		retry++;
		if(retry>200)return 0;//等待超时退出
	}
	return SPI1->DR; //返回收到的数据
}
/**********************************************************
** 函数名:SPI_Flash_Init
** 功能描述:W25X16的GPIO初始化
** 输入参数: 无
** 输出参数: 无
** 返    回：无
***********************************************************/
void SPI_Flash_Init(void)
{
	RCC->APB2ENR|=1<<3; //PORTC时钟使能
	//PA4--CS
	GPIOA->CRL&=0XFFF0FFFF;
	GPIOA->CRL|=0X00030000;//PC5推挽输出
	GPIOA->ODR|=1<<4; //PC5上拉
	//SPI_FLASH_CS(0);
	delay_ms(1);
	SPIx_Init(); //初始化SPI1
}

/**********************************************************
** 函数名:SPI_Flash_ReadSR
** 功能描述:读取FLASH的状态寄存器
** 输入参数: 无
** 输出参数: 无
** 返    回：byte-读取的寄存器值
** 说明：BIT7   6   5  4   3   2   1   0
		    SPR RV TB BP2 BP1 BP0 WEL BUSY
		SPR:默认0,状态寄存器保护位,配合WP使用
		TB,BP2,BP1,BP0:FLASH区域写保护设置
		WEL:写使能锁定
		BUSY:忙标记位(1,忙;0,空闲)
***********************************************************/
u8 SPI_Flash_ReadSR(void)
{
	u8 byte=0;
	SPI_FLASH_CS(0); //使能器件
	SPIx_ReadWriteByte(W25X_ReadStatusReg); //发送读取状态寄存器命令
	byte=SPIx_ReadWriteByte(0Xff); //读取一个字节
	SPI_FLASH_CS(1); //取消片选
	return byte;
}
/**********************************************************
** 函数名:SPI_FLASH_Write_SR
** 功能描述:写FLASH状态寄存器
** 输入参数: sr--写入状态寄存器的数据
** 输出参数: 无
** 返    回：无
** 说明：	只有SPR,TB,BP2,BP1,BP0(bit 7,5,4,3,2)可以写
***********************************************************/
void SPI_FLASH_Write_SR(u8 sr)
{
	SPI_FLASH_CS(0); //使能器件
	SPIx_ReadWriteByte(W25X_WriteStatusReg); //发送写取状态寄存器命令
	SPIx_ReadWriteByte(sr); //写入一个字节
	SPI_FLASH_CS(1); //取消片选
}
/**********************************************************
** 函数名:SPI_FLASH_Write_Enable
** 功能描述:FLASH写使能
** 输入参数: 无
** 输出参数: 无
** 返    回：无
***********************************************************/
void SPI_FLASH_Write_Enable(void)
{
	SPI_FLASH_CS(0); //使能器件
	SPIx_ReadWriteByte(W25X_WriteEnable); //发送写使能
	SPI_FLASH_CS(1); //取消片选
}

/**********************************************************
** 函数名:SPI_FLASH_Write_Disable
** 功能描述:FLASH写禁止
** 输入参数: 无
** 输出参数: 无
** 返    回：无
***********************************************************/
void SPI_FLASH_Write_Disable(void)
{
	SPI_FLASH_CS(0); //使能器件
	SPIx_ReadWriteByte(W25X_WriteDisable); //发送写禁止指令
	SPI_FLASH_CS(1); //取消片选
}
/**********************************************************
** 函数名:SPI_Flash_ReadID
** 功能描述:读取芯片ID，W25X16的ID为0XEF14
** 输入参数: 无
** 输出参数: 无
** 返    回：Temp--读取的ID
***********************************************************/
u16 SPI_Flash_ReadID(void)
{
	u16 Temp = 0;
	SPI_FLASH_CS(0);
	SPIx_ReadWriteByte(0x90);//发送读取ID命令
	SPIx_ReadWriteByte(0x00);
	SPIx_ReadWriteByte(0x00);
	SPIx_ReadWriteByte(0x00);
	Temp|=SPIx_ReadWriteByte(0xFF)<<8;//读取高8位
	Temp|=SPIx_ReadWriteByte(0xFF);	//读取低8
	SPI_FLASH_CS(1);
	return Temp;

}
/**********************************************************
** 函数名:SPI_Flash_Read
** 功能描述:在指定地址开始读取指定长度的数据
** 输入参数: *pBuffer--数据存储区地址指针
		     ReadAddr--开始读取的地址(24bit)
			 NumByteToRead--要读取的字节数(最大65535)
** 输出参数: 无
** 返    回：无
***********************************************************/
void SPI_Flash_Read(u8* pBuffer,u32 ReadAddr,u16 NumByteToRead)
{
	SPI_FLASH_CS(0); //使能器件
	SPIx_ReadWriteByte(W25X_ReadData); //发送读取命令
	SPIx_ReadWriteByte((ReadAddr)>>16); //发送24bit地址
	SPIx_ReadWriteByte((ReadAddr)>>8);
	SPIx_ReadWriteByte(ReadAddr);
	while(NumByteToRead--)
	{
		*pBuffer++=SPIx_ReadWriteByte(0Xff); //循环读数
	}
	SPI_FLASH_CS(1); //取消片选
}

/**********************************************************
** 函数名:SPI_Flash_Write_Page
** 功能描述: 在指定地址开始写入最大256字节的数据
			 在一页(0~65535)内写入少于256个字节的数据
** 输入参数: *pBuffer--数据存储区地址指针
			 WriteAddr--开始写入的地址(24bit)
			 NumByteToWrite--要写入的字节数(最大256),该数不应该超过该页的剩余字节数
** 输出参数: 无
** 返    回：无
***********************************************************/
void SPI_Flash_Write_Page(u8* pBuffer,u32 WriteAddr,u16 NumByteToWrite)
{
	u16 i;
	SPI_FLASH_Write_Enable(); //SET WEL
	SPI_FLASH_CS(0); //使能器件
	SPIx_ReadWriteByte(W25X_PageProgram); //发送写页命令
	SPIx_ReadWriteByte((u8)((WriteAddr)>>16)); //发送24bit地址    
    SPIx_ReadWriteByte((u8)((WriteAddr)>>8));   
    SPIx_ReadWriteByte((u8)WriteAddr); 
	while(NumByteToWrite--)
	{
		SPIx_ReadWriteByte(*pBuffer);//循环写数
		pBuffer++;
	}
	SPI_FLASH_CS(1); //取消片选
	SPI_Flash_Wait_Busy(); //等待写入结束
}
/**********************************************************
** 函数名:SPI_Flash_Write_NoCheck
** 功能描述:无检验写SPI FLASH
			必须确保所写的地址范围内的数据全部为0XFF,否则在非0XFF处写入的数据将失败!
			具有自动换页功能
			在指定地址开始写入指定长度的数据,但是要确保地址不越界!
** 输入参数: *pBuffer--数据存储区地址指针
			 WriteAddr--开始写入的地址(24bit)
			 NumByteToWrite--要写入的字节数(最大65535)
** 输出参数: 无
** 返    回：无
***********************************************************/
void SPI_Flash_Write_NoCheck(u8* pBuffer,u32 WriteAddr,u16 NumByteToWrite)
{
	u16 pageremain;
	pageremain=256-WriteAddr%256; //单页剩余的字节数
	if(NumByteToWrite<=pageremain)
		pageremain=NumByteToWrite;//不大于256个字节
	while(1)
	{
		SPI_Flash_Write_Page(pBuffer,WriteAddr,pageremain);
		if(NumByteToWrite==pageremain)
				break;//写入结束了
		else //NumByteToWrite>pageremain
		{
			pBuffer+=pageremain;
			WriteAddr+=pageremain;
			NumByteToWrite-=pageremain; //减去已经写入了的字节数
			if(NumByteToWrite>256)
				pageremain=256; //一次可以写入256个字节
			else 
				pageremain=NumByteToWrite; //不够256个字节了
		}
	};
}

u8 SPI_FLASH_BUF[4096];
/**********************************************************
** 函数名:SPI_Flash_Write
** 功能描述: 在任意指定地址开始写入指定长度的数据,该函数带擦除操作!
** 输入参数: *pBuffer--数据存储区地址指针
			 WriteAddr--开始写入的地址(24bit)
			 NumByteToWrite--要写入的字节数(最大65535)
** 输出参数: 无
** 返    回：无
***********************************************************/
void SPI_Flash_Write(u8* pBuffer,u32 WriteAddr,u16 NumByteToWrite)
{
	u32 secpos;
	u16 secoff;
	u16 secremain;
	u16 i;
	secpos=WriteAddr/4096;//扇区地址 0~511 for w25x16
	secoff=WriteAddr%4096;//在扇区内的偏移
	secremain=4096-secoff;//扇区剩余空间大小
	if(NumByteToWrite<=secremain)secremain=NumByteToWrite;//不大于4096个字节
	while(1)
	{
		SPI_Flash_Read(SPI_FLASH_BUF,secpos*4096,4096);//读出整个扇区的内容
		for(i=0;i<secremain;i++)//校验数据
		{
			if(SPI_FLASH_BUF[secoff+i]!=0XFF)break;//需要擦除
		}
		if(i<secremain)//需要擦除
		{
			SPI_Flash_Erase_Sector(secpos);//擦除这个扇区
			for(i=0;i<secremain;i++) //复制
			{
				SPI_FLASH_BUF[i+secoff]=pBuffer[i];
			}
			SPI_Flash_Write_NoCheck(SPI_FLASH_BUF,secpos*4096,4096);//写入整个扇区
		}
		else 
			SPI_Flash_Write_NoCheck(pBuffer,WriteAddr,secremain);//写已经擦除了的,直接写入扇区剩余区间.
		if(NumByteToWrite==secremain)break;//写入结束了
		else//写入未结束
		{
			secpos++;//扇区地址增1
			secoff=0;//偏移位置为0
			pBuffer+=secremain; //指针偏移
			WriteAddr+=secremain;//写地址偏移
			NumByteToWrite-=secremain; //字节数递减
			if(NumByteToWrite>4096)
				secremain=4096; //下一个扇区还是写不完
			else 
				secremain=NumByteToWrite; //下一个扇区可以写完了
		}
	};
}
/**********************************************************
** 函数名:SPI_Flash_Erase_Chip
** 功能描述: 擦除整个芯片，等待时间比较长...
** 输入参数: 无
** 输出参数: 无
** 返    回：无
***********************************************************/
void SPI_Flash_Erase_Chip(void)
{
	SPI_FLASH_Write_Enable(); //SET WEL
	SPI_Flash_Wait_Busy();
	SPI_FLASH_CS(0); //使能器件
	SPIx_ReadWriteByte(W25X_ChipErase); //发送片擦除命令
	SPI_FLASH_CS(1); //取消片选
	SPI_Flash_Wait_Busy(); //等待芯片擦除结束
}

/**********************************************************
** 函数名:SPI_Flash_Erase_Sector
** 功能描述: 擦除一个扇区
** 输入参数: Dst_Addr--扇区地址 0~511 for w25x16
** 输出参数: 无
** 返    回：无
***********************************************************/
void SPI_Flash_Erase_Sector(u32 Dst_Addr)
{
	Dst_Addr*=4096;
	SPI_FLASH_Write_Enable(); //SET WEL
	SPI_Flash_Wait_Busy();
	SPI_FLASH_CS(0); //使能器件
	SPIx_ReadWriteByte(W25X_SectorErase); //发送扇区擦除指令
	SPIx_ReadWriteByte((u8)((Dst_Addr)>>16)); //发送24bit地址
	SPIx_ReadWriteByte((u8)((Dst_Addr)>>8));
	SPIx_ReadWriteByte((u8)Dst_Addr);
	SPI_FLASH_CS(1); //取消片选
	SPI_Flash_Wait_Busy(); //等待擦除完成
}
/**********************************************************
** 函数名:SPI_Flash_Wait_Busy
** 功能描述: 等待FLASH处于空闲状态
** 输入参数: 无
** 输出参数: 无
** 返    回：无
***********************************************************/
void SPI_Flash_Wait_Busy(void)
{
	while ((SPI_Flash_ReadSR()&0x01)==0x01); // 等待BUSY位清空
}
/**********************************************************
** 函数名:SPI_Flash_PowerDown
** 功能描述: 进入掉电模式
** 输入参数: 无
** 输出参数: 无
** 返    回：无
***********************************************************/
void SPI_Flash_PowerDown(void)
{
	SPI_FLASH_CS(0); //使能器件
	SPIx_ReadWriteByte(W25X_PowerDown); //发送掉电命令
	SPI_FLASH_CS(1); //取消片选
	delay_us(3); //等待TPD
}

/**********************************************************
** 函数名:SPI_Flash_WAKEUP
** 功能描述: 唤醒
** 输入参数: 无
** 输出参数: 无
** 返    回：无
***********************************************************/
void SPI_Flash_WAKEUP(void)
{
	SPI_FLASH_CS(0); //使能器件
	SPIx_ReadWriteByte(W25X_ReleasePowerDown); // send W25X_PowerDown command 0xAB
	SPI_FLASH_CS(1); //取消片选
	delay_us(3); //等待TRES1
}

