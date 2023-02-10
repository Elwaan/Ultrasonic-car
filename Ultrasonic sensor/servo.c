/*
 * servo.c
 *
 * Created: 11/4/2022 7:50:44 PM
 *  Author: DELL
 */ 
 #include "servo.h"
 
 void Servo_init()
 {
	 Timer_init(Normal,clk_1024);                       //initialize timer and choose prescaler
	DIO_Fun_Set_Pin_Dir(PD,PIN7,OUTPUT);                // signal pin for servo is output
 }
 
 void Set_Servo_Angle(U8_t angle)
 {
	 Adjust_angle(angle);                               // send the servo angle to timer
	 Timer_Start(248);                                  //start the timer to start the signal
 }