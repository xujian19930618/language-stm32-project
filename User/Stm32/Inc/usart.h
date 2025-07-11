//
// Created by 徐剑 on 25-4-13.
//

#ifndef USART_H
#define USART_H

#include "main.h"

extern UART_HandleTypeDef huart1;


// HAL_StatusTypeDef HAL_UART_Transmit(UART_HandleTypeDef *huart,
//                                     const uint8_t *pData,
//                                     uint16_t Size,
//                                     uint32_t Timeout);
// 参数huart  : 填写串口句柄的指针
// 参数pData  : 填写要发送的数据指针
// 参数Size   : 填写要发送数据的数量, 以字节为单位
// 参数Timeout: 超时时间, 单位ms; HAL_MAX_DELAY: 无限期地等待下去, 直到发送完成为止
// HAL_StatusTypeDef: HAL_OK: 成功; HAL_ERROR: 发送出错; HAL_BUSY: 串口忙; HAL_TIMEOUT: 发送超时


void send_uart_data(uint8_t );



#endif //USART_H
