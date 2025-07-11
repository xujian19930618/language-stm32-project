//
// Created by 徐剑 on 25-4-1.
//

#define DELAY_400NS  67
#define DELAY_800NS  134

// SendKeyReport(0x00, 0x05);
// const int temp = HC165D_Read();
// HAL_Delay(10);
// const int temp1 = HC165D_Read();
// if (temp == temp1 && temp > 0 ) {
//   int k = 7;
//   while (k >= 0) {
//     if (!(temp & (0x01 << k)))
//     SendKeyReport(0x00, arr[k]);
//     k--;
//   }
// }
// if (KEY_Scan() && Key == 0) {
//   Key = 1;
//   HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13,GPIO_PIN_SET);
//   SendKeyReport(0x04, 0x06);
// }else if (KEY_Scan() && Key == 1) {
//   Key = 0;
//   HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13,GPIO_PIN_RESET);
//   SendKeyReport(0x04, 0x19);
// }
// if (KEY_Scan() ) {
//
//   uint8_t Key = 0x04 + 'C' - 'C';
//   SendKeyReport(0x00, Key);
// }
// HAL_Delay(1000);
// HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
// HAL_Delay(1000);
//     HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_SET);
// for (volatile int i = 0; i < DELAY_800NS; i++);
// HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_RESET);
// for (volatile int i = 0; i < DELAY_400NS; i++);
// HAL_Delay(500); // 延时500ms
// KEY_Click_Listener();