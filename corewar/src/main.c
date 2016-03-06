/*
** main.c for corewar in /home/vicostudio/rendu/cpe/CorewarGIT/corewar
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Mon Feb 29 22:21:44 2016 victor sousa
** Last update Sun Mar  6 23:42:52 2016 Victor Sousa
*/

#include	"corewar.h"

int		main(int ac, char **av, char **env)
{
  t_champ	champion;

  if (env != NULL && verif_arg(ac, av) == 1)
    puts("programm running");
  (void)champion;
  return (0);
}
