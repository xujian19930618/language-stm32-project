//
// Created by 徐剑 on 25-4-13.
//

#ifndef STM32_I2C_H
#define STM32_I2C_H

// 向从机写数据
// HAL_StatusTypeDef HAL_I2C_Master_Transmit(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout);
// 参数hi2c: 填写 i2c 的句柄
// 参数DevAddress: 填写额从机地址
// 参数pData: 填写要发送的数据
// 参数Size: 填写要发送数据的数量, 以字节为单位
// 参数Timeout: 超时时间, 单位是ms HAL_MAX_DELAY
// 返回值: HAL_OK,成功; HAL_ERROR,发送出错; HAL_BUSY,I2c接口忙; HAL_TIMEOUT, 发送超时

void send_i2c_data();





// 从从机读数据
// HAL_StatusTypeDef HAL_I2C_Master_Receive(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout);
// 参数hi2c: 填写 i2c 的句柄
// 参数DevAddress: 填写额从机地址
// 参数pData: 填写要发送的数据
// 参数Size: 填写要发送数据的数量, 以字节为单位
// 参数Timeout: 超时时间, 单位是ms HAL_MAX_DELAY
// 返回值: HAL_OK,成功; HAL_ERROR,发送出错; HAL_BUSY,I2c接口忙; HAL_TIMEOUT, 发送超时

void accept_i2c_data();



#endif //STM32_I2C_H
