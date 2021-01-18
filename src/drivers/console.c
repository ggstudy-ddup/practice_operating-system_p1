#include <console.h>

/* cursor position */
static byte cursor_x = 0;
static byte cursor_y = 0;

void
set_cursor_pos()
{
    /* position in the video memory */
    word cursor_vidmem_pos = cursor_y * VID_XMAX + cursor_x;

    /* addr port:
     *  0x3D4
     * val port:
     *  0x3D5
     */
    /* cursor position low-register:
     *     15
     * cursor position high-register:
     *     14
     */

    /* cursor position lower byte */
    outb(0x3D4, 15);
    outb(0x3D5, cursor_vidmem_pos);
    /* cursor position higher byte */
    outb(0x3D4, 14);
    outb(0x3D5, cursor_vidmem_pos >> 8);
}

void
scroll_up()
{
    /* substitute the lines by their next lines */
    for (int i = 0; i < VID_YMAX - 1 /* without the last line */; i++)
    {
        memcpy(VID_MEM_BEG +                    /* Starting addr */
                    i                           /* line number */
                    * sizeof(word) * VID_XMAX,  /* offset bytes per line */
               VID_MEM_BEG + (i + 1) * sizeof(word) * VID_XMAX,
               sizeof(word) * VID_XMAX);        /* line len */
    }
    /* clear the last line */
    bzero(VID_MEM_BEG +                 /* Starting addr */
            (VID_YMAX - 1)              /* the last line */
            * sizeof(word) * VID_XMAX,  /* offset bytes per line */
          sizeof(word) * VID_XMAX);     /* line len */
    /* set the cursor */
    if (cursor_y)   /* cursor_y != 0 */
        cursor_y--; /* keep the cursor in the same ouput line */
}

void
clear_screen()
{
    /* video ptr position */
    word *vid_pos = VID_MEM_BEG;

    /* blank */
    byte attribute_byte = (0 << 4) | (15 & 0x0F);
    word blank = ' ' | (attribute_byte << 8);
    for (int i = 0; i < VID_YMAX * VID_XMAX; i++)
        *vid_pos++ = blank;

    /* set cursor to the very first position */
    cursor_x = cursor_y = 0;
    set_cursor_pos();
}

void
put_char(char c, int bg, int fg)
{
    word attribute = (word)(((byte)bg << 4) | ((byte)fg & 0x0F)) << 8;
    switch (c)
    {
    /* backspace */
    case 0x08:
        if (cursor_x) cursor_x--;
        break;
    /* tab */
    case 0x09:
        cursor_x += 8 - (cursor_x % 8);
        break;
    /* \r */
    case '\r':
        cursor_x = 0;
        break;
    /* linebreak */
    case '\n':
        cursor_x = 0;
        cursor_y++;
        break;
    /* normal char */
    case (0x20)...(0x7E):
        *(word*)(VID_MEM_BEG + cursor_y * VID_XMAX + cursor_x) = c | attribute;
        cursor_x++;
        break;
    default:
        break;
    }
    if (VID_XMAX <= cursor_x)
    {
        cursor_x = 0;
        cursor_y++;
    }
    if (VID_YMAX <= cursor_y)
        scroll_up();

    /* refresh the cursor position */
    set_cursor_pos();
}

void
put_str(const char *s)
{
    while (*s)
        put_char(*s++, rc_black, rc_white);
}

void
put_str_color(const char *s, int bc, int fc)
{
    while (*s)
        put_char(*s++, bc, fc);
}

