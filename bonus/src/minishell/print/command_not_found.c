/*
** command_not_found.c for minishell1 in /mnt/hgfs/Shared/Rendu/PSU/PSU_2015_minishell1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Sun Jan 24 01:42:21 2016 victor sousa
** Last update Fri Mar 25 10:13:45 2016 Victor Sousa
*/

#include		"corewar.h"

void			print_unknow_cmd(char *str)
{
  my_putstr("command not found : ");
  my_putstr(str);
  my_putchar('\n');
  free(str);
  exit(-1);
}
