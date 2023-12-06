#ifndef __BSP_PWM_H
#define __BSP_PWM_H

#include "stm32f10x.h"

//马达GPIO时钟定义
#define MOTOR_GPIO_CLK				RCC_APB2Periph_GPIOB

//马达GPIO定义
#define MOTOR_GPIO_Pin				GPIO_Pin_0
#define MOTOR_GPIO_Port				GPIOB

//TIM2定时器定义
#define TIMx									TIM3
#define TIMx_Period						199
#define TIMx_Prescaler				(7200-1)
#define TIM_OCxInit						TIM_OC3Init
#define TIM_OCxPreloadConfig	TIM_OC3PreloadConfig

void TIM1_PWM_Init(uint16_t arr,uint16_t psc);


#endif /*__BSP_PWM_H*/

