/*
** params.c for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/corewar/src/utils/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Mon Mar  7 00:39:28 2016 Gaëtan Léandre
** Last update Fri Mar 11 05:28:14 2016 Gaëtan Léandre
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
      pos = circle(pos, 1);
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
      pos = circle(pos, 1);
    }
  return (arena);
}

int		*take_ind(unsigned char *arena, int pos, int modu)
{    nbr = take_param(arena->arena,
		     circle(mod(take_param(arena->arena, process->pos + 1,
					   IND_SIZE), IDX_MOD), 0), DIR_SIZE);
  int		nbr;

  if (modu == 1)
    nbr = take_param(arena, circle(mod(take_param(arena, pos, IND_SIZE),
				       IDX_MOD), O), DIR_SIZE);
  else
    nbr = take_param(arena, circle(take_param(arena, pos, IND_SIZE), O),
		     DIR_SIZE);
   return (nbr);
}
