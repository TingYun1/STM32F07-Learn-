#include "bsp_systick.h"
#include "bsp_systick.h"


 __IO u32 TimingDelay;
void SysTick_Init(void)
{
	if(SysTick_Config(SystemCoreClock/1000))
	{
		while(1);
	
	}
}

void Delay_ms(__IO u32 nTime)
{
	TimingDelay =nTime;
	while(TimingDelay!=0);
}

