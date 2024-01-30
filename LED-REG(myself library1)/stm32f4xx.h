#ifndef _STM32F4XX_H
#define _STM32F4XX_H

#define GPIOA_BASE   ((unsigned int)0x40020000)
#define RCC_BASE   	 ((unsigned int)0x40023800)

#define GPIOA_MODER  *(unsigned int*)(GPIOA_BASE+0X00)
#define GPIOA_OTYPER *(unsigned int*)(GPIOA_BASE+0X04)
#define GPIOA_ODR    *(unsigned int*)(GPIOA_BASE+0X14)

#define RCC_AHB1ENR  *(unsigned int*)(RCC_BASE+0X30)
	
typedef unsigned int             uint32_t;
typedef unsigned short int       uint16_t;
typedef struct
{
	uint32_t MODER;
	uint32_t OTYPER;
	uint32_t OSPEEDR;
	uint32_t PUPDER;
	uint32_t IDR;
	uint32_t ODR;
	uint16_t BSRRL;
	uint16_t BSRRH;
	uint32_t LCKR;
	uint32_t AFRL;
	uint32_t AFRH;
}GPIO_Taypedef;

#define  GPIOA   ((GPIO_Taypedef*)GPIOA_BASE)

#endif 
