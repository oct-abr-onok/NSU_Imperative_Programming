#include "pack.h"
#include <stdarg.h>
#include <stdio.h>

static int format_arg_cnt(const char *format)
{
    int n = 0;

    for (int i = 0; format[i] != 0; i++)
    {
        if (i > 0)
        {
            if (format[i] == '%' && format[i - 1] != 92)
            {
                n++;
            }
        }
        else
        {
            if (format[i] == '%')
            {
                n++;
            }
        }
    }

    return n;
}

int pack(char *buffer, const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int cnt = 0;
    char *str;
    int d_mem;
    double lf_mem;
    char *mem_loc;

    for (int i = 0; format[i] != 0; i++)
    {
        if ((i > 0 && format[i] == '%' && format[i - 1] != 92) || (format[i] == '%' && i == 0))
        {
            switch (format[i + 1])
            {
            case 'd':
                d_mem = va_arg(args, int);
                mem_loc = (char *)&d_mem;
                if (buffer != 0)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        buffer[cnt] = mem_loc[j];
                        cnt++;
                    }
                }
                else
                {
                    cnt += 4;
                }
                break;
            case 'l':
                lf_mem = va_arg(args, double);
                mem_loc = (char *)&lf_mem;
                if (buffer != 0)
                {
                    for (int j = 0; j < 8; j++)
                    {
                        buffer[cnt] = mem_loc[j];
                        cnt++;
                    }
                }
                else
                {
                    cnt += 8;
                }
                break;
            case 's':
                str = va_arg(args, char *);
                for (int j = 0; str[j] != 0; j++)
                {
                    if (buffer != 0)
                        buffer[cnt] = str[j];
                    cnt++;
                }
                if (buffer != 0)
                    buffer[cnt] = 0;
                cnt++;
                break;
            default:
                break;
            }
        }
    }

    va_end(args);
    return cnt;
}
