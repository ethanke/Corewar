/*
** my_strcat.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/asm/utils/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Tue Mar 22 23:40:01 2016 Ethan Kerdelhue
** Last update Tue Mar 22 23:40:08 2016 Ethan Kerdelhue
*/

#include "asm.h"

char 		*my_strcat(char *dest, char *src)
{
  int 		len;
  int		i;

  len = my_strlen(dest);
  i = 0;
  while(src[i])
    {
      dest[len + i] = src[i];
		i = i + 1;
    }
  dest[len + i] = '\0';
  return (dest);
}
