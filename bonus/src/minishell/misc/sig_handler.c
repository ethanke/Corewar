/*
** sig_handler.c for minishell1 in /mnt/hgfs/Shared/Rendu/PSU/PSU_2015_minishell1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Wed Jan 13 03:40:45 2016 victor sousa
** Last update Fri Mar 25 10:56:51 2016 Victor Sousa
*/

#include	"corewar.h"

void            sighandler(int sig)
{
  if (sig == 2)
    {
      if (modular_prog_status(0, 0) == 1)
	{
	  my_putstr(" Press again to leave\n");
	  modular_prog_status(1, 0);
	  signal(SIGINT, sighandler);
	}
      else if (modular_prog_status(0, 0) == 0)
	{
	  my_putstr("\n\nSee you soon!\n\n");
	  modular_prog_status(1, -1);
	  exit(1);
	}
    }
  else
    signal(SIGINT, sighandler);
}
