/*
** ldi.c for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/corewar/src/funct/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Fri Mar 11 05:35:28 2016 Gaëtan Léandre
** Last update Sun Mar 13 11:42:22 2016 Gaëtan Léandre
*/

#include	"corewar.h"

int		my_ldi(t_arena *arena, t_process *process, int id, int pc_pos)
{
  int		s;
  int		reg;
  int		regB;
  int		ind;

  process->pos = circle(process->pos, 1);
  if (check_mult_args(arena->arena, 10, process->pos, 3) == -1)
    return (0);
  process->cycle += op_tab[10].nbr_cycles;
  process->carry = (process->carry == 1) ? 0 : 1;
  s = take_what(arena->arena, process->pos, 1, process->pc_pos);
  reg = octet_to_read(arena->arena[process->pos]);
  s += take_what(arena->arena, process->pos + reg + 1, 1, process->pc_pos);
  regB = octet_to_read(arena->arena[process->pos + reg + 1]);
  ind = take_param(arena->arena, process->pos + reg + regB + 3, REG_SIZE);
  s = take_param(arena->arena, circle(mod(s, IDX_MOD), 0), DIR_SIZE);
  arena->arena = put_param(arena->arena, process->pc_pos + 1 + (ind - 1) * REG_SIZE, REG_SIZE, s);
  process->pos = circle(process->pos, 3 + reg + regB + REG_SIZE);
  return (0);
}

int		my_lldi(t_arena *arena, t_process *process, int id, int pc_pos)
{
  int		s;
  int		reg;
  int		regB;
  int		ind;

  process->pos = circle(process->pos, 1);
  if (check_mult_args(arena->arena, 14, process->pos, 3) == -1)
    return (0);
  process->cycle += op_tab[14].nbr_cycles;
  process->carry = (process->carry == 1) ? 0 : 1;
  s = take_what(arena->arena, process->pos, 0, process->pc_pos);
  reg = octet_to_read(arena->arena[process->pos]);
  s += take_what(arena->arena, process->pos + reg + 1, 0, process->pc_pos);
  regB = octet_to_read(arena->arena[process->pos + reg + 1]);
  ind = take_param(arena, process->pos + reg + regB + 3, REG_SIZE);
  s = take_param(arena->arena, circle(s, 0), DIR_SIZE);
  arena->arena = put_param(arena->arena, process->pc_pos + 1 + (ind - 1) * REG_SIZE, REG_SIZE, s);
  process->pos = circle(process->pos, 3 + reg + regB + REG_SIZE);
  return (0);
}
