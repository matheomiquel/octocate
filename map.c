/*
** ETNA PROJECT, 10/05/2019 by miquel_m
** octocat
** File description:
**      array
*/
#include "lib.h"
char **creation_map(int fd, char **array, char *argc)
{
    char buf;
    int i = 0;
    int j = 0;
    
    fd = reset_buffer(fd, argc);
    while (1) { 
        if (read(fd, &buf, 1) == 0)
            break;
        if (buf == 10) {
            j++;
            i = 0;
        }
        else {
            array[j][i] = buf;
            i++;
        }
    }
    return (array);
}

void affichage_map(char **array)
{
    for (int i = 0;i < 7;i++) {
        for (int j = 0;j < 15;j++)
                my_putchar(array[i][j]);
        my_putchar(10);
    }
}