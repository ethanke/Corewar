/*
** parse_instr.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/asm/parsing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Mon Mar 14 06:02:03 2016 Ethan Kerdelhue
** Last update Tue Mar 22 23:23:36 2016 Ethan Kerdelhue
*/

#include "asm.h"

void	create_corline_wl(t_corline tmp, t_corline *corline, op_t op)
{
  op = checkOp(tmp.args[0]);
  tmp.instruction = op.mnemonique;
  tmp.nbr = count_args(tmp.args);
  tmp.tab_args = get_args(tmp.args + 1, -1);
  tmp.mempos = calc_mem_pos(&tmp, corline);
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
    create_corline_wl(tmp, corline, op);
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
  convert_label_value(corfile->first_label->next, corfile->first_line->next);
  return (0);
}
