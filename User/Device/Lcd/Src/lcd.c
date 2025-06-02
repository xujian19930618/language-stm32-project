//
// Created by 徐剑 on 25-3-23.
//

#include "lcd.h"

extern SPI_HandleTypeDef hspi3;


/*****************************************************************************************
*	函 数 名: LCD_WriteCMD
*	入口参数: CMD - 需要写入的控制指令
*	返 回 值: 无
*	函数功能: 用于写入控制字
*	说    明: 无
******************************************************************************************/

void LCD_WriteCommand(uint8_t lcd_command) {
    while ((hspi3.Instance->SR & 0x0080) != RESET);     // 先判断SPI是否空闲，等待通信完成

    HAL_GPIO_WritePin(LCD_DC_PORT, LCD_DC_PIN, GPIO_PIN_RESET);     //	DC引脚输出低，代表写指令

    (&hspi3)->Instance->DR = lcd_command;               // 发送数据
    while ((hspi3.Instance->SR & 0x0002) == 0);         // 等待发送缓冲区清空
    while ((hspi3.Instance->SR & 0x0080) != RESET);     //	等待通信完成

    HAL_GPIO_WritePin(LCD_DC_PORT, LCD_DC_PIN, GPIO_PIN_SET);       //	DC引脚输出高，代表写数据
}

/****************************************************************************************************************************************
*	函 数 名: LCD_WriteData_8bit
*
*	入口参数: lcd_data - 需要写入的数据，8位
*
*	函数功能: 写入8位数据
*
****************************************************************************************************************************************/

void LCD_WriteData_8bit(uint8_t lcd_data) {
    hspi3.Instance->DR = lcd_data;                  // 发送数据
    while ((hspi3.Instance->SR & 0x0002) == 0);     // 等待发送缓冲区清空
}

/****************************************************************************************************************************************
*	函 数 名: LCD_WriteData_16bit
*
*	入口参数: lcd_data - 需要写入的数据，16位
*
*	函数功能: 写入16位数据
*
****************************************************************************************************************************************/

void LCD_WriteData_16bit(uint16_t lcd_data) {
    hspi3.Instance->DR = lcd_data >> 8;             // 发送数据，高8位
    while ((hspi3.Instance->SR & 0x0002) == 0);     // 等待发送缓冲区清空
    hspi3.Instance->DR = lcd_data;                  // 发送数据，低8位
    while ((hspi3.Instance->SR & 0x0002) == 0);     // 等待发送缓冲区清空
}

void SPI_LCD_Init(void) {
    HAL_GPIO_WritePin(LCD_DC_PORT, LCD_DC_PIN, GPIO_PIN_SET);                // DC引脚拉高，默认处于写数据状态
    HAL_GPIO_WritePin(LCD_CS_PORT, LCD_CS_PIN, GPIO_PIN_SET);;                   // 拉高片选，禁止通信
    HAL_GPIO_WritePin(LCD_Backlight_PORT, LCD_Backlight_PIN, GPIO_PIN_RESET);          // 先关闭背光，初始化完成之后再打开


    HAL_Delay(10);              // 屏幕刚完成复位时（包括上电复位），需要等待5ms才能发送指令

    HAL_GPIO_WritePin(LCD_CS_PORT, LCD_CS_PIN, GPIO_PIN_RESET);;                   // 片选拉低，使能IC，开始通信

    LCD_WriteCommand(0x36);     // 显存访问控制 指令，用于设置访问显存的方式
    LCD_WriteData_8bit(0x00);   // 配置成 从上到下、从左到右，RGB像素格式

    LCD_WriteCommand(0x3A);     // 接口像素格式 指令，用于设置使用 12位、16位还是18位色
    LCD_WriteData_8bit(0x05);   // 此处配置成 16位 像素格式

    // 接下来很多都是电压设置指令，直接使用厂家给设定值
    LCD_WriteCommand(0xB2);
    LCD_WriteData_8bit(0x0C);
    LCD_WriteData_8bit(0x0C);
    LCD_WriteData_8bit(0x00);
    LCD_WriteData_8bit(0x33);
    LCD_WriteData_8bit(0x33);

    LCD_WriteCommand(0xB7);     // 栅极电压设置指令
    LCD_WriteData_8bit(0x35);   // VGH = 13.26V，VGL = -10.43V

    LCD_WriteCommand(0xBB);     // 公共电压设置指令
    LCD_WriteData_8bit(0x19);   // VCOM = 1.35V

    LCD_WriteCommand(0xC0);
    LCD_WriteData_8bit(0x2C);

    LCD_WriteCommand(0xC2);     // VDV 和 VRH 来源设置
    LCD_WriteData_8bit(0x01);   // VDV 和 VRH 由用户自由配置

    LCD_WriteCommand(0xC3);     // VRH电压 设置指令
    LCD_WriteData_8bit(0x12);   // VRH电压 = 4.6+( vcom+vcom offset+vdv)

    LCD_WriteCommand(0xC4);     // VDV电压 设置指令
    LCD_WriteData_8bit(0x20);   // VDV电压 = 0v

    LCD_WriteCommand(0xC6);     // 正常模式的帧率控制指令
    LCD_WriteData_8bit(0x0F);   // 设置屏幕控制器的刷新帧率为60帧

    LCD_WriteCommand(0xD0);     // 电源控制指令
    LCD_WriteData_8bit(0xA4);   // 无效数据，固定写入0xA4
    LCD_WriteData_8bit(0xA1);   // AVDD = 6.8V ，AVDD = -4.8V ，VDS = 2.3V

    LCD_WriteCommand(0xE0);     // 正极电压伽马值设定
    LCD_WriteData_8bit(0xD0);
    LCD_WriteData_8bit(0x04);
    LCD_WriteData_8bit(0x0D);
    LCD_WriteData_8bit(0x11);
    LCD_WriteData_8bit(0x13);
    LCD_WriteData_8bit(0x2B);
    LCD_WriteData_8bit(0x3F);
    LCD_WriteData_8bit(0x54);
    LCD_WriteData_8bit(0x4C);
    LCD_WriteData_8bit(0x18);
    LCD_WriteData_8bit(0x0D);
    LCD_WriteData_8bit(0x0B);
    LCD_WriteData_8bit(0x1F);
    LCD_WriteData_8bit(0x23);

    LCD_WriteCommand(0xE1);     // 负极电压伽马值设定
    LCD_WriteData_8bit(0xD0);
    LCD_WriteData_8bit(0x04);
    LCD_WriteData_8bit(0x0C);
    LCD_WriteData_8bit(0x11);
    LCD_WriteData_8bit(0x13);
    LCD_WriteData_8bit(0x2C);
    LCD_WriteData_8bit(0x3F);
    LCD_WriteData_8bit(0x44);
    LCD_WriteData_8bit(0x51);
    LCD_WriteData_8bit(0x2F);
    LCD_WriteData_8bit(0x1F);
    LCD_WriteData_8bit(0x1F);
    LCD_WriteData_8bit(0x20);
    LCD_WriteData_8bit(0x23);

    LCD_WriteCommand(0x21);     // 打开反显，因为面板是常黑型，操作需要反过来

    // 退出休眠指令，LCD控制器在刚上电、复位时，会自动进入休眠模式 ，因此操作屏幕之前，需要退出休眠
    LCD_WriteCommand(0x11);     // 退出休眠 指令
    HAL_Delay(120); // 需要等待120ms，让电源电压和时钟电路稳定下来

    // 打开显示指令，LCD控制器在刚上电、复位时，会自动关闭显示
    LCD_WriteCommand(0x29);     // 打开显示

    while ((hspi3.Instance->SR & 0x0080) != RESET) {}
    //	等待通信完成
    HAL_GPIO_WritePin(LCD_CS_PORT, LCD_CS_PIN, GPIO_PIN_SET);; // 片选拉高

    // 以下进行一些驱动的默认设置
    // LCD_SetBackColor(LCD_BLACK); // 设置背景色
    // LCD_SetColor(LCD_WHITE); // 设置画笔色
    // LCD_Clear(); // 清屏

    // LCD_SetAsciiFont(&ASCII_Font24); // 设置默认字体
    // LCD_ShowNumMode(Fill_Zero); // 设置变量显示模式，多余位填充空格还是填充0

    // 全部设置完毕之后，打开背光
    HAL_GPIO_WritePin(LCD_Backlight_PORT, LCD_Backlight_PIN, GPIO_PIN_SET); // 引脚输出高电平点亮背光
}