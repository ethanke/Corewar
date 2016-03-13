/*
** arena.h for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/corewar/includes/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Mon Mar  7 00:12:21 2016 Gaëtan Léandre
** Last update Sun Mar 13 13:41:04 2016 Gaëtan Léandre
*/

#ifndef			_ARENA_
# define		_ARENA_

# include "corewar.h"

typedef struct		s_arena
{
  unsigned char		*arena;
  int			*live;
  int			*id_champ;
  float			cycle_to_die;
  int			total_cycle;
  int			total_live;
}			t_arena;

#endif			/*_ARENA_*/
