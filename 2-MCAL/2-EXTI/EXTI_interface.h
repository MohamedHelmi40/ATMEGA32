#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H





void EXTI_Enable(u8 INT,u8 EXTI_mode);
void EXTI_Disable(u8 INT );
void Global_InterruptEnable(void);
void EXTI_CALLBACK_INT0(void(*PTR)(void));

#define LOW_LEVEL_MODE 0
#define ANY_CHANGE     1
#define FAILLING       2
#define RAISING        3
#define FAILLING_INT2  0
#define RAISING_INT2   1

#define INT0 6
#define INT1 7
#define INT2 5



#endif