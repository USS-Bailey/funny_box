#include "bsp_bluetooth.h"
#include "stdio.h"

/*����ģ�� GPIO ��ʼ��*/
void Bluetooth_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;      
  
	//USART1 GPIO�˿�ʱ�ӿ���
	USART_GPIO_APBx(USART_GPIO_CLK, ENABLE);
	//USART1 ��������ʱ�ӿ���
	USART_DEV_APBx(USART_DEV_CLK, ENABLE);
	//USART STATE�˿�ʱ�ӿ���
	USART_ST_APBx(USART_ST_CLK, ENABLE);
	
	//USART1 TX�˿�����Ϊ����������� 	
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;    
  GPIO_InitStructure.GPIO_Pin = USART_Tx_Pin;                
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;           
  GPIO_Init(USART_Tx_Port, &GPIO_InitStructure);                
      
	//USART1 RX�˿�����Ϊ��������
  GPIO_InitStructure.GPIO_Pin = USART_Rx_Pin;           
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;        
  GPIO_Init(USART_Rx_Port, &GPIO_InitStructure);                 
       
	//HX05 STATE�˿�����Ϊ��������
  GPIO_InitStructure.GPIO_Pin = USART_Rx_Pin;  
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;    
  GPIO_Init(USART_Rx_Port, &GPIO_InitStructure);     
}

/*���� NVIC ��ʼ��*/
void Bluetooth_NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStruct;
	
	//�ж�������ȼ�
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	//�ж϶˿�����
	NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn;
	//�ж���ռ���ȼ�
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;
	//�ж������ȼ�
	NVIC_InitStruct.NVIC_IRQChannelSubPriority  = 2;
	//�ж�ʹ��
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;

	//��ʼ�� MVIC ����
	NVIC_Init(&NVIC_InitStruct);
}

/*���� USART ��ʼ��*/
void Bluetooth_USART_Config(void)
{
	USART_InitTypeDef USART_InitStructure;
	
	// ���ò�����
	USART_InitStructure.USART_BaudRate = USART_x_BAUDRATE;
	// ���� �������ֳ�
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	// ����ֹͣλ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	// ����У��λ
	USART_InitStructure.USART_Parity = USART_Parity_No ;
	// ����Ӳ��������
	USART_InitStructure.USART_HardwareFlowControl = 
	USART_HardwareFlowControl_None;
	// ���ù���ģʽ���շ�һ��
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	// ��ɴ��ڵĳ�ʼ������
	USART_Init(USART_x, &USART_InitStructure);
	
	// �����ж����ȼ�����
	Bluetooth_NVIC_Config();
	
	// ʹ�ܴ��ڽ����ж�
	USART_ITConfig(USART_x, USART_IT_RXNE, ENABLE);	
	
	// ʹ�ܴ���
	USART_Cmd(USART_x, ENABLE);	
}

void bluetooth_Config(void)
{
	Bluetooth_GPIO_Config();
	Bluetooth_NVIC_Config();
	Bluetooth_USART_Config();
}

/*���������غ���*/
int fputc(int ch, FILE *f)
{
		/* ����һ���ֽ����ݵ����� */
		USART_SendData(USART_x, (uint8_t) ch);
		
		/* �ȴ�������� */
		while (USART_GetFlagStatus(USART_x, USART_FLAG_TXE) == RESET);		
	
		return (ch);
}

///�ض���c�⺯��scanf�����ڣ���д����ʹ��scanf��getchar�Ⱥ���
int fgetc(FILE *f)
{
		/* �ȴ������������� */
		while (USART_GetFlagStatus(USART_x, USART_FLAG_RXNE) == RESET);

		return (int)USART_ReceiveData(USART_x);
}

