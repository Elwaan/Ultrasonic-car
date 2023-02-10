	/*
 * memory_Map.h
 *
 * Created: 6/11/2022 6:15:47 AM
 *  Author: Muhammad Mustafa
 */ 


#ifndef MEMORY_MAP_H_
#define MEMORY_MAP_H_

#include "STD_TYPE.h"

#define ISR(vector)    void vector(void) __attribute__ ((signal)); void vector(void)

/*DIO*/
#define PIND		*((volatile U8_t*)0x30)
#define DDRD		*((volatile U8_t*)0x31)
#define PORTD		*((volatile U8_t*)0x32)

#define PINC		*((volatile U8_t*)0x33)
#define DDRC		*((volatile U8_t*)0x34)
#define PORTC		*((volatile U8_t*)0x35)

#define PINB		*((volatile U8_t*)0x36)
#define DDRB		*((volatile U8_t*)0x37)
#define PORTB		*((volatile U8_t*)0x38)

#define PINA		*((volatile U8_t*)0x39)
#define DDRA		*((volatile U8_t*)0x3A)
#define PORTA		*((volatile U8_t*)0x3B)

#define	ADMUX       *((volatile U8_t*)0x27)

#define ADCSRA      *((volatile U8_t*)0x26)
#define ADCH        *((volatile U8_t*)0x25)
#define ADCL        *((volatile U8_t*)0x24)
#define ADCLH       *((volatile U16_t*)0x24)

#define SREG        *((volatile U8_t*)0x5F)
#define MCUCR       *((volatile U8_t*)0x55)
#define MCUCSR      *((volatile U8_t*)0x54)
#define GICR        *((volatile U8_t*)0x5B)

#define TCCR0       *((volatile U8_t*)0x53)	
#define TIMSK       *((volatile U8_t*)0x59)
#define TCNT0		*((volatile U8_t*)0x52)
#define OCR0		*((volatile U8_t*)0x5C)

#define UDR			*((volatile U8_t*)0x2C)
#define UCSRA		*((volatile U8_t*)0x2B)
#define UCSRB		*((volatile U8_t*)0x2A)
#define UBRRL		*((volatile U8_t*)0x29)
#define UBRRH		*((volatile U8_t*)0x40)
#define UCSRC		*((volatile U8_t*)0x40)

//TWI
#define TWCR		*((volatile U8_t*)0x56)
#define TWDR		*((volatile U8_t*)0x23)
#define TWAR		*((volatile U8_t*)0x22)
#define TWAR_TWGCE	0		//General call recongnition enable
#define TWSR		*((volatile U8_t*)0x21)
#define TWSR_TWPS0	0		//Prescaler bit 0
#define TWSR_TWPS1	1		//Prescaler bit 1
#define TWBR		*((volatile U8_t*)0x20)


#define TCCR1A		*((volatile U8_t*)0x4F)
#define TCCR1B		*((volatile U8_t*)0x4E)
#define TCNT1H		*((volatile U8_t*)0x4D)
#define TCNT1L		*((volatile U8_t*)0x4C)
#define TCNT1		*((volatile U16_t*)0x4C)

#endif /* MEMORY_MAP_H_ */

