//
// Created by YangHui on 2021/4/15.
//

#include "main.h"
#include "../FVControl/FVControl.h"
#include "../UIControl/UIControl.h"
#include "../Driver/AD9910/AD9910.h"

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (GPIO_Pin == GPIO_PIN_0)
    {
        HAL_Delay(100);
        if (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_0) == 0)
        {
            positionChange();
            setNumber();
            setPointer();
        }
    }
    else if (GPIO_Pin == GPIO_PIN_3)
    {
        HAL_Delay(100);
        if (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_3) == 0)
        {
            positionNumUp();
            setNumber();
            setPointer();
        }
    }
    else if (GPIO_Pin == GPIO_PIN_4)
    {
        HAL_Delay(100);
        if (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_4) == 0)
        {
            positionNumDown();
            setNumber();
            setPointer();
        }
    }
    else if (GPIO_Pin == GPIO_PIN_5)
    {
        HAL_Delay(100);
        if (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_5) == 0)
        {
            switchScanMode();
        }
    }
    else if (GPIO_Pin == GPIO_PIN_14)
    {
        HAL_Delay(100);
        if (HAL_GPIO_ReadPin(AD9910_MAS_REST_GPIO_Port, AD9910_MAS_REST_Pin))
        {
            AD9910_Init();
            AD9910_SetFrequency(getGenerateVoltage(), getFrequency() * 10000);
            AD9910_SetScale(getGenerateVoltage(), getFrequency() * 10000);
        }
    }
}