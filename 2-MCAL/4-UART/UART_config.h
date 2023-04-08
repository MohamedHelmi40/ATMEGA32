#ifndef UART_CONFIG_H
#define UART_CONFIG_H





#define USART_MODE_SELECT    ASYNC_OPERATION
/*
you can choose 
ASYNC_OPERATION
SYNC_OPERATION
*/

#define PARITY_MODE          ODD_PARITY
/*
you can choose 
EVEN_PARITY
ODD_PARITY

*/
#define STOP_BIT_SELECT      ONE_BIT
/*
you can choose 
ONE_BIT
TWO_BIT

*/
#define CHARACTER_SIZE       EIGHT_BIT
/*
you can choose 
FIVE_BIT
SIX_BIT
SEVEN_BIT
EIGHT_BIT
NINE_BIT
*/ 
    

#define RX_COMPLETE_INTERRUPT          Enable
/* You can choose 
Enable 
Disable
*/

#define TX_COMPLETE_INTERRUPT          Enable
/* You can choose 
Enable 
Disable
*/

#define DATA_Register_Empty_INTERRUPT  Enable
/* You can choose 
Enable 
Disable
*/






#endif