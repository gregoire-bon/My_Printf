/*
** EPITECH PROJECT, 2025
** cpoolday09
** File description:
** my_h
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

#ifndef MY
    #define MY

int my_put_nbr(int nb);
unsigned int my_unsigned_put_nbr(unsigned int nbr);
int my_putstr(char const *str);
int my_printf(const char *format, ...);
int my_put_oct(unsigned int decimal);
int my_put_hex(unsigned int decimal, char maj);
int my_put_ptr(void *ptr);
int my_put_flt(float num, int precision);
int my_put_sci(double num, char maj);
#endif /* MY */
