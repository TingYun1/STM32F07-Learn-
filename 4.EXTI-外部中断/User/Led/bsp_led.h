
#ifndef _BSP_LED_H
#define _BSP_LED_H

#include "stm32f4xx_gpio.h"
#define  LED_GPIO_PIN   GPIO_Pin_6
#define  LED_GPIO_PORT  GPIOA
#define LED_TOGGLE      {LED_GPIO_PORT->ODR^=LED_GPIO_PIN;}
void LED_GPIO_Config(void);
#endif
