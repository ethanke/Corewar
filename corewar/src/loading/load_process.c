/*
** load_process.c for corewar in /Users/sousa_v/Shared/rendu/cpe/Coreware_temp/corewar/src/loading/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Mon Mar  7 02:10:33 2016 Victor Sousa
** Last update Sun Mar 13 14:06:23 2016 Victor Sousa
*/

#include		"corewar.h"

void			print_champ(t_champ *champ)
{
  int		 	i;

  i = -1;

  while (++i < champ->nbr_champ)
    my_printf("champ %d\n\tid:%d\n\tname:%s\n\tcomment:%s\n\tprog_size:%d\n\tpc_pos:%d\n\tinstruction:%s\n\n",
	      i + 1,
              champ->id_champ[i],
	      champ->header[i].prog_name,
	      champ->header[i].comment,
	      champ->header[i].prog_size,
	      champ->pc_pos[i],
	      champ->process[i]);
}

void			load_process(t_champ *champ, int ac, char **av)
{
  int			i;
  int			j;
  int			read_id_needed;
  int			fd;

  j = 0;
  i = -1;
  while (++i < ac)
    {
      i += (read_id_needed = is_a_id_request(av[i])) * 2;
      if (is_a_champ_path(av[i]))
	{
	  if ((fd = open(av[i], O_RDONLY)) < 0)
	    my_putstr_error("couldn't open one of the requested champion\n", 1);
	  champ->id_champ[j] = get_id(&read_id_needed, i, av);
	  champ->header[j] = get_header(fd);
	  champ->pc_pos[j] = MEM_SIZE / champ->nbr_champ * (j + 1);
	  /*champ->instru[j] = get_instruct(fd, champ->header[j].prog_size);*/
	  j++;
	}
    }
  check_id(champ);

  print_champ(champ);
}
