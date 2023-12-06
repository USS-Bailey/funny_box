#include "bsp_key.h"

/*KEY GPIO端口配置*/
void KEY_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	//开启 GPIO 时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO|KEY_GPIO_CLK, ENABLE);
	
	//配置 GPIO 结构体
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Pin = KEY_GPIO_PIN;
	
	//初始化 GPIO 配置
	GPIO_Init(KEY_GPIO_PORT, &GPIO_InitStruct);
}

/*KEY NVIC中断优先级配置*/
void KEY_NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStruct;
		
	//中断组别优先级
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	//中断端口配置
	NVIC_InitStruct.NVIC_IRQChannel = EXTI0_IRQn;
	//中断抢占优先级
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	//中断子优先级
	NVIC_InitStruct.NVIC_IRQChannelSubPriority  = 1;
	//中断使能
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;

	//初始化 MVIC 配置
	NVIC_Init(&NVIC_InitStruct);
	
}

/*KEY EXTI中断配置*/
void KEY_EXTI_Config(void)
{
	EXTI_InitTypeDef EXTI_InitStruct;
	
	//开启GPIO与EXTI映射
	GPIO_EXTILineConfig(KEY_EXTI_PORT,KEY_EXTI_PIN);
	
	//中断EXTI线
	EXTI_InitStruct.EXTI_Line = KEY_EXTI_LINE;
	//配置为中断模式
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	//配置为下降沿中断
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;
	//中断使能开
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	
	//初始化 EXTI 配置
	EXTI_Init(&EXTI_InitStruct);
}

void KEY_Config(void)
{
	


	KEY_NVIC_Config();
	KEY_GPIO_Config();
	KEY_EXTI_Config();
}

