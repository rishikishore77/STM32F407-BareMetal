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

    while(1)
    {
        GPIOD->ODR ^= 0x1<<12; // Toggle PD12
        delay(1000000);
    }

}