//
// Created by YangHui on 2021/3/22.
//

/**
 * @brief   这是AD9910的驱动程序
 * @author  YangHui
 * TODO: 当前已经实现了AD9910的初始化和频率调节，接下来需要做AD9910的幅度调节
 * */

#include "AD9910.h"
#include "main.h"
#include "math.h"
#include "../HAL_Support/LockRelease.h"

private void AD9910Send_8Bit(uint8_t data);
private void Send_Profile(void);

private uint8_t CFR1[] = {0x00, 0x00, 0x00, 0x00}; //cfr1控制字
private uint8_t CFR2[] = {0x01, 0x00, 0x00, 0x00}; //cfr2控制字
private uint8_t CFR3[] = {0x05, 0x0F, 0x41, 0x32}; //cfr3控制字  40M输入  25倍频  VC0=101  ICP=001;
private uint8_t profile[] = {0x3F, 0xFF, 0x00, 0x00, 0x25, 0x09, 0x7b, 0x42}; //profile1控制字 0x25,0x09,0x7b,0x42
private uint8_t stopScan = 0;
//01振幅控制 23相位控制 4567频率调谐字
#ifdef AD9910_USE_DRG
const private uint8_t DRG_LIMIT[] = {0x0C, 0xCC, 0xCC, 0xCC, 0x00, 0x41, 0x89, 0x37}; // 频率调制字
const private uint8_t DRG_STEP[] = {0x00, 0x00, 0x01, 0xad, 0x00, 0x00, 0x01, 0xad}; // 步长控制字，步长为100Hz
const private uint8_t DRG_SPEED[] = {0x09, 0xF7, 0x09, 0xF7}; // 刷新速度控制字
#endif
private uint8_t inDRGMode = 0;

private double Sa(double);

/**
 * @brief   AD9910的初始化方法，该方法必须在GPIO初始化调用完毕以后才能使用
 * @require    PB12->PWR
 * @require    PB13->SDIO
 * @require    PB14->DRHOLD
 * @require    PB15->DROVER
 * @require    PD8->UPDATE
 * @require    PD9~11->PROFILE0~2
 * @require    PD12->MAS_RSET
 * @require    PD13->SCLK
 * @require    PD14->DRCTL
 * @require    PD15->OSK
 * @require    PG2->CS
 * @param   void
 * @return  void
 * */
public void AD9910_Init(void)
{
    HAL_GPIO_WritePin(AD9910_PWR_GPIO_Port, AD9910_PWR_Pin, GPIO_PIN_RESET); // 软件拉低PWR使能，开始进入初始化状态

    HAL_GPIO_WritePin(AD9910_PROFILE0_GPIO_Port, AD9910_PROFILE0_Pin | AD9910_PROFILE1_Pin | AD9910_PROFILE2_Pin,
                      GPIO_PIN_RESET); // 选取000号寄存器进行操作

    /* 抄模板的 */
    HAL_GPIO_WritePin(AD9910_DRCTL_GPIO_Port, AD9910_DRCTL_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(AD9910_DRHOLD_GPIO_Port, AD9910_DRHOLD_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(AD9910_MAS_REST_GPIO_Port, AD9910_MAS_REST_Pin, GPIO_PIN_SET);

    /* 抄模板的 */
    HAL_GPIO_WritePin(AD9910_MAS_REST_GPIO_Port, AD9910_MAS_REST_Pin, GPIO_PIN_RESET);

    /* 初始化CFR1 */
    HAL_GPIO_WritePin(AD9910_CS_GPIO_Port, AD9910_CS_Pin, GPIO_PIN_RESET);
    AD9910Send_8Bit(0x00);
    for (uint8_t i = 0; i < 4; i++)
        AD9910Send_8Bit(CFR1[i]);
    HAL_GPIO_WritePin(AD9910_CS_GPIO_Port, AD9910_CS_Pin, GPIO_PIN_SET);

    /* 初始化CFR2, 这里模板注释掉了 */
    HAL_GPIO_WritePin(AD9910_CS_GPIO_Port, AD9910_CS_Pin, GPIO_PIN_RESET);
    AD9910Send_8Bit(0x01);
    for (uint8_t i = 0; i < 4; i++)
        AD9910Send_8Bit(CFR2[i]);
    HAL_GPIO_WritePin(AD9910_CS_GPIO_Port, AD9910_CS_Pin, GPIO_PIN_SET);

    /* 初始化CFR3 */
    HAL_GPIO_WritePin(AD9910_CS_GPIO_Port, AD9910_CS_Pin, GPIO_PIN_RESET);
    AD9910Send_8Bit(0x02);
    for (uint8_t i = 0; i < 4; i++)
        AD9910Send_8Bit(CFR3[i]);
    HAL_GPIO_WritePin(AD9910_CS_GPIO_Port, AD9910_CS_Pin, GPIO_PIN_SET);

#ifdef AD9910_USE_DRG
    /* 初始化0X0B数字斜坡限制数值 */
    HAL_GPIO_WritePin(AD9910_CS_GPIO_Port, AD9910_CS_Pin, GPIO_PIN_RESET);
    AD9910Send_8Bit(0x0B);
    for (uint8_t i = 0; i < 8; i++)
        AD9910Send_8Bit(DRG_LIMIT[i]);
    HAL_GPIO_WritePin(AD9910_CS_GPIO_Port, AD9910_CS_Pin, GPIO_PIN_SET);

    /* 初始化0X0C数字斜坡步长限制数值 */
    HAL_GPIO_WritePin(AD9910_CS_GPIO_Port, AD9910_CS_Pin, GPIO_PIN_RESET);
    AD9910Send_8Bit(0x0C);
    for (uint8_t i = 0; i < 8; i++)
        AD9910Send_8Bit(DRG_STEP[i]);
    HAL_GPIO_WritePin(AD9910_CS_GPIO_Port, AD9910_CS_Pin, GPIO_PIN_SET);

    /* 初始化0X0D数字斜坡变化速度限制数值 */
    HAL_GPIO_WritePin(AD9910_CS_GPIO_Port, AD9910_CS_Pin, GPIO_PIN_RESET);
    AD9910Send_8Bit(0x0D);
    for (uint8_t i = 0; i < 4; i++)
        AD9910Send_8Bit(DRG_SPEED[i]);
    HAL_GPIO_WritePin(AD9910_CS_GPIO_Port, AD9910_CS_Pin, GPIO_PIN_SET);
#endif

    HAL_GPIO_WritePin(AD9910_UPDATE_GPIO_Port, AD9910_UPDATE_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(AD9910_UPDATE_GPIO_Port, AD9910_UPDATE_Pin, GPIO_PIN_RESET);
}

/**
 * @brief   向AD9910发送8bit数据的方法，遵循SPI协议
 * @param   data: 需要发送的数据
 * @return  void
 * @note    这里使用了宏定义，如果是在OS状态的话就用RTOS的接口函数
 * */
private void AD9910Send_8Bit(uint8_t data)
{
    uint32_t LOCK;
    LOCK_SWITCH(&LOCK);
    uint8_t sbt = 0x80;
    HAL_GPIO_WritePin(AD9910_SCLK_GPIO_Port, AD9910_SCLK_Pin, GPIO_PIN_RESET);
    for (uint8_t i = 0; i < 8; i++)
    {
        if ((data & sbt) == 0)
            HAL_GPIO_WritePin(AD9910_SDIO_GPIO_Port, AD9910_SDIO_Pin, GPIO_PIN_RESET);
        else
            HAL_GPIO_WritePin(AD9910_SDIO_GPIO_Port, AD9910_SDIO_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(AD9910_SCLK_GPIO_Port, AD9910_SCLK_Pin, GPIO_PIN_SET);
        sbt >>= 1;
        HAL_GPIO_WritePin(AD9910_SCLK_GPIO_Port, AD9910_SCLK_Pin, GPIO_PIN_RESET);
    }
    RELEASE_SWITCH(LOCK);
}

/**
 * @brief   设置AD9910的频率，自动更新上传
 * @param   frequency: 需要设置的频率
 * @return  void
 * */
public void AD9910_SetFrequency(uint16_t scale, uint64_t frequency)
{
    frequency = (uint64_t) (frequency * 4.294967296); // 4.294967296 = (2^32) / 1G
    profile[7] = (uint8_t) frequency;
    profile[6] = (uint8_t) (frequency >> 8);
    profile[5] = (uint8_t) (frequency >> 16);
    profile[4] = (uint8_t) (frequency >> 24);
    AD9910_SetScale(scale, frequency);
}
// 028F5C28

/**
 * @brief   设置AD9910的幅度，自动更新上传
 * TODO: 这个函数的思想从一开始就是有问题的，由于Sa采样函数的存在，只能表示一个相对的数值
 * @param   scale   电压范围，5~1000mV
 * @return  void
 * */
public void AD9910_SetScale(uint16_t scale, uint64_t frequency)
{
    // 低通滤波器幅频特性修正，Sa滤波纠正
    // scale最多为14位数，表示14Bit-DAC，向满偏1000和scale做一个等比偏置
    scale = scale / 205.0 * ((1 << 14) - 1);
    profile[0] = (uint8_t) (scale >> 8);
    profile[1] = (uint8_t) scale;
    Send_Profile();
}

#ifdef AD9910_USE_HardScan

/**
 * @brief   AD9910启动扫频
 * @param   start   扫频开始的频率
 * @param   end     扫频结束的频率
 * */
public void AD9910_ScanFre(uint64_t start, uint64_t end, uint16_t scale)
{
#ifndef USE_FREERTOS
    stopScan = 1;
#endif
    uint64_t freq = start;
    int8_t orientation = start < end ? 1 : -1;
    while (1)
    {
        if (stopScan != 1)
        {
            uint32_t LOCK;
            LOCK_SWITCH(&LOCK);
            AD9910_SetFrequency(scale, freq);
            freq += orientation * 1000;
            if (freq < start && orientation == -1)
                freq = end;
            if (freq > end && orientation == 1)
                freq = start;
            RELEASE_SWITCH(LOCK);
        }
        else
        {
            stopScan = 0;
#ifdef USE_FREERTOS
            vTaskSuspend(NULL);
#else
            break;
#endif
        }
    }
}

/**
 * @brief   AD9910停止扫频
 * @param   void
 * @return  void
 * */
public void AD9910_StopScan()
{
    stopScan = 1;
}

#endif

/**
 * @brief   向AD9910发送寄存器内容的方法
 * @param   void
 * @return  void
 * */
private void Send_Profile(void)
{
    uint32_t LOCK;
    LOCK_SWITCH(&LOCK);
    HAL_GPIO_WritePin(AD9910_CS_GPIO_Port, AD9910_CS_Pin, GPIO_PIN_RESET);
    AD9910Send_8Bit(0x0e);
    for (uint8_t i = 0; i < 8; i++)
        AD9910Send_8Bit(profile[i]);
    HAL_GPIO_WritePin(AD9910_CS_GPIO_Port, AD9910_CS_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(AD9910_UPDATE_GPIO_Port, AD9910_UPDATE_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(AD9910_UPDATE_GPIO_Port, AD9910_UPDATE_Pin, GPIO_PIN_RESET);
    RELEASE_SWITCH(LOCK);
}
/**
 * @brief   Sa函数
 * */
private double Sa(double x)
{
    return sin(x) / x;
}