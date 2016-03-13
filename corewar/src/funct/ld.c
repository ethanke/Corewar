/*
** ld.c for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/corewar/src/funct/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Fri Mar 11 00:34:17 2016 Gaëtan Léandre
** Last update Sun Mar 13 12:14:34 2016 Gaëtan Léandre
*/

#include	"corewar.h"

int		my_ld(t_arena *arena, t_process *process, int id, int pc_pos)
{
  int		arg;
  int		nbr;
  int		reg;
  int		size;

  process->pos = circle(process->pos, 1);
  if (check_mult_args(arena->arena, 2, process->pos, 2) == -1)
    return (0);
  process->cycle += op_tab[2].nbr_cycles;
  process->carry = (process->carry == 1) ? 0 : 1;
  nbr = take_what(arena->arena, process->pos, 1, process->pc_pos);
  reg = octet_to_read(arena->arena[process->pos]);
  if ((size = check_reg(take_param(arena->arena, process->pos + reg + 2,
				   REG_SIZE))) == -1)
    return (0);
  arena->arena = put_param(arena->arena, pc_pos + 1 + (size - 1) * REG_SIZE, REG_SIZE, nbr);
  process->pos = circle(process->pos, 2 + reg + REG_SIZE);
  return (0);
}

int		my_lld(t_arena *arena, t_process *process, int id, int pc_pos)
{
  int		arg;
  int		nbr;
  int		reg;
  int		size;

  process->pos = circle(process->pos, 1);
  if (check_mult_args(arena->arena, 2, process->pos, 2) == -1)
    return (0);
  process->cycle += op_tab[2].nbr_cycles;
  process->carry = (process->carry == 1) ? 0 : 1;
  nbr = take_what(arena->arena, process->pos, 0, process->pc_pos);
  reg = octet_to_read(arena->arena[process->pos]);
  if ((size = check_reg(take_param(arena->arena, process->pos + reg + 2,
				   REG_SIZE))) == -1)
    return (0);
  arena->arena = put_param(arena->arena, pc_pos + 1 + (size - 1) * REG_SIZE, REG_SIZE, nbr);
  process->pos = circle(process->pos, 2 + reg + REG_SIZE);
  return (0);
}
