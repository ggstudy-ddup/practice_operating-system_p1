#include "define.h"

static word *video_mem_ptr = (word*) 0x68000;
void printf(char *str)
{
    for (dword i = 0; str[i]; i++)
        video_mem_ptr[i] = (0xFF00 & video_mem_ptr[i]) | str[i];
}

extern "C" void kernel_main(void *multiboot_struct, dword magic)
{
    printf("Hello world!");
	while(1);
}

