/*
** init_arena.c for corewar in /Users/sousa_v/Shared/rendu/cpe/Coreware_temp/corewar/src/loading/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Mon Mar 14 16:47:03 2016 Victor Sousa
** Last update Thu Mar 17 04:51:19 2016 Victor Sousa
*/

#include		"corewar.h"

void			init_func_tab(t_arena *arena)
{
  arena->func[0] = my_live;
  arena->func[1] = my_ld;
  arena->func[2] = my_st;
  arena->func[3] = my_add;
  arena->func[4] = my_sub;
  arena->func[5] = my_and;
  arena->func[6] = my_or;
  arena->func[7] = my_xor;
  arena->func[8] = my_zjump;
  arena->func[9] = my_ldi;
  arena->func[10] = my_sti;
  arena->func[11] = my_fork;
  arena->func[12] = my_lld;
  arena->func[13] = my_lldi;
  arena->func[14] = my_lfork;
  arena->func[15] = my_aff;
}

void			fill_battle_field(t_arena *arena, t_champ *champ)
{
  int			nb_champ;
  int			i;

  nb_champ = -1;
  while (++nb_champ < champ->nbr_champ)
    {
      i = -1;
      while (++i < champ->header[nb_champ].prog_size)
	{
	  arena->arena[i + champ->process[nb_champ]->pc_pos] =
	  champ->instru[nb_champ][i];
	  arena->proprio[i + champ->process[nb_champ]->pc_pos] =
	  champ->id_champ[nb_champ];
	}
    }
}

t_arena			init_arena(t_champ *champ)
{
  t_arena		arena;

  arena.champ = champ;
  arena.arena = xmalloc(sizeof(unsigned char) * MEM_SIZE);
  my_memset(arena.arena, MEM_SIZE, 0);
  arena.proprio = xmalloc(sizeof(char) * MEM_SIZE);
  my_memset(arena.proprio, MEM_SIZE, -1);
  fill_battle_field(&arena, champ);
  arena.cycle_to_die = CYCLE_TO_DIE;
  arena.total_cycle = 0;
  arena.total_live = 0;
  arena.nbr_live = 0;
  init_func_tab(&arena);
  return (arena);
}
