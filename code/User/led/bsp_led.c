//bsp �� braod support package �弶֧�ְ�
#include "bsp_led.h"

void LED_GPIO_Config(void)
{
	GPIO_InitTypeDef GOIP_InitStruct;
	
	//���� GPIO ʱ��
	RCC_APB2PeriphClockCmd(LED_GPIO_CLK, ENABLE);
	
	//GPIO�ṹ������
	GOIP_InitStruct.GPIO_Pin = LED_GPIO_PIN;
	GOIP_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GOIP_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	
	//��ʼ�� GPIO ����
	GPIO_Init(LED_GPIO_PORT, &GOIP_InitStruct);
}
