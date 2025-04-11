//
// Created by 徐剑 on 25-4-11.
//

#ifndef INC_74HC165D_H
#define INC_74HC165D_H

#include "main.h"

// PL#:
#define HC165D_PL_PORT  GPIOB
#define HC165D_PL_PIN   GPIO_PIN_5

// CE#: 时钟使能输入(可直接接地)
#define HC165D_CE_PORT  GPIOB
#define HC165D_CE_PIN   GPIO_PIN_6

// CP: CLK
#define HC165D_CP_PORT  GPIOB
#define HC165D_CP_PIN   GPIO_PIN_7

// Q7: 串行输出
#define HC165D_Q7_PORT  GPIOB
#define HC165D_Q7_PIN   GPIO_PIN_8


// Q7#: 上一阶段的互补输出



void HC165D_Init(void);

uint8_t HC165D_Read();



#endif //INC_74HC165D_H
