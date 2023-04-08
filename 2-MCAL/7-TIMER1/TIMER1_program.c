#include "../../1-LIB/STD_TYPES.h"
#include "../../1-LIB/BIT_MATH.h"


#include "TIMER1_interface.h"
#include "TIMER1_private.h"
#include "TIMER1_config.h"




void TIMER1_Init(void)
{
	#if COM_U_A == OC1A_DISCONNECTED
	    CLR_BIT(TCCR1A,COM1A1);   CLR_BIT(TCCR1A,COM1A0);
	#elif COM_U_A == TOGGLE_OC1A
	    CLR_BIT(TCCR1A,COM1A1);   SET_BIT(TCCR1A,COM1A0);
	#elif COM_U_A == NON_INVERTING_OC1A
	    SET_BIT(TCCR1A,COM1A1);   CLR_BIT(TCCR1A,COM1A0);
	#elif COM_U_A == INVERTING_OC1A
	    SET_BIT(TCCR1A,COM1A1);   SET_BIT(TCCR1A,COM1A0);
	#endif
	#if COM_U_B == OC1B_DISCONNECTED
	CLR_BIT(TCCR1A,COM1B1);   CLR_BIT(TCCR1A,COM1B0);
	#elif COM_U_B == TOGGLE_OC1B
	CLR_BIT(TCCR1A,COM1B1);   SET_BIT(TCCR1A,COM1B0);
	#elif COM_U_B == NON_INVERTING_OC1B
	SET_BIT(TCCR1A,COM1B1);   CLR_BIT(TCCR1A,COM1B0);
	#elif COM_U_B == INVERTING_OC1B
	SET_BIT(TCCR1A,COM1B1);   SET_BIT(TCCR1A,COM1B0);
	#endif
	
	#if WAVE_GEN   == NORMAL 
	CLR_BIT(TCCR1B,WGM13); CLR_BIT(TCCR1B,WGM12); CLR_BIT(TCCR1A,WGM11); CLR_BIT(TCCR1A,WGM10);
	#elif WAVE_GEN == PWM_PHASE_CORRECT_8_BIT
	CLR_BIT(TCCR1B,WGM13); CLR_BIT(TCCR1B,WGM12); CLR_BIT(TCCR1A,WGM11); SET_BIT(TCCR1A,WGM10);
	#elif WAVE_GEN == PWM_PHASE_CORRECT_9_BIT
	CLR_BIT(TCCR1B,WGM13); CLR_BIT(TCCR1B,WGM12); SET_BIT(TCCR1A,WGM11); CLR_BIT(TCCR1A,WGM10);
	#elif WAVE_GEN == PWM_PHASE_CORRECT_10_BIT
	CLR_BIT(TCCR1B,WGM13); CLR_BIT(TCCR1B,WGM12); SET_BIT(TCCR1A,WGM11); SET_BIT(TCCR1A,WGM10);
	#elif WAVE_GEN == CTC_OCR1A
	CLR_BIT(TCCR1B,WGM13); SET_BIT(TCCR1B,WGM12); CLR_BIT(TCCR1A,WGM11); CLR_BIT(TCCR1A,WGM10);
	#elif WAVE_GEN == FAST_PWM_8_BIT
	CLR_BIT(TCCR1B,WGM13); SET_BIT(TCCR1B,WGM12); CLR_BIT(TCCR1A,WGM11); SET_BIT(TCCR1A,WGM10);
	#elif WAVE_GEN == FAST_PWM_9_BIT
	CLR_BIT(TCCR1B,WGM13); SET_BIT(TCCR1B,WGM12); SET_BIT(TCCR1A,WGM11); CLR_BIT(TCCR1A,WGM10);
	#elif WAVE_GEN == FAST_PWM_10_BIT
	CLR_BIT(TCCR1B,WGM13); SET_BIT(TCCR1B,WGM12); SET_BIT(TCCR1A,WGM11); SET_BIT(TCCR1A,WGM10);
	#elif WAVE_GEN == PWM_PHASE_FREQ_CORRECT_ICR1
	SET_BIT(TCCR1B,WGM13); CLR_BIT(TCCR1B,WGM12); CLR_BIT(TCCR1A,WGM11); CLR_BIT(TCCR1A,WGM10);
	#elif WAVE_GEN == PWM_PHASE_FREQ_CORRECT_OCR1A
	SET_BIT(TCCR1B,WGM13); CLR_BIT(TCCR1B,WGM12); CLR_BIT(TCCR1A,WGM11); SET_BIT(TCCR1A,WGM10);
	#elif WAVE_GEN == PWM_PHASE_CORRECT_ICR1
	SET_BIT(TCCR1B,WGM13); CLR_BIT(TCCR1B,WGM12); SET_BIT(TCCR1A,WGM11); CLR_BIT(TCCR1A,WGM10);
	#elif WAVE_GEN == PWM_PHASE_CORRECT_OCR1A
	SET_BIT(TCCR1B,WGM13); CLR_BIT(TCCR1B,WGM12); SET_BIT(TCCR1A,WGM11); SET_BIT(TCCR1A,WGM10);
	#elif WAVE_GEN == CTC
	SET_BIT(TCCR1B,WGM13); SET_BIT(TCCR1B,WGM12); CLR_BIT(TCCR1A,WGM11); CLR_BIT(TCCR1A,WGM10);
	#elif WAVE_GEN == FAST_PWM_ICR1
	SET_BIT(TCCR1B,WGM13); SET_BIT(TCCR1B,WGM12); SET_BIT(TCCR1A,WGM11); CLR_BIT(TCCR1A,WGM10);
	#elif WAVE_GEN == FAST_PWM_OCR1A
	SET_BIT(TCCR1B,WGM13); SET_BIT(TCCR1B,WGM12); SET_BIT(TCCR1A,WGM11); SET_BIT(TCCR1A,WGM10);
	#endif
    TCCR1B |=(INPUT_CAPTURE_NOISE_CANCELER<<ICNC1);
	TCCR1B |=(INPUT_CAPTURE_EDGE_SELECT<<ICES1);
	#if OCA_INTERRUPT==ENABLE
		SET_BIT(TIMSK,OCIE1A);
	#elif OCA_INTERRUPT==DISABLE
	   CLR_BIT(TIMSK,OCIE1A);
	#endif
	#if OCB_INTERRUPT==ENABLE
	SET_BIT(TIMSK,OCIE1B);
	#elif OCB_INTERRUPT==DISABLE
	CLR_BIT(TIMSK,OCIE1B);
	#endif
	#if ICP_INTERRUPT==ENABLE
	SET_BIT(TIMSK,TICIE1);
	#elif ICP_INTERRUPT==DISABLE
	CLR_BIT(TIMSK,TICIE1);
	#endif
	#if OVF_INTERRUPT_ENABLE==ENABLE
	SET_BIT(TIMSK,TOIE1);
	#elif OVF_INTERRUPT_ENABLE==DISABLE
	CLR_BIT(TIMSK,TOIE1);
	#endif
	OCR1AL = OCR1A_VALUE;
	OCR1BL = OCR1B_VALUE;
	ICR1L  = ICR1_VALUE;
}
void TIMER1_Start(void)
{
	TCCR1B |=(CLOCK_SOURCE<<CS10);
}
void TIMER1_Stop(void)
{
	TCCR1B &=0xf8;
	
}
void TIMER1_Delay_Sec(float Time)
{
	int prescaler=0;
	int OVF_counter=0;
	switch(CLOCK_SOURCE){
		
		case NO_PRESCALING 	 : prescaler=1;   break;
		case PRESCALER_8   	 : prescaler=8;	  break;
		case PRESCALER_64  	 : prescaler=64;  break;
		case PRESCALER_256 	 : prescaler=256; break;
		case PRESCALER_1024	 : prescaler=1024;break;
	}
	float tick_time = (float)prescaler /(float)F_CPU;
	float ovf_time = tick_time *RESOLUTION;
	float Total_time=(Time*(float)RESOLUTION)/ovf_time;
	int ovf_num = Time /ovf_time;
	TIMER1_Start();
	if(ovf_num>1)
	{
		while(OVF_counter <= ovf_num)
		{
			while(!GET_BIT(TIFR,TOV1));
			TIFR |= (1<<TOV1);
			OVF_counter++;
		}
	}else
	{
		u32 preload = RESOLUTION - Total_time;
		TCNT1L=preload;
		while (!GET_BIT(TIFR,TOV1));
		SET_BIT(TIFR,TOV1);
	}
	
	TIMER1_Stop();
}

void TIMER1_PWM_freq_HZ(u16 freq)
{
	if (freq==0);
	else
	{
		u32 time_fr = (u32)1000000/freq;
		if(time_fr >=1)
		{
	    ICR1L = (time_fr)-1;
		}
		else
		{
		ICR1L=0;
		}
	}
}
void TIMER1_voidFastPWM_OC1A(u8 Duty_Cycle)
{
	#if COM_U_A == NON_INVERTING_OC1A
	    OCR1AL=((Duty_Cycle*((ICR1L+1))/100)-1);
	#elif COM_U_A == INVERTING_OC1A
	    OCR1AL=(ICR1_VALUE - ((Duty_Cycle*(ICR1L+1)/100)));
	#endif
}
void TIMER1_voidPhaseCorrectPWM_OC1A(u8 Duty_Cycle)
{
	#if COM_U_A == NON_INVERTING_OC1A
	OCR1AL=((Duty_Cycle*(ICR1L))/100);
	#elif COM_U_A == INVERTING_OC1A
	OCR1AL=(ICR1_VALUE-((Duty_Cycle*ICR1L)/100));
	#endif
}
void TIMER1_voidFastPWM_OC1B(u8 Duty_Cycle)
{
	#if COM_U_B == NON_INVERTING_OC1B
	OCR1BL=((Duty_Cycle*((ICR1L+1))/100)-1);
	#elif COM_U_B == INVERTING_OC1B
	OCR1BL=(ICR1_VALUE - ((Duty_Cycle*(ICR1L+1)/100)));
	#endif
}
void TIMER1_voidPhaseCorrectPWM_OC1B(u8 Duty_Cycle)
{
	#if COM_U_B == NON_INVERTING_OC1B
	OCR1BL=((Duty_Cycle*(ICR1L))/100);
	#elif COM_U_B == INVERTING_OC1B
	OCR1BL=(ICR1_VALUE-((Duty_Cycle*ICR1L)/100));
	#endif
}
void TIMER1_Interrupt_OVF_Enable(void)
{
	SET_BIT(TIMSK,TOIE1);
}
void TIMER1_Interrupt_OCA_Enable(void)
{
	SET_BIT(TIMSK,OCIE1A);
}
void TIMER1_Interrupt_OCB_Enable(void)
{
	SET_BIT(TIMSK,OCIE1B);
}
void TIMER1_Interrupt_ICP_Enable(void)
{
	SET_BIT(TIMSK,TICIE1);
}
void TIMER1_Interrupt_OVF_Disable(void)
{
	CLR_BIT(TIMSK,TOIE1) ;
}
void TIMER1_Interrupt_OCA_Disable(void)
{
	
	CLR_BIT(TIMSK,OCIE1A);
	
}
void TIMER1_Interrupt_OCB_Disable(void)
{
	CLR_BIT(TIMSK,OCIE1B);
}
void TIMER1_Interrupt_ICP_Disable(void)
{
	CLR_BIT(TIMSK,TICIE1);
}


void TIMER1_ICP_EdgeSelect(u8 EdgeSelect)
{
	TCCR1B|=(EdgeSelect<<ICES1);
}
void (*PTF_OVF)(void)=NULL;
void TIMER1_CallBack_OVF(void(*PTR_OVF)(void))
{
	PTF_OVF=PTR_OVF;
}
void (*PTF_COMPB)(void)=NULL;
void TIMER1_CallBack_COMPB(void(*PTR_COMPB)(void))
{
	PTF_COMPB=PTR_COMPB;
}
void (*PTF_COMPA)(void)=NULL;
void TIMER1_CallBack_COMPA(void(*PTR_COMPA)(void))
{
	PTF_COMPA=PTR_COMPA;
}
void (*PTF_CAPT)(void)=NULL;
void TIMER1_CallBack_CAPT(void(*PTR_CAPT)(void))
{
	PTF_CAPT=PTR_CAPT;
}
void __vector_9(void)__attribute__((signal,used));
void __vector_9(void)
{
	if(PTF_OVF!=NULL)
	{
		PTF_OVF();
	}
}
void __vector_8(void)__attribute__((signal,used));
void __vector_8(void)
{	
	if(PTF_COMPB!=NULL)
	{
		PTF_COMPB();
	}
	
}
void __vector_7(void)__attribute__((signal,used));
void __vector_7(void)
{
	if (PTF_COMPA!=NULL)
	{
		PTF_COMPA();
	}
	
}
void __vector_6(void)__attribute__((signal,used));
void __vector_6(void)
{
	if(PTF_CAPT!=NULL)
	{
		PTF_CAPT();
	}
	
}


