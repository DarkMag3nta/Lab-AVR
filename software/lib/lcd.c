#include "main.h"
#include "lcd.h"

void LCD_cmd(unsigned char cmd)
{
  LCD_DATA = cmd;
  _delay_ms(1);
  ctrl = (0<<rs)|(0<<rw)|(1<<en);
  _delay_ms(1);
  ctrl = (0<<rs)|(0<<rw)|(0<<en);
  _delay_ms(10);
}

void LCD_init()
{
  LCD_cmd(0x38);
  _delay_ms(1);
  LCD_cmd(0x01);
  _delay_ms(1);
  LCD_cmd(0x0E);
  _delay_ms(1);
  LCD_cmd(0x80);
  _delay_ms(1);
}

void LCD_write(unsigned char data)
{
  LCD_DATA = data;
  ctrl = (1<<rs)|(0<<rw)|(1<<en);
  _delay_ms(1);
  ctrl = (1<<rs)|(0<<rw)|(0<<en);
  _delay_ms(10);
}

void LCD_write_string(unsigned char data)
{
  int n = 0;
  while (data[n])
  {
    LCD_write(data[n]);
    n++;
    if (n == 16)
    {
      LCD_cmd(0xC0);
    }    
  }  
}

void LCD_gotoxy(int x, int y)
{
  if(x == 1)
  {
    LCD_cmd(0x80);
    for (int i = 1; i < y; i++)
    {
      LCD_cmd(0x06);
    }    
  }

  if (x == 2)
  {
    LCD_cmd(0xC0);
    for (int i = 1; i < y; i++)
    {
      LCD_cmd(0x06);
    }    
  }  
}

void LCD_clear()
{
  LCD_cmd(0x01);
}