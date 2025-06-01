//
// Created by 徐剑 on 25-3-23.
//

#ifndef LED_H
#define LED_H

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





#endif //LED_H
