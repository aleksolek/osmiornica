/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
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

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"
#include "board_hal.h"
#include "stm32c0xx_ll_exti.h"
#include "stm32c0xx_ll_bus.h"

void GPIO_Init(void)
{

  LL_EXTI_InitTypeDef EXTI_InitStruct = {0};
  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOB);
  LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOC);
  LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOF);
  LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOA);

  /*USELESS BUTTON - PULL UP*/
  GPIO_InitStruct.Pin = USELESS_BUTTON_PIN;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
  LL_GPIO_Init(USELESS_BUTTON_PORT, &GPIO_InitStruct);

  /*NRST*/
  GPIO_InitStruct.Pin = NRST_PIN;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(NRST_PORT, &GPIO_InitStruct);

  /*INTERRUPT PIN*/
  GPIO_InitStruct.Pin = INTERRUPT_PIN;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(INTERRUPT_PORT, &GPIO_InitStruct);

  /*SWITCH1*/
  EXTI_InitStruct.Line_0_31 = LL_EXTI_LINE_3;
  EXTI_InitStruct.LineCommand = ENABLE;
  EXTI_InitStruct.Mode = LL_EXTI_MODE_IT;
  EXTI_InitStruct.Trigger = LL_EXTI_TRIGGER_RISING_FALLING;
  LL_EXTI_Init(&EXTI_InitStruct);

  /*SWITCH2*/
  EXTI_InitStruct.Line_0_31 = LL_EXTI_LINE_4;
  EXTI_InitStruct.LineCommand = ENABLE;
  EXTI_InitStruct.Mode = LL_EXTI_MODE_IT;
  EXTI_InitStruct.Trigger = LL_EXTI_TRIGGER_RISING_FALLING;
  LL_EXTI_Init(&EXTI_InitStruct);

  /*SWITCH3*/
  EXTI_InitStruct.Line_0_31 = LL_EXTI_LINE_6;
  EXTI_InitStruct.LineCommand = ENABLE;
  EXTI_InitStruct.Mode = LL_EXTI_MODE_IT;
  EXTI_InitStruct.Trigger = LL_EXTI_TRIGGER_RISING_FALLING;
  LL_EXTI_Init(&EXTI_InitStruct);

  /*SWITCH4*/
  EXTI_InitStruct.Line_0_31 = LL_EXTI_LINE_7;
  EXTI_InitStruct.LineCommand = ENABLE;
  EXTI_InitStruct.Mode = LL_EXTI_MODE_IT;
  EXTI_InitStruct.Trigger = LL_EXTI_TRIGGER_RISING_FALLING;
  LL_EXTI_Init(&EXTI_InitStruct);

  /*SWITCH5*/
  EXTI_InitStruct.Line_0_31 = LL_EXTI_LINE_7;
  EXTI_InitStruct.Line_0_31 = LL_EXTI_LINE_11;
  EXTI_InitStruct.LineCommand = ENABLE;
  EXTI_InitStruct.Mode = LL_EXTI_MODE_IT;
  EXTI_InitStruct.Trigger = LL_EXTI_TRIGGER_RISING_FALLING;
  LL_EXTI_Init(&EXTI_InitStruct);

  /*Set EXTI Pins*/
  LL_GPIO_SetPinMode(SWITCH1_PORT, SWITCH1_PIN, LL_GPIO_MODE_INPUT);
  LL_GPIO_SetPinPull(SWITCH1_PORT, SWITCH1_PIN, LL_GPIO_PULL_NO);
  LL_GPIO_SetPinMode(SWITCH2_PORT, SWITCH2_PIN, LL_GPIO_MODE_INPUT);
  LL_GPIO_SetPinPull(SWITCH2_PORT, SWITCH2_PIN, LL_GPIO_PULL_NO);
  LL_GPIO_SetPinMode(SWITCH3_PORT, SWITCH3_PIN, LL_GPIO_MODE_INPUT);
  LL_GPIO_SetPinPull(SWITCH3_PORT, SWITCH3_PIN, LL_GPIO_PULL_NO);
  LL_GPIO_SetPinMode(SWITCH4_PORT, SWITCH4_PIN, LL_GPIO_MODE_INPUT);
  LL_GPIO_SetPinPull(SWITCH4_PORT, SWITCH4_PIN, LL_GPIO_PULL_NO);
  LL_GPIO_SetPinMode(SWITCH5_PORT, SWITCH5_PIN, LL_GPIO_MODE_INPUT);
  LL_GPIO_SetPinPull(SWITCH5_PORT, SWITCH5_PIN, LL_GPIO_PULL_NO);
  LL_EXTI_SetEXTISource(LL_EXTI_CONFIG_PORTA, LL_EXTI_CONFIG_LINE3);
  LL_EXTI_SetEXTISource(LL_EXTI_CONFIG_PORTA, LL_EXTI_CONFIG_LINE4);
  LL_EXTI_SetEXTISource(LL_EXTI_CONFIG_PORTA, LL_EXTI_CONFIG_LINE6);
  LL_EXTI_SetEXTISource(LL_EXTI_CONFIG_PORTA, LL_EXTI_CONFIG_LINE7);
  LL_EXTI_SetEXTISource(LL_EXTI_CONFIG_PORTA, LL_EXTI_CONFIG_LINE11);
  /*Clear EXTI Flags*/
  LL_EXTI_ClearFallingFlag_0_31(LL_EXTI_LINE_3);
  LL_EXTI_ClearFallingFlag_0_31(LL_EXTI_LINE_4);
  LL_EXTI_ClearFallingFlag_0_31(LL_EXTI_LINE_6);
  LL_EXTI_ClearFallingFlag_0_31(LL_EXTI_LINE_7);
  LL_EXTI_ClearFallingFlag_0_31(LL_EXTI_LINE_11);
  LL_EXTI_ClearRisingFlag_0_31(LL_EXTI_LINE_3);
  LL_EXTI_ClearRisingFlag_0_31(LL_EXTI_LINE_4);
  LL_EXTI_ClearRisingFlag_0_31(LL_EXTI_LINE_6);
  LL_EXTI_ClearRisingFlag_0_31(LL_EXTI_LINE_7);
  LL_EXTI_ClearRisingFlag_0_31(LL_EXTI_LINE_11);
  /*Clear EXTI IT*/
  LL_EXTI_EnableIT_0_31(LL_EXTI_LINE_3);
  LL_EXTI_EnableIT_0_31(LL_EXTI_LINE_4);
  LL_EXTI_EnableIT_0_31(LL_EXTI_LINE_6);
  LL_EXTI_EnableIT_0_31(LL_EXTI_LINE_7);
  LL_EXTI_EnableIT_0_31(LL_EXTI_LINE_11);
  /* EXTI interrupt init*/
  NVIC_SetPriority(EXTI2_3_IRQn, 0);
  NVIC_EnableIRQ(EXTI2_3_IRQn);
  NVIC_SetPriority(EXTI4_15_IRQn, 0);
  NVIC_EnableIRQ(EXTI4_15_IRQn);

}
