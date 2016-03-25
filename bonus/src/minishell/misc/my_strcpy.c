/*
** my_strcpy.c for minishell1 in /mnt/hgfs/Shared/Rendu/PSU/PSU_2015_minishell1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Tue Jan 12 21:42:31 2016 victor sousa
** Last update Fri Mar 25 10:25:33 2016 Victor Sousa
*/

#include	"corewar.h"

char		*my_strcpy(char *dest, char *src)
{
  int   i;

  i = -1;
  while (src[++i])
    dest[i] = src[i];
  dest[i] = '\0';
  return (dest);
}
