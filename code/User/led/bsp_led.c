//bsp ： braod support package 板级支持包
#include "bsp_led.h"

void LED_GPIO_Config(void)
{
	GPIO_InitTypeDef GOIP_InitStruct;
	
	//开启 GPIO 时钟
	RCC_APB2PeriphClockCmd(LED_GPIO_CLK, ENABLE);
	
	//GPIO结构体配置
	GOIP_InitStruct.GPIO_Pin = LED_GPIO_PIN;
	GOIP_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GOIP_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	
	//初始化 GPIO 配置
	GPIO_Init(LED_GPIO_PORT, &GOIP_InitStruct);
}
