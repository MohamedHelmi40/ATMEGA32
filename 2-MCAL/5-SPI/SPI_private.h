#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H



#define SPCR  (*(volatile u8*)0x2D)
#define SPSR  (*(volatile u8*)0x2E)
#define SPDR  (*(volatile u8*)0x2F)


#define SPIE 7
#define SPE  6
#define DORD 5
#define MSTR 4
#define CPOL 3
#define CPHA 2
#define SPR1 1
#define SPR0 0

#define SPIF  7
#define WCOL  6
#define SPI2X 1

#define ENABLE  1
#define DISABLE 0

#define MSB_FIRST 1
#define LSB_FIRST 0

#define SLAVE  0
#define MASTER 1

#define HIGH_IDLE 1
#define LOW_IDLE  0
#define SAMPLED_LEADING   1
#define SAMPLED_TRAILING  0


#define FOSC_4      0
#define FOSC_16     1
#define FOSC0_64    2
#define FOSC_128    3
#define FOSC_2      4
#define FOSC_8      5
#define FOSC_32     6
#define FOSC1_64    7
 








#endif