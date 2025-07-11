//
// Created by 徐剑 on 25-4-13.
//

#ifndef LED_H
#define LED_H
#include "stm32f4xx_hal.h"

#define LED_COUNT 64                // 灯数量
#define BIT_COUNT LED_COUNT * 24    // 每个灯24Bit数据

// TIM_HandleTypeDef htim1;


void led_w2812();

#endif //LED_H
