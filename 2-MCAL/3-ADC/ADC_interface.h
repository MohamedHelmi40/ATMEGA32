#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H


void ADC_init(void);
u16 ADC_Read(u8 copy_ADC_channel);
void ADC_CallBack(void(*Ptr)(void));


#define ADC0    0
#define ADC1    1
#define ADC2    2
#define ADC3    3
#define ADC4    4
#define ADC5    5
#define ADC6    6
#define ADC7    7


#endif