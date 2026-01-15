/*
** EPITECH PROJECT, 2025
** cpoolday04
** File description:
** display each letter of a char
*/
#include <unistd.h>

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(1, &str[i], 1);
        i++;
    }
    return (i);
}
