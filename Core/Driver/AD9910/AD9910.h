//
// Created by YangHui on 2021/3/22.
//

#ifndef ELEDESIGN_TASK2_AD9910_H
#define ELEDESIGN_TASK2_AD9910_H

#include "main.h"
//#define AD9910_USE_DRG
#define AD9910_USE_HardScan
#ifdef USE_FREERTOS
#include "FreeRTOS.h"
#endif

// 本项目自行定义区域
#define AD9910_Freq_SysClk 1000000000
#define AD9910_Freq_Max 50000000
#define AD9910_Time_SysClk 1 / AD9910_Freq_SysClk

#ifdef __cplusplus
extern "C" {
#endif
void AD9910_Init(void);
void AD9910_SetFrequency(uint16_t scale, uint64_t frequency);
void AD9910_SetScale(uint16_t scale, uint64_t frequency);
#ifdef AD9910_USE_HardScan
_Noreturn void AD9910_ScanFre(uint64_t, uint64_t, uint16_t);
void AD9910_StopScan();
#endif
#ifdef __cplusplus
}
#endif
#endif //ELEDESIGN_TASK2_AD9910_H
