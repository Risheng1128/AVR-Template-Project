/**
  ******************************************************************************
  * @file    myusart.h
  * @author  Ri-Sheng Chen
  * @brief   This file contains UART setting functions definition
  ******************************************************************************
  */

#ifndef _MYUSART_H_
#define _MYUSART_H_

#include <stdio.h>
#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#define FOSC          16000000UL
#define USART_BAUD    9600
#define MYUBRR        FOSC/16/USART_BAUD - 1

/*  functions definition  */
void USART_Init(void);
void stdio_putchar(uint8_t TxData, FILE *stream);
uint8_t stdio_getchar(FILE *stream);

#endif /* end of _MYUSART_H_ */