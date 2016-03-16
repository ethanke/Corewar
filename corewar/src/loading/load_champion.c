/*
** load_champion.c for corewar in /Users/sousa_v/Shared/rendu/cpe/Coreware_temp/corewar/src/loading/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Tue Mar 15 17:23:54 2016 Victor Sousa
** Last update Wed Mar 16 19:11:55 2016 Victor Sousa
*/

#include		"corewar.h"

void			print_champ(t_champ *champ)
{
  int		 	i;

  i = -1;

  while (++i < champ->nbr_champ)
    {
      my_printf("champ %d\n\tid:%d\n\tmagic:0x%x\n\tname:%s",
		i + 1,
		champ->id_champ[i],
		champ->header[i].magic,
		champ->header[i].prog_name);
      my_printf("\n\tcomment:%s\n\tprog_size:%d\n\tpc_pos:%d",
		champ->header[i].comment,
		champ->header[i].prog_size,
		champ->process[i]->pc_pos);
      /*print_instruct(champ->instru[i], champ->header[i].prog_size);*/
      my_printf("\n\n");
    }
}

void			load_process(t_champ *champ, int ac, char **av)
{
  int			i;
  int			j;
  int			read_id_needed;
  int			fd;

  j = (i = -1) * 0;
  while (++i < ac)
    {
      i += (read_id_needed = is_a_id_request(av[i])) * 2;
      if (is_a_champ_path(av[i]))
	{
	  fd = xopen(av[i]);
	  champ->id_champ[j] = get_id(&read_id_needed, i, av);
	  champ->header[j] = get_header(fd);
	  if (champ->header[j].prog_size > MEM_SIZE / 4)
	    my_putstr_error("Error, size of the program is too big\n", 1);
	  champ->instru[j] = get_instruct(fd, champ->header[j].prog_size);
	  close(fd);
	  j++;
	}
    }
  check_id(champ);
}
