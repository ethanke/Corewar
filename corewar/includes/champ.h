/*
** champ.h for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/includes/includes_corewar/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sat Mar  5 21:25:43 2016 Gaëtan Léandre
** Last update Mon Mar 14 15:16:00 2016 Victor Sousa
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
  struct s_process	*next;
  struct s_process	*child;
}			t_process;

typedef struct		s_champ
{
  char			nbr_champ; /*done*/
  int			*live;
  int			*id_champ; /*done*/
  int			*pc_pos;   /*done*/
  header_t		*header;   /*done*/
  unsigned char		**instru;  /*done*/
  t_process		**process;
}			t_champ;

#endif		      /*CHAMP_H_*/
