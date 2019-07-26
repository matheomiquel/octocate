/*
** ETNA PROJECT, 10/05/2019 by miquel_m
** octocat
** File description:
**      my_putstr
*/
#include "lib.h"
void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0';i++)
        my_putchar(str[i]);
}