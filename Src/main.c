/**
  ******************************************************************************
  * @file    main.c
  * @author  Ri-Sheng Chen
  * @brief   This file is a test of Atmega328p 
  ******************************************************************************
  */
#include "myusart.h"

int main (void){
    USART_Init();
    
    int data;
    while(1){
        printf("please input a data\n");
        scanf("%d", &data);
        printf("data: %d\n", data);
    }
    return 0;
}