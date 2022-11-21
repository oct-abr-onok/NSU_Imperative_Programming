#include "logger.h"
#include <stdarg.h>

int log_lever = 0;
static FILE *log_file;
int log_cnt = 0;

void logSetFile(FILE *file)
{
    if (file != 0)
    {
        log_lever = 1;
        log_file = file;
    }
    else
    {
        log_lever = 0;
    }
}

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

void logPrintf(const char *format, ...)
{
    if (log_lever)
    {
        va_list args;
        va_start(args, format);
        vfprintf(log_file, format, args);
        log_cnt++;
        va_end(args);
    }
}

int getLogCallsCount()
{
    return log_cnt;
}
