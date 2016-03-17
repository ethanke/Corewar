/*
** arena.h for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/corewar/includes/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Mon Mar  7 00:12:21 2016 Gaëtan Léandre
** Last update Thu Mar 17 04:26:41 2016 Victor Sousa
*/

#ifndef			ARENA_H_
# define		ARENA_H_

# include "corewar.h"

typedef struct		s_graph
{
  SDL_Surface		*sdl_surface;
  TTF_Font		*font_title;
  TTF_Font		*font;
  SDL_Surface		*title;
  SDL_Surface		*miam;
  SDL_Color		title_col;
}			t_graph;

typedef struct		s_arena
{
  char			mode;
  t_graph		graph;
  t_champ		*champ;
  unsigned char		*arena;
  char			*proprio;
  int			cycle;
  int			cycle_to_die;
  int			total_cycle;
  int			total_live;
  int			nbr_live;
  int			(*func[16])(struct s_arena *arena,
			 t_process *process,
			 int id, int pc_pos);
}			t_arena;



#endif		      /*ARENA_H_*/
