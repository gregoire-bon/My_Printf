/*
** EPITECH PROJECT, 2025
** cpoolday_myprintf
** File description:
** write a number in scientific writing
*/

#include "../include/my.h"

int my_put_sci(double num, char maj)
{
    int count = 6;
    int exp = 0;
    float output = num;

    while (output >= 10) {
        output = output / 10;
        exp++;
    }
    my_put_flt(output, 6);
    if (maj == 'E')
        my_putstr("E+");
    else if (maj == 'e')
        my_putstr("e+");
    if (count < 10){
        my_put_nbr(0);
        my_put_nbr(exp);
        count++;
    } else
        my_put_nbr(exp);
    return count + 5;
}
