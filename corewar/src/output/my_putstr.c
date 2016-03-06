/*
** my_putstr.c for corewar in /Users/sousa_v/Shared/rendu/cpe/Corewar_temp/corewar/src/output/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Mon Mar  7 00:08:33 2016 Victor Sousa
** Last update Mon Mar  7 00:09:53 2016 Victor Sousa
*/

#include	"corewar.h"

void		my_putstr(char *str)
{
  int		i;

  if (str != NULL)
    {
      i = -1;
      while (str[++i])
	my_putchar(str[i]);
    }
}
