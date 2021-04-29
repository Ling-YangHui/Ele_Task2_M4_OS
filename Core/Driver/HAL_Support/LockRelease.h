//
// Created by YangHui on 2021/4/24.
//

#ifndef ELE_TASK2_M4_OS_LOCKRELEASE_H
#define ELE_TASK2_M4_OS_LOCKRELEASE_H

#include "main.h"
#include "cmsis_gcc.h"
#include "stdint.h"

#ifdef USE_FREERTOS

#include "FreeRTOS.h"
#include "task.h"

#endif

void LOCK_SWITCH(uint32_t *);
void RELEASE_SWITCH(uint32_t);

#ifdef USE_FREERTOS
#define LOCK_NVIC() portDISABLE_INTERRUPTS()
#define RELEASE_NVIC() portENABLE_INTERRUPTS()
#endif

#endif //ELE_TASK2_M4_OS_LOCKRELEASE_H
