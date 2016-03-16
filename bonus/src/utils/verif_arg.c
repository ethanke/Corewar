/*
** verif_arg.c for corewar in /Users/sousa_v/Shared/rendu/cpe/Corewar_temp/corewar/src/utils/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sun Mar  6 23:39:21 2016 Victor Sousa
** Last update Mon Mar  7 01:58:30 2016 Victor Sousa
*/

#include		"corewar.h"

void			verif_arg(int ac, char **av)
{
  if (ac < 2)
    my_putstr_error("not enought parameter\n", 1);
  (void)av;
}
