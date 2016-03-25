/*
** get_cmd.c for minishell1 in /mnt/hgfs/Shared/Rendu/PSU/PSU_2015_minishell1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Sun Jan 24 03:26:54 2016 victor sousa
** Last update Fri Mar 25 10:41:05 2016 Victor Sousa
*/

#include		"corewar.h"

t_cmd           parse_str(char *str)
{
  t_cmd         cmd;

  cmd.exec = get_exec(str);
  cmd.arg = my_str_to_wordtab(str);
  return (cmd);
}
