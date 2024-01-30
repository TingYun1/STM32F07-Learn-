
#include "stm32f4xx.h"

void delay(unsigned int count)
{
	for(;count!=0;count--);
}

int main(void)
{
	#if 0
	//开GPIO端口时钟
	RCC_AHB1ENR |=(1<<0);
	//配置GPIOA为输出
	GPIOA_MODER &=~(3<<(2*0));
	GPIOA_MODER |= (1<<(2*0));
	GPIOA_MODER &=~(3<<(2*1));
	GPIOA_MODER |= (1<<(2*1));
	
	GPIOA_ODR |= (1<<0);
	GPIOA_ODR |= (1<<1);
	
	while(1)
	{
		
	  GPIOA_ODR &=~(1<<0);
		GPIOA_ODR |= (1<<1);
		delay(0xffffff);
		GPIOA_ODR |= (1<<0);
		GPIOA_ODR &=~(1<<1);
		delay(0xffffff);
	}
	#elif 1
	//开GPIO端口时钟
	RCC_AHB1ENR |=(1<<0);
	//配置GPIOA为输出
	GPIOA->MODER &=~(3<<(2*0));
	GPIOA->MODER |= (1<<(2*0));
	GPIOA->MODER &=~(3<<(2*1));
	GPIOA->MODER |= (1<<(2*1));
	
	GPIOA->ODR |= (1<<0);
	GPIOA->ODR |= (1<<1);
	
	while(1)
	{
		
	  GPIOA->ODR &=~(1<<0);
		GPIOA->ODR |= (1<<1);
		delay(0xffffff);
		GPIOA->ODR |= (1<<0);
		GPIOA->ODR &=~(1<<1);
		delay(0xffffff);
	}
	#endif
}

void SystemInit(void)
{
	
}
