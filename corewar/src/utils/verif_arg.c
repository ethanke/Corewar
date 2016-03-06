/*
** verif_arg.c for corewar in /Users/sousa_v/Shared/rendu/cpe/Corewar_temp/corewar/src/utils/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sun Mar  6 23:39:21 2016 Victor Sousa
** Last update Sun Mar  6 23:58:28 2016 Victor Sousa
*/

#include		"corewar.h"

int			verif_arg(int ac, char **av)
{
  if (ac < 3)
    return (0);
  (void)av;
  return (1);
}
