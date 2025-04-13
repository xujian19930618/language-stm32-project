//
// Created by 徐剑 on 25-4-13.
//

#include "epd.h"

#include <spi.h>


void epd_reset(void) {
    _EPD_RST_SET;
    HAL_Delay(100);
    _EPD_RST_RESET;
    HAL_Delay(10);
    _EPD_RST_SET;
    HAL_Delay(100);
}

// 设备忙
void epd_read_busy(void) {
    while (1) {
        if (HAL_GPIO_ReadPin(EPD_BUSY_PORT, EPD_BUSY_PIN) == 0) {
            break;
        }
    }
}

void epd_send_command(uint8_t command) {

    HAL_GPIO_WritePin(EPD_DC_PORT, EPD_DC_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(EPD_NSS_PORT, EPD_NSS_PIN, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi2, &command, 1, HAL_MAX_DELAY);
    HAL_GPIO_WritePin(EPD_NSS_PORT, EPD_NSS_PIN, GPIO_PIN_SET);
}

void epd_send_data(uint8_t data) {
    HAL_GPIO_WritePin(EPD_DC_PORT, EPD_DC_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(EPD_NSS_PORT, EPD_NSS_PIN, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi2, &data, 1, HAL_MAX_DELAY);
    HAL_GPIO_WritePin(EPD_NSS_PORT, EPD_NSS_PIN, GPIO_PIN_SET);
}

void epd_address_set(uint16_t x, uint16_t y, uint16_t w, uint16_t h) {
    epd_send_command(0x44);
    epd_send_data((x >> 3) & 0xFF);
    epd_send_data((w >> 3) & 0xFF);
    epd_send_command(0x45);
    epd_send_data(y & 0xFF);
    epd_send_data((y >> 8) & 0xFF);
    epd_send_data(h & 0xFF);
    epd_send_data((h >> 8) & 0xFF);
}

void EPD_SetCursor(uint16_t xs, uint16_t ys) {
    epd_send_command(0x4E); // SET_RAM_X_ADDRESS_COUNTER
    epd_send_data(xs & 0xFF);

    epd_send_command(0x4F); // SET_RAM_Y_ADDRESS_COUNTER
    epd_send_data(ys & 0xFF);
    epd_send_data((ys >> 8) & 0xFF);
}

void EPD_Display() {
    uint16_t i, j, Width, Height;
    Width = (EPD_WIDTH % 8 == 0) ? (EPD_WIDTH / 8) : (EPD_WIDTH / 8 + 1);
    Height = EPD_HEIGHT;
    epd_send_command(0x24);
    for (j = 0; j < Height; j++) {
        for (i = 0; i < Width; i++) {
            epd_send_data(0xFF);
        }
    }
    EPD_Update();
}

void EPD_Update(void) {
    epd_send_command(0x22);
    epd_send_data(0xF7);
    epd_send_command(0x20);
    epd_read_busy();
}

void epd_init(void) {
    // HAL_GPIO_WritePin(EPD_DC_PORT, EPD_DC_PIN, GPIO_PIN_RESET);
    // HAL_GPIO_WritePin(EPD_NSS_PORT, EPD_NSS_PIN, GPIO_PIN_RESET);
    // HAL_GPIO_WritePin(EPD_MOSI_PORT, EPD_MOSI_PIN, GPIO_PIN_SET);
    // HAL_GPIO_WritePin(EPD_RES_PORT, EPD_RES_PIN, GPIO_PIN_SET);
    //
    // epd_reset();
    //
    // epd_send_command(0x06);
    // epd_send_data(0x17);
    // epd_send_data(0x17);
    // epd_send_data(0x17);
    // epd_send_command(0x04);
    //
    // epd_read_busy();
    // epd_send_command(0x00);
    // epd_send_data(0x0F);
    //
    // uint16_t Width, Height;
    // Width = (EPD_WIDTH % 8 == 0)? (EPD_WIDTH / 8 ): (EPD_WIDTH / 8 + 1);
    // Height = EPD_HEIGHT;
    //
    // epd_send_command(0x10);
    // for (uint16_t j = 0; j < Height; j++) {
    //     for (uint16_t i = 0; i < Width; i++) {
    //         epd_send_data(0x00);
    //     }
    // }
    //
    // epd_send_command(0x13);
    // for (uint16_t j = 0; j < Height; j++) {
    //     for (uint16_t i = 0; i < Width; i++) {
    //         epd_send_data(0x00);
    //     }
    // }
    // epd_send_command(0x12); // DISPLAY_REFRESH
    // HAL_Delay(100);
    // epd_read_busy();


    

    epd_read_busy();
    epd_send_command(0x12);
    epd_read_busy();
    epd_send_command(0x21);
    epd_send_data(0x40);
    epd_send_data(0x00);
    epd_send_command(0x3C);
    epd_send_data(0x05);
    epd_send_command(0x11);
    epd_send_data(0x03);
    epd_address_set(0, 0,EPD_WIDTH - 1,EPD_HEIGHT - 1);

    EPD_SetCursor(0, 0);
    epd_read_busy();

}
