/*
 * DIO.h
 *
 * Created: 7/3/2022 12:22:33 PM
 *  Author: Muhammad Mustafa
 */ 


#ifndef DIO_H_
#define DIO_H_



#include "STD_TYPE.h"
#include "MEM_MAP.h"
#include "BIT_MATH.h"



#define PA 0
#define PB 1
#define PC 2
#define PD 3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define INPUT  0
#define OUTPUT 1

#define LOW 0
#define HIGH 1





void DIO_Fun_Set_Pin_Dir(U8_t port_Name, U8_t pin_Number, U8_t dir);
void DIO_Fun_Set_Pin_Val(U8_t port_Name, U8_t pin_Number, U8_t val);
U8_t DIO_Fun_Get_Pin_Value(U8_t port_Name, U8_t pin_Number);
void DIO_Fun_Set_Port_Dir(U8_t port_Name, U8_t dir);
void DIO_Fun_Set_Port_State_Low_High(U8_t port_Name, U8_t val);
void DIO_Fun_Set_Port_Val(U8_t port_Name, U8_t value);
U8_t DIO_Fun_Get_Port_Val(U8_t port_Name);



#endif /* DIO_H_ */