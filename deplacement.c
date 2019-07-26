/*
** ETNA PROJECT, 10/05/2019 by miquel_m
** octocat
** File description:
**      move
*/
#include "lib.h"
char **move(char **array, char buf)
{
    int for_x = 0;
    int for_y = 0;
    if (buf > 114)
        for_x = (buf == 'z') ? -1 : 1;
    else
        for_y = (buf == 'q') ? -1 : 1;
    move_ultime(array, for_x, for_y);
    return (array);
}

char **move_ultime(char **array,int for_x,int for_y)
{
    if ((((joueur.x + for_x > 6 || joueur.x + for_x < 0) ||
     (joueur.y + for_y > 14 || joueur.y + for_y < 0)) ||
     (array[joueur.x + for_x][joueur.y + for_y] == '#'))) {
        string_ultime();
        return (array); 
    }
    array[joueur.x][joueur.y] = 32;
    joueur.x += for_x;
    joueur.y += for_y;
    win(array);
    array[joueur.x][joueur.y] = 'P';
    return (array);
}


void string_ultime()
{
    if (!dur.hardcore)
        my_putstr("vous ne pouvez pas aller par là\n");
    if (dur.hardcore && !joueur.end_of_game) {
        my_putstr("\e[1;1H\e[2J");
        dur.hit_wall = true;
    }
}

void win(char **array)
{
    if (array[joueur.x][joueur.y] == 'X') {
        joueur.end_of_game = true;
    }
}
void string_of_win(int isWin) 
{
    if (isWin) {
    my_putstr("\e[1;1H\e[2J");
    my_putstr("bonjour tu as reussi well de play\n");
    } else {
    my_putstr("Vous vous êtes fait manger par un Grievers\n");
    }
}