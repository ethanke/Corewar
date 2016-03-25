/*
** loop.h for corewar in /Users/sousa_v/Shared/rendu/cpe/Coreware_temp/corewar/includes/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Wed Mar 16 04:03:45 2016 Victor Sousa
** Last update Fri Mar 25 11:45:27 2016 Victor Sousa
*/

#ifndef			LOOP_H_
# define		LOOP_H_

# include		"corewar.h"

# define		WIDTH		1080
# define		HEIGHT		720

# define		SDL_UPDATE_RATE	600

# define		M_NONE		0
# define		M_SDL		1
# define		M_SERVER	2

typedef struct		s_pos
{
  int			x;
  int			y;
}			t_pos;

void			main_loop(t_arena *arena);
int			how_much_alive(t_champ *champ);
void			leave_loop(t_arena *arena);
void			refresh_process(t_process *proc);
void			refresh_process_loop(t_arena *arena);

/*sdl*/
void			init_sdl(t_arena *arena);
void			print_sdl(t_arena *arena);
void			sdl_square(SDL_Surface *scr,
				   t_pos *beg, int size,
				   unsigned int color);

#endif		      /*LOOP_H_*/
