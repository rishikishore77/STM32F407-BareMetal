#include "stm32f407_gpio.h"
#include "stm32f407_rcc.h"

static void delay(volatile int count)
{
    while(count--)
    {
        __asm__("NOP");
    }
}

int main(void)
{
    /* Enable GPIOD clock*/
    RCC_AHB1ENR |= (0x1<<3);

    /* Set PD12 as output */
    GPIOD->MODER &= ~(0x3 << 24);
    GPIOD->MODER |= (0x1 << 24);

    /* Set PD13 as output */
    GPIOD->MODER &= ~(0x3 << 26);
    GPIOD->MODER |= (0x1 << 26);

    /* Set PD14 as output */
    GPIOD->MODER &= ~(0x3 << 28);
    GPIOD->MODER |= (0x1 << 28);

    /* Set PD15 as output */
    GPIOD->MODER &= ~(0x3 << 30);
    GPIOD->MODER |= (0x1 << 30);

    while(1)
    {
        GPIOD->ODR ^= 0x1<<12; // Toggle PD12
        delay(1000000);
        GPIOD->ODR ^= 0x1<<12; // Toggle PD12
        GPIOD->ODR ^= 0x1<<13; // Toggle PD13
        delay(1000000);
        GPIOD->ODR ^= 0x1<<13; // Toggle PD13
        GPIOD->ODR ^= 0x1<<14; // Toggle PD14
        delay(1000000);
        GPIOD->ODR ^= 0x1<<14; // Toggle PD14
        GPIOD->ODR ^= 0x1<<15; // Toggle PD15
        delay(1000000);
        GPIOD->ODR ^= 0x1<<15; // Toggle PD15
    }

}