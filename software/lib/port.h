#ifndef PORTX_H_
#define PORTX_H_
#include <stdbool.h>
#include <stdint.h>

//---------------------------------------------------------------------------------------------------------------------

#define	SPI_CS 2
#define SPI_MOSI 3
#define SPI_MISO 4
#define	SPI_SCK 5

//---------------------------------------------------------------------------------------------------------------------

void PORT_Init();
void PORT_Stop();
void PORT_Start();
void SEG7_Sign(uint8_t position, uint8_t sign, bool dot);
void SEG7_Int(int16_t value);

//---------------------------------------------------------------------------------------------------------------------

extern volatile uint8_t PORTX, PINX, PORTY[4];

//---------------------------------------------------------------------------------------------------------------------
#endif