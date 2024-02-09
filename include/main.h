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
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
#define ADC_X_Pin GPIO_PIN_0
#define ADC_X_GPIO_Port GPIOA
#define ADC_Y_Pin GPIO_PIN_1
#define ADC_Y_GPIO_Port GPIOA
#define V_BAT_Pin GPIO_PIN_6
#define V_BAT_GPIO_Port GPIOA
#define LED1_Pin GPIO_PIN_0
#define LED1_GPIO_Port GPIOB
#define LED2_Pin GPIO_PIN_1
#define LED2_GPIO_Port GPIOB
#define CSN_NRF_Pin GPIO_PIN_12
#define CSN_NRF_GPIO_Port GPIOB
#define SCK_NRF_Pin GPIO_PIN_13
#define SCK_NRF_GPIO_Port GPIOB
#define MISO_NRF_Pin GPIO_PIN_14
#define MISO_NRF_GPIO_Port GPIOB
#define MOSI_NRF_Pin GPIO_PIN_15
#define MOSI_NRF_GPIO_Port GPIOB
#define CE_NRF_Pin GPIO_PIN_8
#define CE_NRF_GPIO_Port GPIOA
#define BUZZ_Pin GPIO_PIN_15
#define BUZZ_GPIO_Port GPIOA
#define BTT_1_Pin GPIO_PIN_3
#define BTT_1_GPIO_Port GPIOB
#define BTT_2_Pin GPIO_PIN_4
#define BTT_2_GPIO_Port GPIOB
#define BTT_3_Pin GPIO_PIN_5
#define BTT_3_GPIO_Port GPIOB
#define BTT_4_Pin GPIO_PIN_6
#define BTT_4_GPIO_Port GPIOB
#define BTT_5_Pin GPIO_PIN_7
#define BTT_5_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
