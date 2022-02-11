#ifndef MFRC522_H
#define MFRC522_H

#include <stdint.h>
#include "rfid522_cmd.h"
#include "rfid522_reg.h"

#define CARD_FOUND		1
#define CARD_NOT_FOUND	2
#define ERROR			3

#define MAX_LEN			16

//Rodzaje kart
#define Mifare_UltraLight 	0x4400
#define Mifare_One_S50		0x0400
#define Mifare_One_S70		0x0200
#define Mifare_Pro_X		0x0800
#define Mifare_DESFire		0x4403

// Mifare_One
# define PICC_REQIDL          0x26               // znajduje antenę nie będącą w stanie hibernacji
# define PICC_REQALL          0x52               // znajduje wszystkie anteny kart
# define PICC_ANTICOLL        0x93               // antykolizja
# define PICC_SElECTTAG       0x93               // wybór karty
# define PICC_AUTHENT1A       0x60               // autoryzacja karty A
# define PICC_AUTHENT1B       0x61               // autoryzacja karty B
# define PICC_READ            0x30               // blok odczytu
# define PICC_WRITE           0xA0               // blok zapisu
# define PICC_DECREMENT       0xC0               // obciążenie
# define PICC_INCREMENT       0xC1               // ładowanie
# define PICC_RESTORE         0xC2               // przesył danych bloku do bufora
# define PICC_TRANSFER        0xB0               // zapis danych w buforze
# define PICC_HALT            0x50               // uśpienie

void mfrc522_init();
void mfrc522_reset();
void mfrc522_write(uint8_t reg, uint8_t data);
uint8_t mfrc522_read(uint8_t reg);
uint8_t	mfrc522_request(uint8_t req_mode, uint8_t * tag_type);
uint8_t mfrc522_to_card(uint8_t cmd, uint8_t *send_data, uint8_t send_data_len, uint8_t *back_data, uint32_t *back_data_len);

#endif