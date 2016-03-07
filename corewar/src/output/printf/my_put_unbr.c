/*
** my_put_nbr.c for my_put_nbr in /home/leandr_g/rendu/j03codes/ex7
** 
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
** 
** Started on  Wed Sep 30 12:45:43 2015 Gaëtan Léandre
** Last update Thu Nov 12 14:50:51 2015 Gaëtan Léandre
*/

#include "my_printf.h"

void	my_put_unbr(unsigned int nbr)
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
