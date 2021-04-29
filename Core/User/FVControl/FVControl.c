//
// Created by YangHui on 2021/3/25.
//

/* TODO: 这里是整个项目的核心控制部分，集成了接收信号和修改内容，在中断中执行这个任务 */

#include "FVControl.h"
#include "../Driver/AD9910/AD9910.h"
#include "../Driver/AD8370/AD8370.h"
#include "task.h"
#include "../Driver/SSD1306/SSD1306CN.h"
#include "FreeRTOS.h"
#include "../OSThreadHandler/OSThreadHandler.h"

#define NUM_LEN (4 + 4 + 2)
#define AD9910_AREA 7
#define AD8370_AREA 13

// 索引低位为高
private int8_t numSet[NUM_LEN] = {2, 0, 0, 0, 0, 1, 0, 0, 1, 0};
private int8_t *frequencyNum = numSet;
private int8_t *generateVoltageNum = numSet + 4;
private int8_t *amplifyNum = numSet + 8;
private uint8_t nowPosition = 0;
private uint8_t scanMode = 0;

private void setScanMode(uint8_t scanMode);

/**
 * @brief   调整指针位置
 * */
public void positionChange()
{
    if (scanMode == 0)
    {
        nowPosition++;
        if (nowPosition >= NUM_LEN)
            nowPosition -= NUM_LEN;
    }
}

/**
 * @brief   当前指针数字+1，超过9自动归0
 * */
public void positionNumUp()
{
    if (scanMode == 0)
    {
        numSet[nowPosition]++;
        if (numSet[nowPosition] > 9)
        {
            numSet[nowPosition] -= 10;
        }
        /* 数据校验 */
        if (getFrequency() > 5000)
        {
            frequencyNum[0] = 5;
            frequencyNum[1] = frequencyNum[2] = frequencyNum[3] = 0;
        }
        if (getFrequency() < 100)
        {
            frequencyNum[1] = 1;
            frequencyNum[0] = frequencyNum[2] = frequencyNum[3] = 0;
        }
        if (getGenerateVoltage() > 1000)
        {
            generateVoltageNum[0] = 1;
            generateVoltageNum[1] = generateVoltageNum[2] = generateVoltageNum[3] = 0;
        }
        if (getGenerateVoltage() < 5)
        {
            generateVoltageNum[3] = 5;
            generateVoltageNum[0] = generateVoltageNum[1] = generateVoltageNum[2] = 0;
        }
        // 处于扫描模式，不进行数据的上传
        if (nowPosition <= AD9910_AREA)
        {
            AD9910_SetFrequency(getGenerateVoltage(), getFrequency() * 10000);
            AD9910_SetScale(getGenerateVoltage(), getFrequency() * 10000);
        }
        else
        {
            AD8370_SetAmplifier(getAmplifier());
        }
    }
}

/**
 * @brief   当前指针数字-1，超过0自动归9
 * */
public void positionNumDown()
{
    if (scanMode == 0)
    {
        numSet[nowPosition]--;
        if (numSet[nowPosition] < 0)
            numSet[nowPosition] += 10;
        /* 数据校验 */
        if (getFrequency() > 5000)
        {
            frequencyNum[0] = 5;
            frequencyNum[1] = frequencyNum[2] = frequencyNum[3] = 0;
        }
        if (getFrequency() < 100)
        {
            frequencyNum[1] = 1;
            frequencyNum[0] = frequencyNum[2] = frequencyNum[3] = 0;
        }
        if (getGenerateVoltage() > 1000)
        {
            generateVoltageNum[0] = 1;
            generateVoltageNum[1] = generateVoltageNum[2] = generateVoltageNum[3] = 0;
        }
        if (getGenerateVoltage() < 5)
        {
            generateVoltageNum[3] = 5;
            generateVoltageNum[0] = generateVoltageNum[1] = generateVoltageNum[2] = 0;
        }
        // 处于扫描模式，不进行数据的上传
        if (nowPosition <= AD9910_AREA)
        {
            AD9910_SetFrequency(getGenerateVoltage(), getFrequency() * 10000);
            AD9910_SetScale(getGenerateVoltage(), getFrequency() * 10000);
        }
        else
        {
            AD8370_SetAmplifier(getAmplifier());
        }
    }
}

/**
 * @brief   切换扫描模式
 * @details 执行形式为切换运行
 * @note    中断调度，内联操作系统
 * */
public void switchScanMode()
{
    if (scanMode == 0)
    {
        scanMode = 1;
        BaseType_t PRI = xTaskResumeFromISR(AD9910ScanTask.taskHandle);
        setScanMode(scanMode);
        if (PRI != pdFAIL)
            portYIELD_FROM_ISR(PRI);
    }
    else
    {
        scanMode = 0;
        setScanMode(scanMode);
        AD9910_StopScan();
        AD9910_SetFrequency(getGenerateVoltage(), getFrequency() * 10000);
        AD9910_SetScale(getGenerateVoltage(), getFrequency() * 10000);
    }
}

/**
 * @brief  获取电压
 * @ingroup FVControl内部API
 * */
public uint16_t getGenerateVoltage()
{
    uint16_t voltage = 0;
    for (uint8_t i = 0; i < 4; i++)
    {
        voltage *= 10;
        voltage += generateVoltageNum[i];
    }
    return voltage;
}

/**
 * @brief  获取频率
 * @ingroup FVControl内部API
 * */
public uint32_t getFrequency()
{
    uint32_t frequency = 0;
    for (uint8_t i = 0; i < 4; i++)
    {
        frequency *= 10;
        frequency += frequencyNum[i];
    }
    return frequency;
}

/**
 * @brief   获取放大倍数*/
public uint8_t getAmplifier()
{
    uint8_t amplifier = 0;
    for (uint8_t i = 0; i < 2; i++)
    {
        amplifier *= 10;
        amplifier += amplifyNum[i];
    }
    return amplifier;
}

/**
 * @brief  获取指针位置
 * @ingroup FVControl内部API
 * */
public uint8_t getPosition()
{
    return nowPosition;
}

private void setScanMode(uint8_t scanMode)
{
    if (scanMode == 0)
    {
        SSD1306_DrawFilledRectangle(0, 47, 128, 64, SSD1306_COLOR_BLACK);
    }
    else
    {
        SSD1306_GotoXY(8, 47);
        SSD1306_Puts("ScanMode", &Font_8x16, SSD1306_COLOR_WHITE);
    }
    SSD1306_UpdateScreen();
}