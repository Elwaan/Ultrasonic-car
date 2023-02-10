/*
 * motor.h
 *
 * Created: 9/11/2022 1:17:37 PM
 *  Author: DELL
 */


#ifndef MOTOR_H_
#define MOTOR_H_

#include "DIO.h"

typedef enum d{left,right}m_dir;
typedef enum m{motor1,motor2}motor;

#define H_en_port PD
#define H_port    PC

#define H_EN1      PIN4
#define H_EN2      PIN5

#define H_A1       PIN3
#define H_A2       PIN4
#define H_A3       PIN5
#define H_A4       PIN6


void Motor_Int(void);
void Motor_Direction(motor,m_dir);
void Motor_Stop();
void move_forward();
void move_backward();
void turn_right();
void turn_left();



#endif /* MOTOR_H_ */
