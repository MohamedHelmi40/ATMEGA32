#include "../STD_TYPES.h"
#include "delay_interface.h"
#include "delay_private.h"


void Delay_ms(u32 Copy_u32Time_ms)
{
	
	Copy_u32Time_ms = (Copy_u32Time_ms * 100000)-(LDELAY_CalculationTime + LDELAY_ContextSwitch);
	u32 Local_u32NoLoops = Copy_u32Time_ms/LDELAY_LoopTime;
	for(u32 i=0;i<Local_u32NoLoops;i++)
	{
		asm("NOP");
	}
	
}

void Delay_us(u32 Copy_u32Time_us)
{
	Copy_u32Time_us = (Copy_u32Time_us * 100) - LDELAY_CalculationTime - LDELAY_ContextSwitch;
	u32 Local_u32NoLoops = Copy_u32Time_us / LDELAY_LoopTime;
	for(u32 i=0;i<Local_u32NoLoops;i++)
	{
		asm("NOP");
	}
}