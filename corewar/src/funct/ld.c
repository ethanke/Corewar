/*
** ld.c for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/corewar/src/funct/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Fri Mar 11 00:34:17 2016 Gaëtan Léandre
** Last update Wed Mar 16 02:38:16 2016 Gaëtan Léandre
*/

#include	"corewar.h"

int		my_ld(t_arena *arena, t_process *process, int id, int pc_pos)
{
  unsigned char	arg;
  int		nbr;
  int		reg;

  (void)id;
  process->pos = circle(process->pos, 1);
  arg = arena->arena[process->pos];
  if (check_mult_args(arena->arena, 1, process->pos, 2) == -1)
    return (0);
  process->cycle += op_tab[1].nbr_cycles;
  process->carry = (process->carry == 1) ? 0 : 1;
  nbr = take_what(arena->arena, process->pos, make_choix(pc_pos, 1, 1),
		  process->reg);
  reg = arena->arena[circle(process->pos, octet_to_read(arg, 1) + 1)];
  process->reg[reg - 1] = nbr;
  process->pos = circle(process->pos, place_to_jump(arg, 2) + 1);
  return (0);
}

int		my_lld(t_arena *arena, t_process *process, int id, int pc_pos)
{
  unsigned char	arg;
  int		nbr;
  int		reg;

  (void)id;
  process->pos = circle(process->pos, 1);
  arg = arena->arena[process->pos];
  if (check_mult_args(arena->arena, 12, process->pos, 2) == -1)
    return (0);
  process->cycle += op_tab[12].nbr_cycles;
  process->carry = (process->carry == 1) ? 0 : 1;
  nbr = take_what(arena->arena, process->pos, make_choix(pc_pos, 0, 1),
		  process->reg);
  reg = arena->arena[circle(process->pos, octet_to_read(arg, 1) + 1)];
  process->reg[reg] = nbr;
  process->pos = circle(process->pos, place_to_jump(arg, 2));
  return (0);
}
