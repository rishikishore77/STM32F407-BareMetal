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
    RCC_AHB1ENR |= (0x1); // Enable GPIOA clock
    RCC_AHB1ENR |= (0x1<<3); // Enable GPIOD clock

    GPIOA->MODER &= ~(0x3 << 0); // PAO0 as input
    GPIOD->MODER &= ~(0x3 << 24); // Clear PD12 mode bits
    GPIOD->MODER |= (0x1 << 24); // Set PD12 as output

    while(1)
    {
        if(GPIOA->IDR & 0x1) // Check if PA0 is high
        {
            GPIOD->ODR ^= (0x1<<12); // Toggle PD12
            delay(10000);
        }
    }


}