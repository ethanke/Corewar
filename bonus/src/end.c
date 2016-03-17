/*
** end.c for corewar in /Users/sousa_v/Shared/rendu/cpe/Coreware_temp/corewar/src/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Mon Mar 14 18:30:41 2016 Victor Sousa
** Last update Thu Mar 17 03:43:38 2016 Victor Sousa
*/

#include		"corewar.h"

void			end_prog(t_arena *arena)
{
  int			i;

  i = -1;
  while (++i < arena->champ->nbr_champ)
    {
      free(arena->champ->instru[i]);
      free_process(arena->champ->process[i]);
    }
  free(arena->champ->live);
  free(arena->champ->id_champ);
  free(arena->champ->header);
  free(arena->champ->instru);
  free(arena->champ->process);
  free(arena->arena);
  free(arena->proprio);
  TTF_CloseFont(arena->graph.font);
  TTF_Quit();
  SDL_FreeSurface(arena->graph.sdl_surface);
  SDL_Quit();
}
