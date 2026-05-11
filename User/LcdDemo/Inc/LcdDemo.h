//
// Created by 徐剑 on 2026/5/11.
//

#ifndef LANGUAGE_STM32_PROJECT_LCDDEMO_H
#define LANGUAGE_STM32_PROJECT_LCDDEMO_H

#include <stdint.h>

/*------------------------------------------------------  引脚配置宏 -------------------------------------------------*/

#define LCD_SCK_PIN         GPIO_PIN_3                      // SCK引脚, 需要重定义SPI3的IO口复用
#define LCD_SCK_PORT        GPIOB                           // SCK引脚用到的端口
#define GPIO_LCD_SCK_CLK    __HAL_RCC_GPIOB_CLK_ENABLE()    // SCK引脚IO口时钟

#define LCD_SDA_PIN         GPIO_PIN_5                      // SDA引脚, 需要重定义SPI3的IO口复用
#define LCD_SDA_PORT        GPIOB                           // SDA引脚用到的端口
#define GPIO_LCD_SDA_CLK    __HAL_RCC_GPIOB_CLK_ENABLE()    // SDA引脚IO口时钟


#define LCD_CS_PIN          GPIO_PIN_11                     // CS片选引脚，低电平有效
#define LCD_CS_PORT         GPIOD                 			// CS引脚用到的端口
#define GPIO_LCD_CS_CLK     __HAL_RCC_GPIOD_CLK_ENABLE()	// CS引脚IO口时钟

#define LCD_DC_PIN          GPIO_PIN_12                     // 数据指令选择  引脚
#define	LCD_DC_PORT         GPIOD                           // 数据指令选择  GPIO端口
#define GPIO_LCD_DC_CLK     __HAL_RCC_GPIOD_CLK_ENABLE()    // 数据指令选择  GPIO时钟

#define LCD_Backlight_PIN           GPIO_PIN_13                     // 背光  引脚
#define	LCD_Backlight_PORT          GPIOD                           // 背光 GPIO端口
#define GPIO_LCD_Backlight_CLK      __HAL_RCC_GPIOD_CLK_ENABLE()    // 背光 GPIO时钟


/*--------------------------------------------------------- 控制宏 ---------------------------------------------------*/

// 因为片选引脚需要频繁操作，使用寄存器效率会高些
#define LCD_CS_H            LCD_CS_PORT->BSRR  = LCD_CS_PIN                                     // 片选拉高
#define LCD_CS_L            LCD_CS_PORT->BSRR  = (uint32_t)LCD_CS_PIN << 16U                    // 片选拉低

#define	LCD_DC_Command      HAL_GPIO_WritePin(LCD_DC_PORT, LCD_DC_PIN, GPIO_PIN_RESET)          // 低电平，指令传输
#define LCD_DC_Data         HAL_GPIO_WritePin(LCD_DC_PORT, LCD_DC_PIN, GPIO_PIN_SET)            // 高电平，数据传输

#define LCD_Backlight_ON    HAL_GPIO_WritePin(LCD_Backlight_PORT, LCD_Backlight_PIN, GPIO_PIN_SET)          // 高电平，开启背光
#define LCD_Backlight_OFF   HAL_GPIO_WritePin(LCD_Backlight_PORT, LCD_Backlight_PIN, GPIO_PIN_RESET)        // 低电平，关闭背光



/*----------------------------------------------- 参数宏 -------------------------------------------*/

#define LCD_Width           240               // LCD的像素长度
#define LCD_Height          240               // LCD的像素宽度

// 显示方向参数
// 使用示例：LCD_DisplayDirection(Direction_H) 设置屏幕横屏显示
#define	Direction_H             0					// LCD横屏显示
#define	Direction_H_Flip        1					// LCD横屏显示,上下翻转
#define	Direction_V             2					// LCD竖屏显示
#define	Direction_V_Flip        3					// LCD竖屏显示,上下翻转

// 设置变量显示时多余位补0还是补空格
// 只有 LCD_DisplayNumber() 显示整数 和 LCD_DisplayDecimals()显示小数 这两个函数用到
// 使用示例： LCD_ShowNumMode(Fill_Zero) 设置多余位填充0，例如 123 可以显示为 000123
#define  Fill_Zero          0		// 填充0
#define  Fill_Space         1		// 填充空格


void SPI_LCD_Init(void);
void LCD_Clear(void); // 清屏函数
void LCD_SetAddress(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);


#endif //LANGUAGE_STM32_PROJECT_LCDDEMO_H
