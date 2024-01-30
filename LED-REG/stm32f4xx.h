

#define GPIOA_BASE   ((unsigned int)0x40020000)
#define RCC_BASE   	 ((unsigned int)0x40023800)

#define GPIOA_MODER  *(unsigned int*)(GPIOA_BASE+0X00)
#define GPIOA_OTYPER *(unsigned int*)(GPIOA_BASE+0X04)
#define GPIOA_ODR    *(unsigned int*)(GPIOA_BASE+0X14)

#define RCC_AHB1ENR  *(unsigned int*)(RCC_BASE+0X30)

