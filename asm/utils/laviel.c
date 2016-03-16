/*
** laviel.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/asm/utils/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Wed Mar 16 04:15:48 2016 Ethan Kerdelhue
** Last update Wed Mar 16 04:46:51 2016 Ethan Kerdelhue
*/

#include "asm.h"

char		check(char c, char *delim)
{
  int		i;

  i = -1;
  while (delim[++i])
    if (delim[i] == c)
      return (0);
  return (c);
}

int		countchars(char *str, char *delim)
{
  int		i;

  i = -1;
  while (check(str[i], delim))
    i++;
  return (i + 1);
}

int		countwords(char *str, char *delim)
{
  int		i;
  int		count;

  i = -1;
  count = 1;
  while (str[++i])
    if (!check(str[i], delim))
      {
	count++;
	while (str[0] && !check(str[i], delim))
	  i++;
      }
return (count);
}

char		**strtowordtab(char *str, char *delim)
{
  int		i;
  int		j;
  int		k;
  char		**tab;

  i = -1;
  j = -1;
  tab = xmalloc(countwords(str, delim));
  while (str[++i])
    {
      tab[++j] = xmalloc(countchars(&str[i], delim));
      k = -1;
      while (check(str[i], delim))
	tab[j][++k] = str[i++];
      tab[j][++k] = 0;
      while (str[i] && !check(str[i], delim))
	i++;
    }
  tab[++j] = NULL;
  return (tab);
}
