#include "../../1-LIB/STD_TYPES.h"
#include "../../1-LIB/BIT_MATH.h"

#include "TIMER0_interface.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"


static u32   OVF_counter=0;
static u32   OVF_number=0; 
void TIMER0_init(u8 copyWaveGen,u8 copyCompareMode)
{
	
	switch(copyCompareMode)
	{
		case OC0_DISCONNECTED      : CLR_BIT(TCCR0,COM00);CLR_BIT(TCCR0,COM01);break;
		case TOGGLE_OC0            : SET_BIT(TCCR0,COM00);CLR_BIT(TCCR0,COM01);break;
		case NON_INVERTING_OC0     : CLR_BIT(TCCR0,COM00);SET_BIT(TCCR0,COM01);break;
		case INVERTING_OC0         : SET_BIT(TCCR0,COM00);SET_BIT(TCCR0,COM01);break;
		default: asm("NOP");
	}
	switch(copyWaveGen)
	{
		case NORMAL           : CLR_BIT(TCCR0,WGM00);CLR_BIT(TCCR0,WGM01);break;
		case PWM_PHASE_CORRECT: SET_BIT(TCCR0,WGM00);CLR_BIT(TCCR0,WGM01);break;
		case CTC              : CLR_BIT(TCCR0,WGM00);SET_BIT(TCCR0,WGM01);break;
		case FAST_PWM         : SET_BIT(TCCR0,WGM00);SET_BIT(TCCR0,WGM01);break;
		default: asm("NOP");
	}
	if (OVF_INTERRUPT_ENABLE == ENABLE)
	    SET_BIT(TIMSK,TOIE0);
    else if(OVF_INTERRUPT_ENABLE == DISABLE)
	   CLR_BIT(TIMSK,TOIE0);
 
	
	if (OC0_INTERRUPT_ENABLE == ENABLE)
	    SET_BIT(TIMSK,OCIE0);
    else if (OC0_INTERRUPT_ENABLE == DISABLE)
	   CLR_BIT(TIMSK,OCIE0);
	   
	   OCR0=OCR0_value;
    
}
void TIMER0_SetDesiredTime_us(u64 copy_time_us)
{
	u32 prescaler=0;
	u32 preload=0;
	switch(CLOCKSOURCE)
	{
		case NO_PRESCALING  : prescaler = 1   ; break;
        case PRESCALER_8    : prescaler = 8   ; break;
        case PRESCALER_64   : prescaler = 64  ; break;
        case PRESCALER_256  : prescaler = 256 ; break;
        case PRESCALER_1024	: prescaler = 1024; break;
	}
	u32 Tick_time = (prescaler*1000000)/F_CPU;
	u32 OVF_time  = Tick_time * RESOLUTION;
	u32 OVF_number= copy_time_us/OVF_time;
	u32 OVF_RemNum = copy_time_us%OVF_time;
	
	TCCR0 |=(CLOCKSOURCE<<CS00);
	while(OVF_counter <= OVF_number)
	{
		while((TIFR & (1<<0))==0);
		TIFR |= (1<<TOV0);
		OVF_counter++;
	}
	if (OVF_RemNum>0)
	{
		preload = RESOLUTION - OVF_RemNum;
		TCNT0 = preload;
	}
	TCCR0 &= 0xF8;
	OVF_counter=0;
	
}
void TIMER0_SetDesiredTime_us_Interrupt_Enable(u64 copy_time_us)
{
	u32 prescaler=0;
	u32 preload=0;
	switch(CLOCKSOURCE)
	{
		case NO_PRESCALING  : prescaler = 1   ; break;
        case PRESCALER_8    : prescaler = 8   ; break;
        case PRESCALER_64   : prescaler = 64  ; break;
        case PRESCALER_256  : prescaler = 256 ; break;
        case PRESCALER_1024	: prescaler = 1024; break;
	}
	u32 Tick_time = (prescaler*1000000)/F_CPU;
	u32 OVF_time  = Tick_time * RESOLUTION;
	    OVF_number= copy_time_us/OVF_time;
	u32 OVF_RemNum = copy_time_us%OVF_time;
	
	
	
	if (OVF_RemNum>0)
	{
		preload = RESOLUTION - OVF_RemNum;
		TCNT0 = preload;
	}
	TCCR0 |=(CLOCKSOURCE<<CS00);

	
	
}
void TIMER0_Start(void)
{
	TCCR0 |=(CLOCKSOURCE<<CS00);
}
void TIMER0_voidFastPWM(u8 Duty_Cycle)
{
	OCR0=((256*Duty_Cycle)/100)-1;
	TCCR0 |=(CLOCKSOURCE<<CS00);
}
void TIMER0_voidPhaseCorrectPWM(u8 Duty_Cycle)
{
	OCR0=((255*Duty_Cycle)/100);
	TCCR0 |=(CLOCKSOURCE<<CS00);
}

void __vector_10(void) __attribute__((signal,used));
void __vector_11(void) __attribute__((signal,used));

void (*PTF_OVF)(void);
void TIMER0_OVF_CALLBACK(void(*PTR_OVF)(void))
{
	PTF_OVF=PTR_OVF;
}

void (*PTF_OC0)(void);
void TIMER0_OC0_CALLBACK(void(*PTR_OC0)(void))
{
	PTF_OC0 = PTR_OC0;
}
void __vector_10(void)
{
	
		PTF_OC0();
	
	
}
void __vector_11(void)
{

		if(OVF_counter < OVF_number)
	    {
	    	OVF_counter++;
	    }
		if(OVF_counter == OVF_number)
		{
		PTF_OVF();
		OVF_counter=0;
		}
}