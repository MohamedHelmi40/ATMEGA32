#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

#define SPI_INTERRUPT_ENABLE ENABLE
/*
You can choose 
ENABLE
DISABLE
*/
#define SPI_ENABLE  ENABLE
/*
You can choose 
ENABLE
DISABLE
*/
#define DATA_ORDER  MSB_FIRST
/*
You can choose 
LSB_FIRST
MSB_FIRST
*/

#define MASTER_SLAVE_SELECT  MASTER
/*
You can choose 
MASTER
SLAVE
*/

#define CLOCK_POLARITY  LOW_IDLE
/*
You can choose 
HIGH_IDLE
LOW_IDLE
*/

#define CLOCK_PHASE    SAMPLED_TRAILING
/*
You can choose 
SAMPLED_LEADING
SAMPLED_TRAILING
*/

#define SPI_Clock_Rate  FOSC_128
/*
You can choose
FOSC_4
FOSC_16
FOSC0_64
FOSC_128
FOSC_2
FOSC_8
FOSC_32
FOSC1_64
*/

#endif