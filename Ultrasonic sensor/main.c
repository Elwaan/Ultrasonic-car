	/*
 * main.c
 *
 * Created: 11/3/2022 11:11:56 PM
 *  Author: hmdok
 */ 

//#include <xc.h>
#include "BIT_MATH.h"
#include "DIO.h"
#include "STD_TYPE.h"
#include "MEM_MAP.h"
#include "LCD.h"
#include "Interupt.h"
#include "servo.h"
#include "motor.h"
#include "Ultrasonic.h"
#include "Timer.h"
#define F_CPU 16000000
#include <util/delay.h>
#include <avr/io.h>
#include <stdlib.h>



int main(void)
{ 
	Motor_Int();
	Ultrasonic_init();
	LCD_F_Init();
 	Servo_init();                     
	 
	LCD_F_Go_To(0,0);
    LCD_F_Write_String("Forward");
	move_forward();                        //start moving forward
	U16_t reading=100;                      // initialize the reading with any high number
   Set_Servo_Angle(90);                    //the servo moves to the middle position (90 degree)
   _delay_ms(200);                         //delay is needed for the servo signal to move(ginal period=20ms)   (timer delay function is not used because it causes problems with the servo signal)

    while(1)
    { 
		
 		reading=Ultrasonic_GetReading();           //get reading from sensor to see the distance in cm
 
  while (reading<=7)
      {
      Motor_Stop();                                // at distance<7cm stop
      Set_Servo_Angle(0);                          //look to the right
      _delay_ms(200);
      
      reading=Ultrasonic_GetReading();            // get a reading
      
      if(reading>7)
      {                                            // if distance is larger than 7 cm
		  LCD_F_Go_To(0,0);
		  LCD_F_Write_String("Right  ");
    	  turn_right();                            //move to the right then break to move forward
    	  _delay_ms(1000);
    	  break;
      }
      
      Set_Servo_Angle(180);                    // if the distance to the right is smaller than 7cm look to the left
      _delay_ms(200);
      reading=Ultrasonic_GetReading();         //get a reading from the left
      if (reading>7)
      {
		   LCD_F_Go_To(0,0);
		   LCD_F_Write_String("Left   ");
    	  turn_left();                          // if the distance from the left is larger than 7cm turn left
    	  _delay_ms(1000);
    	  break;
      }
      
      Set_Servo_Angle(90);                      //if the right and left have both distance smaller than 7cm scan the front again
      _delay_ms(200);
      reading=Ultrasonic_GetReading(); 
      }
      Set_Servo_Angle(90);                     //once you break and the distance is larger than 7cm look forward (90)
      _delay_ms(200);
	  LCD_F_Go_To(0,0);
	  LCD_F_Write_String("Forward");
      move_forward();                          // move forward again
    
        }
}