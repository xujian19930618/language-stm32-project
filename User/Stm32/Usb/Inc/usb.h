//
// Created by 徐剑 on 25-4-13.
//

#ifndef USB_H
#define USB_H


#include "usb_device.h"
#include "usbd_hid.h"

void SendKeyReport(uint8_t fn,uint8_t key);

#endif //USB_H
