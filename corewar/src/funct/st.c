/*
** st.c for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/corewar/src/funct/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sun Mar 13 11:45:09 2016 Gaëtan Léandre
** Last update Wed Mar 16 00:00:54 2016 Gaëtan Léandre
*/

#include	"corewar.h"

int		my_st(t_arena *arena, t_process *process, int id, int pc_pos)
{
  int		nbr;
  int		ind;
  unsigned char	arg;

  (void)id;
  process->pos = circle(process->pos, 1);
  arg = arena->arena[process->pos];
  if (check_mult_args(arena->arena, 2, process->pos, 2) == -1)
    return (0);
  process->cycle += op_tab[2].nbr_cycles;
  nbr = process->reg[arena->arena[circle(process->pos, 1)] - 1];
  if (octet_to_read(arg, 1) == T_REG)
    process->reg[arena->arena[circle(process->pos, 2)] - 1] = nbr;
  else
    {
      ind = take_param(arena->arena, process->pos + 2, IND_SIZE);
      arena->arena = put_param(arena->arena,
			       circle(pc_pos, mod(ind, IDX_MOD))
			       * REG_SIZE, DIR_SIZE, nbr);
    }
  process->pos = circle(process->pos, place_to_jump(arg, 2) + 1);
  return (0);
}

int		my_sti(t_arena *arena, t_process *process, int id, int pc_pos)
{
  int		a;
  int		b;
  int		c;
  unsigned char	arg;

  (void)id;
  process->pos = circle(process->pos, 1);
  arg = arena->arena[process->pos];
  if (check_mult_args(arena->arena, 11, process->pos, 3) == -1)
    return (0);
  process->cycle += op_tab[11].nbr_cycles;
  a = process->reg[arena->arena[circle(process->pos, 1)] - 1];
  b = take_what(arena->arena, process->pos, make_choix(pc_pos, 0, 2),
		process->reg);
  c = take_what(arena->arena, process->pos, make_choix(pc_pos, 0, 3),
		process->reg);
  arena->arena = put_param(arena->arena, circle(pc_pos, b + c), REG_SIZE, a);
  process->pos = circle(process->pos, place_to_jump(arg, 3) + 1);
  return (0);
}
