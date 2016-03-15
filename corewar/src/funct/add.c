/*
** add.c for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/corewar/src/funct/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sun Mar 13 12:06:01 2016 Gaëtan Léandre
** Last update Wed Mar 16 00:20:09 2016 Gaëtan Léandre
*/

#include	"corewar.h"

int		my_add(t_arena *arena, t_process *process, int id, int pc_pos)
{
  int		nbr;
  int		ind;
  unsigned char	arg;

  (void)id;
  process->pos = circle(process->pos, 1);
  arg = arena->arena[process->pos];
  if (check_mult_args(arena->arena, 3, process->pos, 3) == -1)
    return (0);
  process->cycle += op_tab[3].nbr_cycles;
  nbr = take_what(arena->arena, process->pos, make_choix(pc_pos, 1, 1),
		  process->reg);
  nbr += take_what(arena->arena, process->pos, make_choix(pc_pos, 1, 2),
		   process->reg);
  ind = arena->arena[circle(process->pos, place_to_jump(arg, 2) + 1)];
  process->reg[ind - 1] = nbr;
  process->pos = circle(process->pos, place_to_jump(arg, 3) + 1);
  return (0);
}

int		my_sub(t_arena *arena, t_process *process, int id, int pc_pos)
{
  int		nbr;
  int		ind;
  unsigned char	arg;

  (void)id;
  process->pos = circle(process->pos, 1);
  arg = arena->arena[process->pos];
  if (check_mult_args(arena->arena, 4, process->pos, 3) == -1)
    return (0);
  process->cycle += op_tab[4].nbr_cycles;
  nbr = take_what(arena->arena, process->pos, make_choix(pc_pos, 1, 1),
		  process->reg);
  nbr += take_what(arena->arena, process->pos, make_choix(pc_pos, 1, 2),
		   process->reg);
  ind = arena->arena[circle(process->pos, place_to_jump(arg, 2) + 1)];
  process->reg[ind - 1] = nbr;
  process->pos = circle(process->pos, place_to_jump(arg, 3) + 1);
  return (0);
}

int		my_and(t_arena *arena, t_process *process, int id, int pc_pos)
{
  int		nbr;
  int		ind;
  unsigned char	arg;

  (void)id;
  process->pos = circle(process->pos, 1);
  arg = arena->arena[process->pos];
  if (check_mult_args(arena->arena, 5, process->pos, 3) == -1)
    return (0);
  process->cycle += op_tab[5].nbr_cycles;
  nbr = take_what(arena->arena, process->pos, make_choix(pc_pos, 1, 1),
		  process->reg);
  nbr &= take_what(arena->arena, process->pos, make_choix(pc_pos, 1, 2),
		   process->reg);
  ind = arena->arena[circle(process->pos, place_to_jump(arg, 2) + 1)];
  process->reg[ind - 1] = nbr;
  process->pos = circle(process->pos, place_to_jump(arg, 3) + 1);
  return (0);
}

int		my_or(t_arena *arena, t_process *process, int id, int pc_pos)
{
  int		nbr;
  int		ind;
  unsigned char	arg;

  (void)id;
  process->pos = circle(process->pos, 1);
  arg = arena->arena[process->pos];
  if (check_mult_args(arena->arena, 5, process->pos, 3) == -1)
    return (0);
  process->cycle += op_tab[5].nbr_cycles;
  nbr = take_what(arena->arena, process->pos, make_choix(pc_pos, 1, 1),
		  process->reg);
  nbr |= take_what(arena->arena, process->pos, make_choix(pc_pos, 1, 2),
		   process->reg);
  ind = arena->arena[circle(process->pos, place_to_jump(arg, 2) + 1)];
  process->reg[ind - 1] = nbr;
  process->pos = circle(process->pos, place_to_jump(arg, 3) + 1);
  return (0);
}

int		my_xor(t_arena *arena, t_process *process, int id, int pc_pos)
{
  int		nbr;
  int		ind;
  unsigned char	arg;

  (void)id;
  process->pos = circle(process->pos, 1);
  arg = arena->arena[process->pos];
  if (check_mult_args(arena->arena, 5, process->pos, 3) == -1)
    return (0);
  process->cycle += op_tab[5].nbr_cycles;
  nbr = take_what(arena->arena, process->pos, make_choix(pc_pos, 1, 1),
		  process->reg);
  nbr ^= take_what(arena->arena, process->pos, make_choix(pc_pos, 1, 2),
		   process->reg);
  ind = arena->arena[circle(process->pos, place_to_jump(arg, 2) + 1)];
  process->reg[ind - 1] = nbr;
  process->pos = circle(process->pos, place_to_jump(arg, 3) + 1);
  return (0);
}
