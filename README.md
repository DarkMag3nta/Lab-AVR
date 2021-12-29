# Jakub Malik
# Projekt na laboratorium Techniki mikroprocesorowej

## Temat projektu
W ramach tego projektu zamierzam zbudować i zaprogramować system bezpieczeństwa oparty na tokenach RFID. Układ będzie decydował o udzieleniu dostępu (otwarciu np. drzwi) na podstawie zastosowanej przez użytkownika karcie bądź breloku RFID. Konstrukcja zostanie wykonana w oparciu o mikrokontroler ATMega 32A-PU.

## Lista elementów
**Hardware:** ATMega 32A-PU, programator AVR, wyświetlacz LCD 16x2, moduł RFID RC522, karta oraz brelok RFID, zasilanie 5V, przewody, płytka prototypowa a/
**Software:** Visual Studio Code

## Dlaczego ATMega32A-PU
Mój wybór padł na ten konkretny mikrokontroler, ponieważ w opinii wielu, ukontrolery produkowane przez firmę Atmel są świetnym rozwiązaniem na początek przygody z programowaniem. W internecie znajdziemy olbrzymią liczbę opracowań różnych problemów i rozwiązań na jakie możemy się natknąć w trakcie pracy z ukontrolerem.

## Dlaczego moduł RFID RC522
Głównym powodem wyboru tego konkretnego modułu była moja styczność z nim w trakcie realizacji poprzednich projektów. Układ jest stosunkowo łatwy w obsłudze, tani oraz posiada na start, w zestawie, kartę oraz brelok RFID. Płytka umożliwia odczyt i zapis danych z urządzeń RFID na częstotliwości 13,56 MHz, oparty jest o popularny układ RC522, posiada wbudowaną antenę, a zasilany jest napięciem 3,3V.