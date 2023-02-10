/*
 * Timer.h
 *
 * Created: 9/7/2022 3:04:33 PM
 *  Author: DELL
 */


#ifndef TIMER_H_
#define TIMER_H_

#include "MEM_MAP.h"
#include "BIT_MATH.h"
#include "DIO.h"

#define TIMER0_OVF_vect __vector_11
 #define TIMER0_COMP_vect __vector_10

#define CS00    0
#define CS01    1
#define CS02    2     //clock select (prescaler)
#define WGM01   3     //waveform generation mode
#define COMO0   4
#define COMO1   5     //compare match output mode
#define WGM00   6
#define FOC0    7     //force output compare

enum Timer_mode {Normal,CTC}mode;
enum PWM_mode {fast,phase_correct}pmode;
enum clk_ps{stop,clk_1,clk_8,clk_64,clk_256,clk_1024}ps;

#define non_inverted 0
#define inverted     1

void Timer_init(enum Timer_mode m,enum clk_ps p);
void Timer_Start(int preload);
void Timer_Stop(void);
void TOVf_callback(void(*Tf_local)(void));
void TCOMP_callback(void(*Tf_local)(void));
void PWM_init(enum PWM_mode m,enum clk_ps p);
void PWM_Start(enum clk_ps p);
void PWM_Set_Duty_Cycle(U8_t duty,U8_t state);
void Timer_phasePWM_Duty(U8_t state, U8_t duty);
void Timer_fastPWM_Duty(U8_t state, U8_t duty);
void Timer_Delay_ms(U32_t time);
void Adjust_angle(U8_t n);
void Timer1_Start(enum clk_ps p);
void Timer1_Stop();
void Timer1_ClockReset();


#endif /* TIMER_H_ */
