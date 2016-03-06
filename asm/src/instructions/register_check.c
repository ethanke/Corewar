/*
** register_check.c for  in /home/sagot/rendu/Corewar/asm/src/instructions/
**
** Made by Guillaume SAGOT
** Login   <sagot_g@epitech.eu>
**
** Started on  Wed Mar  2 23:07:44 2016 Guillaume SAGOT
** Last update Fri Mar  4 14:02:48 2016 Guillaume SAGOT
*/

#include "assembly.h"

void		checkComment(t_system *sys, int *name)
{
  int		i;

  i = 0;
  while (sys->name != NULL & name != 0)
    {
      if (sys->name[i] == '#')
	my_printf("%c", sys->name[i] + 1);
      i++;
    }
}

int             register_conditions(t_system *sys)
{
  if (sys->ins.str[sys->ins.i] == 'r' && sys->ins.str[sys->ins.i + 1] <= '0'
      && sys->ins.str[sys->ins.i + 1] >= '9')
    {
      if (sys->ins.cmptr == 0)
        sys->ins.c += 0x40;
      else if (sys->ins.cmptr == 1)
        sys->ins.c += 0x10;
      else if (sys->ins.cmptr == 2)
        sys->ins.c += 0x4;
      else if (sys->ins.cmptr == 3)
        sys->ins.c += 0x1;
    }
  return (0);
}
