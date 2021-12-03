/**
  ******************************************************************************
  * @file    myusart.c
  * @author  Ri-Sheng Chen
  * @brief   This file contains USART functions
  ******************************************************************************
  */

#include "../Inc/myusart.h"

static FILE STDIO_BUFFER = FDEV_SETUP_STREAM(stdio_putchar, stdio_getchar, _FDEV_SETUP_RW);
/* From Atmega328 datasheet p.150, Sending Frames with 5 to 8 Data Bit */
void stdio_putchar(uint8_t TxData, FILE *stream) 
{
	/* When send a '\n', need to send a '\r' */
    if (TxData == '\n') 
        stdio_putchar('\r',stream); 
	/* Wait for empty transmit buffer */
    while(!(UCSR0A & (1 << UDRE0))); 
	/* Put data into buffer, sends the data */
    UDR0 = TxData;
}

/* From Atmega328p datasheet p.152, Receiving Frames with 5 to 8 Data Bits */
uint8_t stdio_getchar(FILE *stream)
{
	uint8_t RxData;
	/* Wait for data to be received */
    while(!(UCSR0A & (1 << RXC0)));
	/* Get received data from buffer */
	RxData = UDR0;
	/* Send the data which is received */
	stdio_putchar(RxData,stream);
	if(RxData == '\r')	/* Receive ENTER, send '\n' */
		stdio_putchar('\n',stream);

	return RxData;
}

/* From Atmega328p datasheet p.149, USART initialization */
void USART_Init(void) 
{
	/* Asynchronous Normal Mode */
	/* From Atmega328p datasheet p.146 */
	UBRR0H = (uint32_t)(MYUBRR >> 8);
	UBRR0L = (uint32_t)MYUBRR;
	/* Rx Enable, Tx Enable */
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);
	/* Character Size : 8-bit */
	/* Stop Bit: 1 bit */
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
	/* 指定printf、scanf使用的暫存區 */
	stdout = &STDIO_BUFFER;
	stdin = &STDIO_BUFFER;
}
