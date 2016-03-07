/*
** my_put_nbr.c for my_put_nbr in /home/leandr_g/rendu/j03codes/ex7
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Wed Sep 30 12:45:43 2015 Gaëtan Léandre
** Last update Mon Mar  7 03:25:27 2016 Victor Sousa
*/

#include "corewar.h"

int	positif(int nbr, int test)
{
  if (nbr >= 0)
    {
      return (1);
    }
  else if (nbr == -2147483648)
    {
      my_putchar('-');
      my_putchar('2');
      return (2);
    }
  else if (test == 1)
    {
      my_putchar('-');
      return (-1);
    }
  return (-1);
}

void	display_numbers(int nbr)
{
  int	i;
  int	number;
  int	first;

  first = 0;
  i = 1000000000;
  if (nbr == 0)
    my_putchar('0');
  while (i > 0)
    {
      number = nbr / i;
      if (number != 0 || first != 0)
	{
	  my_putchar(number + 48);
	  nbr = nbr % i;
	  first = 1;
	}
      i = i / 10;
    }
}

void	my_put_nbr(int nbr)
{
  if (positif(nbr, 0) != 2)
    {
      nbr = positif(nbr, 1) * nbr;
    }
  else
    {
      nbr = 147483648;
    }
  display_numbers(nbr);
}
