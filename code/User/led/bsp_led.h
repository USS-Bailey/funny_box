#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "stm32f10x.h"


//GPIO 宏定义
#define LED_GPIO_PIN				GPIO_Pin_13
#define LED_GPIO_PORT				GPIOC
#define LED_GPIO_CLK				RCC_APB2Periph_GPIOC

//LED 开关宏定义
#define ON  								0
#define OFF									1

#define LED(type)					if(type)\
															GPIO_SetBits(LED_GPIO_PORT,LED_GPIO_PIN);\
														else \
															GPIO_ResetBits(LED_GPIO_PORT,LED_GPIO_PIN);

//LED 初始化函数														
void LED_GPIO_Config(void);


#endif /*_BSP_LED_H*/

