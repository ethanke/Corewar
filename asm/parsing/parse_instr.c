/*
** parse_instr.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/asm/parsing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Mon Mar 14 06:02:03 2016 Ethan Kerdelhue
** Last update Mon Mar 14 07:13:34 2016 Ethan Kerdelhue
*/

#include "asm.h"

int	line_is_label(char *args)
{
  char	flag;
  char	*label;

  label = malloc(my_strlen(args) + 1);
  my_memset(label, my_strlen(args) + 1, '\0');
  flag = 0;
  while(*args)
    {
      if (*args == LABEL_CHAR)
	flag = 1;
     (*args)++;
    }
  if (flag == 1)
    label = checkLabel(my_strncpy(args, args, my_strlen(args - 1)));
  else
    label = NULL;
  return (0);
}

int	start_parse_instr(t_corline *corline, char *str)
{
  t_corline	tmp;

  (void) corline;
  tmp.args = my_str_to_wordtab(str);
  puts(tmp.args[0]);
  line_is_label(tmp.args[0]);

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
