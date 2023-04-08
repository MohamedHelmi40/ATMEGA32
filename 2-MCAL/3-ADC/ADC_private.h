#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H


#define ADMUX  (*(volatile u8*)(0x27))
#define ADCSRA (*(volatile u8*)(0x26))
#define ADCL   (*(volatile u16*)(0x24))
#define SFIOR  (*(volatile u8*)(0x50))


//ADMUX register  
#define REFS1 7
#define REFS0 6
#define ADLAR 5
#define MUX4  4
#define MUX3  3
#define MUX2  2
#define MUX1  1
#define MUX0  0

//ADCSRA register
#define ADEN   7
#define ADSC   6 
#define ADATE  5
#define ADIF   4
#define ADIE   3
#define ADPS2  2
#define ADPS1  1
#define ADPS0  0

//SFIOR register
#define ADTS2  7
#define ADTS1  6
#define ADTS0  5

#define AREF             0
#define AVCC             1
#define V_REF_CAPACITOR  3


 

#define ADC_pre_2     1
#define ADC_pre_4     2
#define ADC_pre_8     3
#define ADC_pre_16    4
#define ADC_pre_32    5
#define ADC_pre_64    6
#define ADC_pre_128   7

#define FREE_RUNNING_MODE       0
#define ANALOG_COMPARATOR       1
#define EXT_INTERRUPT_REQUEST   2
#define T_C_0COMPARE_MATCH      3
#define T_C_0_OVERFLOW          4
#define T_C_1_COMPARE_MATCH_B   5
#define T_C_1_OVERFLOW          6
#define T_C_1_CAPTURE_EVENT     7

#define ENABLE  1
#define DISABLE 0





#endif