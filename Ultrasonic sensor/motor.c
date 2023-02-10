/*
 * motor.c
 *
 * Created: 9/11/2022 1:18:00 PM
 *  Author: DELL
 */
#include "motor.h"

void Motor_Int(void)
{
	DIO_Fun_Set_Pin_Dir(H_en_port,H_EN1,OUTPUT);
	DIO_Fun_Set_Pin_Dir(H_en_port,H_EN2,OUTPUT);//the enable of motors

	DIO_Fun_Set_Pin_Dir(H_port,H_A1,OUTPUT);
	DIO_Fun_Set_Pin_Dir(H_port,H_A2,OUTPUT);//pins for motor 1

	DIO_Fun_Set_Pin_Dir(H_port,H_A3,OUTPUT);
	DIO_Fun_Set_Pin_Dir(H_port,H_A4,OUTPUT);//pins for motor 2
}


void Motor_Direction(motor m,m_dir dir)
{
	switch(m)                                // switch case to choose which motor
	{
		case motor1:
	DIO_Fun_Set_Pin_Val(H_en_port,PIN4,HIGH);           // enable motor 1
	switch(dir){                                        // switch case to chose direction
	case left: 
	DIO_Fun_Set_Pin_Val(H_port,H_A1,HIGH);              
	DIO_Fun_Set_Pin_Val(H_port,H_A2,LOW);               // one pin is high and the other is low
	break;
	case right:
	DIO_Fun_Set_Pin_Val(H_port,H_A1,LOW);
	DIO_Fun_Set_Pin_Val(H_port,H_A2,HIGH);              // inverse of left
	break;}
	break;

	case motor2:
		DIO_Fun_Set_Pin_Val(H_en_port,PIN5,HIGH);      //enable motor 2
		switch(dir){                                    
			case left:                
			DIO_Fun_Set_Pin_Val(H_port,H_A3,HIGH);
			DIO_Fun_Set_Pin_Val(H_port,H_A4,LOW);
			break;
			case right:
			DIO_Fun_Set_Pin_Val(H_port,H_A3,LOW);
			DIO_Fun_Set_Pin_Val(H_port,H_A4,HIGH);
	     	break;}
		break;
	}
}




void Motor_Stop()
{
	DIO_Fun_Set_Pin_Val(H_en_port,PIN4,LOW);
	DIO_Fun_Set_Pin_Val(H_en_port,PIN5,LOW);//both motors are now not enabled
}

void move_forward()
{
	Motor_Direction(motor1,right);      //enable motors both in same direction
    Motor_Direction(motor2,right);

}



void move_backward()
{
	Motor_Direction(motor1,left);      //both motors enabled in direction opposite do forward
	Motor_Direction(motor2,left);
}


void turn_left()
{
	Motor_Direction(motor1,right);        //motors are in opposite direction so they create a torque to the left
	Motor_Direction(motor2,left);

}


void turn_right()
{
    Motor_Direction(motor1,left);
    Motor_Direction(motor2,right);        //motors are in a direction opposite to left so they create torque to the right
}
