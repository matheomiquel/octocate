##
## ETNA PROJECT, 10/05/2019 by miquel_m
## octocat
## File description:
##      Makefile
##
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -std=c99

NAME    = octocat
RM      = rm -f
SRC	= \
	my_putchar.c \
    my_putstr.c \
	my_putnbr.c \
	main.c \
	check.c \
	array.c \
	deplacement.c \
	my_strcmp.c \
	map.c \

OBJ     = $(SRC:.c=.o)

all: $(NAME) 

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all $(NAME) clean fclean re