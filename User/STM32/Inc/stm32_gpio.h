//
// Created by 徐剑 on 25-4-13.
//

#ifndef STM32_GPIO_H
#define STM32_GPIO_H

#include "main.h"

//  void HAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
//                          参数一: GPIO_TypeDef* GPIOx, 组编号
//                          参数二: uint16_t GPIO_Pin, 引脚编号
//                          参数三: GPIO_PinState PinState, 要写的值 GPIO_PIN_RESET = 0, GPIO_PIN_SET = 1

//  GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
//                          参数一: GPIO_TypeDef* GPIOx, 组编号
//                          参数二: uint16_t GPIO_Pin, 引脚编号
//                          返回值: GPIO_PinState, 值 GPIO_PIN_RESET = 0, GPIO_PIN_SET = 1

//  void HAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin):
//                          参数一: GPIO_TypeDef* GPIOx, 组编号
//                          参数二: uint16_t GPIO_Pin, 引脚编号


void gpio_test(uint8_t);


#endif //STM32_GPIO_H
