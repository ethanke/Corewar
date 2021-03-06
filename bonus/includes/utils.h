/*
** util.h for UTILS in /Users/sousa_v/Shared/rendu/cpe/UTILS_temp/UTILS/includes/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sun Mar  6 23:40:08 2016 Victor Sousa
** Last update Thu Mar 17 04:50:19 2016 Victor Sousa
*/

#ifndef			UTILS_H_
# define		UTILS_H_

int			my_strlen(char *str);
int			my_getnbr(const char *str);
void			verif_arg(int ac, char **av);
void			*xmalloc(int size);
int			xopen(char *path);
int			mod(int nbr, int modulo);
int			take_param(unsigned char *arena, int pos, int bit);
void			put_param(t_arena *arena, int pos, int id, int nbr);
int			take_ind(unsigned char *arena, int pos,
				 int modu, int pc);
int			take_reg(unsigned char *arena,
				 unsigned char reg, char pc);
int			take_what(unsigned char *arena, int pos,
				  t_choix choix, int *reg);
int			circle(int pos, int incr);
void			my_memset(void *ptr, int size, char c);
void			end_prog(t_arena *arena);
char			who_are_u(unsigned char param, int to_read);
int			octet_to_read(unsigned char param, int to_read);
int			octet_to_r(char arg);
struct s_choix		make_choix(int pc, char modu, char place);
int			place_to_jump(unsigned char arg, char place);
void			free_process(t_process *process);
void			create_registre(t_process *process, int id);
void			cpy_registre(t_process *child, t_process *parent);
unsigned int		pick_color(int id);
t_process		*add_child(t_process *father);
void			init_child(t_process *father, t_process *child);
t_process		*add_child(t_process *father);

#endif		      /*UTILS_H*/
