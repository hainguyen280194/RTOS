#include "w25x16.h"
#include "main.h"
//W25X16 ��������
//4KbytesΪһ��Sector
//16������Ϊ1��Block
//W25X16
//����Ϊ2M�ֽ�,����32��Block,512��Sector

/**********************************************************
** ������:SPIx_Init
** ��������:SPI1��ʼ��
** �������: ��
** �������: ��
** ��    �أ���
***********************************************************/
void SPIx_Init(void)
{
	RCC->APB2ENR|=1<<2; //PORTAʱ��ʹ��
	RCC->APB2ENR|=1<<12; //SPI1ʱ��ʹ��
	//����ֻ���SPI�ڳ�ʼ��
	GPIOA->CRL&=0X000FFFFF;
	GPIOA->CRL|=0XBBB00000;//PA5.6.7����
	GPIOA->ODR|=0X7<<5; //PA5.6.7����
	SPI1->CR1|=0<<10;//ȫ˫��ģʽ
	SPI1->CR1|=1<<9; //���nss����
	SPI1->CR1|=1<<8;
	SPI1->CR1|=1<<2; //SPI����
	SPI1->CR1|=0<<11;//8bit���ݸ�ʽ
	//W25X16�����ֹ���ģʽ����������CLK�����ز�������CPHA=1��CPOL=1����CPHA=0��CPOL=0
	SPI1->CR1|=1<<1; //����ģʽ��SCKΪ1 CPOL=1
	SPI1->CR1|=1<<0; //���ݲ����ӵڶ���ʱ����ؿ�ʼ,CPHA=1  
	SPI1->CR1|=7<<3; //Fsck=Fcpu/256
	SPI1->CR1|=0<<7; //MSBfirst
	SPI1->CR1|=1<<6; //SPI�豸ʹ��
	SPIx_ReadWriteByte(0xff);//��������
}
/**********************************************************
** ������:SPIx_SetSpeed
** ��������:SPI1ʱ���ٶ�����
** �������: SpeedSet--SPI1ʱ�ӷ�Ƶϵ��
** �������: ��
** ��    �أ���
***********************************************************/
void SPIx_SetSpeed(u8 SpeedSet)
{
	SPI1->CR1&=0XFFC7;//Fsck=Fcpu/256
	if(SpeedSet==SPI_SPEED_2)//����Ƶ
	{
		SPI1->CR1|=0<<3;//Fsck=Fpclk/2=36Mhz
	}
	else if(SpeedSet==SPI_SPEED_8)//�˷�Ƶ
	{
		SPI1->CR1|=2<<3;//Fsck=Fpclk/8=9Mhz
	}
	else if(SpeedSet==SPI_SPEED_16)//ʮ����Ƶ
	{
	
		SPI1->CR1|=3<<3;//Fsck=Fpclk/16=4.5Mhz
	}
	else //256��Ƶ
	{
		SPI1->CR1|=7<<3; //Fsck=Fpclk/256=281.25Khz ����ģʽ
	}
	SPI1->CR1|=1<<6; //SPI�豸ʹ��
}

/**********************************************************
** ������:SPIx_ReadWriteByte
** ��������:SPI1��дһ�ֽ�����
** �������: TxData--Ҫд����ֽ�
** �������: ��
** ��    �أ�SPI1->DR--��ȡ�����ֽ�
***********************************************************/
u8 SPIx_ReadWriteByte(u8 TxData)
{
	u8 retry=0;
	while((SPI1->SR&1<<1)==0)//�ȴ���������
	{
		retry++;
		if(retry>200)return 0;//�ȴ���ʱ�˳�
	}
	SPI1->DR=TxData; //����һ��byte
	retry=0;
	while((SPI1->SR&1<<0)==0) //�ȴ�������һ��byte
	{
		retry++;
		if(retry>200)return 0;//�ȴ���ʱ�˳�
	}
	return SPI1->DR; //�����յ�������
}
/**********************************************************
** ������:SPI_Flash_Init
** ��������:W25X16��GPIO��ʼ��
** �������: ��
** �������: ��
** ��    �أ���
***********************************************************/
void SPI_Flash_Init(void)
{
	RCC->APB2ENR|=1<<3; //PORTCʱ��ʹ��
	//PA4--CS
	GPIOA->CRL&=0XFFF0FFFF;
	GPIOA->CRL|=0X00030000;//PC5�������
	GPIOA->ODR|=1<<4; //PC5����
	//SPI_FLASH_CS(0);
	delay_ms(1);
	SPIx_Init(); //��ʼ��SPI1
}

/**********************************************************
** ������:SPI_Flash_ReadSR
** ��������:��ȡFLASH��״̬�Ĵ���
** �������: ��
** �������: ��
** ��    �أ�byte-��ȡ�ļĴ���ֵ
** ˵����BIT7   6   5  4   3   2   1   0
		    SPR RV TB BP2 BP1 BP0 WEL BUSY
		SPR:Ĭ��0,״̬�Ĵ�������λ,���WPʹ��
		TB,BP2,BP1,BP0:FLASH����д��������
		WEL:дʹ������
		BUSY:æ���λ(1,æ;0,����)
***********************************************************/
u8 SPI_Flash_ReadSR(void)
{
	u8 byte=0;
	SPI_FLASH_CS(0); //ʹ������
	SPIx_ReadWriteByte(W25X_ReadStatusReg); //���Ͷ�ȡ״̬�Ĵ�������
	byte=SPIx_ReadWriteByte(0Xff); //��ȡһ���ֽ�
	SPI_FLASH_CS(1); //ȡ��Ƭѡ
	return byte;
}
/**********************************************************
** ������:SPI_FLASH_Write_SR
** ��������:дFLASH״̬�Ĵ���
** �������: sr--д��״̬�Ĵ���������
** �������: ��
** ��    �أ���
** ˵����	ֻ��SPR,TB,BP2,BP1,BP0(bit 7,5,4,3,2)����д
***********************************************************/
void SPI_FLASH_Write_SR(u8 sr)
{
	SPI_FLASH_CS(0); //ʹ������
	SPIx_ReadWriteByte(W25X_WriteStatusReg); //����дȡ״̬�Ĵ�������
	SPIx_ReadWriteByte(sr); //д��һ���ֽ�
	SPI_FLASH_CS(1); //ȡ��Ƭѡ
}
/**********************************************************
** ������:SPI_FLASH_Write_Enable
** ��������:FLASHдʹ��
** �������: ��
** �������: ��
** ��    �أ���
***********************************************************/
void SPI_FLASH_Write_Enable(void)
{
	SPI_FLASH_CS(0); //ʹ������
	SPIx_ReadWriteByte(W25X_WriteEnable); //����дʹ��
	SPI_FLASH_CS(1); //ȡ��Ƭѡ
}

/**********************************************************
** ������:SPI_FLASH_Write_Disable
** ��������:FLASHд��ֹ
** �������: ��
** �������: ��
** ��    �أ���
***********************************************************/
void SPI_FLASH_Write_Disable(void)
{
	SPI_FLASH_CS(0); //ʹ������
	SPIx_ReadWriteByte(W25X_WriteDisable); //����д��ָֹ��
	SPI_FLASH_CS(1); //ȡ��Ƭѡ
}
/**********************************************************
** ������:SPI_Flash_ReadID
** ��������:��ȡоƬID��W25X16��IDΪ0XEF14
** �������: ��
** �������: ��
** ��    �أ�Temp--��ȡ��ID
***********************************************************/
u16 SPI_Flash_ReadID(void)
{
	u16 Temp = 0;
	SPI_FLASH_CS(0);
	SPIx_ReadWriteByte(0x90);//���Ͷ�ȡID����
	SPIx_ReadWriteByte(0x00);
	SPIx_ReadWriteByte(0x00);
	SPIx_ReadWriteByte(0x00);
	Temp|=SPIx_ReadWriteByte(0xFF)<<8;//��ȡ��8λ
	Temp|=SPIx_ReadWriteByte(0xFF);	//��ȡ��8
	SPI_FLASH_CS(1);
	return Temp;

}
/**********************************************************
** ������:SPI_Flash_Read
** ��������:��ָ����ַ��ʼ��ȡָ�����ȵ�����
** �������: *pBuffer--���ݴ洢����ַָ��
		     ReadAddr--��ʼ��ȡ�ĵ�ַ(24bit)
			 NumByteToRead--Ҫ��ȡ���ֽ���(���65535)
** �������: ��
** ��    �أ���
***********************************************************/
void SPI_Flash_Read(u8* pBuffer,u32 ReadAddr,u16 NumByteToRead)
{
	SPI_FLASH_CS(0); //ʹ������
	SPIx_ReadWriteByte(W25X_ReadData); //���Ͷ�ȡ����
	SPIx_ReadWriteByte((ReadAddr)>>16); //����24bit��ַ
	SPIx_ReadWriteByte((ReadAddr)>>8);
	SPIx_ReadWriteByte(ReadAddr);
	while(NumByteToRead--)
	{
		*pBuffer++=SPIx_ReadWriteByte(0Xff); //ѭ������
	}
	SPI_FLASH_CS(1); //ȡ��Ƭѡ
}

/**********************************************************
** ������:SPI_Flash_Write_Page
** ��������: ��ָ����ַ��ʼд�����256�ֽڵ�����
			 ��һҳ(0~65535)��д������256���ֽڵ�����
** �������: *pBuffer--���ݴ洢����ַָ��
			 WriteAddr--��ʼд��ĵ�ַ(24bit)
			 NumByteToWrite--Ҫд����ֽ���(���256),������Ӧ�ó�����ҳ��ʣ���ֽ���
** �������: ��
** ��    �أ���
***********************************************************/
void SPI_Flash_Write_Page(u8* pBuffer,u32 WriteAddr,u16 NumByteToWrite)
{
	u16 i;
	SPI_FLASH_Write_Enable(); //SET WEL
	SPI_FLASH_CS(0); //ʹ������
	SPIx_ReadWriteByte(W25X_PageProgram); //����дҳ����
	SPIx_ReadWriteByte((u8)((WriteAddr)>>16)); //����24bit��ַ    
    SPIx_ReadWriteByte((u8)((WriteAddr)>>8));   
    SPIx_ReadWriteByte((u8)WriteAddr); 
	while(NumByteToWrite--)
	{
		SPIx_ReadWriteByte(*pBuffer);//ѭ��д��
		pBuffer++;
	}
	SPI_FLASH_CS(1); //ȡ��Ƭѡ
	SPI_Flash_Wait_Busy(); //�ȴ�д�����
}
/**********************************************************
** ������:SPI_Flash_Write_NoCheck
** ��������:�޼���дSPI FLASH
			����ȷ����д�ĵ�ַ��Χ�ڵ�����ȫ��Ϊ0XFF,�����ڷ�0XFF��д������ݽ�ʧ��!
			�����Զ���ҳ����
			��ָ����ַ��ʼд��ָ�����ȵ�����,����Ҫȷ����ַ��Խ��!
** �������: *pBuffer--���ݴ洢����ַָ��
			 WriteAddr--��ʼд��ĵ�ַ(24bit)
			 NumByteToWrite--Ҫд����ֽ���(���65535)
** �������: ��
** ��    �أ���
***********************************************************/
void SPI_Flash_Write_NoCheck(u8* pBuffer,u32 WriteAddr,u16 NumByteToWrite)
{
	u16 pageremain;
	pageremain=256-WriteAddr%256; //��ҳʣ����ֽ���
	if(NumByteToWrite<=pageremain)
		pageremain=NumByteToWrite;//������256���ֽ�
	while(1)
	{
		SPI_Flash_Write_Page(pBuffer,WriteAddr,pageremain);
		if(NumByteToWrite==pageremain)
				break;//д�������
		else //NumByteToWrite>pageremain
		{
			pBuffer+=pageremain;
			WriteAddr+=pageremain;
			NumByteToWrite-=pageremain; //��ȥ�Ѿ�д���˵��ֽ���
			if(NumByteToWrite>256)
				pageremain=256; //һ�ο���д��256���ֽ�
			else 
				pageremain=NumByteToWrite; //����256���ֽ���
		}
	};
}

u8 SPI_FLASH_BUF[4096];
/**********************************************************
** ������:SPI_Flash_Write
** ��������: ������ָ����ַ��ʼд��ָ�����ȵ�����,�ú�������������!
** �������: *pBuffer--���ݴ洢����ַָ��
			 WriteAddr--��ʼд��ĵ�ַ(24bit)
			 NumByteToWrite--Ҫд����ֽ���(���65535)
** �������: ��
** ��    �أ���
***********************************************************/
void SPI_Flash_Write(u8* pBuffer,u32 WriteAddr,u16 NumByteToWrite)
{
	u32 secpos;
	u16 secoff;
	u16 secremain;
	u16 i;
	secpos=WriteAddr/4096;//������ַ 0~511 for w25x16
	secoff=WriteAddr%4096;//�������ڵ�ƫ��
	secremain=4096-secoff;//����ʣ��ռ��С
	if(NumByteToWrite<=secremain)secremain=NumByteToWrite;//������4096���ֽ�
	while(1)
	{
		SPI_Flash_Read(SPI_FLASH_BUF,secpos*4096,4096);//������������������
		for(i=0;i<secremain;i++)//У������
		{
			if(SPI_FLASH_BUF[secoff+i]!=0XFF)break;//��Ҫ����
		}
		if(i<secremain)//��Ҫ����
		{
			SPI_Flash_Erase_Sector(secpos);//�����������
			for(i=0;i<secremain;i++) //����
			{
				SPI_FLASH_BUF[i+secoff]=pBuffer[i];
			}
			SPI_Flash_Write_NoCheck(SPI_FLASH_BUF,secpos*4096,4096);//д����������
		}
		else 
			SPI_Flash_Write_NoCheck(pBuffer,WriteAddr,secremain);//д�Ѿ������˵�,ֱ��д������ʣ������.
		if(NumByteToWrite==secremain)break;//д�������
		else//д��δ����
		{
			secpos++;//������ַ��1
			secoff=0;//ƫ��λ��Ϊ0
			pBuffer+=secremain; //ָ��ƫ��
			WriteAddr+=secremain;//д��ַƫ��
			NumByteToWrite-=secremain; //�ֽ����ݼ�
			if(NumByteToWrite>4096)
				secremain=4096; //��һ����������д����
			else 
				secremain=NumByteToWrite; //��һ����������д����
		}
	};
}
/**********************************************************
** ������:SPI_Flash_Erase_Chip
** ��������: ��������оƬ���ȴ�ʱ��Ƚϳ�...
** �������: ��
** �������: ��
** ��    �أ���
***********************************************************/
void SPI_Flash_Erase_Chip(void)
{
	SPI_FLASH_Write_Enable(); //SET WEL
	SPI_Flash_Wait_Busy();
	SPI_FLASH_CS(0); //ʹ������
	SPIx_ReadWriteByte(W25X_ChipErase); //����Ƭ��������
	SPI_FLASH_CS(1); //ȡ��Ƭѡ
	SPI_Flash_Wait_Busy(); //�ȴ�оƬ��������
}

/**********************************************************
** ������:SPI_Flash_Erase_Sector
** ��������: ����һ������
** �������: Dst_Addr--������ַ 0~511 for w25x16
** �������: ��
** ��    �أ���
***********************************************************/
void SPI_Flash_Erase_Sector(u32 Dst_Addr)
{
	Dst_Addr*=4096;
	SPI_FLASH_Write_Enable(); //SET WEL
	SPI_Flash_Wait_Busy();
	SPI_FLASH_CS(0); //ʹ������
	SPIx_ReadWriteByte(W25X_SectorErase); //������������ָ��
	SPIx_ReadWriteByte((u8)((Dst_Addr)>>16)); //����24bit��ַ
	SPIx_ReadWriteByte((u8)((Dst_Addr)>>8));
	SPIx_ReadWriteByte((u8)Dst_Addr);
	SPI_FLASH_CS(1); //ȡ��Ƭѡ
	SPI_Flash_Wait_Busy(); //�ȴ��������
}
/**********************************************************
** ������:SPI_Flash_Wait_Busy
** ��������: �ȴ�FLASH���ڿ���״̬
** �������: ��
** �������: ��
** ��    �أ���
***********************************************************/
void SPI_Flash_Wait_Busy(void)
{
	while ((SPI_Flash_ReadSR()&0x01)==0x01); // �ȴ�BUSYλ���
}
/**********************************************************
** ������:SPI_Flash_PowerDown
** ��������: �������ģʽ
** �������: ��
** �������: ��
** ��    �أ���
***********************************************************/
void SPI_Flash_PowerDown(void)
{
	SPI_FLASH_CS(0); //ʹ������
	SPIx_ReadWriteByte(W25X_PowerDown); //���͵�������
	SPI_FLASH_CS(1); //ȡ��Ƭѡ
	delay_us(3); //�ȴ�TPD
}

/**********************************************************
** ������:SPI_Flash_WAKEUP
** ��������: ����
** �������: ��
** �������: ��
** ��    �أ���
***********************************************************/
void SPI_Flash_WAKEUP(void)
{
	SPI_FLASH_CS(0); //ʹ������
	SPIx_ReadWriteByte(W25X_ReleasePowerDown); // send W25X_PowerDown command 0xAB
	SPI_FLASH_CS(1); //ȡ��Ƭѡ
	delay_us(3); //�ȴ�TRES1
}

