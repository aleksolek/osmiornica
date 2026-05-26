/**
 ******************************************************************************
 * @file    servo.c
 * @brief   This file provides code for controlling servos
 ******************************************************************************
 */

#include "stm32c092xx.h"
#include "stm32_assert.h"
#include "tim.h"
#include "servo.h"
#define CLOSE_ON_TIME_US 1500
#define OPEN_ON_TIME_US 1000
void Servo_SetPosition(uint32_t servoNumber, enum position_t position) {
  assert_param(servoNumber >= 1 && servoNumber <= SERVOS_NUMBER);
  assert_param(position == OPEN || position == CLOSE);

  /* Servo1 - TIM1 CH1
     Servo2 - TIM1 CH2
     Servo3 - TIM1 CH3
     Servo4 - TIM1 CH4
     Servo5 - TIM2 CH1
     Servo6 - TIM2 CH2 */
  uint32_t channel = servoNumber;
  TIM_TypeDef *TIMx = TIM1;

  if (servoNumber > 4) {
    TIMx = TIM2;
    channel = servoNumber % 4;
  }
  const uint32_t onTime = position == OPEN ? OPEN_ON_TIME_US : CLOSE_ON_TIME_US;
  TIM_SetOnTime(TIMx, channel, onTime);
}

void Servo_TurnOn(void){
  TIM_Start(TIM1);
  TIM_Start(TIM2);
}

void Servo_TurnOff(void){
  TIM_Stop(TIM1);
  TIM_Stop(TIM2);
}