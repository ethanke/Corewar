/*
** epur_cw.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/asm/utils/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Tue Mar 22 22:58:11 2016 Ethan Kerdelhue
** Last update Tue Mar 22 22:58:19 2016 Ethan Kerdelhue
*/

#include "asm.h"

char	*epur_cw(char *str)
{
  char	*new;
  int	i;
  int	j;

  i = 0;
  j = 0;
  new = malloc(my_strlen(str));
  while (str[i])
    {
      if ((str[i] != 'r') && (str[i] != LABEL_CHAR) & (str[i] != DIRECT_CHAR))
	{
	  new[j] = str[i];
	  j++;
	}
      i++;
    }
  new[j] = 0;
  return (new);
}
