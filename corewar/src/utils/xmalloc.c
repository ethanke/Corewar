/*
** xmalloc.c for  in /Users/sousa_v/Shared/rendu/cpe/Coreware_temp/corewar/src/utils/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Mon Mar  7 01:35:17 2016 Victor Sousa
** Last update Mon Mar  7 01:37:48 2016 Victor Sousa
*/

#include	"corewar.h"

void		*xmalloc(int size)
{
  void		*ptr;

  if ((ptr = malloc(size)) == NULL)
    my_putstr_error("Impossible to allocate Memory\n", 1);
  return (ptr);
}
