/*
** loop2.c for corewar in /Users/sousa_v/Shared/rendu/cpe/Coreware_temp/bonus/src/loop/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Thu Mar 17 04:53:29 2016 Victor Sousa
** Last update Thu Mar 17 04:55:29 2016 Victor Sousa
*/

#include		"corewar.h"

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
  my_printf("le joueur %d(%s) a gagné\n",
	    arena->champ->id_champ[arena->champ->last_live],
	    arena->champ->header[arena->champ->last_live].prog_name);
  end_prog(arena);
  exit(0);
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
    refresh_process(arena->champ->process[i]);
  arena->nbr_live = 0;
}
