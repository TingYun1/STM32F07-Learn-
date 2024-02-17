#include "bsp_exti.h"

static void NVIC_Configuration(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	NVIC_InitStructure.NVIC_IRQChannel=EXTI0_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	
	NVIC_Init(&NVIC_InitStructure);
	
}
void EXTI_Key_Config(void)
{		
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	/*��һ������ʼ����Ҫ���ӵ�EXTI�ߵ�GPIO*/

	/*��������GPIO��ʱ��*/
	RCC_AHB1PeriphClockCmd(KEY1_INT_GPIO_CLK,ENABLE);

	/*������������NVIC*/
	NVIC_Configuration();
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	/*�ڶ���������һ��GPIO��ʼ���ṹ��*/
	
	/*������������GPIO��ʼ���ṹ���Ա*/
	GPIO_InitStructure.GPIO_Pin  =GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode =GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd =GPIO_PuPd_NOPULL;
	
	GPIO_Init(GPIOA,&GPIO_InitStructure);

	/*�ڶ�������ʼ��EXTI*/
	
	/*��������SYCFGʱ��*/
	RCC_AHB1PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE);	
	
	/*����EXTI�ж�Դ��key1����*/
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA,EXTI_PinSource0);
	
	/*ѡ��EXTI�ж�Դ*/
	EXTI_InitStructure.EXTI_Line=EXTI_Line0;
	/*�ж�ģʽ*/
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	/*�½��ش���*/
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Rising;	
	/*ʹ���ж�/�¼���*/
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	
	EXTI_Init(&EXTI_InitStructure);
	/*������������NVIC*/
	 NVIC_Configuration();
	/*���Ĳ�����д�жϷ�����*/
}

