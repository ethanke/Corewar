/*
** my_putnbr_base.c for my_putnbr_base in /home/leandr_g/rendu/Piscine_C_J06/ex_16
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Mon Oct  5 13:31:52 2015 Gaëtan Léandre
** Last update Mon Mar  7 03:26:00 2016 Victor Sousa
*/

#include "corewar.h"

size_t	power_add(size_t nbr, int pow)
{
  int	i;
  size_t	copy_nbr;

  copy_nbr = nbr;
  i = 1;
  if (pow == 0)
    return (1);
  while (i < pow)
    {
      nbr = nbr * copy_nbr;
      i++;
    }
  return (nbr);
}

int	big_pow_add(size_t nbr, int base_size)
{
  int	i;

  i = 0;
  while (power_add(base_size, i) <= nbr)
    i++;
  i--;
  return (i);
}

void	my_putnbr_base_add(size_t nbr, char *base, int taille)
{
  int	base_size;
  int	i;
  int	puissance;

  base_size = my_strlen(base);
  i = taille >= 0 ? taille : big_pow_add(nbr, base_size);
  while (i >= 0)
    {
      puissance = nbr / power_add(base_size, i);
      my_putchar(base[puissance]);
      nbr = nbr - puissance * power_add(base_size, i);
      i--;
    }
}
