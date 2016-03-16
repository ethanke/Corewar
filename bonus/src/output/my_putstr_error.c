/*
** my_putstr_error.c for corewar in /Users/sousa_v/Shared/rendu/cpe/Corewar_temp/corewar/src/output/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Mon Mar  7 00:17:39 2016 Victor Sousa
** Last update Mon Mar  7 00:22:18 2016 Victor Sousa
*/

#include	"corewar.h"

void		my_putstr_error(char *str, int do_exit)
{
  int		i;

  if (str != NULL)
    {
      i = -1;
      while (str[++i])
	my_putchar(str[i]);
    }
  if (do_exit != 0)
    exit(do_exit);
}
