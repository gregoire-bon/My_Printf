/*
** EPITECH PROJECT, 2025
** cpoolday04
** File description:
** display each number of an octal in decimal
*/

#include "../include/my.h"
#include <stdio.h>

int my_put_oct(unsigned int decimal)
{
    int octal[100];
    int i = 0;
    int count = 0;

    if (decimal == 0) {
        write(1, "0", 1);
        return (1);
    }
    while (decimal != 0) {
        octal[i] = decimal % 8;
        decimal = decimal / 8;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        count += my_put_nbr(octal[j]);
    }
    return (count);
}
