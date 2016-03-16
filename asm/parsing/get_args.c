/*
** get_args.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/asm/parsing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Tue Mar 15 17:14:40 2016 Ethan Kerdelhue
** Last update Wed Mar 16 05:55:12 2016 Ethan Kerdelhue
*/

#include "asm.h"

t_corarg	*get_args(char **tab, int i)
{
  t_corarg	*tmp;

  tmp = malloc(sizeof(t_corarg) * count_args(tab) * 3);
  while (tab[++i])
    {
      if (tab[i][0] == DIRECT_CHAR && tab[i][1] != LABEL_CHAR)
	{
	  tmp[i].type = T_DIR;
	  tmp[i].value = tab[i] + 1;
	}
      if (tab[i][0] == DIRECT_CHAR && tab[i][1] == LABEL_CHAR)
	{
	  tmp[i].type = T_LAB;
	  tmp[i].value = tab[i] + 2;
	}
      if (tab[i][0] == 'r')
	{
	  if (my_getnbr(tab[i] + 1) <= REG_NUMBER)
	    {
	      tmp[i].type = T_REG;
	      tmp[i].value = tab[i];
	    }
	}
    }
  tmp[i].type = -3;
  return (tmp);
}
