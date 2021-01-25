#include <io/screen.h>

int
sprintf(char * buf, char * format, ...)
{
    va_list list;
    va_start(list, format);
    int count = 0;
    while (*format)
    {
        if ('%'  == *format)
        {
            ++format;
            switch (*format)
            {
            case 'x':
                count += itoa(va_arg(list, int), buf + count);
                break;
            default:
                break;
            }
        }
        else
            *(char*)(buf + count++) = *format;
        ++format;
    }
    va_end(list);
    return count;
}

