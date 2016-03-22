/*
** write_args.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/asm/writing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Tue Mar 22 23:38:00 2016 Ethan Kerdelhue
** Last update Tue Mar 22 23:44:35 2016 Ethan Kerdelhue
*/

#include "asm.h"

void	write_args_wpb(int fd, t_corarg *args)
{
  int	i;

  i = 0;
  while (args[i].type != -3)
    {
      if (args[i].type == T_REG)
	put_param(my_getnbr(args[i].value), 1, fd);
      else if (args[i].type == T_DIR)
	put_param(my_getnbr(args[i].value), 4, fd);
      else if (args[i].type == T_IND)
	put_param(my_getnbr(args[i].value), 2, fd);
      i++;
    }
}

void	write_args(int fd, t_corarg *args)
{
  int	i;

  i = 0;
  write_byte_param(fd, args);
  while (args[i].type != -3)
    {
      if (args[i].type == T_REG)
	put_param(my_getnbr(args[i].value), 1, fd);
      else if (args[i].type == T_DIR)
	put_param(my_getnbr(args[i].value), 4, fd);
      else if (args[i].type == T_IND)
	put_param(my_getnbr(args[i].value), 2, fd);
      i++;
    }
}
