//
// Created by 徐剑 on 25-4-13.
//

#ifndef EPD_H
#define EPD_H

#include "main.h"

#define EPD_WIDTH 400
#define EPD_HEIGHT 300

// 四线SPI
/**
 * MOSI: 主机发送从机接收   SDA: 设备接收数据
 * MISO: 主机接收从机发送
 * SCK: 串行时钟线         SCL: 时钟线
 * NSS: 片选, 从机选择     CS#: 从机选择
 *                       D/C#: 命令(0)/数据(1) 控制   (可以不需要)
 *                       RES#: 复位
 *                       BS1:
 */
#define EPD_MOSI_PORT  GPIOC                // SDA
#define EPD_MOSI_PIN   GPIO_PIN_3           // SDA

#define EPD_SCK_PORT  GPIOB                 // SCL
#define EPD_SCK_PIN   GPIO_PIN_10            // SCL

#define EPD_NSS_PORT  GPIOB                 // CS#
#define EPD_NSS_PIN   GPIO_PIN_12            // CS#


#define EPD_DC_PORT  GPIOB                  // DC
#define EPD_DC_PIN   GPIO_PIN_13            // DC

// #define EPD_BS1_PORT  GPIOE                 // BS1
// #define EPD_BS1_PIN   GPIO_PIN_8            // BS1

#define EPD_RES_PORT  GPIOB                 // RES  复位
#define EPD_RES_PIN   GPIO_PIN_14            // RES  复位

#define EPD_BUSY_PORT  GPIOB
#define EPD_BUSY_PIN   GPIO_PIN_11

// void EPD_ReadBusy(void);
// void EPD_RESET(void);
// void EPD_Sleep(void);
//
// void EPD_Update(void);
// void EPD_Update_Fast(void);
// void EPD_Update_Part(void);
// void EPD_Update_4Gray(void);
//
// void EPD_Address_Set(u16 xs,u16 ys,u16 xe,u16 ye);
// void EPD_SetCursor(u16 xs,u16 ys);
//
// void EPD_Display(const u8 *Image);
// void EPD_Display_Fast(const u8 *Image);
// void EPD_Display_Part(u16 x,u16 y,u16 sizex, u16 sizey,const u8 *Image);
//
// void EPD_Init(void);
// void EPD_Init_Fast(u8 mode);
// void EPD_Init_Part(void);


// void EPD_Clear(void);

// 复位
#define _EPD_RST_SET    HAL_GPIO_WritePin(EPD_RES_PORT, EPD_RES_PIN, GPIO_PIN_SET)
#define _EPD_RST_RESET  HAL_GPIO_WritePin(EPD_RES_PORT, EPD_RES_PIN, GPIO_PIN_RESET)
// 读取设备是否忙
// #define _EPD_BUSY_READ  HAL_GPIO_ReadPin(EPD_BUSY_PORT, EPD_BUSY_PIN);

void epd_read_busy(void);
void epd_send_command(uint8_t command) ;
void epd_send_data(uint8_t data) ;
void epd_address_set(uint16_t x, uint16_t y, uint16_t w, uint16_t h) ;
void EPD_SetCursor(uint16_t xs, uint16_t ys);
void EPD_Display();
void epd_reset(void);
void EPD_Update(void);
void epd_init(void);




#endif //EPD_H
