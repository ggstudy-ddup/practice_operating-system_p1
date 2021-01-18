/*
 * common.h
 * defines some common functions needed for the incomplete OS
 *  
 */
#ifndef __INCLUDE_COMMON_H__
#define __INCLUDE_COMMON_H__

#include <define.h>
#include <port.h>
#include <string.h>

/* --- Video --- */

/* constants */
#define VID_MEM_BEG (word*)(0xB8000)
#define VID_YMAX  (25)
#define VID_XMAX (80)

typedef
enum console_real_colors
{
    rc_black           = 0,
    rc_blue            = 1,
    rc_green           = 2,
    rc_cyan            = 3,
    rc_red             = 4,
    rc_magenta         = 5,
    rc_brown           = 6,
    rc_grey            = 7,
    rc_dark_grey       = 8,
    rc_light_blue      = 9,
    rc_light_green     = 10,
    rc_light_cyan      = 11,
    rc_light_red       = 12,
    rc_light_magenta   = 13,
    rc_light_brown     = 14,
    rc_white           = 15
} termrc;

/* set cursor position */
void set_cursor_pos();

/* scroll a line up */
void scroll_up();

/* clear the screen */
void clear_screen();

/* display a char */
void put_char(char c, int bg, int fc);

/* print a string */
void put_str(const char *s);

/* print a string with color */
void put_str_color(const char *s, int bc, int fc);

/* --- --- */

 #endif /* !__INCLUDE_COMMON_H__ */

