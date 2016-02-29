/*
** labrary_lenght.c for  in /home/sagot_g/rendu/PSU_2015_my_printf
**
** Made by guillaume sagot
** Login   <sagot_g@epitech.net>
**
** Started on  Mon Nov  2 16:20:06 2015 guillaume sagot
** Last update Wed Nov  4 19:25:53 2015 guillaume sagot
*/

#include "printf.h"

int             my_strlen_tabs(char **tab)
{
  int           i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}

void		display_zero(char c)
{
  int		i;

  i = 0;
  while (c * i < 64)
  {
    my_put_nbr(0);
    i = i * 8;
  }
}

int		my_strlen(char *str)
{
  int		len;

  while (str[len])
    len++;
  return (len);
}

int	     	my_str_isprintable(char *str)
{
  int  		i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '\0')
        return (1);
      else if (str[i] >= 33 && str[i] <= 126)
        return (1);
      else
        return (0);
      i++;
    }
  return (1);
}
