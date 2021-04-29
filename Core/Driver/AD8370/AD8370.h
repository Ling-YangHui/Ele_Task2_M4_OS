//
// Created by YangHui on 2021/4/5.
//

#ifndef ELEDESIGN_TASK2_AD8370_H
#define ELEDESIGN_TASK2_AD8370_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif
#ifdef USE_FREERTOS
#include "FreeRTOS.h"
#endif
void AD8370_Init();
uint8_t AD8370_SetAmplifier(float dB);
#ifdef __cplusplus
}
#endif
#endif //ELEDESIGN_TASK2_AD8370_H
