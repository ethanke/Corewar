/*
** main.c for corewar in /home/vicostudio/rendu/cpe/CorewarGIT/corewar
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Mon Feb 29 22:21:44 2016 victor sousa
** Last update Mon Mar  7 00:22:29 2016 Victor Sousa
*/

#include	"corewar.h"

int		main(int ac, char **av, char **env)
{
  t_champ	champion;

  (void)champion;
  if (env != NULL && verif_arg(ac, av) == 0)
    {
      my_putstr_error("programm failed\n", 1);
      return (1);
    }
  my_putstr("program running\n");
  return (0);
}
