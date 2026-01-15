/*
** EPITECH PROJECT, 2026
** My_Printf
** File description:
** Example usage of my_printf
*/
#include "include/my.h"

int main(void)
{
    int num = 42;
    unsigned int unum = 42;
    char *str = "Hello, World!";
    char c = 'A';
    void *ptr = &num;
    double d = 123.456;

    my_printf("--- Basic Types ---\n");
    my_printf("Character: %c\n", c);
    my_printf("String: %s\n", str);
    my_printf("Percent sign: %%\n");

    my_printf("\n--- Integers ---\n");
    my_printf("Signed Integer (d): %d\n", num);
    my_printf("Signed Integer (i): %i\n", num);
    my_printf("Unsigned Integer: %u\n", unum);

    my_printf("\n--- Number Bases ---\n");
    my_printf("Octal: %o\n", unum);
    my_printf("Hexadecimal (lower): %x\n", unum);
    my_printf("Hexadecimal (upper): %X\n", unum);

    my_printf("\n--- Pointers & Scientific ---\n");
    my_printf("Pointer address: %p\n", ptr);
    my_printf("Scientific (lower): %e\n", d);
    my_printf("Scientific (upper): %E\n", d);

    return 0;
}