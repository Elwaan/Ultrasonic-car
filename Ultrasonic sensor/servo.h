/*
 * servo.h
 *
 * Created: 11/4/2022 7:51:02 PM
 *  Author: DELL
 */ 


#ifndef SERVO_H_
#define SERVO_H_

#include "DIO.h"
#include "Timer.h"
#include "std_type.h"

void Servo_init();
void Set_Servo_Angle(U8_t angle);




#endif /* SERVO_H_ */