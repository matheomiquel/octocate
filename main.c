/*
** ETNA PROJECT, 10/05/2019 by miquel_m
** octocat
** File description:
**      main
*/
#include "lib.h"

int main(int argv, char **argc)
{
    int fd;

    my_putstr("\e[1;1H\e[2J");
    if (check_arg(argv) == -1)
        return (1);
    if (check_hardcore(argv, argc) == -1)
        return (1);
    fd = check_file(argc[1]);
    if (fd == -1)
        return (-1);
    if (brain(fd, argc) == 0)
        return (0);
    return 1;
}

int brain(int fd, char **argc)
{
    char **array;

    array = malloc(sizeof(char *) * 15);
    for (int i = 0;i < 7;i++) {
        array[i] = malloc(sizeof(char) * 7);
        if (array[i] == NULL)
        return (1);
    }
    if (initialization_array(fd) != 0)
        return (1);
    array = creation_map(fd, array, argc[1]);
    if (!dur.hardcore)
        while (!joueur.end_of_game)
            level_simple(array);
    else 
        level_hardcore(array, fd, argc[1]);
    //my_putchar(str[i]);
    my_putstr("\e[1;1H\e[2J");
    string_of_win(joueur.end_of_game);
    affichage_map(array);
    free(array);
    close(fd);
    return (0);
}

int reset_buffer(int fd, char *argc) 
{
    close(fd);
    fd = open(argc, O_RDONLY);
    return (fd);
}

char **level_simple(char **array)
{
    char buf = 0;

    if(joueur.wrong_key)
        my_putstr("mauvaise touche \n");
    my_putstr("pour bougez dans le labyrinthe utiliser z, q, s, d !!!\n");
    affichage_map(array);
    read(1, &buf, 1);
    my_putstr("\e[1;1H\e[2J");
    if (buf != '\n') {
        if (buf == 'z' || buf == 'q' || buf == 's' || buf == 'd'){
            joueur.wrong_key = false;
            move(array, buf);
            while (getchar() != '\n');
        } else {
            joueur.wrong_key = true;
        }
    }  
    return (array);
}

int level_hardcore(char **array,int fd, char *argc)
{
    char buf = 0;

    my_putstr("mettez tout vos mouvement en meme temps, pour valider appuyer sur entrée.\n");
    my_putstr("Pour effacer toute la ligne faite ctrl + d.\n");
    affichage_map(array);
    while (buf != 10) {
        if (read(1, &buf, 1) == 0) {
            my_putstr("\e[1;1H\e[2J");
            array = creation_map(fd, array, argc);
            level_hardcore(array, fd,argc);
        }
        if (buf != '\n' && (buf == 'z' || buf == 'q' || buf == 's' || buf == 'd')){
            move(array, buf);
        }
    }
    return (0);
}
