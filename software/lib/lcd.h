#define LCD_DATA PORTC
#define ctrl PORTB
#define rs PINB7
#define rw PINB6
#define en PINB5

#include <avr/io.h>
#include <util/delay.h>

void LCD_cmd(unsigned char);
void LCD_init(); //funkcja inicjująca ekran
void LCD_write(unsigned char); //funkcja odpowiadająca za 
void LCD_write_string(unsigned char); //funkcja odpowiadająca za wyświetlanie stringów na ekranie
void LCD_gotoxy(int, int); //funkcja odpowiadająca za ustawienie "kursora" na ekranie 
void LCD_clear(); //funkcja czyszcząca ekran