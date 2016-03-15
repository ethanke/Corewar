/*
** funct.h for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/corewar/includes/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sun Mar 13 11:44:48 2016 Gaëtan Léandre
** Last update Tue Mar 15 22:01:50 2016 Victor Sousa
*/

#ifndef		FUNCT_H_
# define	FUNCT_H_

typedef struct		s_choix
{
  int			pc;
  char			modu;
  char			place;
}			t_choix;

typedef struct	s_func
{
  void		(*func)(t_arena *arena, t_process *process, int id, int pc_pos);
}		t_func;

int		check_arg(int funct, int pos, char arg);
int		check_reg(int reg);
int		check_mult_args(unsigned char *arena, int fun,
				int pos, int siz);
int		my_fork(t_arena *arena, t_process *process, int id, int pc_pos);
int		my_lfork(t_arena *arena, t_process *process,
			 int id, int pc_pos);

#endif	      /*FUNCT_H_*/
