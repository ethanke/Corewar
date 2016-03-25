/*
** free_wordtab.c for minishell1 in /mnt/hgfs/Shared/Rendu/PSU/PSU_2015_minishell1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Sun Jan 24 03:04:10 2016 victor sousa
** Last update Fri Mar 25 10:12:24 2016 Victor Sousa
*/

#include		"corewar.h"

void			free_wordtab(char **str)
{
  int			i;

  i = 0;
  while (str[i] != '\0')
    free(str[i++]);
  free(str);
}
