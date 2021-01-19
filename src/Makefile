.PHONY: all
all: build
.PHONY: build
build: kernel.bin

C_DEBUG_FLAG = -ggdb -gstabs+

C = gcc
AS = as
LD = ld
C_FLAGS = -c -Wall -m32 -nostdinc -nostdlib -fno-builtin -fno-stack-protector \
			-I $(H)/include/
AS_FLAGS = --32
LD_FLAGS = -T $(H)/scripts/linker.ld -m elf_i386 -nostdlib

H := $(shell pwd)

C_SRC := $(shell find $(H)/kernel -name "*.c")
C_SRC += $(shell find $(H)/libs -name "*.c")
C_SRC += $(shell find $(H)/drivers -name "*.c")
AS_SRC := $(shell find $(H)/kernel -name "*.s")

C_OBJ := $(C_SRC:.c=.c.o)
AS_OBJ := $(AS_SRC:.s=.s.o)

$(C_OBJ): $(C_SRC)
	$(C) $(C_FLAGS) -o $@ -c $(@:.c.o=.c)

$(AS_OBJ): $(AS_SRC)
	$(AS) $(AS_FLAGS) -o $@ $<

kernel.bin: $(AS_OBJ) $(C_OBJ) $(H)/scripts/linker.ld 
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
	rm -f $(H)/kernel.bin

