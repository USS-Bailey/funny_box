#ifndef __BSP_BLUETOOTH_H
#define __BSP_BLUETOOTH_H

#include "stm32f10x.h"

/*===================USART1 GPIO�˿ں궨��===================*/
//ʱ�Ӳ���
#define USART_GPIO_CLK								RCC_APB2Periph_GPIOA
#define USART_GPIO_APBx								RCC_APB2PeriphClockCmd
#define USART_DEV_CLK									RCC_APB2Periph_USART1
#define USART_DEV_APBx								RCC_APB2PeriphClockCmd
#define USART_ST_CLK									RCC_APB2Periph_GPIOA
#define USART_ST_APBx									RCC_APB2PeriphClockCmd

//USART1 TX��Ų���
#define USART_Tx_Port									GPIOA
#define USART_Tx_Pin									GPIO_Pin_9

//USART1 RX��Ų���
#define USART_Rx_Port									GPIOA
#define USART_Rx_Pin									GPIO_Pin_10

//USART STATE��Ų���
#define USART_St_Port									GPIOA
#define USART_St_Pin									GPIO_Pin_4

//USART ��������
#define	USART_x_BAUDRATE							115200
#define	USART_x												USART1

//������
void bluetooth_Config(void);

#endif /*__BSP_BLUETOOTH_H*/
