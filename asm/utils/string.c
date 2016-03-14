/*
** string.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/ethan/utils/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Fri Mar 11 18:19:15 2016 Ethan Kerdelhue
** Last update Mon Mar 14 16:15:21 2016 Guillaume SAGOT
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

void	msgError(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    write(2, &str[i++], 1);
}
