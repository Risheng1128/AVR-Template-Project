# ------------------------------------------------
# Generic Makefile
# 
# Author: Ri-Sheng Chen
# ------------------------------------------------

PORT = 3 # arduino uno
TARGET = main
SRC = $(wildcard ./Src/*.c)
INC = -IInc
SRCOBJ = $(patsubst %.c, %.o,$(SRC))
DEVICE = atmega328p
BAUD = 115200
LINKER = -Wl,-u,vfprintf -Wl,--start-group -Wl,-lm -Wl,-lprintf_flt -Wl,-lscanf_flt -Wl,--end-group -Wl,--gc-sections -mrelax -Wl,-u,vfscanf
CC = avr-gcc $(INC) -Wall -Os -mmcu=$(DEVICE) $(LINKER)
BUILD = Debug

all: $(BUILD) $(TARGET)
$(BUILD):
	mkdir $@

$(TARGET): $(SRCOBJ)
	$(CC) -o $(BUILD)/$@.elf $^
	avr-objcopy -j .text -j .data -O ihex $(BUILD)/$@.elf $(BUILD)/$@.hex
	avr-size --format=avr --mcu=$(DEVICE) $(BUILD)/$@.elf

%.o: %.c
	$(CC) -c $< -o $@

.PHONY: clean terminal upload
upload:
	avrdude -v -p $(DEVICE) -c arduino -P COM$(PORT) -b $(BAUD) -U flash:w:$(BUILD)/$(TARGET).hex

terminal:
	putty -serial COM$(PORT) -sercfg 9600,8,1,n,N

clean:
	@rm -r $(BUILD)
	@rm ./Src/*.o