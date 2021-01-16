#include <common.h>

/* video ptr position */
static word *vid_pos = VID_MEM_BEG;

/* cursor position */
static byte cursor_x = 0;
static byte cursor_y = 0;

void
clear_screen()
{
    byte attribute_byte = (0 << 4) | (15 & 0x0F);
    word blank = ' ' | (attribute_byte << 8);
    for (int i = 0; i < VID_YROWS * VID_XLINES; i++)
        *vid_pos++ = blank;
    vid_pos = VID_MEM_BEG;
}

void
put_str(const char *s)
{
    byte attribute_byte = (0 << 4) | (15 & 0x0F);
    for (; *s; s++)
    {
        switch (*s)
        {
        default:
            *vid_pos++ = (word)(*s | (attribute_byte << 8));
        }
    }
}

void
put_str_color(const char *s, int bc, int fc);

