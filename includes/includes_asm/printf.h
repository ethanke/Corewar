/*
** printf.h for  in /home/sagot_g/rendu/PSU_2015_my_printf
**
** Made by guillaume sagot
** Login   <sagot_g@epitech.net>
**
** Started on  Mon Nov  2 09:56:12 2015 guillaume sagot
** Last update Wed Nov 25 19:01:06 2015 Guillaume SAGOT
*/

#ifndef _PRINTF_H_
# define _PRINTF_H_
# define FLAGS_NB 12

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <stdio.h>

typedef struct 	s_count
{
  int		nb_char;
  int		i;
}		t_count;

typedef 	int(*flag)(va_list);

/* display    */
void		my_putchar(char c);
void		my_putstr(char *str);
char 		*my_put_int(int nb);
int		my_put_nbr(int nb);
int		my_put_float(double, int);
int             my_put_unsigned_int(unsigned int nb);
int		my_put_unsigned_int_base(unsigned int nb, char *base);
int		my_put_unsigned_long_int_base(unsigned int nb, char *base);

/* multiusage */
void		display_zero(char c);
int		my_strlen(char *str);
int		my_show_wordtab(char **tab);
int		my_str_isprintable(char *str);
int             my_strlen_tabs(char **tab);

/* exist      */
flag		*stock_flags();
void		init_flags(t_count *count, flag **flag_ptr);
int		my_printf(const char *format, ...);

/* flags_args */
void		read_flags(const char *format, t_count *count, flag *plag_ptr,
			   va_list);
int		flags_n(va_list ap);
int		flags_b(va_list ap);
int		flags_c(va_list ap);
int		flags_d(va_list ap);
int		flags_i(va_list ap);
int		flags_o(va_list ap);
int		flags_p(va_list ap);
int		flags_s(va_list ap);
int		flags_t(va_list ap);
int		flags_u(va_list ap);
int		flags_x(va_list ap);
int		flags_X(va_list ap);
int		flags_S(va_list ap);
int		flags_f(va_list ap);
int		flags_ld(va_list ap);
int		flags_percent();

#endif
