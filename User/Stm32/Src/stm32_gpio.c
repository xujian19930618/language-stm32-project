//
// Created by 徐剑 on 25-4-13.
//

#include "stm32_gpio.h"
void gpio_test()
{
    HAL_GPIO_WritePin(GPIOC,GPIO_PIN_15, GPIO_PIN_RESET);   // 引脚写高低电平
    // HAL_GPIO_ReadPin(GPIOx, GPIO_Pin);                           // 读高低电平
    // HAL_GPIO_TogglePin(GPIOx, GPIO_Pin);                         // 反转高低电平
}