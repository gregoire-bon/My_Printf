/*
** EPITECH PROJECT, 2025
** pointer
** File description:
** put pointer
*/

#include <unistd.h>
#include "../include/my.h"

int my_put_ptr(void *ptr)
{
    int count = 0;
    unsigned long addr = (unsigned long)ptr;

    write(1, "0x", 2);
    count += 2;
    count += my_put_hex((unsigned int)addr, 'x');
    return (count);
}
