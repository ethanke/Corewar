/*
** load_champion.c for corewar in /Users/sousa_v/Shared/rendu/cpe/Coreware_temp/corewar/src/loading/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Mon Mar  7 01:11:01 2016 Victor Sousa
** Last update Mon Mar  7 01:30:39 2016 Victor Sousa
*/

#include		"corewar.h"

int			count_champ(int ac, char **av)
{
  int			out;
  int			i;

  i = 0;
  out = 0;
  while (i < ac)
    {
      if (av[i][my_strlen(av[i]) - 1] == 'r' &&
	  av[i][my_strlen(av[i]) - 2] == 'o' &&
	  av[i][my_strlen(av[i]) - 3] == 'c' &&
	  av[i][my_strlen(av[i]) - 4] == '.')
	out++;
      i++;
    }
  return (out);
}

t_champ			load_champion(int ac, char **av)
{
  t_champ		champ;

  if ((champ.nbr_champ = count_champ(ac, av)) < 1)
    my_putstr_error("Not enought champion\n", 1);
  return (champ);
}
