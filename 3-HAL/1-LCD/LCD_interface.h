#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H



void LCD_init(void);
void LCD_WriteCommand(u8 copy_command);
void LCD_WriteData(u8 copy_data);
void LCD_WriteString(u8* string);
void LCD_WriteNum(u32 num);
void LCD_Clear(void);
void LCD_GoToXY(u8 row, u8 col);







#endif