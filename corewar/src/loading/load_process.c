/*
** load_process.c for corewar in /Users/sousa_v/Shared/rendu/cpe/Coreware_temp/corewar/src/loading/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Mon Mar  7 02:10:33 2016 Victor Sousa
** Last update Mon Mar  7 03:27:27 2016 Victor Sousa
*/

#include		"corewar.h"

int			is_a_id_request(char *str)
{
  if (str[0] == '-' &&
      str[1] == 'n' &&
      str[2] == '\0')
    return (1);
  return (0);
}

void			load_process(t_champ *champ, int ac, char **av)
{
  int			i;
  int			read_id_needed;
  int			id;

  id = 0;
  i = -1;
  while (++i < ac)
    {
      i += (read_id_needed = is_a_id_request(av[i])) * 2;
      if (is_a_champ_path(av[i]))
	{
	  my_putstr("champ found\n");
	  if (read_id_needed)
	    {
	      champ->id_champ[i] = my_getnbr(av[i - 1]);
	      my_printf("id%d\n", champ->id_champ[i]);
	    }
	  else
	    champ->id_champ[i] = id++;

	  read_id_needed = 0;
	}
    }
  (void)champ;
  (void)ac;
  (void)av;
}
