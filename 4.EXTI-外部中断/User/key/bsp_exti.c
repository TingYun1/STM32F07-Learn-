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
	/*第一步：初始化需要连接到EXTI线的GPIO*/

	/*开启按键GPIO口时钟*/
	RCC_AHB1PeriphClockCmd(KEY1_INT_GPIO_CLK,ENABLE);

	/*第三步：配置NVIC*/
	NVIC_Configuration();
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	/*第二步：定义一个GPIO初始化结构体*/
	
	/*第三步：配置GPIO初始化结构体成员*/
	GPIO_InitStructure.GPIO_Pin  =GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode =GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd =GPIO_PuPd_NOPULL;
	
	GPIO_Init(GPIOA,&GPIO_InitStructure);

	/*第二步：初始化EXTI*/
	
	/*开启按键SYCFG时钟*/
	RCC_AHB1PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE);	
	
	/*连接EXTI中断源到key1引脚*/
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA,EXTI_PinSource0);
	
	/*选择EXTI中断源*/
	EXTI_InitStructure.EXTI_Line=EXTI_Line0;
	/*中断模式*/
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	/*下降沿触发*/
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Rising;	
	/*使能中断/事件线*/
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	
	EXTI_Init(&EXTI_InitStructure);
	/*第三步：配置NVIC*/
	 NVIC_Configuration();
	/*第四步：编写中断服务函数*/
}

