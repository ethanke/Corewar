/*
** parse_instr.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/asm/parsing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Mon Mar 14 06:02:03 2016 Ethan Kerdelhue
** Last update Tue Mar 15 19:21:17 2016 Ethan Kerdelhue
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
  return (i - 1);
}

int	get_size(t_corarg *tab_args)
{
  int	i;
  int	memsize;

  i = 0;
  while (tab_args[i])
    {
      if (tab_args[i].type == 1)
	memsize += 1;
      else if (tab_args[i].type == 2)
	memsize += 4;
      else if (tab_args[i].type == 4)
	memsize += 2;
      else if (tab_args[i].type == 8)
	memsize += 4;
      i++;
    }
  return (memsize + 1); /* + 1 pour l'octet representatif de l'instruction */
}

char	get_last_label(t_corline *corline)
{
  t_corline	*tmp;

  tmp = corline;
  while (tmp->next != NULL)
    tmp = tmp-next;
  return (tmp->label);
}

int	calc_mem_pos(int line, t_corline *corline)
{
  t_corline 	*tmp;
  int		mempos;

  while (corline->next != NULL)
    tmp = corline;
  mempos = tmp->mempos;
  if (((my_strcmp(corline->mnemonique, "live") != 1) ||
      (my_strcmp(corline->mnemonique, "fork") != 1) ||
      (my_strcmp(corline->mnemonique, "lfork") != 1) ||
      (my_strcmp(corline->mnemonique, "zjmp") != 1)))
    mempos += 1;
  mempos += get_size(tmp->tab_args);
  return (mempos);
}

int	start_parse_instr(t_corline *corline, char *str, int line)
{
  t_corline	tmp;
  op_t		op;

  (void) corline;
  tmp.args = my_str_to_wordtab(str);
  tmp.line = line;
  if (line_is_label(tmp.args[0]) != 1)
    {
      op = checkOp(tmp.args[0]);
      tmp.instruction = op.mnemonique;
      tmp.nbr = count_args(tmp.args);
      tmp.tab_args = get_args(tmp.args, 0);
      tmp.mempos = calc_mem_pos(line, corline);
      tmp.label = NULL;
    }
  else
    {
      op = checkOp(tmp.args[0]);
      tmp.instruction = op.mnemonique;
      tmp.nbr = count_args(tmp.args);
      tmp.tab_args = get_args(tmp.args, 0);
      tmp.mempos = calc_mem_pos(line, corline);
    }
  return (0);
}

int 	parse_instr(t_cor *corfile)
{
  int		i;
  int		line;
  t_corline	*corline;

  i = 3;
  line = 0;
  corline = corline_init();
  while (corfile->tab[i])
    {
      start_parse_instr(corline, corfile->tab[i], line);
      i++;
      line++;
    }
  return (0);
}
