/*
** prog_status.c for minishell1 in /mnt/hgfs/Shared/Rendu/PSU/PSU_2015_minishell1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Wed Jan 13 03:44:13 2016 victor sousa
** Last update Fri Mar 25 10:13:40 2016 Victor Sousa
*/

#include	"corewar.h"

int             modular_prog_status(char boolean, int value)
{
  static int    status = 1;

  if (boolean)
    status = value;
  return (status);
}
