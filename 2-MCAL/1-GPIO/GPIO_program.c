
#include "../../1-LIB/STD_TYPES.h"
#include "../../1-LIB/BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"


void SetPortDirection(u8 copy_port,u8 copy_direction)
{
	switch (copy_port)
	{
		case GPIO_PORTA:
		    if (copy_direction==GPIO_OUTPUT)
			{
				DDRA=0b11111111;
			}
			else{
				DDRA=0b00000000;
			}  
		break;
		case GPIO_PORTB:
		     if (copy_direction==GPIO_OUTPUT)
			{
				DDRB=0b11111111;
			}
			else{
				DDRB=0b00000000;
			} 
		break;
		case GPIO_PORTC:
		     if (copy_direction==GPIO_OUTPUT)
			{
				DDRC=0b11111111;
			}
			else{
				DDRC=0b00000000;
			} 
		break;
		case GPIO_PORTD:
		     if (copy_direction==GPIO_OUTPUT)
			{
				DDRD=0b11111111;
			}
			else{
				DDRD=0b00000000;
			} 
		break;
		default: asm("NOP");
	}
	
}
void SetPinDirection(u8 copy_port,u8 copy_pin,u8 copy_direction)
{
	switch (copy_port)
	{
		case GPIO_PORTA:
		    if (copy_direction==GPIO_OUTPUT)
			{
				SET_BIT(DDRA,copy_pin);
			}
			else{
				CLR_BIT(DDRA,copy_pin);
			}  
		break;
		case GPIO_PORTB:
		     if (copy_direction==GPIO_OUTPUT)
			{
				SET_BIT(DDRB,copy_pin);
			}
			else{
				CLR_BIT(DDRB,copy_pin);
			} 
		break;
		case GPIO_PORTC:
		     if (copy_direction==GPIO_OUTPUT)
			{
				SET_BIT(DDRC,copy_pin);
			}
			else{
				CLR_BIT(DDRC,copy_pin);
			} 
		break;
		case GPIO_PORTD:
		     if (copy_direction==GPIO_OUTPUT)
			{
				SET_BIT(DDRD,copy_pin);
			}
			else{
				CLR_BIT(DDRD,copy_pin);
			} 
		break;
		default: asm("NOP");
	}
}

void SetPortValue(u8 copy_port,u8 copy_value)
{
	switch (copy_port)
	{
		case GPIO_PORTA:
		     if(copy_value==GPIO_HIGH)
			 {
				 PORTA=0b11111111;
			 }else{
				 PORTA=0b00000000;
			 }
		break;
		case GPIO_PORTB:
		     if(copy_value==GPIO_HIGH)
			 {
				 PORTB=0b11111111;
			 }else{
				 PORTB=0b00000000;
			 }
		break;
		
		case GPIO_PORTC:
		if(copy_value==GPIO_HIGH)
		{
			PORTC=0b11111111;
		}else{
			PORTC=0b00000000;
		}
		break;
		case GPIO_PORTD:
		     if(copy_value==GPIO_HIGH)
			 {
				 PORTD=0b11111111;
			 }else{
				 PORTD=0b00000000;
			 }
		break;
		default: asm("NOP");
	}
}
void SetPinValue(u8 copy_port,u8 copy_pin,u8 copy_value)
{
	switch (copy_port)
	{
		case GPIO_PORTA:
		if(copy_value==GPIO_HIGH)
		{
			SET_BIT(PORTA,copy_pin);
		}else{
			CLR_BIT(PORTA,copy_pin);
		}
		break;
		case GPIO_PORTB:
		if(copy_value==GPIO_HIGH)
		{
			SET_BIT(PORTB,copy_pin);
		}else{
			CLR_BIT(PORTB,copy_pin);
		}
		break;
		case GPIO_PORTC:
		if(copy_value==GPIO_HIGH)
		{
			SET_BIT(PORTC,copy_pin);
		}else{
			CLR_BIT(PORTC,copy_pin);
		}
		break;
		case GPIO_PORTD:
		if(copy_value==GPIO_HIGH)
		{
			SET_BIT(PORTD,copy_pin);
		}else{
			CLR_BIT(PORTD,copy_pin);
		}
		break;
		default: asm("NOP");
	}
}

u8 GetPortValue(u8 copy_port)
{
	u8 local_result=0;
	switch(copy_port)
	{
		case GPIO_PORTA:
		  local_result=PINA;
		break;
		case GPIO_PORTB:
		  local_result=PINB;
		break;
		case GPIO_PORTC:
		  local_result=PINC;
		break;
		case GPIO_PORTD:
		  local_result=PIND;
		break;
		default: asm("NOP");
	}
	return local_result;
}
u8 GetPinValue(u8 copy_port,u8 copy_pin)
{
	u8 local_result=0;
	switch(copy_port)
	{
		case GPIO_PORTA:
		  local_result=GET_BIT(PINA,copy_pin);
		break;
		case GPIO_PORTB:
		  local_result=GET_BIT(PINB,copy_pin);
		break;
		case GPIO_PORTC:
		  local_result=GET_BIT(PINC,copy_pin);
		break;
		case GPIO_PORTD:
		  local_result=GET_BIT(PIND,copy_pin);
		break;
		default: asm("NOP");
	}
	return local_result;
}

void TogPort(u8 copy_port)
{
	switch (copy_port)
	{
		case GPIO_PORTA:
		  PORTA ^= 0xff;
		break;
		case GPIO_PORTB:
		  PORTB ^= 0xff;
		break;
		case GPIO_PORTC:
		  PORTC ^= 0xff;
		break;
		case GPIO_PORTD:
		  PORTD ^= 0xff;
		break;
		default: asm("NOP");
	}
}
void TogPin(u8 copy_port,u8 copy_pin)
{
	switch (copy_port)
	{
		case GPIO_PORTA:
		  TOG_BIT(PORTA,copy_pin);
		break;
		case GPIO_PORTB:
		  TOG_BIT(PORTB,copy_pin);
		break;
		case GPIO_PORTC:
		  TOG_BIT(PORTC,copy_pin);
		break;
		case GPIO_PORTD:
		  TOG_BIT(PORTD,copy_pin);
		break;
		default: asm("NOP");
	}
}

void ConfigPullUpPort(u8 copy_port,u8 copy_pullup_value)
{
	switch (copy_port)
	{
		case GPIO_PORTA:
		if(copy_pullup_value==GPIO_PULLUP)
		{
			PORTA = 0xff;
		}else
		{
			PORTA = 0x00;
		}
		  
		break;
		case GPIO_PORTB:
		  if(copy_pullup_value==GPIO_PULLUP)
		{
			PORTB = 0xff;
		}else
		{
			PORTB = 0x00;
		}
		break;
		case GPIO_PORTC:
		  if(copy_pullup_value==GPIO_PULLUP)
		{
			PORTC = 0xff;
		}else
		{
			PORTC = 0x00;
		}
		break;
		case GPIO_PORTD:
		  if(copy_pullup_value==GPIO_PULLUP)
		{
			PORTD = 0xff;
		}else
		{
			PORTD = 0x00;
		}
		break;
		default: asm("NOP");
	}
}
void ConfigPullUpPin(u8 copy_port,u8 copy_pin,u8 copy_pullup_value)
{
	switch (copy_port)
	{
		case GPIO_PORTA:
		if(copy_pullup_value==GPIO_PULLUP)
		{
			SET_BIT(PORTA,copy_pin);
		}else
		{
			CLR_BIT(PORTA,copy_pin);
		}
		  
		break;
		case GPIO_PORTB:
		  if(copy_pullup_value==GPIO_PULLUP)
		{
			SET_BIT(PORTB,copy_pin);
		}else
		{
			CLR_BIT(PORTB,copy_pin);
		}
		break;
		case GPIO_PORTC:
		  if(copy_pullup_value==GPIO_PULLUP)
		{
			SET_BIT(PORTC,copy_pin);
		}else
		{
			CLR_BIT(PORTC,copy_pin);
		}
		break;
		case GPIO_PORTD:
		  if(copy_pullup_value==GPIO_PULLUP)
		{
			SET_BIT(PORTD,copy_pin);
		}else
		{
			CLR_BIT(PORTD,copy_pin);
		}
		break;
		default: asm("NOP");
	}
}