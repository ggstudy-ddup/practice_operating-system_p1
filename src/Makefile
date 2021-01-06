.PHONY: all
all: kernel.bin

C = i686-elf-gcc
AS = i686-elf-as
LD = i686-elf-ld
C_FLAGS = -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore \
			-I ./include/
AS_FLAGS = --32
LD_FLAGS = -melf_i386

OBJ = loader.o kernel.o

%.o : %.c
	$(C) $(C_FLAGS) -o $@ -c $<

%.o: %.s
	$(AS) $(AS_FLAGS) -o $@ $<

kernel.bin: linker.ld $(OBJ)
	$(LD) $(LD_FLAGS) -T $< -o $@ $(OBJ)

../assets/floppy.img: ../assets/floppy.img

.PHONY: install
install: ../assets/floppy.img kernel.bin
	sudo mkdir -p /mnt/floppy
	sudo mount ../assets/floppy.img /mnt/floppy 
	sudo cp kernel.bin /mnt/floppy/kernel
	sudo umount /mnt/floppy

.PHONY: clean
clean:
	rm -f *.o *.bin *.out

