//
// Created by YangHui on 2021/4/26.
//

#include "LockRelease.h"
#ifdef STM32F407xx
#define portVECTACTIVE_MASK 0xFFUL
#endif
public void LOCK_SWITCH(uint32_t *CRITICAL_ISR)
{
#ifdef USE_FREERTOS
    // 检查是否在中断服务函数
    if ((portNVIC_INT_CTRL_REG & portVECTACTIVE_MASK) == 0)
        taskENTER_CRITICAL();
    else
        *CRITICAL_ISR = taskENTER_CRITICAL_FROM_ISR();
#else
    __disable_irq();
#endif
}

public void RELEASE_SWITCH(uint32_t CRITICAL_ISR)
{
#ifdef USE_FREERTOS
    // 检查是否在中断服务函数
    if ((portNVIC_INT_CTRL_REG & portVECTACTIVE_MASK) == 0)
        taskEXIT_CRITICAL();
    else
        taskEXIT_CRITICAL_FROM_ISR(CRITICAL_ISR);
#else
    __enable_irq();
#endif
}
