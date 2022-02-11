#ifndef SPI_H
#define SPI_H

#include "spi_config.h"
#include <stdint.h>

void spi_init();                        // spi.c linia 8
uint8_t spi_transmit(uint8_t data);     // spi.c linia 15

#define ENABLE_CHIP() (SPI_PORT &= (~(1<<SPI_SS)))
#define DISABLE_CHIP() (SPI_PORT |= (1<<SPI_SS))


#endif