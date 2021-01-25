#ifndef __INCLUDE_DEFINE_H__
#define __INCLUDE_DEFINE_H__

#define M32 1

/* arch 32 bits */
#ifdef M32
#define TRUE (1)
#define FALSE (0)
/* quick types */
typedef unsigned char uchar, u8, byte;
typedef unsigned short ushort, u16, word;
typedef unsigned int uint, u32, dword;
/* other types */
typedef unsigned int size_t;
#define BOOL int
#endif /* M32 */


/*
 * Common defines
 */
/* normal values */
#define NULL ((void*)(0))
#define NULLPTR ((void*)0)
/* args */
typedef byte *va_list;
#define va_start(p, first) (p = (va_list)&first + sizeof(first))
#define va_arg(p, type) (*(type*)((p += sizeof(type)) - sizeof(type)))
#define va_end(p)

#endif /* !__INCLUDE_DEFINE_H__ */

