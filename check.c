/*
** ETNA PROJECT, 10/05/2019 by miquel_m
** octocat
** File description:
**      check
*/
#include "lib.h"

int check_arg(int argv)
{
    if (argv < 2) {
        my_putstr("vous n'avez pas mis de fichier\n");
        return (-1);
    }
    return (0);
}

int check_file(char *argc)
{
    int fd = open(argc, O_RDONLY);;

    if (fd == (-1)) {
        my_putstr("le fichier est introuvable\n");
        return (-1);
    }
    return (fd);
}

int check_hardcore(int argv, char **argc)
{
    if (argv > 2) {
        if (my_strcmp(argc[2], "--hardcore") == 0 || my_strcmp(argc[2], "-h") == 0) {
            dur.hardcore = true;
        } else {
            my_putstr("le troisieme argument n'a pas de sens connue\n");
            return (-1);
        }
    }
    return (0);
}