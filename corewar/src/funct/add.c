/*
** add.c for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/corewar/src/funct/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sun Mar 13 12:06:01 2016 Gaëtan Léandre
** Last update Sun Mar 13 12:37:34 2016 Gaëtan Léandre
*/

#include	"corewar.h"

int		my_add(t_arena *arena, t_process *process, int id, int pc_pos)
{
  int		nbr;
  int		ind;

  process->pos = circle(process->pos, 1);
  if (check_mult_args(arena->arena, 4, process->pos, 3) == -1)
    return (0);
  process->cycle += op_tab[4].nbr_cycles;
  nbr = take_what(arena->arena, process->pos, 1, pc_pos);
  nbr += take_what(arena->arena, process->pos + REG_SIZE + 1, 1, pc_pos);
  ind = take_param(arena->arena, process->pos + REG_SIZE * 2 + 3, REG_SIZE);
  arena->arena = put_param(arena->arena, pc_pos + 1 + (ind - 1) * REG_SIZE, REG_SIZE, nbr);
  process->pos = circle(process->pos, 3 * REG_SIZE + 3);
  return (0);
}

int		my_sub(t_arena *arena, t_process *process, int id, int pc_pos)
{
  int		nbr;
  int		ind;

  process->pos = circle(process->pos, 1);
  if (check_mult_args(arena->arena, 5, process->pos, 3) == -1)
    return (0);
  process->cycle += op_tab[5].nbr_cycles;
  nbr = take_what(arena->arena, process->pos, 1, pc_pos);
  nbr -= take_what(arena->arena, process->pos + REG_SIZE + 1, 1, pc_pos);
  ind = take_param(arena->arena, process->pos + REG_SIZE * 2 + 3, REG_SIZE);
  arena->arena = put_param(arena->arena, pc_pos + 1 + (ind - 1) * REG_SIZE, REG_SIZE, nbr);
  process->pos = circle(process->pos, 3 * REG_SIZE + 3);
  return (0);
}

int		my_and(t_arena *arena, t_process *process, int id, int pc_pos)
{
  int		nbr;
  int		reg;
  int		regB;
  int		ind;

  process->pos = circle(process->pos, 1);
  if (check_mult_args(arena->arena, 6, process->pos, 3) == -1)
    return (0);
  process->cycle += op_tab[6].nbr_cycles;
  nbr = take_what(arena->arena, process->pos, 0, pc_pos);
  reg = octet_to_read(arena->arena[process->pos]);
  nbr &= take_what(arena->arena, process->pos + reg + 1, 0, pc_pos);
  regB = octet_to_read(arena->arena[process->pos + reg + 1]);
  ind = take_param(arena->arena, process->pos + reg + regB + 3, REG_SIZE);
  arena->arena = put_param(arena->arena, pc_pos + 1 + (ind - 1) * REG_SIZE, REG_SIZE, nbr);
  process->pos = circle(process->pos, reg + regB + REG_SIZE + 3);
  return (0);
}

int		my_or(t_arena *arena, t_process *process, int id, int pc_pos)
{
  int		nbr;
  int		reg;
  int		regB;
  int		ind;

  process->pos = circle(process->pos, 1);
  if (check_mult_args(arena->arena, 7, process->pos, 3) == -1)
    return (0);
  process->cycle += op_tab[7].nbr_cycles;
  nbr = take_what(arena->arena, process->pos, 0, pc_pos);
  reg = octet_to_read(arena->arena[process->pos]);
  nbr |= take_what(arena->arena, process->pos + reg + 1, 0, pc_pos);
  regB = octet_to_read(arena->arena[process->pos + reg + 1]);
  ind = take_param(arena->arena, process->pos + reg + regB + 3, REG_SIZE);
  arena->arena = put_param(arena->arena, pc_pos + 1 + (ind - 1) * REG_SIZE, REG_SIZE, nbr);
  process->pos = circle(process->pos, reg + regB + REG_SIZE + 3);
  return (0);
}

int		my_xor(t_arena *arena, t_process *process, int id, int pc_pos)
{
  int		nbr;
  int		reg;
  int		regB;
  int		ind;

  process->pos = circle(process->pos, 1);
  if (check_mult_args(arena->arena, 8, process->pos, 3) == -1)
    return (0);
  process->cycle += op_tab[8].nbr_cycles;
  nbr = take_what(arena->arena, process->pos, 0, pc_pos);
  reg = octet_to_read(arena->arena[process->pos]);
  nbr ˆ= take_what(arena->arena, process->pos + reg + 1, 0, pc_pos);
  regB = octet_to_read(arena->arena[process->pos + reg + 1]);
  ind = take_param(arena->arena, process->pos + reg + regB + 3, REG_SIZE);
  arena->arena = put_param(arena->arena, pc_pos + 1 + (ind - 1) * REG_SIZE, REG_SIZE, nbr);
  process->pos = circle(process->pos, reg + regB + REG_SIZE + 3);
  return (0);
}
