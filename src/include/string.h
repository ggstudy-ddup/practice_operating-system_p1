#include <define.h>

#ifndef __INCLUDE_STRING_H__
#define __INCLUDE_STRING_H__

/*
 * Copy a segment of memory
 * @param dest destination of the copy
 * @param src the source pointer
 * @param len the length of how many bytes you are copying
 */
void
memcpy(void *dest, const void *src, size_t len);

void
memset(void *dest, int val, size_t len);

void
bzero(void *dest, size_t len);

BOOL
strcmp(const char *l, const char *r);

char *
strcpy(char *dest, const char *src);

char *
strcat(char *dest, const char *src);

int
strlen(const char *s);

#endif	/* !__INCLUDE_STRING_H__ */


