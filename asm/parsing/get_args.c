/*
** get_args.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/asm/parsing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Tue Mar 15 17:14:40 2016 Ethan Kerdelhue
** Last update Tue Mar 22 22:59:50 2016 Ethan Kerdelhue
*/

#include "asm.h"

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
	  tmp[i] = add_ind(tmp[i], tab[i]);
    }
  tmp[i].value = NULL;
  tmp[i].type = -3;
  return (tmp);
}
