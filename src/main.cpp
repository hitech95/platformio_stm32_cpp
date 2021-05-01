#include "stm32f4xx_hal.h"
#include "blinky.h"
#include "../lib/ioPin/src/gpioPin.hpp"


int main(void)
{
  HAL_Init();

  LED_GPIO_CLK_ENABLE();
  IOPin ledPin(LED_GPIO_PORT, LED_PIN);

  while (1)
  {
    ledPin.togglePin();

    HAL_Delay(600);
  }
}

extern "C" void SysTick_Handler(void)
{
  HAL_IncTick();
}