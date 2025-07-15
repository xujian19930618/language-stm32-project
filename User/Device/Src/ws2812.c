//
// Created by 徐剑 on 25-4-1.
//

#define DELAY_400NS  67
#define DELAY_800NS  134

// SendKeyReport(0x00, 0x05);
// const int temp = HC165D_Read();
// HAL_Delay(10);
// const int temp1 = HC165D_Read();
// if (temp == temp1 && temp > 0 ) {
//   int k = 7;
//   while (k >= 0) {
//     if (!(temp & (0x01 << k)))
//     SendKeyReport(0x00, arr[k]);
//     k--;
//   }
// }
// if (KEY_Scan() && Key == 0) {
//   Key = 1;
//   HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13,GPIO_PIN_SET);
//   SendKeyReport(0x04, 0x06);
// }else if (KEY_Scan() && Key == 1) {
//   Key = 0;
//   HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13,GPIO_PIN_RESET);
//   SendKeyReport(0x04, 0x19);
// }
// if (KEY_Scan() ) {
//
//   uint8_t Key = 0x04 + 'C' - 'C';
//   SendKeyReport(0x00, Key);
// }
// HAL_Delay(1000);
// HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
// HAL_Delay(1000);
//     HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_SET);
// for (volatile int i = 0; i < DELAY_800NS; i++);
// HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_RESET);
// for (volatile int i = 0; i < DELAY_400NS; i++);
// HAL_Delay(500); // 延时500ms
// KEY_Click_Listener();

#include "ws2812.h"
extern TIM_HandleTypeDef htim1;

void WS2812_Send(void) {
    // Fill reset slots (low signal)
    for (int i = WS2812_PWM_BITS; i < WS2812_BUFFER_SIZE; i++) {
        ws2812_pwm_data[i] = 0;
    }

    HAL_TIM_PWM_Start_DMA(&htim1, TIM_CHANNEL_1, ws2812_pwm_data, WS2812_BUFFER_SIZE);
}

void WS2812_SendData(uint8_t red, uint8_t green, uint8_t blue, int led_index) {
    uint32_t color = ((uint32_t)green << 16) | ((uint32_t)red << 8) | blue;

    for (int i = 0; i < 24; i++) {
        if (color & (1 << (23 - i))) {
            ws2812_pwm_data[led_index * 24 + i] = 19;  // 1 = 2/3 duty
        } else {
            ws2812_pwm_data[led_index * 24 + i] = 9;   // 0 = 1/3 duty
        }
    }
}
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim) {
    HAL_TIM_PWM_Stop_DMA(htim, TIM_CHANNEL_1);
}