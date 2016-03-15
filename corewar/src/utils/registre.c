/*
** registre.c for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/corewar/src/utils/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Tue Mar 15 18:25:22 2016 Gaëtan Léandre
** Last update Tue Mar 15 19:12:58 2016 Victor Sousa
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

void		cpy_registre(int *reg_child, int *reg_parent)
{
  int		pos;

  pos = -1;
  while (++pos < REG_NUMBER)
    reg_child[pos] = reg_parent[pos];
}
