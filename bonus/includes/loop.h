/*
** loop.h for corewar in /Users/sousa_v/Shared/rendu/cpe/Coreware_temp/corewar/includes/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Wed Mar 16 04:03:45 2016 Victor Sousa
** Last update Wed Mar 16 04:15:23 2016 Victor Sousa
*/

#ifndef			LOOP_H_
# define		LOOP_H_

# include		"corewar.h"

typedef struct		s_loop
{
  int			cycle_to_die;

}			t_loop;

void			main_loop(t_arena *arena);

#endif		      /*LOOP_H_*/
