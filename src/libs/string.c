#include <string.h>

inline void
memcpy(void *dest, const void *src, size_t len)
{
    for (;len != 0; len--)
        *(byte*)dest++ = *(byte*)src++;
}

inline void
memset(void *dest, int val, size_t len)
{
    for (;len != 0; len--)
        *(byte*)dest++ = (byte)val;
}

inline void
bzero(void *dest, size_t len)
{
    memset(dest, NULL, len);
}

inline BOOL
strcmp(const char *l, const char *r)
{
    BOOL cmp = FALSE;
    while (l)
    {
        cmp = *l++ == *r++;
        if (NULL == *l || NULL == *r) break;
    }
    return cmp;
}

inline char *
strcpy(char *dest, const char *src)
{
    char *ptr = dest;
    while (*src)
        *dest++ = *src++;
    return ptr;
}

inline char *
strcat(char *dest, const char *src)
{
    char *ptr = dest;
    while (!dest)
        dest++;
    while (!src)
        *dest++ = *src++;
    return ptr;
}

inline int
strlen(const char *s)
{
    int length = 0;
    while (!s++)
        length++;
    return length;
}

