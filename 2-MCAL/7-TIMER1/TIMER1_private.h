#ifndef TIMER1_PRIVATE_H
#define TIMER1_PRIVATE_H




#define TCCR1A (*(volatile u8*)0x4F)
#define TCCR1B (*(volatile u8*)0x4E)

#define TCNT1L (*(volatile u16*)0x4C)

#define OCR1AL (*(volatile u16*)0x4A)
#define OCR1BL (*(volatile u16*)0x48)
#define ICR1L  (*(volatile u16*)0x46)
#define TIMSK  (*(volatile u8*)0x59)
#define TIFR   (*(volatile u8*)0x58) 

//Compare Output Mode for Compare unit A,B
#define OC1A_DISCONNECTED    0
#define TOGGLE_OC1A          1
#define NON_INVERTING_OC1A   2
#define INVERTING_OC1A       3
#define OC1B_DISCONNECTED    0
#define TOGGLE_OC1B          1
#define NON_INVERTING_OC1B   2
#define INVERTING_OC1B       3

#define NORMAL                          0
#define PWM_PHASE_CORRECT_8_BIT         1
#define PWM_PHASE_CORRECT_9_BIT         2
#define PWM_PHASE_CORRECT_10_BIT        3
#define CTC_OCR1A                       4
#define FAST_PWM_8_BIT                  5
#define FAST_PWM_9_BIT                  6 
#define FAST_PWM_10_BIT                 7
#define PWM_PHASE_FREQ_CORRECT_ICR1     8
#define PWM_PHASE_FREQ_CORRECT_OCR1A    9
#define PWM_PHASE_CORRECT_ICR1          10
#define PWM_PHASE_CORRECT_OCR1A         11
#define CTC                             12
#define RESERVED                        13
#define FAST_PWM_ICR1                   14
#define FAST_PWM_OCR1A                  15

//Clock Source
#define NO_CLOCk_SOURCE  0
#define NO_PRESCALING    1
#define PRESCALER_8      2
#define PRESCALER_64     3
#define PRESCALER_256    4
#define PRESCALER_1024   5
#define T0_FALLING       6
#define T0_RISING        7
#define ENABLE    1
#define DISABLE   0

#define COM1A1 7
#define COM1A0 6
#define COM1B1 5
#define COM1B0 4
#define FOC1A  3
#define FOC1B  2
#define WGM11  1
#define WGM10  0

#define ICNC1  7
#define ICES1  6
#define WGM13  4
#define WGM12  3
#define CS12   2
#define CS11   1
#define CS10   0

#define TICIE1 5
#define OCIE1A 4
#define OCIE1B 3
#define TOIE1  2

#define ICF1   5
#define OCF1A  4
#define OCF1B  3
#define TOV1   2

#define NULL 0
#define FALLING_EDGE_TRIGGER  0
#define RISING_EDGE_TRIGGER   1
#endif