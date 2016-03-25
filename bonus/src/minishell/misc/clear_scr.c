/*
** xclear.c for minishell1 in /mnt/hgfs/Shared/Rendu/PSU/PSU_2015_minishell1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Tue Jan 12 19:24:16 2016 victor sousa
** Last update Fri Mar 25 10:12:09 2016 Victor Sousa
*/

#include	"corewar.h"

void	clear_scr(void)
{
  my_putstr("\033[1;1H\033[2J");
}
