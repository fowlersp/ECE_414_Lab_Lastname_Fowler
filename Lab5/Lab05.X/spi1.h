/* 
 * File:   spi1.h
 * Author: sonkinj
 *
 * Created on October 6, 2022, 8:19 AM
 */

#ifndef SPI1_H
#define	SPI1_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* SPI1_H */

#include "plib.h"
#include <inttypes.h>

void SpiInit(uint32_t baudRate);
uint32_t setBaudRate(uint32_t baudRate);
uint8_t RxSPIReadRdy();
uint8_t TxSPIWriteRdy();
void SPI_txWrite(char c);
void SPI_txWrite_str(char *cp);








