/*
** st.c for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/corewar/src/funct/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sun Mar 13 11:45:09 2016 Gaëtan Léandre
** Last update Sun Mar 13 11:48:35 2016 Gaëtan Léandre
*/

#include	"corewar.h"

int		my_st(t_arena *arena, t_process *process, int id, int pc_pos)
{
  int		nbr;
  int		reg;
  int		ind;

  process->pos = circle(process->pos, 1);
  if (check_mult_args(arena->arena, 3, process->pos, 2) == -1)
    return (0);
  process->cycle += op_tab[3].nbr_cycles;
  nbr = take_what(arena->arena, process->pos, 1, process->pc_pos);
  reg = octet_to_read(arena->arena[process->pos]);
  if (arena->arena[process->pos + reg + 1] == T_REG)
    {
      ind = take_param(arena->arena, process->pos + reg + 2, REG_SIZE);
      arena->arena = put_param(arena->arena, process->pc_pos + 1 + (ind - 1)
			       * REG_SIZE, REG_SIZE, nbr);
    }
  else
    {
      ind = take_param(arena->arena, process->pos + reg + 2, IND_SIZE);
      arena->arena = put_param(arena->arena,
			       circle(process->pc_pos + mod(ind, IDX_MOD), 0)
			       * REG_SIZE, DIR_SIZE, nbr);
    }
  process->pos = circle(process->pos, 2 + reg +
			octet_to_read(arena->arena[process->pos + reg + 1]));
  return (0);
}

int		my_sti(t_arena *arena, t_process *process, int id, int pc_pos)
{
  int		nbr;
  int		reg;
  int		regB;
  int		ind;

  process->pos = circle(process->pos, 1);
  if (check_mult_args(arena->arena, 11, process->pos, 3) == -1)
    return (0);
  process->cycle += op_tab[11].nbr_cycles;
  nbr = take_what(arena->arena, process->pos, 1, process->pc_pos);
  reg = octet_to_read(arena->arena[process->pos]);
  ind = take_what(arena->arena, process->pos + reg + 1, 1, process->pc_pos);
  regB = octet_to_read(arena->arena[process->pos]);
  ind += take_what(arena->arena, process->pos + reg + regB + 2, 1, process->pc_pos);
  arena->arena = put_param(arena->arena, circle(ind, 0) * REG_SIZE, DIR_SIZE, nbr);
  process->pos = circle(process->pos, 3 + reg + regB +
			octet_to_read(arena->arena[process->pos + reg + regB + 2]));
  return (0);
}
