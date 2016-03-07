/*
** my_putstr.c for my_putstr in /home/leandr_g/rendu/Piscine_C_J04
** 
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
** 
** Started on  Thu Oct  1 08:59:15 2015 Gaëtan Léandre
** Last update Mon Nov 16 16:49:20 2015 Gaëtan Léandre
*/

#include "my_printf.h"

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    my_putstr("(null)");
  else
    {
      while (str[i] != '\0')
	{
	  my_putchar(str[i]);
	  i++;
	}
    }
}
