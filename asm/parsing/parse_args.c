/*
** parse_args.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/asm/parsing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Tue Mar 22 23:05:46 2016 Ethan Kerdelhue
** Last update Tue Mar 22 23:05:58 2016 Ethan Kerdelhue
*/

#include "asm.h"

int		count_args(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
      i++;
  return (i - 1);
}
