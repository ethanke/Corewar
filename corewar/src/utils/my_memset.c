/*
** my_memset.c for corewar in /Users/sousa_v/Shared/rendu/cpe/Coreware_temp/corewar/src/utils/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Mon Mar 14 17:22:35 2016 Victor Sousa
** Last update Mon Mar 14 17:25:29 2016 Victor Sousa
*/

#include		"corewar.h"

void			my_memset(void *ptr, int size, char c)
{
  int			i;
  char			*buf;

  buf = ptr;
  i = -1;
  while (++i < size)
    buf[i] = c;
}
