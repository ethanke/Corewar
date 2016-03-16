/*
** fill_process.c for corewar in /Users/sousa_v/Shared/rendu/cpe/Coreware_temp/corewar/src/loading/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Tue Mar 15 17:31:06 2016 Victor Sousa
** Last update Wed Mar 16 19:07:50 2016 Victor Sousa
*/

#include		"corewar.h"

t_process		*fill_process(int pos, int id)
{
  t_process		*proc;

  proc = xmalloc(sizeof(t_process));
  proc->live = 1;
  proc->living = 0;
  proc->pos = pos;
  proc->pc_pos = pos;
  proc->cycle = 0;
  proc->carry = 0;
  create_registre(proc, id);
  proc->next = NULL;
  proc->child = NULL;
  return (proc);
}
