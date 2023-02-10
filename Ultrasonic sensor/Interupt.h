/*
 * Interupt.h
 *
 * Created: 9/6/2022 9:37:39 AM
 *  Author: hmdok
 */ 


#ifndef INTERUPT_H_
#define INTERUPT_H_
#include "MEM_MAP.h"

typedef enum interuptnum {REQ0 = 0 , REQ1 = 1 , REQ2= 2}extinterupt;
	
typedef enum Trigger {low=0 , fallorrise=1 , fall=2 , rise=3}trig;

void EXTI_F_Enable(extinterupt ext);
void EXTI_F_Disable(extinterupt ext);
void EXTI_F_TriggerSource(extinterupt ext,trig trigger);
void EXIT_F_SET_Callback(extinterupt extlocal, void(*pf_Local)(void));
ISR(__vector_1);
//ISR(__vector_2);
//ISR(__vector_3);



#endif /* INTERUPT_H_ */