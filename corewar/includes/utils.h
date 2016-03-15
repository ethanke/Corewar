/*
** util.h for UTILS in /Users/sousa_v/Shared/rendu/cpe/UTILS_temp/UTILS/includes/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sun Mar  6 23:40:08 2016 Victor Sousa
<<<<<<< HEAD
** Last update Tue Mar 15 18:09:50 2016 Victor Sousa
=======
** Last update Tue Mar 15 18:06:58 2016 Gaëtan Léandre
>>>>>>> 9cd296a3937a892a87447024d3ff8f8b9fd60487
*/

#ifndef			UTILS_H_
# define		UTILS_H_

typedef struct		s_choix
{
  int			pc;
  char			modu;
  char			place;
}			t_choix;

int			my_strlen(char *str);
int			my_getnbr(const char *str);
void			verif_arg(int ac, char **av);
void			*xmalloc(int size);
int			xopen(char *path);
int			mod(int nbr, int modulo);
int			take_param(unsigned char *arena, int pos, int bit);
unsigned char		*put_param(unsigned char *arena, int pos,
				   int bit, int nbr);
int			take_ind(unsigned char *arena, int pos,
				 int modu, int pc);
int			take_reg(unsigned char *arena,
				 unsigned char reg, char pc);
int			take_what(unsigned char *arena, int pos,
				  struct s_choix choix);
int			circle(int pos, int incr);
void			my_memset(void *ptr, int size, char c);
void			end_prog(t_arena *arena);
char			who_are_u(unsigned char param, int to_read);
int			octet_to_read(unsigned char param, int to_read);
int			octet_to_r(char arg);
struct s_choix		make_choix(int pc, char modu, char place);
int			place_to_jump(unsigned char arg, char place);

#endif		      /*UTILS_H*/
