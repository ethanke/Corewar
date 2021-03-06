/*
** load_champion.c for corewar in /Users/sousa_v/Shared/rendu/cpe/Coreware_temp/corewar/src/loading/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Mon Mar  7 01:11:01 2016 Victor Sousa
** Last update Tue Mar 22 15:18:43 2016 Kerdelhue Ethan
*/

#include		"corewar.h"

int			is_a_champ_path(char *str)
{
  if (str[my_strlen(str) - 1] == 'r' &&
      str[my_strlen(str) - 2] == 'o' &&
      str[my_strlen(str) - 3] == 'c' &&
      str[my_strlen(str) - 4] == '.')
    return (1);
  return (0);
}

int			count_champ(int ac, char **av)
{
  int			out;
  int			i;

  i = 0;
  out = 0;
  while (i < ac)
    {
      if (is_a_champ_path(av[i]))
	out++;
      i++;
    }
  return (out);
}

t_champ			init_champion(int ac, char **av)
{
  t_champ		champ;
  int			i;

  if ((champ.nbr_champ = count_champ(ac, av)) < 1)
    my_putstr_error("Not enought champion\n", 1);
  champ.live = xmalloc(sizeof(int) * (champ.nbr_champ));
  i = -1;
  while (++i < champ.nbr_champ)
    champ.live[i] = 0;
  champ.id_champ = xmalloc(sizeof(int) * (champ.nbr_champ));
  champ.header = xmalloc(sizeof(header_t) * (champ.nbr_champ));
  champ.instru = xmalloc(sizeof(char *) * (champ.nbr_champ));
  champ.process = xmalloc(sizeof(t_process *) * (champ.nbr_champ));
  champ.last_live = 0;
  load_process(&champ, ac, av);
  return (champ);
}
