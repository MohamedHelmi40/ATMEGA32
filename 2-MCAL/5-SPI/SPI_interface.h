#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H




void SPI_Init(void);
u8 SPI_SendReciveData(u8 Data);
void SPI_CallBack(void(*PTR)(void));









#endif