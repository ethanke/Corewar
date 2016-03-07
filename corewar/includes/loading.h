/*
** loading.h for corewar in /Users/sousa_v/Shared/rendu/cpe/Coreware_temp/corewar/includes/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Mon Mar  7 01:18:37 2016 Victor Sousa
** Last update Mon Mar  7 04:12:27 2016 Victor Sousa
*/

#ifndef			LOADING_H_
# define		LOADING_H_

t_champ			init_champion(int ac, char **av);
int			is_a_champ_path(char *str);
void			load_process(t_champ *champ, int ac, char **av);

/* ID STUFF */
int			is_a_id_request(char *str);
int			get_id(int *read_id_needed, int i, char **av);
void			check_id(t_champ *champ);

#endif		      /*LOADING_H*/
