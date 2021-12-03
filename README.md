# AVR Template Project
###### tags: `AVR`
使用stm32f303ze完成的專案，並實作printf及scanf功能

## 檔案編排
> ARM-Template-Project
>> Inc
>>> myusart.h

>> Src
>>> main.c 
>>> myusart.c

>> Makefile
>> README.md

## 使用設備
- Ardiono UNO R3
  ![](https://i.imgur.com/AZhx57D.png)
  CPU為 Atmega328p
  
- 需要工具
  1. [avr-gcc](https://blog.zakkemble.net/avr-gcc-builds/)

  2. avrdude

## 目標: 使板子可以使用 printf() 及 scanf() 函式
### USART設定
- 使用USART0
  - F_CLK:           16MHz
  - USART0_Mode:     Tx/Rx Enable
  - USART0_Parity:   Parity disable
  - USART0_StopBits: 1
  - USART0_WordLen:  8
  - USART0_Baud:     9600
  - USART0_HW_FLOW:  None

## 結果(在putty上顯示)
  ![](https://i.imgur.com/EfIvBQZ.png)

