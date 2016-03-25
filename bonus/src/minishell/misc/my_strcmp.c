/*
** my_strcmp.c for minishell1 in /mnt/hgfs/Shared/Rendu/PSU/PSU_2015_minishell1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Sun Jan 24 18:52:59 2016 victor sousa
** Last update Fri Mar 25 10:25:28 2016 Victor Sousa
*/

#include		"corewar.h"

int			my_strcmp(char *s1, char *s2)
{
  int			i;

  if (my_strlen(s1) != my_strlen(s2))
    return (0);
  i = 0;
  while (s1[i] && s2[i])
    {
      if (s1[i] != s2[i])
	return (0);
      i++;
    }
  return (1);
}
