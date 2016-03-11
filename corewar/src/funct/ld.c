/*
** ld.c for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/corewar/src/funct/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Fri Mar 11 00:34:17 2016 Gaëtan Léandre
** Last update Fri Mar 11 02:22:25 2016 Gaëtan Léandre
*/

#include	"corewar.h"

int		my_ld(t_arena *arena, t_process *process, int id, int pc_pos)
{
  int		arg;
  int		nbr;
  int		reg;
  int		size;

  process->pos = circle(process->pos, 1);
  if (check_arg(2, 0, arena->arena[process->pos]) == -1
      || check_arg(2, 1, arena->arena[process->pos +
		   octet_to_read(arena->arena[process->pos])]) == -1)
    return (0);
  process->cycle += op_tab[2].nbr_cycles;
  process->carry = (process->carry == 1) ? 0 : 1;
  if ((reg = octet_to_read(arena->arena[process->pos])) == DIR_SIZE)
    nbr = take_param(arena->arena, process->pos + 1, DIR_SIZE);
  else
    nbr = take_param(arena->arena,
		     circle(mod(take_param(arena->arena, process->pos + 1,
					   IND_SIZE), IDX_MOD), 0), DIR_SIZE);
    if ((size = check_reg(take_param(arena->arena, process->pos + reg + 2,
				    REG_SIZE))) == -1)
	return (0);
      put_param(arena->arena, pc_pos + 1 + (size - 1) * REG_SIZE, REG_SIZE, nbr);
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
  if (check_arg(13, 0, arena->arena[process->pos]) == -1
      || check_arg(13, 1, arena->arena[process->pos +
                 octet_to_read(arena->arena[process->pos])]) == -1)
    return (0);
  process->cycle += op_tab[13].nbr_cycles;
  process->carry = (process->carry == 1) ? 0 : 1;
  if ((reg = octet_to_read(arena->arena[process->pos])) == DIR_SIZE)
    nbr = take_param(arena->arena, process->pos + 1, DIR_SIZE);
  else
    nbr = take_param(arena->arena,
                   circle(take_param(arena->arena, process->pos + 1,
				     IND_SIZE), 0), DIR_SIZE);
    if ((size = check_reg(take_param(arena->arena, process->pos + reg + 2,
                                  REG_SIZE))) == -1)
      return (0);
      put_param(arena->arena, pc_pos + 1 + (size - 1) * REG_SIZE, REG_SIZE, nbr);
      process->pos = circle(process->pos, 2 + reg + REG_SIZE);
    return (0);
}
