/*
** ETNA PROJECT, 10/05/2019 by miquel_m
** octocat
** File description:
**      lib
*/
#ifndef MY_LIST_H_
#define MY_LIST_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>

typedef struct player_s{
    int x;
    int y;
    int x_base;
    int y_base;
    bool end_of_game;
    bool wrong_key;
    bool nb_arg_map;
} player_t;

typedef struct hardcore_s{
    bool hardcore;
    bool hit_wall;
} hardcore_t ;

player_t joueur;
hardcore_t dur;

void my_putchar(char c);
void my_putstr(char *str);
void my_putnbr(int n);
int check_arg(int argv);
int check_file(char *argc);
int brain(int fd, char **argc);
char **creation_map(int fd, char **array, char *argc);
int initialization_array(int fd);
int check_map(int *size, int fd, int player, char *buf, int sortie);
int reset_buffer(int fd, char *argc);
void affichage_map(char **array);
char **level_simple(char **array);
void incrementation(int *player, int *sortie, char buf, int *size);
char **move(char **array, char buf);
int check_hardcore(int argv, char **argc);
int level_hardcore(char **array,int fd, char *argc);
int my_strcmp(char *s1, char *s2);
char **move_ultime(char **array,int for_x,int for_y);
void string_ultime();
void win(char **array);
void string_of_win();

#endif
