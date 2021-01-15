/*
 * common.h
 * defines some common functions needed for the incomplete OS
 *  
 */
#ifndef __INCLUDE_COMMON_H__
#define __INCLUDE_COMMON_H__

#include <define.h>

/* --- Video --- */

/* constants */
#define VID_MEM_BEG (word*)(0xB8000)
#define VID_YROWS  (25)
#define VID_XLINES (80)

typedef
enum real_colors
{
    black           = 0,
    blue            = 1,
    green           = 2,
    cyan            = 3,
    red             = 4,
    magenta         = 5,
    brown           = 6,
    grey            = 7,
    dark_grey       = 8,
    light_blue      = 9,
    light_green     = 10,
    light_cyan      = 11,
    light_red       = 12,
    light_magenta   = 13,
    light_brown     = 14,
    white           = 15
} TERM_COLOR;

/* clear the screen */
void clear_screen();

/* print a string */
void put_str(const char *s);

/* print a string with color */
void put_str_color(const char *s, int bc, int fc);

/* --- --- */

 #endif /* !__INCLUDE_COMMON_H__ */

