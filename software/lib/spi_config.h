#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

#include <avr/io.h>


#define SPI_CONFIG_AS_MASTER 	1



#define SPI_DDR		DDRB
#define SPI_PORT	PORTB
#define SPI_PIN		PINC
#define SPI_MOSI	PC5
#define SPI_MISO	PC6
#define SPI_SS		PC4
#define SPI_SCK		PC7

#endif