/*
** funct.h for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/corewar/includes/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sun Mar 13 11:44:48 2016 Gaëtan Léandre
** Last update Wed Mar 16 03:07:14 2016 Victor Sousa
*/

#ifndef		FUNCT_H_
# define	FUNCT_H_

typedef struct		s_choix
{
  int			pc;
  char			modu;
  char			place;
}			t_choix;

int		check_arg(int funct, int pos, char arg);
int		check_reg(int reg);
int		check_mult_args(unsigned char *arena, int fun,
				int pos, int siz);

int		my_live(t_arena *arena, t_process *process, int id, int pc_pos);
int		my_ld(t_arena *arena, t_process *process, int id, int pc_pos);
int		my_st(t_arena *arena, t_process *process, int id, int pc_pos);
int		my_add(t_arena *arena, t_process *process, int id, int pc_pos);
int		my_sub(t_arena *arena, t_process *process, int id, int pc_pos);
int		my_and(t_arena *arena, t_process *process, int id, int pc_pos);
int		my_or(t_arena *arena, t_process *process, int id, int pc_pos);
int		my_xor(t_arena *arena, t_process *process, int id, int pc_pos);
int		my_zjump(t_arena *arena, t_process *process, int id, int pc_pos);
int		my_ldi(t_arena *arena, t_process *process, int id, int pc_pos);
int		my_sti(t_arena *arena, t_process *process, int id, int pc_pos);
int		my_fork(t_arena *arena, t_process *process, int id, int pc_pos);
int		my_lld(t_arena *arena, t_process *process, int id, int pc_pos);
int		my_lldi(t_arena *arena, t_process *process, int id, int pc_pos);
int		my_lfork(t_arena *arena, t_process *process, int id, int pc_pos);
int		my_aff(t_arena *arena, t_process *process, int id, int pc_pos);

#endif	      /*FUNCT_H_*/
