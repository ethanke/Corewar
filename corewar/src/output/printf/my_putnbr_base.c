/*
** my_putnbr_base.c for my_putnbr_base in /home/leandr_g/rendu/Piscine_C_J06/ex_16
** 
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
** 
** Started on  Mon Oct  5 13:31:52 2015 Gaëtan Léandre
** Last update Fri Nov 13 11:18:19 2015 Gaëtan Léandre
*/

#include "my_printf.h"

int	my_strlen(char *base)
{
  int	i;

  i = 0;
  while (base[i] != '\0')
    i++;
  return (i);
}

int	power(int nbr, int pow)
{
  int	i;
  int	copy_nbr;

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

int	big_pow(int nbr, int base_size)
{
  int	i;

  i = 0;
  while (power(base_size, i) <= nbr)
    i++;
  i--;
  return (i);
}

void	my_putnbr_base(int nbr, char *base, int taille)
{
  int	base_size;
  int	i;
  int	puissance;

  if (nbr < 0)
    {
      my_putchar('-');
      nbr = nbr * (-1);
    }
  base_size = my_strlen(base);
  i = taille >= 0 ? taille : big_pow(nbr, base_size);
  while (i >= 0)
    {
      puissance = nbr / power(base_size, i);
      my_putchar(base[puissance]);
      nbr = nbr - puissance * power(base_size, i);
      i--;
    }
}
