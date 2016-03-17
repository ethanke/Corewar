/*
** sdl_print.c for corewar in /Users/sousa_v/Shared/rendu/cpe/Coreware_temp/bonus/src/loop/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Thu Mar 17 04:46:51 2016 Victor Sousa
** Last update Thu Mar 17 04:47:19 2016 Victor Sousa
*/

#include		"corewar.h"

void			print_sdl(t_arena *arena)
{
  t_pos			pos;
  SDL_Rect		text_pos;
  int			i;
  int			size;
  char			str[100];

  SDL_FillRect(arena->graph.sdl_surface, NULL, 0x00000000);

  sprintf(str, "cycle to die: %d", arena->cycle_to_die);
  arena->graph.title = TTF_RenderText_Blended(arena->graph.font, str, arena->graph.title_col);
  text_pos.x = 25;
  text_pos.y = 70;
  SDL_BlitSurface(arena->graph.title, NULL, arena->graph.sdl_surface, &text_pos);

  sprintf(str, "total cycle: %d", arena->total_cycle);
  arena->graph.title = TTF_RenderText_Blended(arena->graph.font, str, arena->graph.title_col);
  text_pos.x = 25;
  text_pos.y = 90;
  SDL_BlitSurface(arena->graph.title, NULL, arena->graph.sdl_surface, &text_pos);

  sprintf(str, "total live: %d", arena->total_live);
  arena->graph.title = TTF_RenderText_Blended(arena->graph.font, str, arena->graph.title_col);
  text_pos.x = 25;
  text_pos.y = 110;
  SDL_BlitSurface(arena->graph.title, NULL, arena->graph.sdl_surface, &text_pos);

  arena->graph.title = TTF_RenderText_Blended(arena->graph.font_title, "Corewar!", arena->graph.title_col);
  text_pos.x = WIDTH / 2 - arena->graph.title->w / 2;
  text_pos.y = 15;
  SDL_BlitSurface(arena->graph.title, NULL, arena->graph.sdl_surface, &text_pos);

  text_pos.x = WIDTH / 2 - arena->graph.miam->w / 2;
  text_pos.y = HEIGHT - arena->graph.miam->h;
  SDL_BlitSurface(arena->graph.miam, NULL, arena->graph.sdl_surface, &text_pos);
  SDL_LockSurface(arena->graph.sdl_surface);
  size = (WIDTH - 80) / (MEM_SIZE / (MEM_SIZE / 128)) + 1;
  pos.x = 30;
  pos.y = HEIGHT / 2 - ((MEM_SIZE / 128) * size) / 2 - 15;
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
