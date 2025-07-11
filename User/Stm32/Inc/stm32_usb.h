//
// Created by 徐剑 on 25-4-13.
//

#ifndef STM32_USB_H
#define STM32_USB_H


#include "usb_device.h"
#include "usbd_hid.h"

void SendKeyReport(uint8_t fn,uint8_t key);

#endif //STM32_USB_H
