/*
** corewar.h for  in /home/sagot/Downloads/corewar/asm/
**
** Made by Guillaume SAGOT
** Login   <sagot_g@epitech.eu>
**
** Started on  Thu Jan 28 14:25:39 2016 Guillaume SAGOT
** Last update Tue Mar  1 00:50:14 2016 Guillaume SAGOT
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

#endif
