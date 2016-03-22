/*
** loop.c for corewar in /Users/sousa_v/Shared/rendu/cpe/Coreware_temp/corewar/src/loop/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Wed Mar 16 04:02:36 2016 Victor Sousa
** Last update Tue Mar 22 15:25:24 2016 Kerdelhue Ethan
*/

#include		"corewar.h"

void		pick_function(t_arena *arena, t_process *proc, int id)
{
  if (proc->cycle == 0)
    {
      if (arena && arena->arena[proc->pos] >= 1 &&
	  arena->arena[proc->pos] <= 16)
	arena->func[arena->arena[proc->pos] - 1](arena, proc,
						 id, proc->pc_pos);
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
      if (arena->nbr_live >= NBR_LIVE)
	{
	  refresh_process_loop(arena);
	  if (how_much_alive(arena->champ) < 2)
	    leave_loop(arena);
	  arena->cycle = 0;
	  arena->cycle_to_die -= CYCLE_DELTA;
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
  arena->cycle_to_die = CYCLE_TO_DIE;
  while (arena->cycle_to_die > 0)
    {
      usleep(100);
      arena->cycle = 0;
      while (arena->cycle < arena->cycle_to_die)
	{
	  loop_champ(arena);
	  if (arena->mode == M_SDL && arena->cycle % SDL_UPDATE_RATE == 0)
	    print_sdl(arena);
	  arena->total_cycle++;
	  arena->cycle++;
	}
      refresh_process_loop(arena);
      if (how_much_alive(arena->champ) < 2)
	leave_loop(arena);
      arena->cycle_to_die -= CYCLE_DELTA;
      if (arena->mode == M_SDL)
        print_sdl(arena);
    }
  leave_loop(arena);
}
