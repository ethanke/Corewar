/*
** load_process.c for corewar in /Users/sousa_v/Shared/rendu/cpe/Coreware_temp/corewar/src/loading/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Mon Mar  7 02:10:33 2016 Victor Sousa
** Last update Mon Mar  7 04:11:23 2016 Victor Sousa
*/

#include		"corewar.h"

void			load_process(t_champ *champ, int ac, char **av)
{
  int			i;
  int			j;
  int			read_id_needed;

  j = 0;
  i = -1;
  while (++i < ac)
    {
      i += (read_id_needed = is_a_id_request(av[i])) * 2;
      if (is_a_champ_path(av[i]))
	{
	  my_putstr("champ found\n");
	  champ->id_champ[j] = get_id(&read_id_needed, i, av);

	  my_putchar('\n');
	  j++;
	}
    }
  check_id(champ);
}
