/*
** corewar.h for  in /home/sagot/Downloads/corewar/asm/
**
** Made by Guillaume SAGOT
** Login   <sagot_g@epitech.eu>
**
** Started on  Thu Jan 28 14:25:39 2016 Guillaume SAGOT
** Last update Fri Mar 11 19:53:44 2016 Ethan Kerdelhue
*/

#ifndef _ASSEMBLY_H_
# define _ASSEMBLY_H_
# define _GNU_SOURCE


# include               <sys/types.h>
# include               <sys/stat.h>
# include               <dirent.h>
# include               <stdlib.h>
# include 		<string.h>
# include               <unistd.h>
# include               <fcntl.h>
# include               <stdio.h>
# include               <time.h>
# include               <pwd.h>
# include               <grp.h>

#include 		"printf.h"
#include		"get_next_line.h"

typedef struct          s_label
{
  int                   i;
  int                   fd;
  int                   line;
  char                  *name;
  char			*pos;
  struct s_label	*next;
}                       t_label;

typedef struct          s_instruction
{
  char			*name;
  int			*value_type;
  char			*value_content;
  int			parent_label_id;
}                       t_instruction;

typedef struct		s_system
{
  char			**tab;
  char			*name;
  char			*file_name;
  char			*ret;
  char			*str;
  int			col;
  int			i;
  t_label		label[128];
  t_instruction		*instruction;
}			t_system;

int     	mstrcmp(char *s1, char *s2);
char		*mstrrchr(const char *s, int c);

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
