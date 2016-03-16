/*
** arena.h for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/corewar/includes/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Mon Mar  7 00:12:21 2016 Gaëtan Léandre
** Last update Wed Mar 16 17:41:42 2016 Victor Sousa
*/

#ifndef			ARENA_H_
# define		ARENA_H_

# include "corewar.h"

typedef struct		s_arena
{
  t_champ		*champ;
  unsigned char		*arena;
  char			*proprio;
  float			cycle_to_die;
  int			total_cycle;
  int			total_live;
  int			nbr_live;
  int			(*func[16])(struct s_arena *arena,
			 t_process *process,
			 int id, int pc_pos);
}			t_arena;



#endif		      /*ARENA_H_*/
