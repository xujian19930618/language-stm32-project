//
// Created by 徐剑 on 25-4-16.
//


#ifndef EPD_SPI_H
#define EPD_SPI_H

#include "main.h"

// 定义GPIO端口和引脚
#define EPD_SCK_GPIO_PORT            GPIOG
#define EPD_SCK_GPIO_PIN             GPIO_PIN_12

#define EPD_MOSI_GPIO_PORT           GPIOD
#define EPD_MOSI_GPIO_PIN            GPIO_PIN_5

#define EPD_RES_GPIO_PORT            GPIOD
#define EPD_RES_GPIO_PIN             GPIO_PIN_4

#define EPD_DC_GPIO_PORT             GPIOD
#define EPD_DC_GPIO_PIN              GPIO_PIN_15

#define EPD_CS_GPIO_PORT             GPIOD
#define EPD_CS_GPIO_PIN              GPIO_PIN_1

#define EPD_BUSY_GPIO_PORT           GPIOE
#define EPD_BUSY_GPIO_PIN            GPIO_PIN_8

// 定义GPIO时钟
#define EPD_SCK_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOG_CLK_ENABLE()
#define EPD_MOSI_GPIO_CLK_ENABLE()    __HAL_RCC_GPIOD_CLK_ENABLE()
#define EPD_RES_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOD_CLK_ENABLE()
#define EPD_DC_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOD_CLK_ENABLE()
#define EPD_CS_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOD_CLK_ENABLE()
#define EPD_BUSY_GPIO_CLK_ENABLE()    __HAL_RCC_GPIOE_CLK_ENABLE()

// 定义GPIO操作宏
#define EPD_SCK_Set()               HAL_GPIO_WritePin(EPD_SCK_GPIO_PORT, EPD_SCK_GPIO_PIN, GPIO_PIN_SET)
#define EPD_SCK_Clr()               HAL_GPIO_WritePin(EPD_SCK_GPIO_PORT, EPD_SCK_GPIO_PIN, GPIO_PIN_RESET)

#define EPD_MOSI_Set()              HAL_GPIO_WritePin(EPD_MOSI_GPIO_PORT, EPD_MOSI_GPIO_PIN, GPIO_PIN_SET)
#define EPD_MOSI_Clr()              HAL_GPIO_WritePin(EPD_MOSI_GPIO_PORT, EPD_MOSI_GPIO_PIN, GPIO_PIN_RESET)

#define EPD_RES_Set()               HAL_GPIO_WritePin(EPD_RES_GPIO_PORT, EPD_RES_GPIO_PIN, GPIO_PIN_SET)
#define EPD_RES_Clr()               HAL_GPIO_WritePin(EPD_RES_GPIO_PORT, EPD_RES_GPIO_PIN, GPIO_PIN_RESET)

#define EPD_DC_Set()                HAL_GPIO_WritePin(EPD_DC_GPIO_PORT, EPD_DC_GPIO_PIN, GPIO_PIN_SET)
#define EPD_DC_Clr()                HAL_GPIO_WritePin(EPD_DC_GPIO_PORT, EPD_DC_GPIO_PIN, GPIO_PIN_RESET)

#define EPD_CS_Set()                HAL_GPIO_WritePin(EPD_CS_GPIO_PORT, EPD_CS_GPIO_PIN, GPIO_PIN_SET)
#define EPD_CS_Clr()                HAL_GPIO_WritePin(EPD_CS_GPIO_PORT, EPD_CS_GPIO_PIN, GPIO_PIN_RESET)

#define EPD_ReadBUSY()              HAL_GPIO_ReadPin(EPD_BUSY_GPIO_PORT, EPD_BUSY_GPIO_PIN)

void EPD_GPIOInit(void);   //初始化GPIO
void EPD_WR_Bus(uint8_t dat);   //模拟SPI时序
void EPD_WR_REG(uint8_t reg);   //写入一个命令
void EPD_WR_DATA8(uint8_t dat); //写入一个字节
#endif //EPD_SPI_H
