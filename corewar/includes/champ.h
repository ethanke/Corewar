/*
** champ.h for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/includes/includes_corewar/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sat Mar  5 21:25:43 2016 Gaëtan Léandre
** Last update Sun Mar  6 23:46:28 2016 Gaëtan Léandre
*/

#ifndef			CHAMP_H
# define 		CHAMP_H

# include		"op.h"

typedef struct		s_proces
{

  struct s_proces	*next;
  struct s_proces	*child;
}			t_proces;

typedef struct		s_champ
{
  char			nbr_champ;
  int			*id_champ;
  header_t		*header;
  char			**instru;
  t_proces		**proces;
}			t_champ;

#endif		      /*CHAMP_H*/
