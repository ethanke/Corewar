/*
** util.h for UTILS in /Users/sousa_v/Shared/rendu/cpe/UTILS_temp/UTILS/includes/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sun Mar  6 23:40:08 2016 Victor Sousa
** Last update Fri Mar 11 06:20:20 2016 Gaëtan Léandre
*/

#ifndef			UTILS_H_
# define		UTILS_H_

int			my_strlen(char *str);
int			my_getnbr(const char *str);
void			verif_arg(int ac, char **av);
void			*xmalloc(int size);
int			mod(int nbr, int modulo);
int			circle(int pos, int incr);

#endif		      /*UTILS_H*/
