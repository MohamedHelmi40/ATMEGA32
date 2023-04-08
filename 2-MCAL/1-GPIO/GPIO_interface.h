#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H



void SetPortDirection(u8 copy_port,u8 copy_direction);
void SetPinDirection(u8 copy_port,u8 copy_pin,u8 copy_direction);

void SetPortValue(u8 copy_port,u8 copy_value);
void SetPinValue(u8 copy_port,u8 copy_pin,u8 copy_value);

u8 GetPortValue(u8 copy_port);
u8 GetPinValue(u8 copy_port,u8 copy_pin);

void TogPort(u8 copy_port);
void TogPin(u8 copy_port,u8 copy_pin);

void ConfigPullUpPort(u8 copy_port,u8 copy_pullup_value);
void ConfigPullUpPin(u8 copy_port,u8 copy_pin,u8 copy_pullup_value);


#define GPIO_OUTPUT 1
#define GPIO_INPUT  0

#define GPIO_HIGH   1
#define GPIO_LOW    0

#define GPIO_PULLUP   1
#define GPIO_PULLDOWN 0	
		  
#define GPIO_DDRA  1
#define GPIO_DDRB  2
#define GPIO_DDRC  3
#define GPIO_DDRD  4
#define GPIO_PORTA 5
#define GPIO_PORTB 6
#define GPIO_PORTC 7
#define GPIO_PORTD 8
#define GPIO_PINA  9
#define GPIO_PINB  10
#define GPIO_PINC  11
#define GPIO_PIND  12

//      PORTA BITS
#define PORTA7 7
#define PORTA6 6
#define PORTA5 5
#define PORTA4 4
#define PORTA3 3
#define PORTA2 2
#define PORTA1 1
#define PORTA0 0
//      PORTB BITS
#define PORTB7 7
#define PORTB6 6
#define PORTB5 5
#define PORTB4 4
#define PORTB3 3
#define PORTB2 2
#define PORTB1 1
#define PORTB0 0
//      PORTC BITS
#define PORTC7 7
#define PORTC6 6
#define PORTC5 5
#define PORTC4 4
#define PORTC3 3
#define PORTC2 2
#define PORTC1 1
#define PORTC0 0
//      PORTD BITS
#define PORTD7 7
#define PORTD6 6
#define PORTD5 5
#define PORTD4 4
#define PORTD3 3
#define PORTD2 2
#define PORTD1 1
#define PORTD0 0

//     DDRA BITS
#define DDA7 7
#define DDA6 6
#define DDA5 5
#define DDA4 4
#define DDA3 3
#define DDA2 2
#define DDA1 1
#define DDA0 0

//     DDRB BITS
#define DDB7 7
#define DDB6 6
#define DDB5 5
#define DDB4 4
#define DDB3 3
#define DDB2 2
#define DDB1 1
#define DDB0 0

//     DDRC BITS
#define DDC7 7
#define DDC6 6
#define DDC5 5
#define DDC4 4
#define DDC3 3
#define DDC2 2
#define DDC1 1
#define DDC0 0

//     DDRD BITS
#define DDD7 7
#define DDD6 6
#define DDD5 5
#define DDD4 4
#define DDD3 3
#define DDD2 2
#define DDD1 1
#define DDD0 0

//      PINA BITS
#define PINA7 7
#define PINA6 6
#define PINA5 5
#define PINA4 4
#define PINA3 3
#define PINA2 2
#define PINA1 1
#define PINA0 0

//      PINB BITS
#define PINB7 7
#define PINB6 6
#define PINB5 5
#define PINB4 4
#define PINB3 3
#define PINB2 2
#define PINB1 1
#define PINB0 0

//      PINC BITS
#define PINC7 7
#define PINC6 6
#define PINC5 5
#define PINC4 4
#define PINC3 3
#define PINC2 2
#define PINC1 1
#define PINC0 0

//      PIND BITS
#define PIND7 7
#define PIND6 6
#define PIND5 5
#define PIND4 4
#define PIND3 3
#define PIND2 2
#define PIND1 1
#define PIND0 0
#endif