#include <io/screen.h>

static char buffer[PRINTK_BUF_SIZE] = { 0 };

int
sprintf(char * buf, const char * format, va_list list)
{
    int count = 0;
    while (*format)
    {
        if ('%'  == *format)
        {
            ++format;
            switch (*format)
            {
            case 'x':
                count += uitox(va_arg(list, int), buf + count);
                break;
            default:
                break;
            }
        }
        else
            *(char*)(buf + count++) = *format;
        ++format;
    }
    return count;
}

int
printk(const char * format, ...)
{
    bzero(buffer, PRINTK_BUF_SIZE);
    /* start format process */
    va_list list;
    va_start(list, format);
    int count = sprintf(buffer, format, list);
    va_end(list);
    /* print the str */
    put_str(buffer);
    return count;
}
