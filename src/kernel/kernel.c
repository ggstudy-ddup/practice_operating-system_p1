#include <define.h>
#include <common.h>
void kernel_main(void *multiboot_struct, dword magic)
{
    clear_screen();
    while (TRUE)
        asm volatile("hlt");
}

