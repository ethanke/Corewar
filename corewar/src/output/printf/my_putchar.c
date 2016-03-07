/*
** my_putchar.c for my_putchar in /home/leandr_g/rendu/Piscine_C_J07/lib/my
** 
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
** 
** Started on  Tue Oct  6 10:35:20 2015 Gaëtan Léandre
** Last update Thu Nov 12 14:42:38 2015 Gaëtan Léandre
*/

#include "my_printf.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
