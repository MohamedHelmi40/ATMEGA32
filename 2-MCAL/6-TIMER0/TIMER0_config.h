#ifndef TIMER0_CONFIG_H
#define TIMER0_CONFIG_H



#define F_CPU      8000000
#define RESOLUTION  256
#define OCR0_value  200
#define CLOCKSOURCE  PRESCALER_8
/*
You can choose 
 NO_CLOCk_SOURCE
 NO_PRESCALING
 PRESCALER_8
 PRESCALER_64
 PRESCALER_256
 PRESCALER_1024
 T0_FALLING
 T0_RISING
*/
#define OC0_INTERRUPT_ENABLE   ENABLE
/*
You can choose 
DISABLE
ENABLE
*/

#define OVF_INTERRUPT_ENABLE   DISABLE

/*
You can choose 
DISABLE
ENABLE
*/




#endif