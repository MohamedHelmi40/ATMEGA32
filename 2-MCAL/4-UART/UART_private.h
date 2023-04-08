#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H




#define UDR        (*(volatile u8*)(0x2C))
#define UCSRA      (*(volatile u8*)(0x2B))
#define UCSRB      (*(volatile u8*)(0x2A))
#define UCSRC      (*(volatile u8*)(0x40))
#define UBRRL      (*(volatile u8*)(0x29))
#define UBRRH      (*(volatile u8*)(0x40))


#define RXC   7        
#define TXC   6
#define UDRE  5
#define FE    4
#define DOR   3
#define PE    2
#define U2X   1
#define MPCM  0


#define RXCIE   7               
#define TXCIE   6
#define UDRIE   5
#define RXEN    4
#define TXEN    3
#define UCSZ2   2
#define RXB8    1
#define TXB8    0



#define URSEL   7                      
#define UMSEL   6
#define UPM1    5
#define UPM0    4
#define USBS    3
#define UCSZ1   2
#define UCSZ0   1
#define UCPOL   0



#define ASYNC_OPERATION   0
#define SYNC_OPERATION    1
#define EVEN_PARITY       2
#define ODD_PARITY        3
#define ONE_BIT           0
#define TWO_BIT           1
#define FIVE_BIT          0
#define SIX_BIT           1
#define SEVEN_BIT         2
#define EIGHT_BIT         3
#define NINE_BIT          7


#define Enable  1
#define Disable 0





#endif