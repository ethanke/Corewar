/*
** my_put_nbr.c for my_put_nbr in /home/leandr_g/rendu/j03codes/ex7
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Wed Sep 30 12:45:43 2015 Gaëtan Léandre
** Last update Mon Mar  7 04:07:54 2016 Victor Sousa
*/

#include	"corewar.h"

void		my_put_nbr(int nbr)
{
  int		mod;

  if (nbr < 0)
    {
      my_putchar('-');
      nbr = nbr * (-1);
    }
  if (nbr >= 0)
    {
      if (nbr >= 10)
	{
	  mod = (nbr % 10);
          nbr = (nbr - mod) / 10;
	  my_put_nbr(nbr);
	  my_putchar(48 + mod);
        }
      else
        my_putchar(48 + nbr % 10);
    }
}
