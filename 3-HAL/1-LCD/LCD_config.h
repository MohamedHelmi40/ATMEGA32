#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H



#define RS   GPIO_PORTA,PORTA6    // H-Display Data   L-instruction code
#define RW   GPIO_PORTA,PORTA5    // H-read opration  L-write opration
#define E    GPIO_PORTA,PORTA4    // H-read Data      L-writ Data

#define DB4  GPIO_PORTA,PORTA3
#define DB5  GPIO_PORTA,PORTA2
#define DB6  GPIO_PORTA,PORTA1
#define DB7  GPIO_PORTA,PORTA0

#define GPIO_PORT_cfg  GPIO_PORTA





#endif