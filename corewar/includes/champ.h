/*
** champ.h for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/includes/includes_corewar/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sat Mar  5 21:25:43 2016 Gaëtan Léandre
** Last update Wed Mar 16 02:24:31 2016 Gaëtan Léandre
*/

#ifndef			CHAMP_H_
# define 		CHAMP_H_

# include		"corewar.h"

typedef struct		s_process
{
  char			live;
  char			living;
  int			pos;
  int			cycle;
  int			carry;
  int			*reg;
  struct s_process	*next;
  struct s_process	*child;
}			t_process;

typedef struct		s_champ
{
  char			nbr_champ;
  int			*live;
  int			last_live;
  int			*id_champ;
  int			*pc_pos;
  header_t		*header;
  unsigned char		**instru;
  t_process		**process;
}			t_champ;

#endif		      /*CHAMP_H_*/
