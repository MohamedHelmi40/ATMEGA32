#include "../../1-LIB/STD_TYPES.h"
#include "../../1-LIB/BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"


void SPI_Init(void)
{
	#if SPI_Clock_Rate == FOSC_4
    CLR_BIT(SPSR,SPI2X); CLR_BIT(SPCR,SPR1);CLR_BIT(SPCR,SPR0);	
	#elif SPI_Clock_Rate == FOSC_16
	CLR_BIT(SPSR,SPI2X); CLR_BIT(SPCR,SPR1);SET_BIT(SPCR,SPR0); 
    #elif SPI_Clock_Rate == FOSC0_64
    CLR_BIT(SPSR,SPI2X); SET_BIT(SPCR,SPR1);CLR_BIT(SPCR,SPR0);	
	#elif SPI_Clock_Rate == FOSC_128
	CLR_BIT(SPSR,SPI2X); SET_BIT(SPCR,SPR1);SET_BIT(SPCR,SPR0);
    #elif SPI_Clock_Rate == FOSC_2
    SET_BIT(SPSR,SPI2X); CLR_BIT(SPCR,SPR1);CLR_BIT(SPCR,SPR0);	
	#elif SPI_Clock_Rate == FOSC_8
	SET_BIT(SPSR,SPI2X); CLR_BIT(SPCR,SPR1);SET_BIT(SPCR,SPR0); 
    #elif SPI_Clock_Rate == FOSC_32
    SET_BIT(SPSR,SPI2X); SET_BIT(SPCR,SPR1);CLR_BIT(SPCR,SPR0);	
	#elif SPI_Clock_Rate == FOSC1_64
	SET_BIT(SPSR,SPI2X); SET_BIT(SPCR,SPR1);SET_BIT(SPCR,SPR0);	
	#endif
	#if CLOCK_PHASE == SAMPLED_LEADING
	CLR_BIT(SPCR,CPHA);
	#elif CLOCK_PHASE == SAMPLED_TRAILING
	SET_BIT(SPCR,CPHA);
	#endif
	#if CLOCK_POLARITY == HIGH_IDLE
	SET_BIT(SPCR,CPOL);
	#elif CLOCK_POLARITY == LOW_IDLE
	CLR_BIT(SPCR,CPOL);
	#endif
	#if SPI_INTERRUPT_ENABLE == ENABLE
	SET_BIT(SPCR,SPIE);
	#elif SPI_INTERRUPT_ENABLE == DISABLE
	CLR_BIT(SPCR,SPIE);
	#endif

	#if DATA_ORDER == LSB_FIRST
	SET_BIT(SPCR,DORD);
	#elif DATA_ORDER == MSB_FIRST
	CLR_BIT(SPCR,DORD);
	#endif
	#if MASTER_SLAVE_SELECT == MASTER
	SET_BIT(SPCR,MSTR);
	#elif MASTER_SLAVE_SELECT == SLAVE
	CLR_BIT(SPCR,MSTR);
	#endif
	
	
	#if SPI_ENABLE == ENABLE
	SET_BIT(SPCR,SPE);
	#elif SPI_ENABLE ==DISABLE
	CLR_BIT(SPCR,SPE);
	#endif
	
}

u8 SPI_SendReciveData(u8 Data)
{
	SPDR =Data;
	while(GET_BIT(SPSR,SPIF) == 0);
	return SPDR;
}

void(*PTF)(void);
void SPI_CallBack(void(*PTR)(void))
{
	PTF=PTR;
}
void __vector_12(void)
{
	
	PTF();
}