#include "stm32f4xx.h"
#include "bsp_led.h"
#include "bsp_key.h"

void Delay(uint32_t count)
{
	for(;count!=0;count--);
}
int main(void)
{
	LED_GPIO_Config();
	KEY_LED_GPIO_Config();
	//GPIO_SetBits(GPIOA,GPIO_Pin_6);
  GPIO_ResetBits(GPIOA,GPIO_Pin_6);
	
	//°´¼üÉ¨Ãè
	while(1)
	{
//		if(KEY_Scan(GPIOA,GPIO_Pin_0)==KEY_ON) LED_TOGGLE;
		if(KEY_Scan(GPIOA,GPIO_Pin_0)==KEY_ON) LED_TOGGLE;
			
//		GPIO_SetBits(GPIOA,GPIO_Pin_6);
//		Delay(0xffffff);
//    GPIO_ResetBits(GPIOA,GPIO_Pin_6);
//		Delay(0xffffff);
	}
	
}

