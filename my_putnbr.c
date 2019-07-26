/*
** ETNA PROJECT, 10/05/2019 by miquel_m
** octocat
** File description:
**      my_putnbr
*/
#include "lib.h"

void my_putnbr(int n)
{
	long nbr = n;

    if (nbr < 0) {
	  my_putchar(45);
	  nbr = nbr * -1;
	}
	if (nbr > 9 || nbr < -9) {
	  my_putnbr(nbr / 10);
  	my_putnbr(nbr % 10);
    nbr = nbr * 10;
	} else {
  	my_putchar(nbr + 48);
  }
}