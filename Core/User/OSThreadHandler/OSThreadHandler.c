//
// Created by YangHui on 2021/4/24.
//

#include "OSThreadHandler.h"
#include "../Driver/AD8370/AD8370.h"
#include "../Driver/AD9910/AD9910.h"
#include "../../Driver/HAL_Support/LockRelease.h"
#include "../FVControl/FVControl.h"
#include "../UIControl/UIControl.h"
#include "../Driver/SSD1306/SSD1306CN.h"

public Task AD9910ScanTask;
public void AD9910ScanTask_Func(const void *);

void InitializeTask()
{
    uint32_t LOCK;
    LOCK_SWITCH(&LOCK);

    AD9910ScanTask.taskFunc = AD9910ScanTask_Func;
    osThreadDef(_AD9910ScanTask, AD9910ScanTask.taskFunc, osPriorityAboveNormal, 1, 256);
    AD9910ScanTask.taskHandle = osThreadCreate(osThread(_AD9910ScanTask), NULL);
    vTaskSuspend(AD9910ScanTask.taskHandle);

    SSD1306_Init();
//    setStarter();
//    HAL_Delay(2000);
//    SSD1306_Fill(SSD1306_COLOR_BLACK);
    setNumber();
    setPointer();

    AD9910_Init();
    AD9910_SetFrequency(getGenerateVoltage(), getFrequency() * 10000);
    AD9910_SetScale(getGenerateVoltage(), getFrequency() * 10000);

    AD8370_Init();
    AD8370_SetAmplifier(getAmplifier());

    RELEASE_SWITCH(LOCK);

}

/**
 * @addtogroup  RTOS_Task
 * */
void AD9910ScanTask_Func(const void *param)
{
    AD9910_ScanFre(1000000, 50000000, getGenerateVoltage());
}