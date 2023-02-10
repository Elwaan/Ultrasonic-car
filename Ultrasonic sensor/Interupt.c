/*
 * Interupt.c
 *
 * Created: 9/6/2022 9:38:04 AM
 *  Author: hmdok
 */ 

#include "Interupt.h"
#include "DIO.h"



void EXTI_F_Enable(extinterupt ext){
	switch(ext){
		case REQ0:
		SET_BIT(GICR,PIN6);
		break;
		case REQ1:
		SET_BIT(GICR,PIN7);
		break;
		case REQ2:
		SET_BIT(GICR,PIN5);
		break;
		default:
		break;
		}
}
	
void EXTI_F_Disable(extinterupt ext){
	switch(ext){
		case REQ0:
		CLR_BIT(GICR,PIN6);
		break;
		case REQ1:
		CLR_BIT(GICR,PIN7);
		break;
		case REQ2:
		CLR_BIT(GICR,PIN5);
		break;
		default:
		break;
	}
	}
	
void EXTI_F_TriggerSource(extinterupt ext,trig trigger){
	switch(ext){
		case REQ1:
		//MCUCR &= 0xFC
		//MCUCR |= trigger << 2
		switch(trigger){
			case low:
			CLR_BIT(MCUCR,PIN2);
			CLR_BIT(MCUCR,PIN3);
			break;
			case fallorrise:
			SET_BIT(MCUCR,PIN2);
			CLR_BIT(MCUCR,PIN3);
			break;
			case fall:
			SET_BIT(MCUCR,PIN3);
			CLR_BIT(MCUCR,PIN2);
			case rise:
			SET_BIT(MCUCR,PIN2);
			SET_BIT(MCUCR,PIN3);
			break;
			default:
			break;
		}
		break;
		case REQ0:
		//MCUCR &= 0xFC
		//MCUCR |= trigger 
		switch(trigger){
			case low:
			CLR_BIT(MCUCR,PIN0);
			CLR_BIT(MCUCR,PIN1);
			break;
			case fallorrise:
			SET_BIT(MCUCR,PIN0);
			CLR_BIT(MCUCR,PIN1);
			break;
			case fall:
			SET_BIT(MCUCR,PIN1);
			CLR_BIT(MCUCR,PIN0);
			case rise:
			SET_BIT(MCUCR,PIN0);
			SET_BIT(MCUCR,PIN1);
			break;
			default:
			break;
		}
		break;
		}
	}
	static void(*EXT0_PF_GLOBAL)(void);
	static void(*EXT1_PF_GLOBAL)(void);
	static void(*EXT2_PF_GLOBAL)(void);
	void(*pfGlobal)(void);
	void EXIT_F_SET_Callback(extinterupt extlocal,void (*pf_Local)(void)){
		switch(extlocal){
		case REQ0:
		EXT0_PF_GLOBAL=pf_Local;
		break;
		case REQ1:
		EXT1_PF_GLOBAL=pf_Local;
		break;
		case REQ2:
		EXT2_PF_GLOBAL=pf_Local;
		break;
	}
	}
	
	/*ISR(__vector_1){
		EXT0_PF_GLOBAL();
	}
	
	ISR(__vector_2){
		EXT1_PF_GLOBAL();
	}
	
	ISR(__vector_2){
		EXT2_PF_GLOBAL();
	}*/