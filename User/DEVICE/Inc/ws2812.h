//
// Created by 徐剑 on 25-4-1.
//

#ifndef WS2812_H
#define WS2812_H
#include "main.h"

#define WS2812_LED_NUM   64
#define WS2812_PWM_BITS  (24 * WS2812_LED_NUM)
#define WS2812_RESET_SLOTS 50  // 最少50us reset -> 800kHz = 40ticks/us -> 50*40=2000
#define WS2812_BUFFER_SIZE (WS2812_PWM_BITS + WS2812_RESET_SLOTS)

uint16_t ws2812_pwm_data[WS2812_BUFFER_SIZE];

void WS2812_Send(void);
void WS2812_SendData(uint8_t red, uint8_t green, uint8_t blue, int led_index);


#endif //WS2812_H
