//
// Created by 徐剑 on 25-4-16.
//
#include "EPD.h"

#include <stm32f4xx_hal.h>

// uint8_t Image_BW[15000];
// uint8_t Image_R[15000];

// uint8_t arr[8] = {0x04, 0x05, 0x06, 0x07, 0x08, 0x09,0x10, 0x16};

// float num = 12.05;
// EPD_GPIOInit();
// EPD_Init();
// EPD_Display(gImage_3);
// EPD_Sleep();
// EPD_Init_Fast(Fast_Seconds_1_s);
// EPD_Display_Fast(gImage_1);
// EPD_Sleep();
// HAL_Delay(1000);
// EPD_Clear();
// Paint_NewImage(Image_BW,EPD_W,EPD_H, 0,WHITE);
// EPD_Full(WHITE); //清空画布
// EPD_Display_Part(0, 0,EPD_W,EPD_H, Image_BW);




// EPD_ShowPicture(16, 0, 368, 198, gImage_2,BLACK);
// EPD_ShowString(68, 200, "zhengzhouzhongjingyuan", 24,BLACK);
// EPD_ShowString(84, 230, "4.2inch", 16,BLACK);
// EPD_ShowChinese(140, 230, "电子墨水屏断电可显示", 16,BLACK);
// EPD_DrawRectangle(20, 250, 65, 295,BLACK, 1);
// EPD_DrawRectangle(80, 250, 125, 295,BLACK, 0);
// EPD_DrawCircle(200, 270, 20,BLACK, 1); //Hollow circle.
// EPD_DrawCircle(230, 270, 20,BLACK, 0);
// EPD_ShowWatch(270, 250, num, 4, 2, 48,BLACK);
// num += 0.01;
// EPD_Display_Part(0, 0,EPD_W,EPD_H, Image_BW);
// HAL_Delay(1000);













void EPD_ReadBusy(void) {
    while (1) {
        if (EPD_ReadBUSY() == 0) {
            break;
        }
    }
}

void EPD_RESET(void) {
    EPD_RES_Set();
    HAL_Delay(100);
    EPD_RES_Clr();
    HAL_Delay(10);
    EPD_RES_Set();
    HAL_Delay(100);
}

void EPD_Sleep(void) {
    EPD_WR_REG(0x10);
    EPD_WR_DATA8(0x01);
    HAL_Delay(200);
}


void EPD_Update(void) {
    EPD_WR_REG(0x22);
    EPD_WR_DATA8(0xF7);
    EPD_WR_REG(0x20);
    EPD_ReadBusy();
}

void EPD_Update_Fast(void) {
    EPD_WR_REG(0x22);
    EPD_WR_DATA8(0xC7);
    EPD_WR_REG(0x20);
    EPD_ReadBusy();
}

void EPD_Update_Part(void) {
    EPD_WR_REG(0x22);
    EPD_WR_DATA8(0xFF);
    EPD_WR_REG(0x20);
    EPD_ReadBusy();
}


void EPD_Address_Set(uint16_t xs, uint16_t ys, uint16_t xe, uint16_t ye) {
    EPD_WR_REG(0x44); // SET_RAM_X_ADDRESS_START_END_POSITION
    EPD_WR_DATA8((xs >> 3) & 0xFF);
    EPD_WR_DATA8((xe >> 3) & 0xFF);

    EPD_WR_REG(0x45); // SET_RAM_Y_ADDRESS_START_END_POSITION
    EPD_WR_DATA8(ys & 0xFF);
    EPD_WR_DATA8((ys >> 8) & 0xFF);
    EPD_WR_DATA8(ye & 0xFF);
    EPD_WR_DATA8((ye >> 8) & 0xFF);
}


void EPD_SetCursor(uint16_t xs, uint16_t ys) {
    EPD_WR_REG(0x4E); // SET_RAM_X_ADDRESS_COUNTER
    EPD_WR_DATA8(xs & 0xFF);

    EPD_WR_REG(0x4F); // SET_RAM_Y_ADDRESS_COUNTER
    EPD_WR_DATA8(ys & 0xFF);
    EPD_WR_DATA8((ys >> 8) & 0xFF);
}


void EPD_Init(void) {
    EPD_RESET();
    EPD_ReadBusy();
    EPD_WR_REG(0x12); // soft  reset
    EPD_ReadBusy();
    EPD_WR_REG(0x21); //  Display update control
    EPD_WR_DATA8(0x40);
    EPD_WR_DATA8(0x00);
    EPD_WR_REG(0x3C); //BorderWavefrom
    EPD_WR_DATA8(0x05);
    EPD_WR_REG(0x11); // data  entry  mode
    EPD_WR_DATA8(0x03); // X-mode
    EPD_Address_Set(0, 0,EPD_W - 1,EPD_H - 1);
    EPD_SetCursor(0, 0);
    EPD_ReadBusy();
}

void EPD_Init_Fast(uint8_t mode) {
    EPD_RESET();
    EPD_ReadBusy();
    EPD_WR_REG(0x12); // soft  reset
    EPD_ReadBusy();
    EPD_WR_REG(0x21);
    EPD_WR_DATA8(0x40);
    EPD_WR_DATA8(0x00);
    EPD_WR_REG(0x3C);
    EPD_WR_DATA8(0x05);
    if (mode == Fast_Seconds_1_5s) {
        EPD_WR_REG(0x1A); // Write to temperature register
        EPD_WR_DATA8(0x6E);
    } else if (mode == Fast_Seconds_1_s) {
        EPD_WR_REG(0x1A); // Write to temperature register
        EPD_WR_DATA8(0x5A);
    }
    EPD_WR_REG(0x22); // Load temperature value
    EPD_WR_DATA8(0x91);
    EPD_WR_REG(0x20);
    EPD_ReadBusy();
    EPD_WR_REG(0x11); // data  entry  mode
    EPD_WR_DATA8(0x03); // X-mode
    EPD_Address_Set(0, 0,EPD_W - 1,EPD_H - 1);
    EPD_SetCursor(0, 0);
    EPD_ReadBusy();
}


void EPD_Clear(void) {
    uint16_t i, j, Width, Height;
    Width = (EPD_W % 8 == 0) ? (EPD_W / 8) : (EPD_W / 8 + 1);
    Height = EPD_H;
    EPD_Init();
    EPD_WR_REG(0x26);
    for (j = 0; j < Height; j++) {
        for (i = 0; i < Width; i++) {
            EPD_WR_DATA8(0xFF);
        }
    }
    EPD_Update();
}

void EPD_Display(const uint8_t *Image) {
    uint16_t i, j, Width, Height;
    Width = (EPD_W % 8 == 0) ? (EPD_W / 8) : (EPD_W / 8 + 1);
    Height = EPD_H;
    EPD_WR_REG(0x26);
    for (j = 0; j < Height; j++) {
        for (i = 0; i < Width; i++) {
            EPD_WR_DATA8(Image[i + j * Width]);
        }
    }
    EPD_Update();
}


void EPD_Display_Fast(const uint8_t *Image) {
    uint16_t i, j, Width, Height;
    Width = (EPD_W % 8 == 0) ? (EPD_W / 8) : (EPD_W / 8 + 1);
    Height = EPD_H;
    EPD_WR_REG(0x26);
    for (j = 0; j < Height; j++) {
        for (i = 0; i < Width; i++) {
            EPD_WR_DATA8(Image[i + j * Width]);
        }
    }
    EPD_Update_Fast();
}


void EPD_Display_Part(uint16_t x, uint16_t y, uint16_t sizex, uint16_t sizey, const uint8_t *Image) {
    uint16_t Width, Height, i, j;
    Width = (sizex % 8 == 0) ? (sizex / 8) : (sizex / 8 + 1);
    Height = sizey;
    EPD_WR_REG(0x3C); //BorderWavefrom,
    EPD_WR_DATA8(0x80);
    EPD_WR_REG(0x21);
    EPD_WR_DATA8(0x00);
    EPD_WR_DATA8(0x00);
    EPD_WR_REG(0x3C);
    EPD_WR_DATA8(0x80);
    EPD_Address_Set(x, y, x + sizex - 1, y + sizey - 1);
    EPD_SetCursor(x, y);
    EPD_WR_REG(0x26);
    for (j = 0; j < Height; j++) {
        for (i = 0; i < Width; i++) {
            EPD_WR_DATA8(Image[i + j * Width]);
        }
    }
    EPD_Update_Part();
}
