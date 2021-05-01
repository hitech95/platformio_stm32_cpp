#include "gpioPin.hpp"


// TODO - Add cofiguration mode and a way to alterate its configuration
// Add support for IRQs, PullUps, etc
// WARNNG: Clocks (RCU) is not set you have to call something like
// __HAL_RCC_GPIOA_CLK_ENABLE()
IOPin::IOPin(GPIO_TypeDef *port, uint32_t pin)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    gpioPin = pin;
    gpioPort = port;

    GPIO_InitStruct.Pin = pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;

    HAL_GPIO_Init(port, &GPIO_InitStruct);
}

IOPin::~IOPin()
{
    HAL_GPIO_DeInit(gpioPort, gpioPin);
}

uint8_t IOPin::readPin()
{
    return HAL_GPIO_ReadPin(gpioPort, gpioPin) == GPIO_PIN_SET;
}

void IOPin::writePin(uint8_t value)
{
    HAL_GPIO_WritePin(gpioPort, gpioPin, (value) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

void IOPin::togglePin()
{
    HAL_GPIO_TogglePin(gpioPort, gpioPin);
}
