// bsp:board support package  �弶֧�ְ�


#include "bsp_led.h"

void LED_GPIO_Config(void)
{
	/*��һ������GPIOʱ��*/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	/*�ڶ���������һ��GPIO��ʼ���ṹ��*/
  GPIO_InitTypeDef GPIO_InitStruct;
	
	/*������������GPIO��ʼ���ṹ���Ա*/
	GPIO_InitStruct.GPIO_Pin  =GPIO_Pin_6;
	GPIO_InitStruct.GPIO_Mode =GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_Speed=GPIO_Low_Speed;
	GPIO_InitStruct.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd =GPIO_PuPd_UP;
	

	/*���Ĳ�������GPIO��ʼ�������������úõĽṹ��ĳ�Ա�Ĳ���д��Ĵ���*/
	GPIO_Init(GPIOA,&GPIO_InitStruct);
}

