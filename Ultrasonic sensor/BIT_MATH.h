/*
 * BIT_MATH.h
 *
 * Created: 7/3/2022 12:21:17 PM
 *  Author: Muhammad Mustafa
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG, BIT)		(REG |= (1<<BIT))
#define CLR_BIT(REG, BIT)		(REG &= ~(1<<BIT))
#define TOGGLE_BIT(REG,BIT)     (REG ^= (1<<BIT))

#define GET_BIT(REG, BIT)		((REG & (1<<BIT))>>BIT)	

#endif /* BIT_MATH_H_ */