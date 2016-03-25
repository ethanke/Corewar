/*
** my_tablen.c for minishell1 in /home/vicostudio/Shared/Rendu/PSU/PSU_2015_minishell1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Sun Jan 24 19:54:18 2016 victor sousa
** Last update Fri Mar 25 10:13:20 2016 Victor Sousa
*/

#include		"corewar.h"

int                     tablen(char **tab)
{
  int                   i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}
