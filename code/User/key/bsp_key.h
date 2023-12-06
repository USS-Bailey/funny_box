#ifndef __BSP_KEY_H
#define __BSP_KEY_H

#include "stm32f10x.h"

//GPIO 宏定义
#define KEY_GPIO_PIN				GPIO_Pin_0
#define KEY_GPIO_PORT				GPIOA
#define KEY_GPIO_CLK				RCC_APB2Periph_GPIOA

//中断部分 宏定义
#define KEY_EXTI_IRQn				EXTI0_IRQn
#define KEY_IRQHandler			EXTI0_IRQHandler

#define KEY_EXTI_PORT				GPIO_PortSourceGPIOA
#define KEY_EXTI_PIN				GPIO_PinSource0

#define KEY_EXTI_LINE				EXTI_Line0

void KEY_Config(void);

#endif /*__BSP_KEY_H*/
