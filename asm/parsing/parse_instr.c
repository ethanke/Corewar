/*
** parse_instr.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/asm/parsing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Mon Mar 14 06:02:03 2016 Ethan Kerdelhue
** Last update Tue Mar 15 17:23:51 2016 Ethan Kerdelhue
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

int	start_parse_instr(t_corline *corline, char *str)
{
  t_corline	tmp;
  op_t		op;

  (void) corline;
  tmp.args = my_str_to_wordtab(str);
  if (line_is_label(tmp.args[0]) != 1)
    {
      op = checkOp(tmp.args[0]);
      tmp.instruction = op.mnemonique;
      tmp.nbr = count_args(tmp.args);
      tmp.tab_args = get_args(tmp.args, 0);
    }
  return (0);
}

int 	parse_instr(t_cor *corfile)
{
  int		i;
  t_corline	*corline;

  i = 3;
  corline = corline_init();
  while (corfile->tab[i])
    {
      start_parse_instr(corline, corfile->tab[i]);
      i++;
    }
  return (0);
}
