/*
** calculs.c for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/corewar/src/utils/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Mon Mar  7 03:31:21 2016 Gaëtan Léandre
** Last update Mon Mar  7 03:34:47 2016 Gaëtan Léandre
*/

#include "corewar.h"

int		mod(int nbr, int modulo)
{
  nbr = nbr % modulo;
  if (nbr < 0)
    nbr = modulo + nbr;
  return (nbr);
}
