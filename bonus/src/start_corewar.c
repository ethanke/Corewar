/*
** main.c for corewar in /home/vicostudio/rendu/cpe/CorewarGIT/corewar
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Mon Feb 29 22:21:44 2016 victor sousa
** Last update Fri Mar 25 13:21:38 2016 Victor Sousa
*/

#include	"corewar.h"

void		choose_graphique(t_arena *arena, int ac, char **av)
{
  int		i;

  arena->mode = M_NONE;
  i = -1;
  while (++i < ac)
    {
      if (my_strcmp(av[i], "--sdl") == 1)
	init_sdl(arena);
      if (my_strcmp(av[i], "--server") == 1)
	arena->mode = M_SERVER;
    }
}

int		start_corewar(int ac, char **av, char **env)
{
  t_arena	arena;
  t_champ	champion;

  if (env == NULL)
    my_putstr_error("can't read env\n", 1);
  verif_arg(ac, av);
  champion = init_champion(ac, av);
  arena = init_arena(&champion);
  choose_graphique(&arena, ac, av);
  main_loop(&arena);
  return (0);
}
