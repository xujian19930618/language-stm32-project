//
// Created by 徐剑 on 25-4-16.
//
#include "../Inc/EPD_SPI.h"

void EPD_GPIOInit(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // 使能GPIO时钟
    __HAL_RCC_GPIOG_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_GPIOE_CLK_ENABLE();

    // SCK引脚配置
    GPIO_InitStruct.Pin = EPD_SCK_GPIO_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(EPD_SCK_GPIO_PORT, &GPIO_InitStruct);

    // MOSI引脚配置
    GPIO_InitStruct.Pin = EPD_MOSI_GPIO_PIN;
    HAL_GPIO_Init(EPD_MOSI_GPIO_PORT, &GPIO_InitStruct);

    // RES引脚配置
    GPIO_InitStruct.Pin = EPD_RES_GPIO_PIN;
    HAL_GPIO_Init(EPD_RES_GPIO_PORT, &GPIO_InitStruct);

    // DC引脚配置
    GPIO_InitStruct.Pin = EPD_DC_GPIO_PIN;
    HAL_GPIO_Init(EPD_DC_GPIO_PORT, &GPIO_InitStruct);

    // CS引脚配置
    GPIO_InitStruct.Pin = EPD_CS_GPIO_PIN;
    HAL_GPIO_Init(EPD_CS_GPIO_PORT, &GPIO_InitStruct);

    // BUSY引脚配置
    GPIO_InitStruct.Pin = EPD_BUSY_GPIO_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(EPD_BUSY_GPIO_PORT, &GPIO_InitStruct);
}

// 定义GPIO初始化函数
void EPD_GPIO_Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // 初始化SCK引脚
    EPD_SCK_GPIO_CLK_ENABLE();
    GPIO_InitStruct.Pin = EPD_SCK_GPIO_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(EPD_SCK_GPIO_PORT, &GPIO_InitStruct);

    // 初始化MOSI引脚
    EPD_MOSI_GPIO_CLK_ENABLE();
    GPIO_InitStruct.Pin = EPD_MOSI_GPIO_PIN;
    HAL_GPIO_Init(EPD_MOSI_GPIO_PORT, &GPIO_InitStruct);

    // 初始化RES引脚
    EPD_RES_GPIO_CLK_ENABLE();
    GPIO_InitStruct.Pin = EPD_RES_GPIO_PIN;
    HAL_GPIO_Init(EPD_RES_GPIO_PORT, &GPIO_InitStruct);

    // 初始化DC引脚
    EPD_DC_GPIO_CLK_ENABLE();
    GPIO_InitStruct.Pin = EPD_DC_GPIO_PIN;
    HAL_GPIO_Init(EPD_DC_GPIO_PORT, &GPIO_InitStruct);

    // 初始化CS引脚
    EPD_CS_GPIO_CLK_ENABLE();
    GPIO_InitStruct.Pin = EPD_CS_GPIO_PIN;
    HAL_GPIO_Init(EPD_CS_GPIO_PORT, &GPIO_InitStruct);

    // 初始化BUSY引脚
    EPD_BUSY_GPIO_CLK_ENABLE();
    GPIO_InitStruct.Pin = EPD_BUSY_GPIO_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(EPD_BUSY_GPIO_PORT, &GPIO_InitStruct);
}


//SPI 写入一个字节
void EPD_WR_Bus(uint8_t dat) {
    uint8_t i;
    EPD_CS_Clr();
    for (i = 0; i < 8; i++) {
        EPD_SCK_Clr();
        if (dat & 0x80) {
            EPD_MOSI_Set();
        } else {
            EPD_MOSI_Clr();
        }
        EPD_SCK_Set();
        dat <<= 1;
    }
    EPD_CS_Set();
}

//SPI发送指令
void EPD_WR_REG(uint8_t reg) {
    EPD_DC_Clr();
    EPD_WR_Bus(reg);
    EPD_DC_Set();
}

//SPI发送数据
void EPD_WR_DATA8(uint8_t dat) {
    EPD_WR_Bus(dat);
}
