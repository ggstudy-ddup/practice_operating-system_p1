.PHONY: all
all: kernel.bin

CPP = i686-elf-g++
AS = i686-elf-as
LD = i686-elf-ld
CPP_FLAGS = -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -I \
			./include/
AS_FLAGS = --32
LD_FLAGS = -melf_i386

OBJ = loader.o kernel.o

%.o : %.cpp
	$(CPP) $(CPP_FLAGS) -o $@ -c $<

%.o: %.s
	$(AS) $(AS_FLAGS) -o $@ $<

kernel.bin: linker.ld $(OBJ)
	$(LD) $(LD_FLAGS) -T $< -o $@ $(OBJ)

.PHONY: install
install: ../assets/floopy.img kernel.bin
	sudo mkdir -p /mnt/floopy
	sudo mount $< /mnt/floopy 
	cp kernel.bin /mnt/floopy/kernel
	sudo umount /mnt/floopy

.PHONY: clean
clean:
	rm -f *.o *.bin *.out

