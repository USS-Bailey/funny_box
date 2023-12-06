#include "bsp_bluetooth.h"
#include "stdio.h"

/*蓝牙模块 GPIO 初始化*/
void Bluetooth_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;      
  
	//USART1 GPIO端口时钟开启
	USART_GPIO_APBx(USART_GPIO_CLK, ENABLE);
	//USART1 串口外设时钟开启
	USART_DEV_APBx(USART_DEV_CLK, ENABLE);
	//USART STATE端口时钟开启
	USART_ST_APBx(USART_ST_CLK, ENABLE);
	
	//USART1 TX端口配置为复用推挽输出 	
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;    
  GPIO_InitStructure.GPIO_Pin = USART_Tx_Pin;                
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;           
  GPIO_Init(USART_Tx_Port, &GPIO_InitStructure);                
      
	//USART1 RX端口配置为浮空输入
  GPIO_InitStructure.GPIO_Pin = USART_Rx_Pin;           
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;        
  GPIO_Init(USART_Rx_Port, &GPIO_InitStructure);                 
       
	//HX05 STATE端口配置为浮空输入
  GPIO_InitStructure.GPIO_Pin = USART_Rx_Pin;  
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;    
  GPIO_Init(USART_Rx_Port, &GPIO_InitStructure);     
}

/*串口 NVIC 初始化*/
void Bluetooth_NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStruct;
	
	//中断组别优先级
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	//中断端口配置
	NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn;
	//中断抢占优先级
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;
	//中断子优先级
	NVIC_InitStruct.NVIC_IRQChannelSubPriority  = 2;
	//中断使能
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;

	//初始化 MVIC 配置
	NVIC_Init(&NVIC_InitStruct);
}

/*串口 USART 初始化*/
void Bluetooth_USART_Config(void)
{
	USART_InitTypeDef USART_InitStructure;
	
	// 配置波特率
	USART_InitStructure.USART_BaudRate = USART_x_BAUDRATE;
	// 配置 针数据字长
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	// 配置停止位
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	// 配置校验位
	USART_InitStructure.USART_Parity = USART_Parity_No ;
	// 配置硬件流控制
	USART_InitStructure.USART_HardwareFlowControl = 
	USART_HardwareFlowControl_None;
	// 配置工作模式，收发一起
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	// 完成串口的初始化配置
	USART_Init(USART_x, &USART_InitStructure);
	
	// 串口中断优先级配置
	Bluetooth_NVIC_Config();
	
	// 使能串口接收中断
	USART_ITConfig(USART_x, USART_IT_RXNE, ENABLE);	
	
	// 使能串口
	USART_Cmd(USART_x, ENABLE);	
}

void bluetooth_Config(void)
{
	Bluetooth_GPIO_Config();
	Bluetooth_NVIC_Config();
	Bluetooth_USART_Config();
}

/*输入输出相关函数*/
int fputc(int ch, FILE *f)
{
		/* 发送一个字节数据到串口 */
		USART_SendData(USART_x, (uint8_t) ch);
		
		/* 等待发送完毕 */
		while (USART_GetFlagStatus(USART_x, USART_FLAG_TXE) == RESET);		
	
		return (ch);
}

///重定向c库函数scanf到串口，重写向后可使用scanf、getchar等函数
int fgetc(FILE *f)
{
		/* 等待串口输入数据 */
		while (USART_GetFlagStatus(USART_x, USART_FLAG_RXNE) == RESET);

		return (int)USART_ReceiveData(USART_x);
}

