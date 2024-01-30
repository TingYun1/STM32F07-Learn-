#include "stm32f4xx.h"
#include "bsp_led.h"

void Delay(uint32_t count)
{
	for(;count!=0;count--);
}
int main(void)
{
	LED_GPIO_Config();
	//GPIO_SetBits(GPIOA,GPIO_Pin_6);
  GPIO_ResetBits(GPIOA,GPIO_Pin_6);
	while(1)
	{
		GPIO_SetBits(GPIOA,GPIO_Pin_6);
		Delay(0xffffff);
    GPIO_ResetBits(GPIOA,GPIO_Pin_6);
		Delay(0xffffff);
	}
	
}

