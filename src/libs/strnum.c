#include <strnum.h>
#include <string.h>

int
itoa(int num, char * buffer)
{
    char buf[12];
    buf[11] = NULL;
    BOOL sign = FALSE;
    if (num < 0)
    {
        num = -num;
        sign = TRUE;    /* sign of negative */
    }
    int i = 10;
    for (; num; i--)
    {
        buf[i] = (char)(num % 10 + '0');
        num /= 10;
    }
    if (sign) buf[i--] = '-';
    memcpy(buffer, buf + i + 1, 12 - i - 1);
    return 12 - i - 2;
}

