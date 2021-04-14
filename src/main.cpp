#include <CMSIS/device/ST/stm32wlxx.h>

#define LED_BANK        GPIOB
#define LED_GREEN       9
#define LED_RED         11
#define LED_BLUE        15

static void delay(int n)
{
    for(int x = 0; x< n * 1000; x++)
    {
        __NOP();
    }
}

int main(int, char**) 
{
    RCC->AHB2ENR = RCC_AHB2ENR_GPIOBEN;
    LED_BANK->MODER = (1 << (2 * LED_GREEN)) | (1 << (2 * LED_RED)) | (1 << (2 * LED_BLUE));
    
    
    while(1)
    {
        LED_BANK->ODR ^= (1 << LED_GREEN);
        delay(100);
        LED_BANK->ODR ^= (1 << LED_RED);
        delay(100);
        LED_BANK->ODR ^= (1 << LED_BLUE);
        delay(100);
    }
}