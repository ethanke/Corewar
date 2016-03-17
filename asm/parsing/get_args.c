/*
** get_args.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/asm/parsing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Tue Mar 15 17:14:40 2016 Ethan Kerdelhue
** Last update Thu Mar 17 05:36:28 2016 Ethan Kerdelhue
*/

#include "asm.h"


int		is_alph_char(char c, char *delim)
{
  int		i;

  i = -1;
  while (delim[++i])
    {
      if (delim[i] == c)
	return (0);
    }
  return (c);
}

int		my_str_isalpha(char *str)
{
  if (*str == 0)
    return (1);
  while (*str != 0)
    {
      if (!is_alph_char(*str, LABEL_CHARS))
	return (0);
      str++;
    }
  return (1);
}

int			checkLabExist(t_corlabel *label, char *str)
{
  t_corlabel	*tmp;

  tmp = label;
  if (my_str_isalpha(str) == 0)
    return (-1);
  while (tmp->next != NULL)
    {

      if (my_strcmp(tmp->name, str))
	{
	  return (1);
	}
      tmp = tmp->next;
    }
  return (0);
}

void			convert_label_value(t_corlabel *label, t_corline *corline)
{
  t_corline	*corline_tmp;
  int		i;

  i = 0;
  corline_tmp = corline;
  while (corline_tmp->next != NULL)
    {
      while (corline_tmp->tab_args[i].value != NULL)
	{
	  if ((corline_tmp->tab_args[i].type == T_DIR)
	      && (checkLabExist(label, corline_tmp->tab_args[i].value) == 1))
	    get_label_value(label, corline_tmp->tab_args[i].value);
	  i++;
	}
      corline_tmp = corline_tmp->next;
    }
}

int			get_label_value(t_corlabel *label, char *str)
{
  t_corlabel		*tmp;
  int			mempos;

  mempos = -1;
  tmp = label;
  while (tmp->next != NULL)
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
  printf("MEMPOS LBL -> %s // %d \n", tmp->name, mempos);
  return (mempos);
}

char	*epur_cw(char *str)
{
  char	*new;
  int	i;
  int	j;

  i = 0;
  j = 0;
  new = malloc(my_strlen(str));
  while (str[i])
    {
      if ((str[i] != 'r') && (str[i] != LABEL_CHAR) & (str[i] != DIRECT_CHAR))
	{
	  new[j] = str[i];
	  j++;
	}
      i++;
    }
  new[j] = 0;
  return (new);
}

t_corarg		add_dir(t_corarg arg, char *str)
{
  arg.type = T_DIR;
  arg.value = epur_cw(str);
  return (arg);
}

t_corarg		add_lab(t_corarg arg, char *str)
{
  arg.type = T_DIR;
  arg.value = epur_cw(str);
  return (arg);
}

t_corarg		add_ind(t_corarg arg, char *str)
{
  arg.type = T_IND;
  arg.value = str;
  return (arg);
}

t_corarg		add_reg(t_corarg arg, char *str)
{
  arg.type = T_REG;
  arg.value = epur_cw(str);
  return (arg);
}

t_corarg	*get_args(char **tab, int i)
{
  t_corarg	*tmp;

  tmp = malloc(sizeof(t_corarg) * count_args(tab) * 3);
  while (tab[++i])
    {
      if (tab[i][0] == DIRECT_CHAR && tab[i][1] != LABEL_CHAR)
	tmp[i] = add_dir(tmp[i], tab[i]);
      else if (tab[i][0] == DIRECT_CHAR && tab[i][1] == LABEL_CHAR)
	tmp[i] = add_lab(tmp[i], tab[i]);
      else if (tab[i][0] == 'r')
	{
	  if (my_getnbr(tab[i] + 1) <= REG_NUMBER)
	    tmp[i] = add_reg(tmp[i], tab[i]);
	}
      else
	{
	  tmp[i] = add_ind(tmp[i], tab[i]);
	}
  }
  tmp[i].value = NULL;
  tmp[i].type = -3;
  return (tmp);
}
