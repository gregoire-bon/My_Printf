/*
** EPITECH PROJECT, 2025
** my_unsigned_put_str.c
** File description:
** write an unsigned int
*/

#include <unistd.h>

unsigned int my_unsigned_put_nbr(unsigned int nbr)
{
    char c;
    int count = 0;

    if (nbr == 0) {
        write(1, "0", 1);
        return (1);
    }
    if (nbr >= 10)
        count = my_unsigned_put_nbr(nbr / 10);
    c = nbr % 10 + '0';
    write(1, &c, 1);
    return (count + 1);
}
