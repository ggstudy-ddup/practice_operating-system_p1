#include <types.h>

#ifndef __INCLUDE_MACHINE_H__
#define __INCLUDE_MACHINE_H__

/* write a byte out, to the port */
void outb(word port, byte val);

/* read a byte in, from the port */
byte inb(word port);

#endif  /* !__INCLUDE_MACHINE_H__ */

