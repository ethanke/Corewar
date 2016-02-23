/*
** my_printf.c for  in /home/sagot_g/rendu/PSU_2015_my_printf
**
** Made by guillaume sagot
** Login   <sagot_g@epitech.net>
**
** Started on  Mon Nov  2 16:20:27 2015 guillaume sagot
** Last update Wed Nov 25 15:10:22 2015 Guillaume SAGOT
*/

#include "printf.h"

void		init_flags(t_count *count, flag **flag_ptr)
{
  count->nb_char = 0;
  count->i = 0;
  *flag_ptr = stock_flags();
}

flag            *stock_flags()
{
  flag          *flag_ptr;

  flag_ptr = malloc((FLAGS_NB + 1) * sizeof(int *));
  if (flag_ptr == NULL)
    return (0);
  flag_ptr[0] = flags_b;
  flag_ptr[1] = flags_c;
  flag_ptr[2] = flags_d;
  flag_ptr[3] = flags_o;
  flag_ptr[4] = flags_p;
  flag_ptr[5] = flags_s;
  flag_ptr[6] = flags_t;
  flag_ptr[7] = flags_u;
  flag_ptr[8] = flags_x;
  flag_ptr[9] = flags_X;
  flag_ptr[10] = flags_S;
  flag_ptr[11] = flags_i;
  flag_ptr[12] = flags_f;
  flag_ptr[13] = flags_ld;
  flag_ptr[14] = flags_percent;
  flag_ptr[15] = NULL;
  return (flag_ptr);
}

void		read_flags(const char *format, t_count *count, flag *flag_ptr,
			  va_list ap)
{
  char		*list_flags;
  int		j;

 j = 0;
 list_flags = "bcdopstuxXSifln%" ;
 while (format[count->i] != list_flags[j] && j <= FLAGS_NB)
    j++;
  if (j < FLAGS_NB)
    count->nb_char = count->nb_char + flag_ptr[j](ap);
  else
  {
    my_putchar('%');
    my_putchar(format[count->i]);
  }
}
