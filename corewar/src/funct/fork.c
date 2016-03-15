/*
** fork.c for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/corewar/src/funct/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Mon Mar  7 03:07:53 2016 Gaëtan Léandre
** Last update Tue Mar 15 19:32:55 2016 Gaëtan Léandre
*/

#include	"corewar.h"

int		my_fork(t_arena *arena, t_process *process, int id, int pc_pos)
{
  t_process	*tmp;

  id = id;
  process->pos = circle(process->pos, 1);
  process->cycle += op_tab[11].nbr_cycles;
  tmp = add_child(process);
  cpy_registre(tmp, process);
  tmp->pos = circle(pc_pos, mod(take_param(arena->arena, process->pos,
					   DIR_SIZE), IDX_MOD));
  process->pos = circle(process->pos, DIR_SIZE);
  return (0);
}

int		my_lfork(t_arena *arena, t_process *process, int id, int pc_pos)
{
  t_process	*tmp;

  id = id;
  process->pos = circle(process->pos, 1);
  process->carry = (process->carry == 1) ? 0 : 1;
  process->cycle += op_tab[14].nbr_cycles;
  tmp = add_child(process);
  cpy_registre(tmp, process);
  tmp->pos = circle(pc_pos, take_param(arena->arena, process->pos,
				       DIR_SIZE));
  process->pos = circle(process->pos, DIR_SIZE);
  return (0);
}
