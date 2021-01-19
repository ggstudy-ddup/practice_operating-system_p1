#include <define.h>
#include <drivers/console.h>
void kernel_main(void *multiboot_struct, dword magic)
{
    clear_screen();
    put_str("Hello world, new OS!\n");
    put_str_color("Hello world, colorful new OS!\n", rc_green, rc_light_magenta);

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

