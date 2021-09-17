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
/* USER CODE BEGIN Private defines */
#define SEG_A_1_PORT		GPIOA
#define SEG_A_1_PIN			GPIO_PIN_1
#define SEG_B_1_PORT		GPIOA
#define SEG_B_1_PIN			GPIO_PIN_2
#define SEG_C_1_PORT		GPIOA
#define SEG_C_1_PIN			GPIO_PIN_3
#define SEG_D_1_PORT		GPIOA
#define SEG_D_1_PIN			GPIO_PIN_4
#define SEG_E_1_PORT		GPIOA
#define SEG_E_1_PIN			GPIO_PIN_5
#define SEG_F_1_PORT		GPIOA
#define SEG_F_1_PIN			GPIO_PIN_6
#define SEG_G_1_PORT		GPIOA
#define SEG_G_1_PIN			GPIO_PIN_7

#define RED1_PORT			GPIOA
#define RED1_PIN			GPIO_PIN_8
#define YELLOW1_PORT		GPIOA
#define YELLOW1_PIN			GPIO_PIN_9
#define GREEN1_PORT			GPIOA
#define GREEN1_PIN			GPIO_PIN_10
#define RED2_PORT			GPIOA
#define RED2_PIN			GPIO_PIN_11
#define YELLOW2_PORT		GPIOA
#define YELLOW2_PIN			GPIO_PIN_12
#define GREEN2_PORT			GPIOA
#define GREEN2_PIN			GPIO_PIN_13
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
