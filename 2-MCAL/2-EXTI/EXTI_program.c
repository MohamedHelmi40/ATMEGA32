#include "../../1-LIB/STD_TYPES.h"
#include "../../1-LIB/BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"




void EXTI_Enable(u8 INT ,u8 EXTI_mode)
{
	switch(INT)
	{
		case INT0:
		     SET_BIT(GICR,INT0);
			 MCUCR |= (EXTI_mode<<2);
		break;
		case INT1:
		     SET_BIT(GICR,INT1);
			 MCUCR |= (EXTI_mode<<0);
		break;
		case INT2:
		     SET_BIT(GICR,INT0);
			 MCUCSR |= (EXTI_mode<<6);
		break;
		default: asm("NOP");
	}
}
void EXTI_Disable(u8 INT )
{
	switch(INT)
	{
		case INT0:
		     CLR_BIT(GICR,INT0);
		break;
		case INT1:
		     CLR_BIT(GICR,INT1);
		break;
		case INT2:
		     CLR_BIT(GICR,INT0);
		break;
		default: asm("NOP");
	}
}
void Global_InterruptEnable(void)
{
	SET_BIT(SREG,7);
}

void(*PTF0)(void);
void EXTI_CALLBACK_INT0(void(*PTR)(void))
{
	PTF0=PTR;
}
void __vector_1(void)
{
	PTF0();
}