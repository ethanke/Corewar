/*
** corewar.h for  in /home/sagot/Downloads/corewar/asm/
**
** Made by Guillaume SAGOT
** Login   <sagot_g@epitech.eu>
**
** Started on  Thu Jan 28 14:25:39 2016 Guillaume SAGOT
** Last update Tue Mar  1 02:21:49 2016 Guillaume SAGOT
*/

#ifndef _ASSEMBLY_H_
# define _ASSEMBLY_H_

/* Header declaration 	*/
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>

#include "printf.h"

typedef struct          s_label
{
  int                   i;
  int                   fd;
  int                   line;
  char                  *name;
  char			*pos;
  struct s_label	next;
}                       t_label;

typedef struct          s_instruction
{
  int                   i;
  int                   fd;
  int                   cmptr;
  int                   *ins;
  int                   base;
  char                  control;
  char                  *instruction_check;
  char                  *str;
}                       t_instruction;

typedef struct		s_system
{
  char			*name;
  char			*file_name;
  char			*ret;
  char			*str;
  int			col;
  int			i;
  t_label		label[128];
  t_instruction		instruction;
}			t_system;

/* functions for instructions */
void		live_instruction(t_system *sys);
void		load_instruction(t_system *sys);
void		store_instruction(t_system *sys);
void		addition_instruction(t_system *sys);
void		substraction_instruction(t_system *sys);
void		and_instruction(t_system *sys);
void		or_instruction(t_system *sys);
void		xor_instruction(t_system *sys);
void		jump_if_zero_instruction(t_system *sys);
void		load_index_instruction(t_system *sys);
void		store_index_instruction(t_system *sys);
void		fork_instruction(t_system *sys);
void		long_load_instruction(t_system *sys);
void		long_load_index_instruction(t_system *sys);
void		long_fork_instruction(t_system *sys);
void		aff_instruction(t_system *sys);

/* functions check errors */
void		live_checkError(t_system *sys, int *values);
void		load_checkError(t_system *sys, int values);
void		store_checkError(t_system *sys, int *values);
void		addition_checkError(t_system *sys, int *values);
void		substraction_checkError(t_system *sys, int *values);
void		and_checkError(t_system *sys, int *values);
void		or_checkError(t_system *sys, int *values);
void		xor_checkError(t_system *sys, int *values);
void		jump_if_zero_checkError(t_system *sys, int *values);
void 		ldi_checkError(t_system *sys, int *values);
void		 sti_checkError(t_system *sys, int *values);
void		fork_checkError(t_system *sys, int *values);
void		fork_checkError(t_system *sys, int *values);
void		lld_checkError(t_system *sys, int *values);
void		lldi_checkError(t_system *sys, int *values);
void		lfork_checkError(t_system *sys, int *values);
void		aff_checkError(t_system *sys, int * values);

/* functions initialisation for errors and simple instructuions */
void		initError(void*(checkError[16]));
t_system	*initInstructions();

/* functions for the header ü */
int		load_addressLabel(t_label *label, char *str, int i);


#endif
