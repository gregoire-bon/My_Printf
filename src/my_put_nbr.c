/*
** EPITECH PROJECT, 2025
** cpoolday03
** File description:
** my_put_nbr
*/

#include <unistd.h>

struct vars {
    char c;
    int count;
};

int my_put_nbr(int nbr)
{
    struct vars v;

    if (nbr == -2147483648) {
        write(1, "-2147483648", 11);
        return (11);
    }
    if (nbr == 0) {
        write(1, "0", 1);
        return (1);
    }
    if (nbr < 0) {
        write(1, "-", 1);
        nbr = -nbr;
        v.count = 1;
    }
    if (nbr >= 10)
        v.count += my_put_nbr(nbr / 10);
    v.c = nbr % 10 + '0';
    write(1, &v.c, 1);
    return (v.count + 1);
}
