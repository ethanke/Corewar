/*
** free_list.c for minishell1 in /mnt/hgfs/Shared/Rendu/PSU/PSU_2015_minishell1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Sun Jan 24 22:15:14 2016 victor sousa
** Last update Fri Mar 25 10:12:19 2016 Victor Sousa
*/

#include		"corewar.h"

void			free_list(t_node *list)
{
  t_node		*tmp;
  t_node		*tmpnext;

  tmp = list;
  while (tmp != NULL)
    {
      tmpnext = tmp->next;
      free(tmp);
      tmp = tmpnext;
    }
  return;
}
