/*
** ETNA PROJECT, 10/05/2019 by miquel_m
** octocat
** File description:
**      my_putchar
*/
#include "lib.h"
void my_putchar(char c)
{
    write(1, &c, 1);
}