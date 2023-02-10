/*
 * Ultrasonic.h
 *
 * Created: 11/4/2022 2:37:35 PM
 *  Author: hmdok
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "BIT_MATH.h"
#include "DIO.h"
#include "STD_TYPE.h"
#include "MEM_MAP.h"
#include "LCD.h"
#include "Interupt.h"
#include "Timer.h"
#define F_CPU 16000000
#include <util/delay.h>
//#include <avr/io.h>
//#include <stdlib.h>
//#include <string.h>

static volatile int pulse=0;
static volatile int i=0;
U16_t count1;  //Time between triggering and interruption of the pulse

void Ultrasonic_init();
U16_t Ultrasonic_GetReading();




#endif /* ULTRASONIC_H_ */