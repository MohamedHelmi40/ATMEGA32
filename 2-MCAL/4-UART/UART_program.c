#include "../../1-LIB/BIT_MATH.h"
#include "../../1-LIB/STD_TYPES.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"



void UART_Init(void)
{
	SET_BIT(UCSRB,TXEN);
	CLR_BIT(UCSRA,U2X);
	SET_BIT(UCSRC,URSEL);
	#if USART_MODE_SELECT == SYNC_OPERATION
	SET_BIT(UCSRC,UMSEL);
	#elif  USART_MODE_SELECT == ASYNC_OPERATION
	CLR_BIT(UCSRC,UMSEL);
	#endif
	
	#if PARITY_MODE == EVEN_PARITY
	SET_BIT(UCSRC,UPM1);
	CLR_BIT(UCSRC,UPM0);
	#elif PARITY_MODE == ODD_PARITY
	SET_BIT(UCSRC,UPM1);
	SET_BIT(UCSRC,UPM0);
	#endif
	#if STOP_BIT_SELECT == ONE_BIT
	CLR_BIT(UCSRC,USBS);
	#elif STOP_BIT_SELECT == TWO_BIT
	SET_BIT(UCSRC,USBS);
	#endif
	#if CHARACTER_SIZE == FIVE_BIT
	CLR_BIT(UCSRB,UCSZ2);  CLR_BIT(UCSRC,UCSZ1);  CLR_BIT(UCSRC,UCSZ0);
	#elif CHARACTER_SIZE == SIX_BIT
	CLR_BIT(UCSRB,UCSZ2);  CLR_BIT(UCSRC,UCSZ1);  SET_BIT(UCSRC,UCSZ0);
	#elif CHARACTER_SIZE == SEVEN_BIT
	CLR_BIT(UCSRB,UCSZ2);  SET_BIT(UCSRC,UCSZ1);  CLR_BIT(UCSRC,UCSZ0);
	#elif CHARACTER_SIZE == EIGHT_BIT
	CLR_BIT(UCSRB,UCSZ2);  SET_BIT(UCSRC,UCSZ1);  SET_BIT(UCSRC,UCSZ0);
	#elif CHARACTER_SIZE == NINE_BIT
	SET_BIT(UCSRB,UCSZ2);  SET_BIT(UCSRC,UCSZ1);  SET_BIT(UCSRC,UCSZ0);
	#endif
	
	#if RX_COMPLETE_INTERRUPT == Enable
	SET_BIT(UCSRB,RXCIE);
	#elif RX_COMPLETE_INTERRUPT == Disable
	CLR_BIT(UCSRB,RXCIE);
	#endif
	
	#if TX_COMPLETE_INTERRUPT == Enable
	SET_BIT(UCSRB,TXCIE);
	#elif TX_COMPLETE_INTERRUPT == Disable
	CLR_BIT(UCSRB,TXCIE);
	#endif
	
	#if DATA_Register_Empty_INTERRUPT == Enable
	SET_BIT(UCSRB,UDRIE);
	#elif DATA_Register_Empty_INTERRUPT == Disable
	CLR_BIT(UCSRB,UDRIE);
	#endif
	
	CLR_BIT(UBRRH,URSEL);
	UBRRH=0;	
	UBRRL=51;
	
}

void UART_Transmit(u8 Data)
{
	
	while(GET_BIT(UCSRA,UDRE)==0);
	UDR=Data;
}
u8 UART_Receive(void)
{
	u8 LocalResult=0;
	SET_BIT(UCSRB,RXEN);
	while(GET_BIT(UCSRA,RXC)== 0);
	LocalResult=UDR;
	
	return LocalResult;
}

void (*PTF1)(void);
void UART_CallBackRxComplete(void (*PTR1)(void))
{
	PTF1=PTR1;
}
void __vector_13(void)
{
	PTF1();
}
void (*PTF3)(void);
void UART_CallBackDataRegisterEmpty(void (*PTR3)(void))
{
	PTF3=PTR3;
}
void __vector_14(void)
{
	PTF3();
}
void (*PTF2)(void);
void UART_CallBackTxComplete(void (*PTR2)(void))
{
	PTF2=PTR2;
}
void __vector_15(void)
{
	PTF2();
}