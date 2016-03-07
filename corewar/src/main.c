/*
** main.c for corewar in /home/vicostudio/rendu/cpe/CorewarGIT/corewar
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Mon Feb 29 22:21:44 2016 victor sousa
** Last update Mon Mar  7 02:15:56 2016 Victor Sousa
*/

#include	"corewar.h"

int		main(int ac, char **av, char **env)
{
  t_champ	champion;
  t_process	process;

  if (env != NULL)
    my_putstr_error("can't read end\n", 1);
  verif_arg(ac, av);

  champion = init_champion(ac, av);
  process = load_process(&champion, ac, av);

  (void)process;
  my_putstr("program running\n");
  return (0);
}
