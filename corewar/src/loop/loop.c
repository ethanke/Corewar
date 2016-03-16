/*
** loop.c for corewar in /Users/sousa_v/Shared/rendu/cpe/Coreware_temp/corewar/src/loop/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Wed Mar 16 04:02:36 2016 Victor Sousa
** Last update Wed Mar 16 18:44:59 2016 Victor Sousa
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

void		refresh_process(t_process *proc)
{
  t_process	*tmp;

  tmp = proc;
  while (tmp != NULL)
    {
      proc->live = proc->living;
      proc->living = 0;
      if (tmp->child != NULL)
	refresh_process(tmp->child);
      tmp = tmp->next;
    }
}

void		refresh_process_loop(t_arena *arena)
{
  int		i;

  i = -1;
  while (++i < arena->champ->nbr_champ)
    {
      arena->champ->live[i] = 0;
      refresh_process(arena->champ->process[i]);
    }
  arena->nbr_live = 0;
}

int		how_much_alive(t_champ *champ)
{
  int		i;
  int		count;

  count = 0;
  i = -1;
  while (++i < champ->nbr_champ)
    {
      if (champ->live[i] == 1)
	count++;
      champ->live[i] = 0;
    }
  return (count);
}

void		leave_loop(t_arena *arena)
{
  my_printf("le joueur %d(%s) a gagné\n", arena->champ->id_champ[arena->champ->last_live],
	    arena->champ->header[arena->champ->last_live].prog_name);
  end_prog(arena);
  exit(0);
}

void		launch_process(t_process *process, t_arena *arena, int id)
{
  t_process	*tmp;

  tmp = process;
  while (tmp != NULL)
    {
      if (arena->nbr_live > NBR_LIVE)
	{
	  refresh_process_loop(arena);
	  if (how_much_alive(arena->champ) < 2)
	    leave_loop(arena);
	}
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
          /*system("clear");
          print_arena_proprio(arena);
          sleep(1);*/
	}
      refresh_process_loop(arena);
      if (how_much_alive(arena->champ) < 2)
	leave_loop(arena);
      cycle_to_die -= CYCLE_DELTA;
    }
}
