/*
** init_arena.c for corewar in /Users/sousa_v/Shared/rendu/cpe/Coreware_temp/corewar/src/loading/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Mon Mar 14 16:47:03 2016 Victor Sousa
** Last update Mon Mar 14 17:26:37 2016 Victor Sousa
*/

#include		"corewar.h"

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
	  arena->arena[i + champ->pc_pos[nb_champ]] = champ->instru[nb_champ][i];
	  arena->proprio[i + champ->pc_pos[nb_champ]] = champ->id_champ[nb_champ];
	}
    }
}

t_arena			init_arena(t_champ *champ)
{
  t_arena		arena;

  arena.champ = champ;
  arena.arena = xmalloc(sizeof(unsigned char) * MEM_SIZE);
  arena.proprio = xmalloc(sizeof(char) * MEM_SIZE);
  my_memset(arena.proprio, MEM_SIZE, -1);
  fill_battle_field(&arena, champ);
  arena.cycle_to_die = CYCLE_TO_DIE;
  arena.total_cycle = 0;
  arena.total_live = 0;
  return (arena);
}
