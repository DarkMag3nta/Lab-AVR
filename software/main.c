#include "main.h"
#include <avr/io.h>
#include <util/delay.h>
#include "lib/uart.h"
#include "lib/rfid522.h"
#include "lib/spi.h"
#include "lib/lcd.h"
#include "lib/adc.h"
#include "lib/port.h"
#include "lib/pwm.h"

uint8_t SelfTestBuffer[64];

int main(void)
{
  uint8_t byte;
  uint8_t str[MAX_LEN];
  _delay_ms(50);
  LCD_init();
  LCD_gotoxy(1, 1);
  LCD_write_string("Projekt TM");
  LCD_gotoxy(2, 9);
  LCD_write_string("Jakub Malik");

  spi_init();
  _delay_ms(1500);
  LCD_clear();
  _delay_ms(1500);
  LCD_gotoxy(1, 1);
  LCD_write_string("SPI Init done");
  _delay_ms(1500);

  mfrc522_init();
  byte = 0x55;
  _delay_ms(1500);
  byte = mfrc522_read(VersionReg);
  _delay_ms(1500);

  if (byte == 0x92)
  {
    LCD_clear();
    LCD_gotoxy(1, 1);
    LCD_write_string("RC522v2");
    LCD_gotoxy(2, 9);
    LCD_write_string("Wykryto");    
  }else if (byte == 0x91 || byte == 0x90)
  {
    LCD_clear();
    LCD_gotoxy(1, 1);
    LCD_write_string("RC522v1");
    LCD_gotoxy(2, 9);
    LCD_write_string("Wykryto");
  }else
  {
    LCD_clear();
    LCD_gotoxy(1, 1);
    LCD_write_string("Nie wykryto");
  }

  byte = mfrc522_read(ComIEnReg);
  mfrc522_write(ComIEnReg, byte|0x20);
  byte = mfrc522_read(DivIEnReg);
  mfrc522_write(DivIEnReg, byte|0x80);

  _delay_ms(1500);
  LCD_clear();
  
    
  while (1)
  {
    byte = mfrc522_request(PICC_REQALL, str);
    _delay_ms(1000);
  }
}