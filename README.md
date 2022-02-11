# Jakub Malik
# Projekt na laboratorium Techniki mikroprocesorowej

# Temat projektu
W ramach tego projektu zamierzam zbudować i zaprogramować system bezpieczeństwa oparty na tokenach RFID. Układ będzie decydował o udzieleniu dostępu (otwarciu np. drzwi) na podstawie zastosowanej przez użytkownika karcie bądź breloku RFID. Konstrukcja zostanie wykonana w oparciu o mikrokontroler ATMega 32A-PU.

# Lista elementów
**Hardware:** ATMega 32A-PU, programator AVR, wyświetlacz LCD 16x2, moduł RFID RC522, karta oraz brelok RFID, zasilanie 5V, przewody, płytka prototypowa, kondensatory 100u oraz 100n, diody LED, rezystory 10k \
**Software:** Visual Studio Code

# Dlaczego ATMega32A-PU
Mój wybór padł na ten konkretny mikrokontroler, ponieważ w opinii wielu, ukontrolery produkowane przez firmę Atmel są świetnym rozwiązaniem na początek przygody z programowaniem. W internecie znajdziemy olbrzymią liczbę opracowań różnych problemów i rozwiązań na jakie możemy się natknąć w trakcie pracy z ukontrolerem.

# Dlaczego moduł RFID RC522
Głównym powodem wyboru tego konkretnego modułu była moja styczność z nim w trakcie realizacji poprzednich projektów. Układ jest stosunkowo łatwy w obsłudze, tani oraz posiada na start, w zestawie, kartę oraz brelok RFID. Płytka umożliwia odczyt i zapis danych z urządzeń RFID na częstotliwości 13,56 MHz, oparty jest o popularny układ RC522, posiada wbudowaną antenę, a zasilany jest napięciem 3,3V.

# Wymagane połaczenia
## ATMega32A ⟶ RFID RC522
- `PB4` ⟶ `SDA/SS`
- `PB5` ⟶ `MOSI`
- `PB6` ⟶ `MISO`
- `PB7` ⟶ `SCK`
\
Wyprowadzenie `IRQ` modułu `RFID RC522` nie jest połączone, natomiast `GND` ⟶ `GND`, `RST` ⟶ `+3.3V`, `3.3V` ⟶ `+3.3V`

## ATMega32A ⟶ LCD
- `PA0` ⟶ `RS`
- `PA1` ⟶ `RW`
- `PA2` ⟶ `E`
- `PA4` ⟶ `D4`
- `PA5` ⟶ `D5`
- `PA6` ⟶ `D6`
- `PA7` ⟶ `D7`
\
Pin `1` wyświetlacza połączono z `GND`, natomiast `3` z `+5V`.

```cpp
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