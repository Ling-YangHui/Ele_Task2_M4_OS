//
// Created by YangHui on 2021/4/5.
//

#include "AD8370.h"
#include "main.h"
#include "math.h"
#include "cmsis_gcc.h"
#include "../HAL_Support/LockRelease.h"

private void AD8370Send_8bit(uint8_t data);

/**
 * @brief   AD8370的初始化方法
 * @require     PE12->LATCH
 * @require     PE13->DATA
 * @require     PE14->CLOCK
 * @param   void
 * @return  void
 * */
public void AD8370_Init()
{
    AD8370_SetAmplifier(0);
}

/**
 * @brief   AD8370设置放大倍数
 * @param   dB: 放大的分贝数
 * @return  uint8_t
 * */
public uint8_t AD8370_SetAmplifier(float dB)
{
    uint8_t writeBytes;
    if (dB > 34 || dB < -50) // 34 = 20log(50.118937957504)
        return 0;
    // 求解放大倍数
    double A_v = pow(10, dB / 20);
    // 使用低放大模式
    if (A_v < 7.079488)
        writeBytes = round(A_v / 0.055744);
        // 使用高放大模式
    else
    {
        writeBytes = round(A_v / 0.055744 / 7.079458);
        writeBytes |= 0x80;
    }
    AD8370Send_8bit(writeBytes);
    return 1;
}

/**
 * @brief   向AD8370发送8bit数据的方法，遵循SPI协议
 * @param   data: 需要发送的数据
 * @return  void
 * */
private void AD8370Send_8bit(uint8_t data)
{
    uint32_t LOCK;
    LOCK_SWITCH(&LOCK);
    uint8_t sbt = 0x80;
    HAL_GPIO_WritePin(AD8370_LATCH_GPIO_Port, AD8370_LATCH_Pin, GPIO_PIN_RESET);
    for (uint8_t i = 0; i < 8; i++)
    {
        if ((data & sbt) == 0)
            HAL_GPIO_WritePin(AD8370_DATA_GPIO_Port, AD8370_DATA_Pin, GPIO_PIN_RESET);
        else
            HAL_GPIO_WritePin(AD8370_DATA_GPIO_Port, AD8370_DATA_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(AD8370_CLOCK_GPIO_Port, AD8370_CLOCK_Pin, GPIO_PIN_SET);
        sbt >>= 1;
        HAL_GPIO_WritePin(AD8370_CLOCK_GPIO_Port, AD8370_CLOCK_Pin, GPIO_PIN_RESET);
    }
    HAL_GPIO_WritePin(AD8370_LATCH_GPIO_Port, AD8370_LATCH_Pin, GPIO_PIN_SET);
    RELEASE_SWITCH(LOCK);
}
