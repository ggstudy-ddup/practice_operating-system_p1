#ifndef __INCLUDE_DEFINE_H__
#define __INCLUDE_DEFINE_H__

#define M32 1
#ifdef M32

/* normal values */
#define NULL 0
#define NULLPTR 0

#define TRUE 1
#define FALSE 0

/* quick types */
typedef unsigned char uchar, u8, byte;
typedef unsigned short ushort, u16, word;
typedef unsigned int uint, u32, dword;

/* other types */
typedef unsigned int size_t;
#define BOOL int

/* args */
typedef byte *va_list;
#define va_start(p, first) (p = (va_list)&first + sizeof(first))
#define va_arg(p, type) (*(type*)((p += sizeof(type)) - sizeof(type)))
#define va_end(p)

#endif /* M32 */

#endif /* !__INCLUDE_DEFINE_H__ */

