#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H



void UART_Init(void);
void UART_Transmit(u8 Data);
u8 UART_Receive(void);
void UART_CallBackRxComplete(void (*PTR1)(void));
void UART_CallBackTxComplete(void (*PTR2)(void));
void UART_CallBackDataRegisterEmpty(void (*PTR3)(void));











#endif