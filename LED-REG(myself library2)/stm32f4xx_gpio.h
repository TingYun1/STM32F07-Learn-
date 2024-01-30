#ifndef _STM32F4XX_GPIO_H
#define  _STM32F4XX_GPIO_H

#include "stm32f4xx.h"

#define GPIO_Pin_0 (uint16_t) (1<<0)
#define GPIO_Pin_1 (uint16_t) (1<<1)
void GPIO_SetBits(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin);
void GPIO_ResetBits(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin);
#endif

