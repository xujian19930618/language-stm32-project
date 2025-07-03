//
// Created by 徐剑 on 25-4-9.
//

#ifndef KEY_H
#define KEY_H
#include "main.h"

uint8_t KEY_Scan(void);

void SendKeyReport(uint8_t fn, uint8_t key);
void KEY_Click_Listener();

#endif //KEY_H
