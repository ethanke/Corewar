/*
** champ.h for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/includes/includes_corewar/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sat Mar  5 21:25:43 2016 Gaëtan Léandre
** Last update Sun Mar  6 22:33:07 2016 Gaëtan Léandre
*/

#ifndef _CHAMP_
# define _CHAMP_

# include "op.h"

typedef struct		s_proces
{

  struct s_proces	*next;
  struct s_proces	*child;
}			t_proces;

typedef struct		s_champ
{
  header_t		*header;
  char			**instru;
  t_proces		**proces;
}			t_champ;

#endif
