/*
** EPITECH PROJECT, 2025
** cpoolday_myprintf
** File description:
** my_put_flt
*/

#include "../include/my.h"

struct variables {
    int length;
    int int_part;
    float frac_part;
    int digit;
    char c;
};

int my_put_flt(float num, int precision)
{
    struct variables vars = {0};

    if (num < 0) {
        vars.length += write(1, "-", 1);
        num = -num;
    }
    vars.int_part = (int)num;
    vars.length += my_put_nbr(vars.int_part);
    vars.length += write(1, ".", 1);
    vars.frac_part = num - vars.int_part;
    for (int i = 0; i < precision; i++) {
        vars.frac_part *= 10;
        vars.digit = (int)vars.frac_part;
        vars.c = vars.digit + '0';
        vars.length += write(1, &vars.c, 1);
        vars.frac_part -= vars.digit;
    }
    return vars.length;
}
