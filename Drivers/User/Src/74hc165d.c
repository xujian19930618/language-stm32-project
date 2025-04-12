//
// Created by 徐剑 on 25-4-11.
//
#include "74hc165d.h"


/**
 * 初始化:
 *      (一) 将PL拉高, 停止并行输入
 *      (二) 将CE拉高, 准备输入
 */
void HC165D_Init(void) {
    // 拉高PL
    HAL_GPIO_WritePin(HC165D_PL_PORT, HC165D_PL_PIN, GPIO_PIN_SET);
    // 拉高CE
    HAL_GPIO_WritePin(HC165D_CE_PORT, HC165D_CE_PIN, GPIO_PIN_SET);
}

uint8_t HC165D_Read() {
    uint8_t temp = 0;

    // 步骤一: PL#低电平, 获取并行数据输入
    // 步骤二: PL#高电平, 停止并行数据输入
    HAL_GPIO_WritePin(HC165D_PL_PORT, HC165D_PL_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(HC165D_PL_PORT, HC165D_PL_PIN, GPIO_PIN_SET);

    if (HAL_GPIO_ReadPin(HC165D_Q7_PORT, HC165D_Q7_PIN)) {
        temp |= 0x01;
    }

    // 步骤三: CE#为低电平, 使能时钟输入

    //步骤四: 时钟CP每产生一个上升沿, 移位寄存器中的数据从高位(D7)到低位(Q0)一次移出Q7
    for (int i = 0; i < 7; i++) {
        temp <<= 1;
        HAL_GPIO_WritePin(HC165D_CE_PORT, HC165D_CE_PIN, GPIO_PIN_RESET);
        HAL_Delay(2);

        HAL_GPIO_WritePin(HC165D_CE_PORT, HC165D_CE_PIN, GPIO_PIN_SET);
        GPIO_PinState hal_gpio_read_pin = HAL_GPIO_ReadPin(HC165D_Q7_PORT, HC165D_Q7_PIN);

        if (HAL_GPIO_ReadPin(HC165D_Q7_PORT, HC165D_Q7_PIN)) {
            temp |= 0x01;
        }
    }
    return temp;
}