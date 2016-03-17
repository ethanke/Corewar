/*
** parse_instr.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/asm/parsing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Mon Mar 14 06:02:03 2016 Ethan Kerdelhue
** Last update Thu Mar 17 04:23:31 2016 Ethan Kerdelhue
*/

#include "asm.h"

int	containCommentChar(char *str)
{
  while (*str)
    {
      if (*str == COMMENT_CHAR)
	return (-1);
      (*str)++;
    }
  return (0);
}

void	checkCommentLine(char **tab)
{
  char	flag;
  int	i;

  i = 0;
  flag = 0;
  while (tab[i])
    {
      if (containCommentChar(tab[i]) == -1 || flag == 1)
	{
	  tab[i] = NULL;
	  flag = 1;
	}
      i++;
    }
}

int		count_args(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
      i++;
  return (i - 1); /* pour l'instruction */
}

int	get_size(t_corarg *tab_args)
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
  return (memsize + 1); /* + 1 pour l'octet representatif de l'instruction */
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
  mempos += get_size(tmp->tab_args) + 1;
  return (mempos);
}

void	create_corline_wl(t_corline tmp, t_corline *corline,
			  t_corlabel *corlabel, op_t op)
{
  (void) corlabel;
  op = checkOp(tmp.args[0]);
  tmp.instruction = op.mnemonique;
  tmp.nbr = count_args(tmp.args);
  tmp.tab_args = get_args(tmp.args + 1, -1);
  tmp.mempos = calc_mem_pos(&tmp, corline);
  printf("mempos -> %d\n", tmp.mempos);
  tmp.label = NULL;
  create_line(corline, tmp);
}

void	create_corline_l(t_corline tmp, t_corline *corline,
			 t_corlabel *corlabel, op_t op)
{
  t_corlabel	label;

  op = checkOp(tmp.args[1]);
  tmp.instruction = op.mnemonique;
  tmp.nbr = count_args(tmp.args);
  tmp.tab_args = get_args(tmp.args + 2, -1);
  tmp.mempos = calc_mem_pos(&tmp, corline);
  printf("mempos -> %d\n", tmp.mempos);
  tmp.label = line_is_label(tmp.args[0]);
  label.mempos = tmp.mempos;
  label.name = tmp.label;
  create_label(corlabel, label);
  create_line(corline, tmp);
}

int	start_parse_instr(t_corline *corline, t_corlabel *corlabel, char *str)
{
  t_corline	tmp;
  op_t		op;

  tmp.args = my_str_to_wordtab(str, STRTWTB);
  if (line_is_label(tmp.args[0]) == NULL)
    create_corline_wl(tmp, corline, corlabel, op);
  else
    create_corline_l(tmp, corline, corlabel, op);
  return (0);
}

int 	parse_instr(t_cor *corfile)
{
  int		i;

  i = 2;
  corfile->first_line = corline_init();
  corfile->first_label = corlabel_init();
  while (corfile->tab[i])
    {
      start_parse_instr(corfile->first_line,
			corfile->first_label, corfile->tab[i]);
      i++;
    }
  puts(corfile->first_line->next->instruction);

  convert_label_value(corfile->first_label->next, corfile->first_line->next);
  return (0);
}
