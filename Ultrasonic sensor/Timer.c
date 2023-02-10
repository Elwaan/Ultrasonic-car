/*
 * Timer.c
 *
 * Created: 9/7/2022 3:05:00 PM
 *  Author: DELL
 */
 #include "Timer.h"

U32_t count;
U32_t T;
U8_t ang;




void Timer_init(enum Timer_mode m,enum clk_ps p)
{
	switch (m){
		case Normal:
		CLR_BIT(TCCR0,WGM01);
		CLR_BIT(TCCR0,WGM00);                     // set to normal mode
		break;
 		case CTC:
		CLR_BIT(TCCR0,WGM01);
 		SET_BIT(TCCR0,WGM00);
 		break;
	}
	    TCNT0=248;                               //preload
 		TCCR0|=p;                                //to set the clock (we use pre-scaler 1024))
 	}




void PWM_init(enum PWM_mode m,enum clk_ps p)
{
 switch (m){
  case fast:
  SET_BIT(TCCR0,WGM00);
  SET_BIT(TCCR0,WGM01);

  CLR_BIT(TCCR0,4);
  SET_BIT(TCCR0,5);  //OCO
/*  SET_BIT(TIMSK,1);*/
  break;
  case phase_correct:
  CLR_BIT(TCCR0,WGM00);
  SET_BIT(TCCR0,WGM01);

  CLR_BIT(TCCR0,4);
  CLR_BIT(TCCR0,5);//non-inverting
  default:
  break;
 }
 TCCR0|=p;
/* DIO_F_SET_PIN_DIR(PB,PIN3,OUTPUT);*/
}                                                             // we won't use pwm in this project
//
// void PWM_Start(enum clk_ps p)
// {
// 	TCCR0|=p;//setting the pre scaler to start the pwm signal
/* }*/

void PWM_Set_Duty_Cycle(U8_t d,U8_t state)
{
	PWM_init(fast,clk_1024);

	float duty=(float)d/100;
	if(state==non_inverted)
	{
	if (d==0)
	OCR0=0;
	else
	OCR0=(duty*256)-1;
	}
	else if(state==inverted)
	OCR0=255-(256*duty)/100;
}                                        //  not used in this project

void Timer_Start(int preload)
{
	TCNT0=preload;    //make it 240 for now
	SET_BIT(TIMSK,0);
}


void Timer_Stop(void)
{
	CLR_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);            // to stop the timer

}

void (*T_fucntion1)(void);
void (*T_fucntion2)(void);

void TOVf_callback(void(*Tf_local)(void))
{
	T_fucntion1=Tf_local;
}
void TCOMP_callback(void(*Tf_local)(void))
{
	T_fucntion2=Tf_local;
}

void Timer_Delay_ms(U32_t time)
{
	Timer_init(Normal,clk_1024);
	Timer_Start(240);
	while (1)
	{
		if (T>=time)
		{
		T=0;
		break;                        // it will count till 1ms then breaks
	   }
	}
	Timer_Stop();
	return;

}



void Adjust_angle(U8_t n)
{
	ang=n;                                              //to take the angle from servo module and use it in timer
}


void Timer1_Start(enum clk_ps p)
{
	TCCR1B|=p;                        // start timer 1
}

void Timer1_Stop()
{
	CLR_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);                  // stop timer 1
}

void Timer1_ClockReset()
{
	TCNT1=0;                                //reset timer 1
}

ISR(TIMER0_OVF_vect)
{
	switch(ang){
		case 0:
	if (count==0)
	DIO_Fun_Set_Pin_Val(PD,PIN7,HIGH);              //the signal will be on for 1ms
	else if (count==2)
	DIO_Fun_Set_Pin_Val(PD,PIN7,LOW);              //off for 19ms
	if (count==38)
	count=0;
	else
	count++;
	break;

	case 90:
	if (count==0)
	DIO_Fun_Set_Pin_Val(PD,PIN7,HIGH);            // on time is 1.5ms
	else if (count==3)
	DIO_Fun_Set_Pin_Val(PD,PIN7,LOW);            // off time is 18.5ms
	if (count==37)
	count=0;
	else
	count++;
	break;

	case 180:
	if (count==0)
	DIO_Fun_Set_Pin_Val(PD,PIN7,HIGH);           // on time 2ms
	else if (count==4)
	DIO_Fun_Set_Pin_Val(PD,PIN7,LOW);            // of time 18ms
	if (count==36)
	count=0;
	else
	count++;
	break;

	default:
	break;
	}
/*	T++;*/
	TCNT0=248;       //preload
	/*if (count=="n")* /*/

		/*T_fucntion1();*/
		/*count=0;*/
	}




// ISR(__vector_10)
// {
// 	static U8_t counter=0;
// 	counter++;
// 	if (counter==125)
// 	{
// 		T_fucntion2();
// 		counter=0;
// 	}
// }

// void Timer_phasePWM_Duty(U8_t state, U8_t duty)
// {
// 		if(state==non_inverted)
// 		OCR0=(duty*255)/100;
// 		else if(state==inverted)
// 		OCR0=255*(1-duty/100);
// 	}
