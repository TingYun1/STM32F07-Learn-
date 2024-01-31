#include "bsp_key.h"

void KEY_LED_GPIO_Config(void)
{
	/*��һ������GPIOʱ��*/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	/*�ڶ���������һ��GPIO��ʼ���ṹ��*/
  GPIO_InitTypeDef GPIO_InitStruct;
	
	/*������������GPIO��ʼ���ṹ���Ա*/
	GPIO_InitStruct.GPIO_Pin  =GPIO_Pin_0;
	GPIO_InitStruct.GPIO_Mode =GPIO_Mode_IN;
	//GPIO_InitStruct.GPIO_Speed=GPIO_Low_Speed;
	//GPIO_InitStruct.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd =GPIO_PuPd_NOPULL;
	

	/*���Ĳ�������GPIO��ʼ�������������úõĽṹ��ĳ�Ա�Ĳ���д��Ĵ���*/
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE,ENABLE);
	/*�ڶ���������һ��GPIO��ʼ���ṹ��*/
  GPIO_InitTypeDef GPIO_InitStruct1;
	
	/*������������GPIO��ʼ���ṹ���Ա*/
	GPIO_InitStruct1.GPIO_Pin  =GPIO_Pin_4;
	GPIO_InitStruct1.GPIO_Mode =GPIO_Mode_IN;
	//GPIO_InitStruct.GPIO_Speed=GPIO_Low_Speed;
	//GPIO_InitStruct.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStruct1.GPIO_PuPd =GPIO_PuPd_UP;
	

	/*���Ĳ�������GPIO��ʼ�������������úõĽṹ��ĳ�Ա�Ĳ���д��Ĵ���*/
	GPIO_Init(GPIOE,&GPIO_InitStruct1);
}


uint8_t KEY_Scan(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin)
{
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin)==KEY_ON)
	{
		while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin)==KEY_ON);
		return KEY_ON;
	}
	else return KEY_OFF;
}

