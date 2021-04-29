/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#define USE_FREERTOS
#include "../Driver/HAL_Support/HAL_Fix.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define NUM_UP_Pin GPIO_PIN_3
#define NUM_UP_GPIO_Port GPIOE
#define NUM_UP_EXTI_IRQn EXTI3_IRQn
#define NUM_DOWN_Pin GPIO_PIN_4
#define NUM_DOWN_GPIO_Port GPIOE
#define NUM_DOWN_EXTI_IRQn EXTI4_IRQn
#define START_SCAN_Pin GPIO_PIN_5
#define START_SCAN_GPIO_Port GPIOE
#define START_SCAN_EXTI_IRQn EXTI9_5_IRQn
#define AD9910_RST_Pin GPIO_PIN_14
#define AD9910_RST_GPIO_Port GPIOC
#define AD8370_LATCH_Pin GPIO_PIN_12
#define AD8370_LATCH_GPIO_Port GPIOE
#define AD8370_DATA_Pin GPIO_PIN_13
#define AD8370_DATA_GPIO_Port GPIOE
#define AD8370_CLOCK_Pin GPIO_PIN_14
#define AD8370_CLOCK_GPIO_Port GPIOE
#define AD9910_CS_Pin GPIO_PIN_11
#define AD9910_CS_GPIO_Port GPIOB
#define AD9910_PWR_Pin GPIO_PIN_12
#define AD9910_PWR_GPIO_Port GPIOB
#define AD9910_SDIO_Pin GPIO_PIN_13
#define AD9910_SDIO_GPIO_Port GPIOB
#define AD9910_DRHOLD_Pin GPIO_PIN_14
#define AD9910_DRHOLD_GPIO_Port GPIOB
#define AD9910_DROVER_Pin GPIO_PIN_15
#define AD9910_DROVER_GPIO_Port GPIOB
#define AD9910_UPDATE_Pin GPIO_PIN_8
#define AD9910_UPDATE_GPIO_Port GPIOD
#define AD9910_PROFILE0_Pin GPIO_PIN_9
#define AD9910_PROFILE0_GPIO_Port GPIOD
#define AD9910_PROFILE1_Pin GPIO_PIN_10
#define AD9910_PROFILE1_GPIO_Port GPIOD
#define AD9910_PROFILE2_Pin GPIO_PIN_11
#define AD9910_PROFILE2_GPIO_Port GPIOD
#define AD9910_MAS_REST_Pin GPIO_PIN_12
#define AD9910_MAS_REST_GPIO_Port GPIOD
#define AD9910_SCLK_Pin GPIO_PIN_13
#define AD9910_SCLK_GPIO_Port GPIOD
#define AD9910_DRCTL_Pin GPIO_PIN_14
#define AD9910_DRCTL_GPIO_Port GPIOD
#define AD9910_OSK_Pin GPIO_PIN_15
#define AD9910_OSK_GPIO_Port GPIOD
#define NUM_CHANGE_Pin GPIO_PIN_0
#define NUM_CHANGE_GPIO_Port GPIOE
#define NUM_CHANGE_EXTI_IRQn EXTI0_IRQn
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
