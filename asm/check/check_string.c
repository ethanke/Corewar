/*
** check_string.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/asm/check/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Tue Mar 22 22:53:35 2016 Ethan Kerdelhue
** Last update Tue Mar 22 22:53:40 2016 Ethan Kerdelhue
*/

#include "asm.h"

int		is_alph_char(char c, char *delim)
{
  int		i;

  i = -1;
  while (delim[++i])
    {
      if (delim[i] == c)
	return (c);
    }
  return (0);
}

int		my_str_isalpha(char *str)
{
  if (*str == 0)
    return (0);
  while (*str != 0)
    {
      if (!is_alph_char(*str, LABEL_CHARS))
	return (0);
      str++;
    }
  return (1);
}

int			my_char_is_num(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}
