/*
** EPITECH PROJECT, 2025
** cpoolday04
** File description:
** display a number in decimal into an hexadecimal
*/

#include "../include/my.h"

struct vars {
    int i;
    int j;
    int temp;
    char hexa[100];
};

int my_put_hex(unsigned int decimal, char maj)
{
    struct vars v;

    v.i = 0;
    if (decimal == 0) {
        write(1, "0", 1);
        return (1);
    }
    while (decimal != 0) {
        v.temp = decimal % 16;
        if (maj == 'X')
            v.temp = (v.temp < 10) ? v.temp + 48 : v.temp + 55;
        else
            v.temp = (v.temp < 10) ? v.temp + 48 : v.temp + 87;
        v.hexa[v.i] = v.temp;
        v.i++;
        decimal = decimal / 16;
    }
    for (v.j = v.i - 1; v.j >= 0; v.j--)
        write(1, &v.hexa[v.j], 1);
    return (v.i);
}
