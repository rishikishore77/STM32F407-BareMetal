#ifndef STM32F407_MEMORY_MAP_H
#define STM32F407_MEMORY_MAP_H

#include <stdint.h>

#define PERIPHERAL_BASE       0x40000000UL
#define AHB1PERIPH_BASE       0x40020000UL

#define RCC_BASE              0x40023800UL

#define GPIOA_BASE            (AHB1PERIPH_BASE + 0x0000UL)
#define GPIOB_BASE            (AHB1PERIPH_BASE + 0x0400UL)
#define GPIOC_BASE            (AHB1PERIPH_BASE + 0x0800UL)
#define GPIOD_BASE            (AHB1PERIPH_BASE + 0x0C00UL)

#endif