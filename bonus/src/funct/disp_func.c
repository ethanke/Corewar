/*
** disp_func.c for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/corewar/src/funct/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Wed Mar 16 01:46:52 2016 Gaëtan Léandre
** Last update Fri Mar 25 16:17:07 2016 Victor Sousa
*/

#include	"corewar.h"

int		my_aff(t_arena *arena, t_process *process, int id, int pc_pos)
{
  int		reg;
  unsigned char	arg;

  (void)pc_pos;
  (void)id;
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

int		my_zjump(t_arena *arena, t_process *process, int id, int pc_pos)
{
  (void)id;
  process->pos = circle(process->pos, 1);
  process->cycle += op_tab[8].nbr_cycles;
  if (process->carry == 1)
    process->pc_pos = circle(pc_pos, mod(take_param(arena->arena, process->pos,
						    IND_SIZE), IDX_MOD));
  else
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

int		my_live(t_arena *arena, t_process *process, int id, int pc_pos)
{
  t_champ	*champ;
  int		who_said;
  int		tmp;
  char		*str;

  (void)id;
  champ = arena->champ;
  process->pos = circle(process->pos, 1);
  process->cycle += op_tab[0].nbr_cycles;
  tmp = take_param(arena->arena, process->pos, DIR_SIZE);
  tmp = circle(pc_pos, tmp);
  who_said = check_proprio(arena->proprio, tmp,
			   champ->nbr_champ, champ->id_champ);
  if (who_said != -1)
    {
	 if (arena->mode == M_SERVER)
	    {
	      str = xmalloc(my_strlen(arena->srv_out.cur_msg) + 1);
	      str = my_strcpy(str, arena->srv_out.cur_msg);
	      free(arena->srv_out.cur_msg);
	      arena->srv_out.cur_msg = xmalloc(my_strlen(champ->header[who_said].prog_name) + my_strlen(str) + 35);
	      sprintf(arena->srv_out.cur_msg, "%sle joueur %d(%s) est en vie\n",
		      str,
		      champ->id_champ[who_said],
		      champ->header[who_said].prog_name);
	      free(str);
	    }
	 else
	    my_printf("le joueur %d(%s) est en vie\n", champ->id_champ[who_said],
		      champ->header[who_said].prog_name);
      champ->last_live = who_said;
      champ->live[who_said] = 1;
      process->living = 1;
      arena->total_live++;
      arena->nbr_live++;
    }
  return (0);
}
