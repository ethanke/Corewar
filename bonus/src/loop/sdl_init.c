/*
** sdl.c for corewar in /Users/sousa_v/Shared/rendu/cpe/Coreware_temp/bonus/src/loop/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Wed Mar 16 22:32:45 2016 Victor Sousa
** Last update Thu Mar 17 04:52:27 2016 Victor Sousa
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
  if (TTF_Init() == -1)
    my_putstr_error("Can't init TTF\n", 1);
  arena->graph.font_title = NULL;
  if ((arena->graph.font_title = TTF_OpenFont(FONT_PATH, 65)) == NULL)
    my_putstr_error("Can't open font\n", 1);
  arena->graph.font = NULL;
  if ((arena->graph.font = TTF_OpenFont(FONT_PATH, 20)) == NULL)
    my_putstr_error("Can't open font\n", 1);
  arena->graph.title_col.r = 200;
  arena->graph.title_col.g = 200;
  arena->graph.title_col.b = 200;
  arena->graph.miam = NULL;
  if ((arena->graph.miam = IMG_Load("sprites/coquillette_jambon.png")) == NULL)
    {
      my_printf("Can't open the coquillette jambon image.. i'm hungry");
      my_putstr_error(" i will not fight until you feed me.....\n", 1);
    }
}
