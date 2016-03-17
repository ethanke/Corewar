/*
** st.c for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/corewar/src/funct/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sun Mar 13 11:45:09 2016 Gaëtan Léandre
** Last update Wed Mar 16 22:53:10 2016 Gaëtan Léandre
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
  if (octet_to_read(arg, 2) == T_REG)
    process->reg[arena->arena[circle(process->pos, 2)] - 1] = nbr;
  else
    {
      ind = take_param(arena->arena, process->pos + 2, IND_SIZE);
      put_param(arena, circle(pc_pos, mod(ind, IDX_MOD)), arena->champ->id_champ[id], nbr);
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
  if (check_mult_args(arena->arena, 10, process->pos, 3) == -1)
    return (0);
  process->cycle += op_tab[10].nbr_cycles;
  a = process->reg[arena->arena[circle(process->pos, 1)] - 1];
  b = take_what(arena->arena, process->pos, make_choix(pc_pos, 0, 2),
		process->reg);
  c = take_what(arena->arena, process->pos, make_choix(pc_pos, 0, 3),
		process->reg);
  put_param(arena, circle(pc_pos, b + c), arena->champ->id_champ[id], a);
  process->pos = circle(process->pos, place_to_jump(arg, 3) + 1);
  return (0);
}
