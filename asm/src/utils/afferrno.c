/*
** afferrno.c for  in /home/sagot/rendu/Corewar/asm/src/utils/
**
** Made by Guillaume SAGOT
** Login   <sagot_g@epitech.eu>
**
** Started on  Tue Mar  1 00:51:52 2016 Guillaume SAGOT
** Last update Tue Mar  1 02:04:03 2016 Guillaume SAGOT
*/

#include "assembly.h"

void		putError(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    write(2, &str[i++], 1);
}

void		printError(t_system *sys, char *str)
{
  my_printf(msg);
  my_printf("%s", sys->file_name)
}
