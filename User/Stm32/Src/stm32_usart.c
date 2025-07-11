//
// Created by 徐剑 on 25-4-13.
//
#include "stm32_usart.h"


#include <stdint.h>
#include "stm32_usart.h"
#include <string.h>

void send_uart_data(uint8_t c) {
    uint8_t byteNumber = 0x5a;
    uint8_t byteArray[] = {1,2,3,4,5};
    char ch = 'a';
    char *str = "Hello world";

    // 发送字节0x5a
    HAL_StatusTypeDef hal_status_type_def = HAL_UART_Transmit(&huart1, &byteNumber, 1, HAL_MAX_DELAY);
    // 发送字节数组{1,2,3,4,5}
    HAL_StatusTypeDef xx = HAL_UART_Transmit(&huart1, byteArray, 5, HAL_MAX_DELAY);
    // 发送字母
    HAL_StatusTypeDef xx1 =  HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
    // 发送字符串
    HAL_StatusTypeDef xx2 =  HAL_UART_Transmit(&huart1, (uint8_t *)str, strlen(str), HAL_MAX_DELAY);
}
