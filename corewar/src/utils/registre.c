/*
** registre.c for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/corewar/src/utils/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Tue Mar 15 18:25:22 2016 Gaëtan Léandre
** Last update Tue Mar 15 19:23:26 2016 Gaëtan Léandre
*/

#include	"corewar.h"

void		create_registre(t_process *process, int id)
{
  int		pos;

  pos = 0;
  process->reg = xmalloc(sizeof(int) * REG_NUMBER);
  process->reg[0] = id;
  while (++pos < REG_NUMBER)
    process->reg[pos] = 0;
}

void		cpy_registre(t_process *child, t_process *parent)
{
  int		pos;

  pos = -1;
  child->reg = xmalloc(sizeof(int) * REG_NUMBER);
  while (++pos < REG_NUMBER)
    child->reg[pos] = parent->reg[pos];
}
