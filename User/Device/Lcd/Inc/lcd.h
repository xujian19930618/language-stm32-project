//
// Created by 徐剑 on 25-3-23.
//

#ifndef LED_H
#define LED_H

#include "main.h"


#define LCD_Width     240		// LCD的像素长度
#define LCD_Height    240		// LCD的像素宽度

/*------------------------------------------------------  引脚配置 -------------------------------------------------*/

#define     LCD_SCK_PIN      		GPIO_PIN_3                  // SCK引脚, 需要重定义SPI3的IO口复用
#define     LCD_SCK_PORT     		GPIOB                       // SCK引脚用到的端口

#define     LCD_SDA_PIN             GPIO_PIN_5                  // SDA引脚, 需要重定义SPI3的IO口复用
#define 	LCD_SDA_PORT            GPIOB                       // SDA引脚用到的端口


#define 	LCD_CS_PIN       		GPIO_PIN_11                 // CS片选引脚,低电平有效
#define 	LCD_CS_PORT      		GPIOD                       // CS引脚用到的端口

#define     LCD_DC_PIN				GPIO_PIN_12                 // 数据指令选择  引脚
#define	    LCD_DC_PORT				GPIOD                       // 数据指令选择  GPIO端口

#define     LCD_Backlight_PIN		GPIO_PIN_13                 // 背光  引脚
#define	    LCD_Backlight_PORT		GPIOD                       // 背光 GPIO端口


/*---------------------------------------- 常用颜色 ------------------------------------------------------

 1. 这里为了方便用户使用，定义的是24位 RGB888颜色，然后再通过代码自动转换成 16位 RGB565 的颜色
 2. 24位的颜色中，从高位到低位分别对应 R、G、B  3个颜色通道
 3. 用户可以在电脑用调色板获取24位RGB颜色，再将颜色输入LCD_SetColor()或LCD_SetBackColor()就可以显示出相应的颜色
 */
#define 	LCD_WHITE       0xFFFFFF	 // 纯白色
#define 	LCD_BLACK       0x000000    // 纯黑色

#define 	LCD_BLUE        0x0000FF	 //	纯蓝色
#define 	LCD_GREEN       0x00FF00    //	纯绿色
#define 	LCD_RED         0xFF0000    //	纯红色
#define 	LCD_CYAN        0x00FFFF    //	蓝绿色
#define 	LCD_MAGENTA     0xFF00FF    //	紫红色
#define 	LCD_YELLOW      0xFFFF00    //	黄色
#define 	LCD_GREY        0x2C2C2C    //	灰色

#define 	LIGHT_BLUE      0x8080FF    //	亮蓝色
#define 	LIGHT_GREEN     0x80FF80    //	亮绿色
#define 	LIGHT_RED       0xFF8080    //	亮红色
#define 	LIGHT_CYAN      0x80FFFF    //	亮蓝绿色
#define 	LIGHT_MAGENTA   0xFF80FF    //	亮紫红色
#define 	LIGHT_YELLOW    0xFFFF80    //	亮黄色
#define 	LIGHT_GREY      0xA3A3A3    //	亮灰色

#define 	DARK_BLUE       0x000080    //	暗蓝色
#define 	DARK_GREEN      0x008000    //	暗绿色
#define 	DARK_RED        0x800000    //	暗红色
#define 	DARK_CYAN       0x008080    //	暗蓝绿色
#define 	DARK_MAGENTA    0x800080    //	暗紫红色
#define 	DARK_YELLOW     0x808000    //	暗黄色
#define 	DARK_GREY       0x404040    //	暗灰色


/*------------------------------------------------ 函数声明 ----------------------------------------------*/

void SPI_LCD_Init(void); // 液晶屏以及SPI初始化
void LCD_Clear(void); // 清屏函数
void LCD_ClearRect(uint16_t x, uint16_t y, uint16_t width, uint16_t height); // 局部清屏函数

// void LCD_SetAddress(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2); // 设置坐标
// void LCD_SetColor(uint32_t Color); //	设置画笔颜色
// void LCD_SetBackColor(uint32_t Color); //	设置背景颜色
// void LCD_SetDirection(uint8_t direction); //	设置显示方向

// //>>>>>	显示ASCII字符
// void LCD_SetAsciiFont(pFONT *fonts); //	设置ASCII字体
// void LCD_DisplayChar(uint16_t x, uint16_t y, uint8_t c); //	显示单个ASCII字符
// void LCD_DisplayString(uint16_t x, uint16_t y, char *p); //	显示ASCII字符串
//
// //>>>>>	显示中文字符，包括ASCII码
// void LCD_SetTextFont(pFONT *fonts); // 设置文本字体，包括中文和ASCII字体
// void LCD_DisplayChinese(uint16_t x, uint16_t y, char *pText); // 显示单个汉字
// void LCD_DisplayText(uint16_t x, uint16_t y, char *pText); // 显示字符串，包括中文和ASCII字符
//
// //>>>>>	显示整数或小数
// void LCD_ShowNumMode(uint8_t mode); // 设置变量显示模式，多余位填充空格还是填充0
// void LCD_DisplayNumber(uint16_t x, uint16_t y, int32_t number, uint8_t len); // 显示整数
// void LCD_DisplayDecimals(uint16_t x, uint16_t y, double number, uint8_t len, uint8_t decs); // 显示小数
//
// //>>>>>	2D图形函数
// void LCD_DrawPoint(uint16_t x, uint16_t y, uint32_t color); // 画点
//
// void LCD_DrawLine_V(uint16_t x, uint16_t y, uint16_t height); // 画垂直线
// void LCD_DrawLine_H(uint16_t x, uint16_t y, uint16_t width); // 画水平线
// void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2); // 两点之间画线
//
// void LCD_DrawRect(uint16_t x, uint16_t y, uint16_t width, uint16_t height); // 画矩形
// void LCD_DrawCircle(uint16_t x, uint16_t y, uint16_t r); // 画圆
// void LCD_DrawEllipse(int x, int y, int r1, int r2); // 画椭圆
//
// //>>>>>	区域填充函数
// void LCD_FillRect(uint16_t x, uint16_t y, uint16_t width, uint16_t height); // 填充矩形
// void LCD_FillCircle(uint16_t x, uint16_t y, uint16_t r); // 填充圆
//
// //>>>>>	绘制单色图片
// void LCD_DrawImage(uint16_t x, uint16_t y, uint16_t width, uint16_t height, const uint8_t *pImage);
//

/*--------------------------------------------------------- 控制宏 ---------------------------------------------------*/

// 因为片选引脚需要频繁操作，使用寄存器效率会高些
#define 	LCD_CS_H    		 	LCD_CS_PORT->BSRR  = LCD_CS_PIN							// 片选拉高
#define 	LCD_CS_L     			LCD_CS_PORT->BSRR  = (uint32_t)LCD_CS_PIN << 16U	// 片选拉低

#define	    LCD_DC_Command          HAL_GPIO_WritePin(LCD_DC_PORT, LCD_DC_PIN, GPIO_PIN_RESET)	  		// 低电平，指令传输
#define 	LCD_DC_Data             HAL_GPIO_WritePin(LCD_DC_PORT, LCD_DC_PIN, GPIO_PIN_SET)				// 高电平，数据传输

#define 	LCD_Backlight_ON        HAL_GPIO_WritePin(LCD_Backlight_PORT, LCD_Backlight_PIN, GPIO_PIN_SET)		// 高电平，开启背光
#define 	LCD_Backlight_OFF       HAL_GPIO_WritePin(LCD_Backlight_PORT, LCD_Backlight_PIN, GPIO_PIN_RESET)	// 低电平，关闭背光


#endif //LED_H
