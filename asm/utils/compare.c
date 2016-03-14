/*
** compare.c for  in /home/sagot/rendu/Corewar/asm/utils/
**
** Made by Guillaume SAGOT
** Login   <sagot_g@epitech.eu>
**
** Started on  Mon Mar 14 15:36:26 2016 Guillaume SAGOT
** Last update Mon Mar 14 15:40:27 2016 Guillaume SAGOT
*/

#include "assembly.h"

int     my_strcmp(char *s1, char *s2)
{
  if (s1[0] == s2[0])
    {
      if (s1[0] == '\0')
        return (0);
      return (my_strcmp(s1 + 1, s2 + 1));
    }
  else
    return (s1[0] - s2[0]);
}

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;
  int	result;

  i = 0;
  result = 0;
  while (s1[i] == s2[i] && i < (n - 1))
    {
      if (s1[i] == '\0' && s2[i] == '\0')
	return (0);
      i++;
    }
  if (s1[i] != s2[i])
    result = s1[i] - s2[i];
  return (result);
}
