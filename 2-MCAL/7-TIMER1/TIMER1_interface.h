#ifndef TIMER1_INTERFACE_H
#define TIMER1_INTERFACE_H


void TIMER1_Init(void);

void TIMER1_Start(void);
void TIMER1_Stop(void);
void TIMER1_Delay_Sec(float Time);
void TIMER1_ICP_EdgeSelect(u8 EdgeSelect);

void TIMER1_PWM_freq_HZ(u16 freq);
void TIMER1_voidFastPWM_OC1A(u8 Duty_Cycle);
void TIMER1_voidPhaseCorrectPWM_OC1A(u8 Duty_Cycle);
void TIMER1_voidFastPWM_OC1B(u8 Duty_Cycle);
void TIMER1_voidPhaseCorrectPWM_OC1B(u8 Duty_Cycle);

void TIMER1_Interrupt_OVF_Enable(void);
void TIMER1_Interrupt_OCA_Enable(void);
void TIMER1_Interrupt_OCB_Enable(void);
void TIMER1_Interrupt_ICP_Enable(void);
void TIMER1_Interrupt_OVF_Disable(void);
void TIMER1_Interrupt_OCA_Disable(void);
void TIMER1_Interrupt_OCB_Disable(void);
void TIMER1_Interrupt_ICP_Disable(void);

void TIMER1_CallBack_OVF(void(*PTR_OVF)(void));
void TIMER1_CallBack_COMPB(void(*PTR_COMPB)(void));
void TIMER1_CallBack_COMPA(void(*PTR_COMPA)(void));
void TIMER1_CallBack_CAPT(void(*PTR_CAPT)(void));

#define FALLING 0
#define RISING  1












#endif