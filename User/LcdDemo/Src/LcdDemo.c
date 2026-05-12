//
// Created by 徐剑 on 2026/5/11.
//

#include "LcdDemo.h"

#include "main.h"
extern SPI_HandleTypeDef hspi3;

#define  LCD_SPI hspi3           // SPI局部宏，方便修改和移植


/*****************************************************************************************
*	函 数 名: LCD_WriteCMD
*	入口参数: CMD - 需要写入的控制指令
*	返 回 值: 无
*	函数功能: 用于写入控制字
*	说    明: 无
******************************************************************************************/

void LCD_WriteCommand(uint8_t lcd_command)
{
    while ((LCD_SPI.Instance->SR & 0x0080) != RESET); // 先判断SPI是否空闲，等待通信完成

    LCD_DC_Command; //	DC引脚输出低，代表写指令

    (&LCD_SPI)->Instance->DR = lcd_command; // 发送数据
    while ((LCD_SPI.Instance->SR & 0x0002) == 0); // 等待发送缓冲区清空
    while ((LCD_SPI.Instance->SR & 0x0080) != RESET); //	等待通信完成

    LCD_DC_Data; //	DC引脚输出高，代表写数据
}

/****************************************************************************************************************************************
*	函 数 名: LCD_WriteData_8bit
*
*	入口参数: lcd_data - 需要写入的数据，8位
*
*	函数功能: 写入8位数据
*
****************************************************************************************************************************************/

void LCD_WriteData_8bit(uint8_t lcd_data)
{
    LCD_SPI.Instance->DR = lcd_data; // 发送数据
    while ((LCD_SPI.Instance->SR & 0x0002) == 0); // 等待发送缓冲区清空
}

/****************************************************************************************************************************************
*	函 数 名: LCD_WriteData_16bit
*
*	入口参数: lcd_data - 需要写入的数据，16位
*
*	函数功能: 写入16位数据
*
****************************************************************************************************************************************/

void LCD_WriteData_16bit(uint16_t lcd_data)
{
    // 等待上一次彻底发完
    while (SPI3->SR & SPI_SR_BSY);

    SPI3->DR = (uint8_t)(lcd_data >> 8);
    while (!(SPI3->SR & SPI_SR_TXE)); // 等待缓冲区空

    SPI3->DR = (uint8_t)(lcd_data & 0xFF);
    while (!(SPI3->SR & SPI_SR_TXE));

    while (SPI3->SR & SPI_SR_BSY); // 确保这一串 16 位彻底物理发完
}

/****************************************************************************************************************************************
*	函 数 名: SPI_LCD_Init
*
*	函数功能: 初始化SPI以及屏幕控制器的各种参数
*
****************************************************************************************************************************************/

void SPI_LCD_Init(void)
{
    HAL_Delay(10); // 屏幕刚完成复位时（包括上电复位），需要等待5ms才能发送指令

    LCD_CS_L; // 片选拉低，使能IC，开始通信

    LCD_WriteCommand(0x36); // 显存访问控制 指令，用于设置访问显存的方式
    LCD_WriteData_8bit(0x00); // 配置成 从上到下、从左到右，RGB像素格式

    LCD_WriteCommand(0x3A); // 接口像素格式 指令，用于设置使用 12位、16位还是18位色
    LCD_WriteData_8bit(0x05); // 此处配置成 16位 像素格式

    // 接下来很多都是电压设置指令，直接使用厂家给设定值
    LCD_WriteCommand(0xB2);
    LCD_WriteData_8bit(0x0C);
    LCD_WriteData_8bit(0x0C);
    LCD_WriteData_8bit(0x00);
    LCD_WriteData_8bit(0x33);
    LCD_WriteData_8bit(0x33);

    LCD_WriteCommand(0xB7); // 栅极电压设置指令
    LCD_WriteData_8bit(0x35); // VGH = 13.26V，VGL = -10.43V

    LCD_WriteCommand(0xBB); // 公共电压设置指令
    LCD_WriteData_8bit(0x19); // VCOM = 1.35V

    LCD_WriteCommand(0xC0);
    LCD_WriteData_8bit(0x2C);

    LCD_WriteCommand(0xC2); // VDV 和 VRH 来源设置
    LCD_WriteData_8bit(0x01); // VDV 和 VRH 由用户自由配置

    LCD_WriteCommand(0xC3); // VRH电压 设置指令
    LCD_WriteData_8bit(0x12); // VRH电压 = 4.6+( vcom+vcom offset+vdv)

    LCD_WriteCommand(0xC4); // VDV电压 设置指令
    LCD_WriteData_8bit(0x20); // VDV电压 = 0v

    LCD_WriteCommand(0xC6); // 正常模式的帧率控制指令
    LCD_WriteData_8bit(0x0F); // 设置屏幕控制器的刷新帧率为60帧

    LCD_WriteCommand(0xD0); // 电源控制指令
    LCD_WriteData_8bit(0xA4); // 无效数据，固定写入0xA4
    LCD_WriteData_8bit(0xA1); // AVDD = 6.8V ，AVDD = -4.8V ，VDS = 2.3V

    LCD_WriteCommand(0xE0); // 正极电压伽马值设定
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

    LCD_WriteCommand(0xE1); // 负极电压伽马值设定
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

    LCD_WriteCommand(0x21); // 打开反显，因为面板是常黑型，操作需要反过来

    // 退出休眠指令，LCD控制器在刚上电、复位时，会自动进入休眠模式 ，因此操作屏幕之前，需要退出休眠
    LCD_WriteCommand(0x11); // 退出休眠 指令
    HAL_Delay(120); // 需要等待120ms，让电源电压和时钟电路稳定下来

    // 打开显示指令，LCD控制器在刚上电、复位时，会自动关闭显示
    LCD_WriteCommand(0x29); // 打开显示

    while ((LCD_SPI.Instance->SR & 0x0080) != RESET); //	等待通信完成
    LCD_CS_H; // 片选拉高

    // LCD_Clear(); // 清屏

    // 全部设置完毕之后，打开背光
    // LCD_Backlight_ON; // 引脚输出高电平点亮背光
}



/****************************************************************************************************************************************
*	函 数 名:	LCD_Clear
*
*	函数功能:	清屏函数，将LCD清除为 LCD.BackColor 的颜色
*
*	说    明:	先用 LCD_SetBackColor() 设置要清除的背景色，再调用该函数清屏即可
*
*****************************************************************************************************************************************/
// 修改后的地址设置，不再主动拉高 CS

// 修改后的清屏
void LCD_Clear()
{
    uint16_t color = 0xF800; // 标准红色
    uint32_t i;
    uint32_t total_pixels = LCD_Width * LCD_Height;

    LCD_CS_L;

    // 1. 设置地址
    LCD_SetAddress(0, 0, LCD_Width - 1, LCD_Height - 1);

    // 2. 核心：在发像素前，确保之前的 0x2C 指令已经彻底在物理线路上发完了
    while ((LCD_SPI.Instance->SR & 0x0080) != RESET);

    LCD_DC_Data; // 切换到数据模式

    for (i = 0; i < total_pixels; i++)
    {
        // 直接操作寄存器是最快的
        SPI3->DR = (uint8_t)(color >> 8);
        while (!(SPI3->SR & 0x0002));

        SPI3->DR = (uint8_t)color;
        while (!(SPI3->SR & 0x0002));
    }

    // 3. 等待最后一颗像素发完再拉高 CS
    while ((SPI3->SR & 0x0080) != RESET);
    LCD_CS_H;
}

/****************************************************************************************************************************************
*	函 数 名:	 LCD_SetAddress
*
*	入口参数:	 x1 - 起始水平坐标   y1 - 起始垂直坐标
*              x2 - 终点水平坐标   y2 - 终点垂直坐标
*
*	函数功能:   设置需要显示的坐标区域
*****************************************************************************************************************************************/
void LCD_SetAddress(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
    LCD_WriteCommand(0x2a);
    LCD_WriteData_16bit(x1);
    LCD_WriteData_16bit(x2);

    LCD_WriteCommand(0x2b);
    LCD_WriteData_16bit(y1);
    LCD_WriteData_16bit(y2);

    LCD_WriteCommand(0x2c); // 准备写显存
}
