//
// Created by 徐剑 on 25-4-13.
//

#include "usb.h"

void SendKeyReport(uint8_t fn,uint8_t key) {
    uint8_t report[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    report[2] = key;  // 将按键码放入报告缓冲区

    USBD_HID_SendReport(&hUsbDeviceFS, report, sizeof(report));
    HAL_Delay(100);  // 延时以模拟按键按下

    memset(report, 0, sizeof(report));  // 清空报告缓冲区以模拟按键释放
    USBD_HID_SendReport(&hUsbDeviceFS, report, sizeof(report));
    HAL_Delay(100);
}
