/*
** linked_list.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/asm/utils/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Mon Mar 14 05:47:59 2016 Ethan Kerdelhue
** Last update Wed Mar 16 20:04:23 2016 Ethan Kerdelhue
*/

#include "asm.h"

t_corlabel	*corlabel_init()
{
  t_corlabel	*corlabel;

  corlabel = malloc(sizeof(*corlabel));
  corlabel->name = NULL;
  corlabel->mempos = 0;
  corlabel->next = NULL;
  return (corlabel);
}

void		create_label(t_corlabel *corlabel, t_corlabel label)
{
  t_corlabel	*tmp;
  t_corlabel	*new;

  tmp = corlabel;
  while (tmp->next != NULL)
    tmp = tmp->next;
  new = xmalloc(sizeof(t_corlabel));
  new->name = label.name;
  new->mempos = label.mempos;
  tmp->next = new;
  new->next = NULL;
}

t_corline	*corline_init()
{
  t_corline	*corline;

  corline = malloc(sizeof(*corline));
  corline->label = NULL;
  corline->instruction = NULL;
  corline->args = NULL;
  corline->nbr = 0;
  corline->mempos = 0;
  corline->tab_args = NULL;
  corline->next = NULL;
  corline->prev = NULL;
  return (corline);
}

void	create_line(t_corline *corline, t_corline line)
{
  t_corline	*tmp;
  t_corline	*new;

  tmp = corline;
  while(tmp->next != NULL)
    tmp = tmp->next;
  new = xmalloc(sizeof(t_corline));
  new->label = line.label;
  new->instruction = line.instruction;
  new->args = line.args;
  new->nbr = line.nbr;
  new->mempos = line.mempos;
  new->tab_args = line.tab_args;
  new->next = NULL;
  new->prev = tmp;
  tmp->next = new;
}
