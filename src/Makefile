.PHONY: all
all: build
.PHONY: build
build: kernel.bin

C_DEBUG_FLAG = -ggdb -gstabs+

C = gcc
AS = as
LD = ld
C_FLAGS = -c -Wall -m32 -nostdinc -nostdlib -fno-builtin -fno-stack-protector \
			-I $(HOME)/include/ \
			$(C_DEBUG_FLAG)
AS_FLAGS = --32
LD_FLAGS = -T $(HOME)/scripts/linker.ld -m elf_i386 -nostdlib

HOME := $(shell pwd)
C_SRC := $(shell find . -name "*.c")
AS_SRC := $(shell find . -name "*.s")

C_OBJ := $(shell find $(HOME)/kernel -name "*.c")
C_OBJ += $(shell find $(HOME)/libs -name "*.c")
C_OBJ := $(C_OBJ:.c=.c.o)
AS_OBJ := $(shell find $(HOME)/kernel -name "*.s")
AS_OBJ := $(AS_OBJ:.s=.s.o)

$(C_OBJ): $(C_SRC)
	$(C) $(C_FLAGS) -o $@ -c $<

$(AS_OBJ): $(AS_SRC)
	$(AS) $(AS_FLAGS) -o $@ $<

kernel.bin: $(AS_OBJ) $(C_OBJ) $(HOME)/scripts/linker.ld 
	$(LD) $(LD_FLAGS) -o $@ $(AS_OBJ) $(C_OBJ)

../assets/floppy.img: ../assets/floppy.img

.PHONY: install
install: ../assets/floppy.img kernel.bin
	sudo mkdir -p /mnt/floppy
	sudo mount ../assets/floppy.img /mnt/floppy 
	sudo cp kernel.bin /mnt/floppy/kernel
	sudo umount /mnt/floppy

.PHONY: clean
clean:
	rm -f $(AS_OBJ)
	rm -f $(C_OBJ)

