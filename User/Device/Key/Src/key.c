//
// Created by 徐剑 on 25-4-10.
//
#include "key.h"

uint8_t KEY_Scan(void)
{
    // 检测GPIOA的第15号引脚是否为低电平
    if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15) == GPIO_PIN_RESET)
    {
        // 等待一段时间以消除抖动
        HAL_Delay(20);

        // 再次检测引脚状态，确认是否仍然为低电平
        if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15) == GPIO_PIN_RESET)
        {
            // 确认按键按下，等待按键释放
            while (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15) == GPIO_PIN_RESET)
            {
                // 可以在这里添加一个最大等待时间，避免死循环
            }

            // 按键释放后，切换GPIOC的第13号引脚状态
            HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
        }
    }
    return 1;
}


void KEY_Click_Listener()
{

}
