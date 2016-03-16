/*
** list.c for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/corewar/src/utils/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Mon Mar  7 02:12:18 2016 Gaëtan Léandre
** Last update Tue Mar 15 19:14:15 2016 Victor Sousa
*/

#include "corewar.h"

t_process	*create_list()
{
  t_process	*process;

  process = xmalloc(sizeof(process));
  process->child = NULL;
  process->next = NULL;
  return (process);
}

void		init_child(t_process *father, t_process *child)
{
  child->carry = father->carry;
  child->live = father->live;
  child->living = father->living;
  child->cycle = father->cycle;
}

t_process	*add_child(t_process *father)
{
  t_process	*tmp;
  t_process	*child;

  child = create_list();
  init_child(father, child);
  if (father->child == NULL)
    father->child = child;
  else
    {
      tmp = father->child;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = child;
    }
  return (child);
}

void		free_process(t_process *process)
{
  t_process	*tmp;

  while (process != NULL)
    {
      free(process->reg);
      if (process->child != NULL)
	free_process(process->child);
      tmp = process;
      process = process->next;
      free(tmp);
    }
}
