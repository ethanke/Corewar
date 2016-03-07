/*
** main.c for corewar in /home/vicostudio/rendu/cpe/CorewarGIT/corewar
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Mon Feb 29 22:21:44 2016 victor sousa
** Last update Mon Mar  7 02:26:44 2016 Victor Sousa
*/

#include	"corewar.h"

int		main(int ac, char **av, char **env)
{
  t_champ	champion;

  if (env == NULL)
    my_putstr_error("can't read env\n", 1);
  verif_arg(ac, av);

  champion = init_champion(ac, av);
  (void)champion;

  my_putstr("program running\n");
  return (0);
}
