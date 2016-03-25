/*
** get_execname.c for minishell1 in /mnt/hgfs/Shared/Rendu/PSU/PSU_2015_minishell1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Sun Jan 24 03:25:12 2016 victor sousa
** Last update Fri Mar 25 10:12:39 2016 Victor Sousa
*/

#include		"corewar.h"

char            *get_exec(char *str)
{
  int           i;
  char          *output;

  i = 0;
  output = xmalloc(sizeof(char) * (my_strlen(str) + 1));
  while (str[i] && str[i] != ' ')
    {
      output[i] = str[i];
      i++;
    }
  output[i] = '\0';
  return (output);
}
