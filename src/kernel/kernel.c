#include <types.h>
#include <drivers/console.h>
#include <io/screen.h>

void kernel_main(void *multiboot_struct, dword magic)
{
    clear_screen();
    put_str("0Hello world, new OS!\n");
    put_str_color("1Hello world, colorful new OS!\n", rc_green, rc_light_magenta);
    printk("print test!\n");
    for (int i = 0; i < 0xFF; i++)
    {
        printk("print test number 0x%x!\n", i);
    }

    /* uncomment if you want to test */

    /* put_str("I put 5 backspaces here.\b\b\b\b\b"); */

    /* put_str("The cursor should be at the beginning of the line!\r"); */

    /* put_str("T\the_tab_test\n");
     * put_str("Th\te_tab_test\n");
     * put_str("The\t_tab_test\n");
     * put_str("The_\ttab_test\n");
     * put_str("The_t\tab_test\n");
     * put_str("The_ta\tb_test\n");
     * put_str("The_tab\t_test\n");
     * put_str("The_tab_\ttest\n");
     * put_str("The_tab_t\test\n");
     * put_str("The_tab_te\tst\n");
     * put_str("The_tab_tes\tt\n");
     */

    /* while (TRUE)
     *    put_str("Testing the put_str function!\n");
     */

    /* Sleeping */
    asm volatile ("cli");
    while (TRUE)
        asm volatile ("hlt");
}

