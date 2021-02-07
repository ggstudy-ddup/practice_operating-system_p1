#include <types.h>

#ifndef __INCLUDE_MACHINE_H__
#define __INCLUDE_MACHINE_H__

/* write a byte out, to the port */
inline void outb(word port, byte val)
{
    asm volatile ("outb %1, %0" : : "dN" (port), "a" (val));
}

/* read a byte in, from the port */
inline byte inb(word port)
{
    byte ret;
    asm volatile ("inb %1, %0" : "=a" (ret) : "dN" (port));
    return ret;
}

#endif  /* !__INCLUDE_MACHINE_H__ */

