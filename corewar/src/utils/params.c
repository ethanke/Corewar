/*
** params.c for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/corewar/src/utils/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Mon Mar  7 00:39:28 2016 Gaëtan Léandre
** Last update Thu Mar 24 21:52:29 2016 victor sousa
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

void		put_param(t_arena *arena, int pos, int id, int nbr)
{
  int		i;
  int		bit;

  bit = (DIR_SIZE - 1) * 8;
  i = 0;
  while (i < DIR_SIZE)
    {
      arena->arena[pos] = nbr >> (bit);;
      arena->proprio[pos] = id;
      i++;
      pos = circle(pos, 1);
      bit -= 8;
    }
}

int		take_ind(unsigned char *arena, int pos, int modu, int pc)
{
  int		nbr;

  if (modu == 1)
    nbr = take_param(arena, circle(pc, mod(take_param(arena, pos, IND_SIZE), IDX_MOD)), DIR_SIZE);
  else
    nbr = take_param(arena, circle(pc, take_param(arena, pos, IND_SIZE)), DIR_SIZE);
  return (nbr);
}

int		take_what(unsigned char *arena, int pos,
			  t_choix choix, int *reg)
{
  char		arg;
  int		tmp;

  tmp = pos + 1;
  arg = who_are_u(arena[pos], choix.place);
  if (choix.place > 1)
    tmp = circle(tmp, place_to_jump(arena[pos], choix.place - 1));
  if (arg == T_REG)
    return (reg[arena[tmp] - 1]);
  else if (arg == T_DIR)
    return (take_param(arena, tmp, DIR_SIZE));
  else if (arg == T_IND - 1)
    return (take_ind(arena, tmp, choix.modu, choix.pc));
  return (0);
}
