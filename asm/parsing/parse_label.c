/*
** parse_label.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/asm/parsing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Tue Mar 22 22:59:15 2016 Ethan Kerdelhue
** Last update Tue Mar 22 23:08:08 2016 Ethan Kerdelhue
*/

#include "asm.h"

int			get_label_value(t_corlabel *label, char *str)
{
  t_corlabel		*tmp;
  int			mempos;

  mempos = -1;
  tmp = label;
  while (tmp != NULL)
    {
      if (my_strcmp(tmp->name, str) == 0)
	mempos = tmp->mempos;
      tmp = tmp->next;
    }
  if (mempos == -1)
    {
      my_putstr("[FILE] Error : Label -> ");
      my_putstr(str);
      putError(" don't exist");
    }
  return (mempos);
}

void			convert_label_value(t_corlabel *label, t_corline *corline)
{
  t_corline	*corline_tmp;
  int		i;

  i = 0;
  corline_tmp = corline;
  while (corline_tmp != NULL)
    {
      while (corline_tmp->tab_args[i].value != NULL)
	{
	  if ((checkLabExist(label, corline_tmp->tab_args[i].value) == 1))
	    {
	      corline_tmp->tab_args[i].value
	      = my_itoa(get_label_value(label, corline_tmp->tab_args[i].value)
			- get_mem_size(corline_tmp->tab_args));
	    }
	  i++;
	}
      i = 0;
      corline_tmp = corline_tmp->next;
    }
}
