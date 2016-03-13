/*
** xmalloc.c for  in /Users/sousa_v/Shared/rendu/cpe/Coreware_temp/corewar/src/utils/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Mon Mar  7 01:35:17 2016 Victor Sousa
** Last update Sun Mar 13 13:24:09 2016 Victor Sousa
*/

#include	"corewar.h"

char            *my_xrealloc(char *str, int size)
{
  char          *output;
  int           i;

  output = xmalloc(size);
  i = -1;
  while (str[++i])
    output[i] = str[i];
  output[i] = 0;
  return (output);
}

void		*xmalloc(int size)
{
  void		*ptr;

  if ((ptr = malloc(size)) == NULL)
    my_putstr_error("Impossible to allocate Memory\n", 1);
  return (ptr);
}
