#include "utils.h"
#include <stdarg.h>
#include <stdio.h>

#define STR_BUFSIZE     64

static char strbuf[STR_BUFSIZE + 1];    // String buffer

char *utilMkStr(const char *fmt, ...)
{
    char *buffer = strbuf;

    va_list args;
    va_start(args, fmt);
    vsprintf(buffer, fmt, args);
    va_end (args);

    return buffer;
}
