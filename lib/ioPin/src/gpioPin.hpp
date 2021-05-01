#include "stm32f4xx_hal.h"

class IOPin
{
private:
    /* data */
    uint32_t gpioPin;
    GPIO_TypeDef *gpioPort;

public:
    IOPin(GPIO_TypeDef *port, uint32_t pin);
    ~IOPin();

    uint8_t readPin();
    void writePin(uint8_t value);
    void togglePin();
};