/*
** util.h for UTILS in /Users/sousa_v/Shared/rendu/cpe/UTILS_temp/UTILS/includes/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sun Mar  6 23:40:08 2016 Victor Sousa
** Last update Sun Mar 13 14:01:31 2016 Gaëtan Léandre
*/

#ifndef			UTILS_H_
# define		UTILS_H_

int			my_strlen(char *str);
int			my_getnbr(const char *str);
void			verif_arg(int ac, char **av);
void			*xmalloc(int size);
int			mod(int nbr, int modulo);
int			take_param(unsigned char *arena, int pos, int bit);
unsigned char		*put_param(unsigned char *arena, int pos,
				   int bit, int nbr);
int			take_ind(unsigned char *arena, int pos,
				 int modu, int pc);
int			take_reg(unsigned char *arena, int pos, int pc);
int			take_what(unsigned char *arena, int pos,
				  int modu, int pc);
int			circle(int pos, int incr);

#endif		      /*UTILS_H*/
