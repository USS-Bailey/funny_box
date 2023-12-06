#include "bsp_key.h"

/*KEY GPIO�˿�����*/
void KEY_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	//���� GPIO ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO|KEY_GPIO_CLK, ENABLE);
	
	//���� GPIO �ṹ��
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Pin = KEY_GPIO_PIN;
	
	//��ʼ�� GPIO ����
	GPIO_Init(KEY_GPIO_PORT, &GPIO_InitStruct);
}

/*KEY NVIC�ж����ȼ�����*/
void KEY_NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStruct;
		
	//�ж�������ȼ�
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	//�ж϶˿�����
	NVIC_InitStruct.NVIC_IRQChannel = EXTI0_IRQn;
	//�ж���ռ���ȼ�
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	//�ж������ȼ�
	NVIC_InitStruct.NVIC_IRQChannelSubPriority  = 1;
	//�ж�ʹ��
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;

	//��ʼ�� MVIC ����
	NVIC_Init(&NVIC_InitStruct);
	
}

/*KEY EXTI�ж�����*/
void KEY_EXTI_Config(void)
{
	EXTI_InitTypeDef EXTI_InitStruct;
	
	//����GPIO��EXTIӳ��
	GPIO_EXTILineConfig(KEY_EXTI_PORT,KEY_EXTI_PIN);
	
	//�ж�EXTI��
	EXTI_InitStruct.EXTI_Line = KEY_EXTI_LINE;
	//����Ϊ�ж�ģʽ
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	//����Ϊ�½����ж�
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;
	//�ж�ʹ�ܿ�
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	
	//��ʼ�� EXTI ����
	EXTI_Init(&EXTI_InitStruct);
}

void KEY_Config(void)
{
	


	KEY_NVIC_Config();
	KEY_GPIO_Config();
	KEY_EXTI_Config();
}

