/*
** id_stuff.c for corewar in /Users/sousa_v/Shared/rendu/cpe/Coreware_temp/corewar/src/loading/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Mon Mar  7 04:11:03 2016 Victor Sousa
** Last update Thu Mar 17 04:50:51 2016 Victor Sousa
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

int			get_id(int *read_id_needed, int i, char **av)
{
  int			out;

  if (*read_id_needed)
    out = my_getnbr(av[i - 1]);
  else
    out = -1;
  *read_id_needed = 0;
  return (out);
}

int			is_id_taken(int *id_tab, int id, int size)
{
  int			i;

  i = -1;
  while (++i < size)
    {
      if (id_tab[i] == id)
	return (1);
    }
  return (0);
}

void			check_id(t_champ *champ)
{
  int			i;
  int			id;

  i = -1;
  id = -1;
  while (++i < champ->nbr_champ)
    {
      if (champ->id_champ[i] == -1)
	{
	  while (is_id_taken(champ->id_champ, ++id, champ->nbr_champ));
	  champ->id_champ[i] = id;
	}
    }
  i = -1;
  while (++i < champ->nbr_champ)
    champ->process[i] = fill_process(MEM_SIZE / champ->nbr_champ * i,
				     champ->id_champ[i]);
}
