/*
** check_commentary.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/asm/check/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Tue Mar 22 23:02:37 2016 Ethan Kerdelhue
** Last update Tue Mar 22 23:02:44 2016 Ethan Kerdelhue
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
