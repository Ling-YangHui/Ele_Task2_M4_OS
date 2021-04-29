//
// Created by YangHui on 2021/3/25.
//

#ifndef ELEDESIGN_TASK2_FVCONTROL_H
#define ELEDESIGN_TASK2_FVCONTROL_H

#include "stdint.h"
#ifdef __cplusplus
extern C {
#endif
void positionChange();
uint16_t getGenerateVoltage();
uint32_t getFrequency();
void positionNumDown();
void positionNumUp();
void switchScanMode();
uint8_t getPosition();
uint8_t getAmplifier();
#ifdef __cplusplus
}
#endif
#endif //ELEDESIGN_TASK2_FVCONTROL_H
