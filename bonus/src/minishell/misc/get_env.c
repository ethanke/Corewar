/*
** get_env.c for minishell1 in /mnt/hgfs/Shared/Rendu/PSU/PSU_2015_minishell1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Sun Jan 24 03:38:03 2016 victor sousa
** Last update Fri Mar 25 10:12:34 2016 Victor Sousa
*/

#include		"corewar.h"

int			how_much_row(char **src)
{
  int			i;

  i = 0;
  while (src[i] != 0)
    i++;
  return (i);
}

char			**get_env(char **src)
{
  char			**dest;
  int			y;
  int			ysize;
  int			xsize;

  y = -1;
  ysize = how_much_row(src);
  dest = xmalloc(sizeof(char *) * (ysize + 1));
  while (++y < ysize)
    {
      xsize = my_strlen(src[y]);
      dest[y] = xmalloc(sizeof(char) * (xsize + 1));
      dest[y] = my_strcpy(dest[y], src[y]);
    }
  dest[y] = '\0';
  return (dest);
}
