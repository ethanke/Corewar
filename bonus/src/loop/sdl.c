/*
** sdl.c for corewar in /Users/sousa_v/Shared/rendu/cpe/Coreware_temp/bonus/src/loop/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Wed Mar 16 22:32:45 2016 Victor Sousa
** Last update Thu Mar 17 02:33:06 2016 Victor Sousa
*/

#include		"corewar.h"

void			my_sdl_setpixel(SDL_Surface *scr, int x, int y,
				    unsigned int color)
{
  *((unsigned int *)scr->pixels + WIDTH * y + x) = color;
}

void			sdl_square(SDL_Surface *scr, t_pos *beg, int size,
				   unsigned int color)
{
  t_pos			pos;

  pos.x = beg->x - 1;
  while (++pos.x < beg->x + size)
    {
      pos.y = beg->y - 1;
      while (++pos.y < beg->y + size)
	my_sdl_setpixel(scr, pos.x, pos.y, color);
    }
}

void			init_sdl(t_arena *arena)
{
  arena->mode = M_SDL;
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    my_putstr_error("Can't init SDL\n", 1);
  atexit(SDL_Quit);
  if ((arena->graph.sdl_surface =
       SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_HWSURFACE )) == NULL)
    my_putstr_error("Can't set video mode\n", 1);
}

void			print_sdl(t_arena *arena)
{
  t_pos			pos;
  int			i;
  int			size;

  SDL_LockSurface(arena->graph.sdl_surface);
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
  SDL_UnlockSurface(arena->graph.sdl_surface);
  SDL_UpdateRect(arena->graph.sdl_surface, 0, 0, 0, 0);
}
