/*
** parse_mem.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/asm/parsing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Tue Mar 22 23:08:44 2016 Ethan Kerdelhue
** Last update Tue Mar 22 23:08:52 2016 Ethan Kerdelhue
*/

#include "asm.h"

int	get_mem_size(t_corarg *tab_args)
{
  int	i;
  int	memsize;

  memsize = 0;
  i = 0;
  while (tab_args[i].type != -3)
    {
      if ((tab_args[i]).type == 1)
	memsize += 1;
      else if ((tab_args[i]).type == 2)
	memsize += 4;
      else if ((tab_args[i]).type == 4)
	memsize += 2;
      else if ((tab_args[i]).type == 8)
	memsize += 4;
      i += 1;
    }
  return (memsize + 1);
}

int	calc_mem_pos(t_corline *tmp, t_corline *corline)
{
  int		mempos;
  t_corline	*corl;

  corl = corline;
  while (corl->next != NULL)
    corl = corl->next;
  mempos = corl->mempos;
  if (((my_strcmp(tmp->instruction, "live") == 0) ||
      (my_strcmp(tmp->instruction, "fork") == 0) ||
      (my_strcmp(tmp->instruction, "lfork") == 0) ||
      (my_strcmp(tmp->instruction, "zjmp") == 0)))
      mempos -= 1;
  mempos += get_mem_size(tmp->tab_args) + 1;
  return (mempos);
}
