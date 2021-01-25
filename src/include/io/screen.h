#ifndef __INCLUDE_IO_SCREEN_H__
#define __INCLUDE_IO_SCREEN_H__

#include <types.h>
#include <strnum.h>

#define PRINTK_BUF_SIZE ((int)(VID_XMAX * VID_YMAX))

/*
 * Do the process of string formatting
 * @param buf the output buffer
 * @param format the format str
 * @param list the variable parameter list
 * @ret the length of output str
 */
int sprintf(char * buf, cosnt char * format, va_list list);

/*
 * Print function for kernel
 * @param format the format str
 * @param ... 
 * @ret the length of print str
 */
int printk(const char * format, ...);

#endif /* !__INCLUDE_IO_SCREEN_H__ */
