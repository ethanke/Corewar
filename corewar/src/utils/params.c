/*
** params.c for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/corewar/src/utils/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Mon Mar  7 00:39:28 2016 Gaëtan Léandre
** Last update Mon Mar  7 04:03:34 2016 Gaëtan Léandre
*/

#include "corewar.h"

int		take_param(unsigned char *arena, int pos, int bit)
{
  unsigned int	result;

  result = 0;
  bit = 8 * (bit - 1);
  while (bit >= 0)
    {
      result = result | (arena[pos] << bit);
      bit -= 8;
      pos++;
      pos = mod(pos, MEM_SIZE);
    }
  return (result);
}

unsigned char	*put_param(unsigned char *arena, int pos, int bit, int nbr)
{
  int		i;

  i = 0;
  while (i < bit)
    {
      arena[pos] = 0;
      arena[pos] = arena[pos] | (nbr << ((i + 1) * 8));
      i++;
      pos++;
      pos = mod(pos, MEM_SIZE);
    }
  return (arena);
}
