/*
** main.c for corewar in /home/vicostudio/rendu/cpe/CorewarGIT/corewar
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Mon Feb 29 22:21:44 2016 victor sousa
** Last update Wed Mar 16 21:57:33 2016 Victor Sousa
*/

#include	"corewar.h"

int			my_strcmp(char *s1, char *s2)
{
  int			i;

  i = 0;
  while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
    i++;
  return (s1[i] - s2[i]);
}

void		loop_sdl(t_arena *arena)
{
  SDL_Surface *screen;

  (void)arena;
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    my_putstr_error("Can't init SDL\n", 1);
  atexit(SDL_Quit);
  if ((screen = SDL_SetVideoMode( 640, 480, 16, SDL_HWSURFACE )) == NULL)
    my_putstr_error("Can't set video mode\n", 1);
}

void		choose_loop(t_arena *arena, int ac, char **av)
{
  int		i;

  i = -1;
  while (++i < ac)
    {
      if (my_strcmp(av[i], "--sdl") == 0)
	loop_sdl(arena);
    }
  main_loop(arena);
}

int		main(int ac, char **av, char **env)
{
  t_arena	arena;
  t_champ	champion;

  if (env == NULL)
    my_putstr_error("can't read env\n", 1);
  verif_arg(ac, av);

  champion = init_champion(ac, av);
  arena = init_arena(&champion);
  my_printf("map looks like :\n");
  print_arena_proprio(&arena);

  my_putstr("program running\n");
  choose_loop(&arena, ac, av);
  return (0);
}
