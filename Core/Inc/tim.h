/**
 ******************************************************************************
 * @file    tim.h
 * @brief   This file contains all the function prototypes for
 *          the tim.c file
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2026 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TIM_H__
#define __TIM_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32c092xx.h"

void TIM1_Init(void);
void TIM2_Init(void);
void TIM_SetOnTime(TIM_TypeDef *TIMx, uint32_t channel, uint32_t ton_us);
void TIM_Start(TIM_TypeDef *TIMx);
void TIM_Stop(TIM_TypeDef *TIMx);

#ifdef __cplusplus
}
#endif

#endif /* __TIM_H__ */
