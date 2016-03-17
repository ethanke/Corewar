/*
** ncurses.c for corewar in /Users/sousa_v/Shared/rendu/cpe/Coreware_temp/bonus/src/loop/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Thu Mar 17 02:38:12 2016 Victor Sousa
** Last update Thu Mar 17 02:44:24 2016 Victor Sousa
*/

#include		"corewar.h"

void			init_curses(t_arena *arena)
{
  arena->mode = M_CURSE;
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    my_putstr_error("Can't init ncurses\n", 1);
  atexit(SDL_Quit);
  if ((arena->graph.sdl_surface =
       SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_HWSURFACE )) == NULL)
    my_putstr_error("Can't set video mode\n", 1);
}
/*
void			print_sdl(t_arena *arena)
{
  t_pos			pos;
  int			i;
  int			size;

  size = (WIDTH - 80) / (MEM_SIZE / (MEM_SIZE / 128)) + 1;
  pos.x = 30;
  pos.y = HEIGHT / 2 - ((MEM_SIZE / 128) * size) / 2;
  i = 0;
  while (++i <= MEM_SIZE)
    {
      sdl_square(arena->graph.sdl_surface, &pos, size - 1,
		 pick_color(arena->proprio[i - 1]));
      pos.x += size;
      if (i % 128 == 0)
	{
	  pos.y += size;
	  pos.x = 30;
	}
    }
}
*/
