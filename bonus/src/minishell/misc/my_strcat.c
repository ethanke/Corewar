/*
** my_strcat.c for minishell1 in /home/vicostudio/Shared/Rendu/PSU/PSU_2015_minishell1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Sun Jan 24 19:21:20 2016 victor sousa
** Last update Fri Mar 25 10:25:22 2016 Victor Sousa
*/

#include		"corewar.h"

char			*my_strcat(char *dest, char *src)
{
  int			i;
  int			j;

  j = 0;
  i = my_strlen(dest);
  while (src[j])
    dest[i++] = src[j++];
  dest[i] = '\0';
  return (dest);
}
