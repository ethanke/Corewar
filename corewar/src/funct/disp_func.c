/*
** disp_func.c for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/corewar/src/funct/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Wed Mar 16 01:46:52 2016 Gaëtan Léandre
** Last update Wed Mar 16 02:32:58 2016 Gaëtan Léandre
*/

#include	"corewar.h"

int		my_aff(t_arena *arena, t_process *process, int pc_pos)
{
  int		reg;
  unsigned char	arg;

  (void)pc_pos;
  process->pos = circle(process->pos, 1);
  arg = arena->arena[process->pos];
  if (check_mult_args(arena->arena, 15, process->pos, 1) == -1)
    return (0);
  process->cycle += op_tab[15].nbr_cycles;
  reg = process->reg[arena->arena[circle(process->pos, 1)] - 1];
  reg = reg % 256;
  my_printf("%c", reg);
  process->pos = circle(process->pos, place_to_jump(arg, 1) + 1);
  return (0);
}

int		my_zjump(t_arena *arena, t_process *process, int pc_pos)
{
  process->pos = circle(process->pos, 1);
  process->cycle += op_tab[8].nbr_cycles;
  if (process->carry == 1)
    process->pos = circle(pc_pos, mod(take_param(arena->arena, process->pos,
						 IND_SIZE), IDX_MOD));
  process->pos = circle(process->pos, octet_to_r(3) + 1);
  return (0);
}

int		check_proprio(char *proprio, int pos, char size, int *id)
{
  int		said;
  int		i;

  said = proprio[pos];
  i = 0;
  if (said == -1)
    return (-1);
  while (i < size)
    {
      if (said == id[i])
	return (i);
      i++;
    }
  return (-1);
}

int		my_live(t_arena *arena, t_process *process, int pc_pos)
{
  t_champ	*champ;
  int		who_said;
  int		tmp;

  champ = arena->champ;
  process->pos = circle(process->pos, 1);
  process->cycle += op_tab[0].nbr_cycles;
  tmp = take_param(arena->arena, process->pos, DIR_SIZE);
  tmp = circle(pc_pos, tmp);
  who_said = check_proprio(arena->proprio, tmp,
			   champ->nbr_champ, champ->id_champ);
  if (who_said != -1)
    {
      my_printf("le joueur %d(%s) est en vie\n", champ->id_champ[who_said],
		champ->header[who_said].prog_name);
      champ->last_live = who_said;
      champ->live[who_said] = 1;
      process->living = 1;
    }
  return (0);
}
