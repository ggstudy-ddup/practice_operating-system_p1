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

int
uitox(int num, char * buffer)
{
    char buf[9];
    buf[8] = NULL;
    int i = 7;
    for (; num; i--)
    {
        buf[i] = (char)((num & 0x0000000F) + '0');
        buf[i] += buf[i] > '9' ? 39 : 0;
        num >>= 4;
    }
    memcpy(buffer, buf + i + 1, 9 - i - 1);
    return 9 - i - 2;
}
