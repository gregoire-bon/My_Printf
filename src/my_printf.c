/*
** EPITECH PROJECT, 2025
** cpoolday_myprintf
** File description:
** printf
*/

#include "../include/my.h"

struct format_vars {
    char c;
    char *str;
    int k;
    unsigned int u;
    char *p;
    int count;
    double db;
};

static int handle_misc3(const char *format, int i, va_list list, int *count)
{
    struct format_vars v;

    switch (format[i + 1]) {
        case 'c':
            v.c = va_arg(list, int);
            write(1, &v.c, 1);
            *count += 1;
            return (1);
        case 'e':
        case 'E':
            v.db = va_arg(list, double);
            *count += my_put_sci(v.db, format[i + 1]);
            return (1);
    }
    return (0);
}

static int handle_misc2(const char *format, int i, va_list list, int *count)
{
    struct format_vars v;

    switch (format[i + 1]) {
        default:
            return handle_misc3(format, i, list, count);
        case 's':
            v.str = va_arg(list, char*);
            *count += my_putstr(v.str);
            return (1);
        case '%':
            write(1, "%", 1);
            *count += 1;
            return (1);
        case 'o':
            v.u = va_arg(list, unsigned int);
            *count += my_put_oct(v.u);
            return (1);
    }
    return (0);
}

int handle_misc(const char *format, int i, va_list list, int *count)
{
    struct format_vars v;

    switch (format[i + 1]) {
        default:
            handle_misc2(format, i, list, count);
            return (1);
        case 'u':
            v.u = va_arg(list, unsigned int);
            *count += my_unsigned_put_nbr(v.u);
            return (1);
        case 'X':
        case 'x':
            v.u = va_arg(list, unsigned int);
            *count += my_put_hex(v.u, format[i + 1]);
            return (1);
    }
    return (0);
}

int handle_long(const char *format, int i, va_list list, int *count)
{
    struct format_vars v;

    if (format[i + 1] == 'l') {
        switch (format[i + 2]) {
            case 'd':
            case 'i':
                write(1, "Undefined\n", 10);
                *count += 10;
                return (1);
        }
    } else {
        handle_misc(format, i, list, count);
    }
    return (0);
}

int handle_base(const char *format, int i, va_list list, int *count)
{
    struct format_vars v;

    if (format[i] == '%') {
        switch (format[i + 1]) {
            default:
                handle_long(format, i, list, count);
                return (1);
            case 'i':
            case 'd':
                v.k = va_arg(list, int);
                *count += my_put_nbr(v.k);
                return (1);
            case 'p':
                v.p = va_arg(list, void*);
                *count += my_put_ptr(v.p);
                return (1);
        }
    }
    return (0);
}

int my_printf(const char *format, ...)
{
    va_list list;
    int skip;
    int y = 0;

    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++) {
        skip = handle_base(format, i, list, &y);
        if (skip == 1) {
            i++;
        } else {
            write(1, &format[i], 1);
            y++;
        }
    }
    return (y);
}
