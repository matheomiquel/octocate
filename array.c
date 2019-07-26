/*
** ETNA PROJECT, 10/05/2019 by miquel_m
** octocat
** File description:
**      array
*/
#include "lib.h"
int initialization_array(int fd)
{
    int player = 0;
    int sortie = 0;
    char *buf = malloc(sizeof(char) * 1);
    int *size = malloc(sizeof(int) * 2);
    
    size[0] = 0;
    size[1] = 0;
    if(buf == NULL || size==NULL)
        return (1);
    if (check_map(size,fd,player, buf, sortie) == 0) {
        free(size);
        free(buf);
        return (0);
    }
    free(buf);
    free(size);
    return (1);
}

void incrementation(int *player, int *sortie, char buf, int *size)
{
    if (buf == 'P') {
        (*player)++;
        joueur.x = size[1];
        joueur.y = size[0];
        joueur.x_base = size[1];
        joueur.y_base = size[0];
    }
    if (buf == 'X'){
        *sortie = *sortie + 1;
    }
}

int check_map(int *size, int fd, int player, char *buf, int sortie) 
{
    while (read(fd, buf, 1) != 0) { 
        incrementation(&player, &sortie, buf[0], size);
        size[0]++;
        if (buf[0] == 10) {
            if(size[0] != 16)
                joueur.nb_arg_map = true;
            size[0] = 0; 
            size[1]++;
        }
        if (buf[0] != '#' && buf[0] != 'P' && buf[0] != 'X' && buf[0] != 10 && buf[0] != 32) 
            joueur.nb_arg_map = true;
        }
        
    if (player != 1 || sortie == 0 || (size[0] != 15 && size [1] != 6)) 
        joueur.nb_arg_map = true;
    if (joueur.nb_arg_map) {
        my_putnbr(size[1]);
        my_putstr("erreur dans le fichier de la map\n");
        return (-1);
    }
    return 0;
}
