#ifndef STM32F407_GPIO_H
#define STM32F407_GPIO_H

#include <stdint.h>

#include "stm32f407_memory_map.h"

typedef struct
{
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t LCKR;
    volatile uint32_t AFR[2];

} GPIO_TypeDef;

#define GPIOD ((GPIO_TypeDef *)GPIOD_BASE)

#endif