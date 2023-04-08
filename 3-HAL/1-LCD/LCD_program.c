#include "../../1-LIB/STD_TYPES.h"
#include "../../1-LIB/BIT_MATH.h"
#include "../../1-LIB/delay/delay_interface.h"
#include "../../2-MCAL/1-GPIO/GPIO_interface.h"
#include "LCD_interface.h"
#include "LCD_config.h"


void LCD_WriteCommand(u8 copy_command)
{
	SetPinValue(RS,GPIO_LOW);
	SetPinValue(RW,GPIO_LOW);
	
	SetPinValue(DB7,GET_BIT(copy_command,7));
	SetPinValue(DB6,GET_BIT(copy_command,6));
	SetPinValue(DB5,GET_BIT(copy_command,5));
	SetPinValue(DB4,GET_BIT(copy_command,4));
	SetPinValue(E,GPIO_HIGH);
	Delay_ms(2);
	SetPinValue(E,GPIO_LOW);
	Delay_ms(2);
	SetPinValue(DB7,GET_BIT(copy_command,3));
	SetPinValue(DB6,GET_BIT(copy_command,2));
	SetPinValue(DB5,GET_BIT(copy_command,1));
	SetPinValue(DB4,GET_BIT(copy_command,0));
	SetPinValue(E,GPIO_HIGH);
	Delay_ms(2);
	SetPinValue(E,GPIO_LOW);
	Delay_ms(2);
}
void LCD_WriteData(u8 copy_data)
{
	SetPinValue(RS,GPIO_HIGH);
	SetPinValue(RW,GPIO_LOW);
	
	SetPinValue(DB7,GET_BIT(copy_data,7));
	SetPinValue(DB6,GET_BIT(copy_data,6));
	SetPinValue(DB5,GET_BIT(copy_data,5));
	SetPinValue(DB4,GET_BIT(copy_data,4));
	SetPinValue(E,GPIO_HIGH);
	Delay_ms(2);
	SetPinValue(E,GPIO_LOW);
	Delay_ms(2);
	SetPinValue(DB7,GET_BIT(copy_data,3));
	SetPinValue(DB6,GET_BIT(copy_data,2));
	SetPinValue(DB5,GET_BIT(copy_data,1));
	SetPinValue(DB4,GET_BIT(copy_data,0));
	SetPinValue(E,GPIO_HIGH);
	Delay_ms(2);
	SetPinValue(E,GPIO_LOW);
	Delay_ms(2);
}
void LCD_init(void)
{
	SetPortDirection(GPIO_PORT_cfg,GPIO_OUTPUT);
	SetPinValue(E,GPIO_LOW);
	LCD_WriteCommand(0x33);
	LCD_WriteCommand(0x32);
	LCD_WriteCommand(0x28);
	LCD_WriteCommand(0x0e);
	LCD_WriteCommand(0x01);
	Delay_us(2000);
	LCD_WriteCommand(0x06);
	
}
void LCD_WriteString(u8* string)
{
	
	while(*string != '\0')
	{
		LCD_WriteData(*string++);
	}
}
void LCD_WriteNum(u32 num)
{

		u32 rem = 0;
		u8 arr [17];
		s8 i = 0;
		while(num != 0)
		{
			rem = num % 10;
			arr[i] = rem + 48;
			i++;
			num = num / 10;
		}
		i--;
		while(i > -1)
		{
			LCD_WriteData(arr[i]);
			i--;
		}

	
}
void LCD_Clear(void)
{
	LCD_WriteCommand(0x01);
}

void LCD_GoToXY(u8 row, u8 col)
{
	if (row ==0)
	{
		LCD_WriteCommand(0x80 +col );
	}
	else if (row==1)
	{
		LCD_WriteCommand(0x80 + 0x40 +col );
	}
	else if(row == 2)
	{
		LCD_WriteCommand(0x80 + 0x14 +col );
	}
	else if(row == 3)
	{
		LCD_WriteCommand(0x80 + 0x54 +col );
	}
	

}
