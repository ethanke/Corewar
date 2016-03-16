/*
** loop.c for corewar in /Users/sousa_v/Shared/rendu/cpe/Coreware_temp/corewar/src/loop/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Wed Mar 16 04:02:36 2016 Victor Sousa
** Last update Wed Mar 16 17:08:02 2016 Victor Sousa
*/

#include		"corewar.h"

void		pick_function(t_arena *arena, t_process *proc, int id)
{
  if (proc->cycle == 0)
    {
      if (arena && arena->arena[proc->pos] >= 1 && arena->arena[proc->pos] <= 16)
	arena->func[arena->arena[proc->pos] - 1](arena, proc, id, arena->champ->pc_pos[id]);
      else
	proc->pos = circle(proc->pos, 1);
    }
  else
    proc->cycle--;
}

void		launch_process(t_process *process, t_arena *arena, int id)
{
  t_process	*tmp;

  tmp = process;
  while (tmp != NULL)
    {
      pick_function(arena, process, id);
      if (tmp->child != NULL && tmp->child->live == 1)
	launch_process(tmp->child, arena, id);
      tmp = tmp->next;
    }
}

void			loop_champ(t_arena *arena)
{
  int			i;

  i = -1;
  while (++i < arena->champ->nbr_champ)
    {
      if (arena->champ->process[i]->live == 1)
	launch_process(arena->champ->process[i], arena, i);
    }
}

void			main_loop(t_arena *arena)
{
  int			i;
  int			cycle_to_die;

  i = -1;
  cycle_to_die = CYCLE_TO_DIE;
  while (cycle_to_die > 0)
    {
      i = -1;
      while (++i < cycle_to_die)
	{
	  loop_champ(arena);
	}
      cycle_to_die -= CYCLE_DELTA;
    }
}
