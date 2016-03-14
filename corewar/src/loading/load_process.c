/*
** load_process.c for corewar in /Users/sousa_v/Shared/rendu/cpe/Coreware_temp/corewar/src/loading/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Mon Mar  7 02:10:33 2016 Victor Sousa
** Last update Mon Mar 14 17:19:30 2016 Victor Sousa
*/

#include		"corewar.h"

void			print_champ(t_champ *champ)
{
  int		 	i;

  i = -1;

  while (++i < champ->nbr_champ)
    {
      my_printf("champ %d\n\tid:%d\n\tmagic:0x%x\n\tname:%s\n\tcomment:%s\n\tprog_size:%d\n\tpc_pos:%d",
		i + 1,
		champ->id_champ[i],
		champ->header[i].magic,
		champ->header[i].prog_name,
		champ->header[i].comment,
		champ->header[i].prog_size,
		champ->pc_pos[i]);
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
	  if (champ->header[j].prog_size > MEM_SIZE / 4)
	    my_putstr_error("Error, size of the program is too big\n", 1);
	  champ->pc_pos[j] = MEM_SIZE / champ->nbr_champ * j;
	  champ->instru[j] = get_instruct(fd, champ->header[j].prog_size);
	  j++;
	}
    }
  check_id(champ);

  print_champ(champ);
}
