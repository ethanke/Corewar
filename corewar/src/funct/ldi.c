/*
** ldi.c for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/corewar/src/funct/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Fri Mar 11 05:35:28 2016 Gaëtan Léandre
** Last update Wed Mar 16 01:41:12 2016 Gaëtan Léandre
*/

#include	"corewar.h"

int		my_ldi(t_arena *arena, t_process *process, int id, int pc_pos)
{
  int		s;
  int		ind;
  unsigned char	arg;

  (void)id;
  process->pos = circle(process->pos, 1);
  arg = arena->arena[process->pos];
  if (check_mult_args(arena->arena, 9, process->pos, 3) == -1)
    return (0);
  process->cycle += op_tab[9].nbr_cycles;
  process->carry = (process->carry == 1) ? 0 : 1;
  s = take_what(arena->arena, process->pos, make_choix(pc_pos, 0, 1),
		process->reg);
  s += take_what(arena->arena, process->pos, make_choix(pc_pos, 0, 2),
		 process->reg);
  ind = arena->arena[circle(process->pos, place_to_jump(arg, 2) + 1)];
  s = take_param(arena->arena, circle(pc_pos, mod(s, IDX_MOD)), DIR_SIZE);
  process->reg[ind - 1] = s;
  process->pos = circle(process->pos, place_to_jump(arg, 3));
  return (0);
}

int		my_lldi(t_arena *arena, t_process *process, int id, int pc_pos)
{
  int		s;
  int		ind;
  unsigned char	arg;

  (void)id;
  process->pos = circle(process->pos, 1);
  arg = arena->arena[process->pos];
  if (check_mult_args(arena->arena, 13, process->pos, 3) == -1)
    return (0);
  process->cycle += op_tab[13].nbr_cycles;
  process->carry = (process->carry == 1) ? 0 : 1;
  s = take_what(arena->arena, process->pos, make_choix(pc_pos, 0, 1),
		process->reg);
  s += take_what(arena->arena, process->pos, make_choix(pc_pos, 0, 2),
		 process->reg);
  ind = arena->arena[circle(process->pos, place_to_jump(arg, 2) + 1)];
  s = take_param(arena->arena, circle(pc_pos, s), DIR_SIZE);
  process->reg[ind - 1] = s;
  process->pos = circle(process->pos, place_to_jump(arg, 3));
  return (0);
}
