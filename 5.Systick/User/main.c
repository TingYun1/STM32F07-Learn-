#include "stm32f4xx.h"
#include "bsp_led.h"
#include "bsp_systick.h"

void Delay(uint32_t count)
{
	for(;count!=0;count--);
}
int main(void)
{
	LED_GPIO_Config();
	SysTick_Init();
	//GPIO_SetBits(GPIOA,GPIO_Pin_6);
  GPIO_ResetBits(GPIOA,GPIO_Pin_6);
	while(1)
	{
		GPIO_SetBits(GPIOA,GPIO_Pin_6);
		Delay_ms(100);
    GPIO_ResetBits(GPIOA,GPIO_Pin_6);
		Delay_ms(100);
	}
	
}

