/*
** is_the_one.c for minishell1 in /home/vicostudio/Shared/Rendu/PSU/PSU_2015_minishell1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Sun Jan 24 19:57:25 2016 victor sousa
** Last update Fri Mar 25 10:12:49 2016 Victor Sousa
*/

#include		"corewar.h"

int                     is_the_one(char *name, char *line)
{
  int                   i;

  i = 0;
  while (name[i] && line[i] && line[i] != '=')
    {
      if (line[i] != name[i])
	return (0);
      i++;
    }
  return (i);
}
