#include <machine.h>

inline void
outb(word port, byte val)
{
    asm volatile ("outb %1, %0" : : "dN" (port), "a" (val));
}

inline byte
inb(word port)
{
    byte ret;
    asm volatile ("inb %1, %0" : "=a" (ret) : "dN" (port));
    return ret;
}

