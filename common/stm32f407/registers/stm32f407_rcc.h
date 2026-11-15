#ifndef STM32F407_RCC_H
#define STM32F407_RCC_H

#include <stdint.h>

#include "stm32f407_memory_map.h"

#define RCC_AHB1ENR     (*(volatile uint32_t *)(RCC_BASE + 0x30U))

#endif