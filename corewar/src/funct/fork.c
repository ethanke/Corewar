/*
** fork.c for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/corewar/src/funct/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Mon Mar  7 03:07:53 2016 Gaëtan Léandre
** Last update Mon Mar  7 03:50:26 2016 Gaëtan Léandre
*/

##include "corewar.h"

int		my_fork(t_arena *arena, t_process *process, int id, int pc_pos)
{
  t_process	*tmp;

  process->cycle += op_tab[11].nbr_cycles;
  tmp = add_child(process);
  tmp->pos = mod(pc_pos + mod(take_param(arena->arena, process->pos + 1,
					 DIR_SIZE), IDX_MOD), MEM_SIZE);
  return (0);
}

int		my_lfork(t_arena *arena, t_process *process, int id, int pc_pos)
{
  t_process	*tmp;

  process->carry = (process->carry == 1) ? 0 : 1;
  process->cycle += op_tab[14].nbr_cycles;
  tmp->pos = mod(pc_pos + take_param(arena->arena, process->pos + 1,
				     DIR_SIZE), MEM_SIZE);
  return (0);
}
