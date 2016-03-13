/*
** string.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/ethan/utils/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Fri Mar 11 18:19:15 2016 Ethan Kerdelhue
** Last update Sat Mar 12 23:47:06 2016 Ethan Kerdelhue
*/

#include "asm.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
      i++;
  return (i);
}

void	putError(char *str)
{
  write(1, str, my_strlen(str));
  exit(-1);
}
