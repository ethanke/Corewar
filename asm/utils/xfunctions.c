/*
** xfunctions.c for  in /home/sagot/rendu/Corewar/sources/tools/
**
** Made by Guillaume SAGOT
** Login   <sagot_g@epitech.eu>
**
** Started on  Mon Feb 29 21:24:53 2016 Guillaume SAGOT
** Last update Mon Mar 14 11:31:02 2016 Guillaume SAGOT
*/

#include "assembly.h"

void            *xmalloc(int size)
{
  void          *i;

  i = malloc(size);
  if (i == NULL)
    {
      write(2, "Error on malloc\n", 16);
      exit(1);
    }
  return (i);
}

ssize_t         xwrite(int fd, const void *buf, size_t count)
{
  ssize_t       tmp;
  if ((tmp = write(fd, buf, count)) == -1)
    {
      write(2, "Write error\n", 12);
      exit(0);
    }
  return (tmp);
}

void		xfree(void *ptr)
{
  if (ptr != NULL)
    free(ptr);
}
