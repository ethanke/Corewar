/*
** arena.h for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/corewar/includes/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Mon Mar  7 00:12:21 2016 Gaëtan Léandre
** Last update Mon Mar  7 00:24:31 2016 Gaëtan Léandre
*/

#ifndef			_ARENA_
# define		_ARENA_

typedef struct		s_arena
{
  unsigned char		*arena;
  float			cycle_to_die;
  int			total_cycle;
  int			total_live;
}			t_arena;

#endif			/*_ARENA_*/
