//
// Created by YangHui on 2021/4/24.
//

#ifndef ELE_TASK2_M4_OS_OSTHREADHANDLER_H
#define ELE_TASK2_M4_OS_OSTHREADHANDLER_H

#include "FreeRTOS.h"
#include "cmsis_os.h"
#include "task.h"

typedef struct Struct_Task
{
    TaskHandle_t taskHandle;
    void (*taskFunc) (const void *);
}Task;

void InitializeTask();

extern Task AD9910ScanTask;
#endif //ELE_TASK2_M4_OS_OSTHREADHANDLER_H
