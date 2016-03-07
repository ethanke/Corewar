/*
** champ.h for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/includes/includes_corewar/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sat Mar  5 21:25:43 2016 Gaëtan Léandre
** Last update Mon Mar  7 02:14:13 2016 Gaëtan Léandre
*/

#ifndef			CHAMP_H
# define 		CHAMP_H

# include		"corewar.h"

typedef struct		s_process
{
  int			live;
  int			pos;
  int			carry;
  struct s_proces	*next;
  struct s_proces	*child;
}			t_process;

typedef struct		s_champ
{
  char			nbr_champ;
  int			*id_champ;
  int			*pc_pos;
  header_t		*header;
  char			**instru;
  t_proces		**process;
}			t_champ;

#endif		      /*CHAMP_H*/
