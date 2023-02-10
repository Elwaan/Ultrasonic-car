/*
 * Ultrasonic.c
 *
 * Created: 11/4/2022 2:37:09 PM
 *  Author: hmdok
 */ 

#include "Ultrasonic.h"

void Ultrasonic_init()
{
	DIO_Fun_Set_Pin_Dir(PD,PIN0,OUTPUT);	 //Trigger pin to trigger and send the wave
	DIO_Fun_Set_Pin_Dir(PD,PIN2,INPUT);		 //Echo pin that goes high and remains until the wave comes back 
	EXTI_F_Enable(0);						 //Enable interrupt request 0
	EXTI_F_TriggerSource(0,fallorrise);		 //Trigger interrupt on rising and falling edge( enable MCUCR bit 0 and clear bit 1)
	SET_BIT(SREG,7);						 //Global Interrupt
}

U16_t Ultrasonic_GetReading()
{
	
		DIO_Fun_Set_Pin_Val(PD,PIN0,HIGH);
		_delay_ms(15);
		DIO_Fun_Set_Pin_Val(PD,PIN0,LOW);		//Trigger to send ultrasonic wave
		count1 = pulse/933;				//Distance calculation with timer calculations 
		
	return count1;
	
}

ISR(__vector_1)
{
	if(i==1)
	{
		Timer1_Stop();	// Stop timer
		pulse= TCNT1;	// Time taken for wave to hit object and come back
		Timer1_ClockReset();	// Make timer start again from 0 next interrupt 
		i=0;
	}
	if(i==0)
	{
		Timer1_Start(clk_1);	 //Start clock with no prescaling
		i=1;
	}
}