ROOT = ../..

CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
SIZE = arm-none-eabi-size

BUILD = build
TARGET = $(BUILD)/firmware

CPU = -mcpu=cortex-m4 -mthumb

CFLAGS = $(CPU) \
         -std=c11 \
         -Wall \
         -Wextra \
         -O0 \
         -g3 \
         -ffreestanding \
         -ffunction-sections \
         -fdata-sections \
         -I$(ROOT)/common/stm32f407/registers

LDFLAGS = $(CPU) \
          -T$(ROOT)/common/stm32f407/linker/stm32f407vg.ld \
          -nostdlib \
          -Wl,--gc-sections \
          -Wl,-Map=$(BUILD)/firmware.map

LIBS = -lgcc

all: $(TARGET).elf $(TARGET).hex $(TARGET).bin
	$(SIZE) $(TARGET).elf

$(BUILD):
	mkdir -p $(BUILD)

$(BUILD)/main.o: src/main.c | $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD)/startup.o: $(ROOT)/common/stm32f407/startup/startup.S | $(BUILD)
	$(CC) $(CPU) -g3 -c $< -o $@

$(TARGET).elf: $(BUILD)/main.o $(BUILD)/startup.o
	$(CC) $(LDFLAGS) $^ $(LIBS) -o $@

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex $< $@

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@

flash: $(TARGET).elf
	openocd -f board/stm32f4discovery.cfg \
	        -c "program $(TARGET).elf verify reset exit"

clean:
	rm -rf $(BUILD)

.PHONY: all clean flash