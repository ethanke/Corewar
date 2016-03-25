/*
** main.c for corewar in /Users/sousa_v/Shared/rendu/cpe/Coreware_temp/bonus/src/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Fri Mar 25 11:22:59 2016 Victor Sousa
** Last update Fri Mar 25 11:27:36 2016 victor sousa
*/

#include	"corewar.h"

int		need_shell(int ac, char **av)
{
  int		i;

  i = -1;
  while (++i < ac)
    {
      if (my_strcmp(av[i], "--shell") == 1)
	return (1);
    }
  return (0);
}

int		main(int ac, char **av, char **env)
{
  if (need_shell(ac, av))
    start_shell(ac, av, env);
  else
    start_corewar(ac, av, env);
  return (0);
}
