#include <define.h>
#include <common.h>
void kernel_main(void *multiboot_struct, dword magic)
{
    clear_screen();
    put_str("Hello world, new OS!");
    
    /* Sleeping */
    asm volatile ("cli");
    while (TRUE)
        asm volatile ("hlt");
}

