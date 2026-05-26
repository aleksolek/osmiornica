/**
 ******************************************************************************
 * @file    servo.h
 * @brief   This file provides code for controlling servos
 ******************************************************************************
 */

#include <stdint.h>

#define SERVOS_NUMBER 6
enum position_t { OPEN, CLOSE };

void Servo_SetPosition(uint32_t servoNumber, enum position_t position);
void Servo_TurnOn(void);
void Servo_TurnOff(void);
