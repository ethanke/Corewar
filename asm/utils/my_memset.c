/*
** my_memset.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/asm/utils/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Mon Mar 14 05:23:38 2016 Ethan Kerdelhue
** Last update Mon Mar 14 05:23:43 2016 Ethan Kerdelhue
*/

#include "asm.h"

void    *my_memset(void *s, size_t n, int c)
{
  size_t        i;
  char          *d;

  d = s;
  i = 0;
  while (i < n)
    {
      *d++ = c;
      i++;
    }
  return (s);
}
