
CPP = g++
CPP_FLAGS = -m32
AS = as
AS_FLAGS = --32
LD = ld
LD_FLAGS = -melf_i386

OBJ = loader.o kernel.o

%.o : %.cpp
	$(CPP) $(CPP_FLAGS) -o $@ -c $<

%.o: %.s
	$(AS) $(AS_FLAGS) -o $@ $<

kernel.bin: linker.ld $(OBJ)
	$(LD) $(LD_FLAGS) -T $< -o $@ $(OBJ)

install: kernel.bin

