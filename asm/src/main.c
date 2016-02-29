/*
** main.c for  in /home/sagot_g/rendu/PSU_2015_my_printf
**
** Made by guillaume sagot
** Login   <sagot_g@epitech.net>
**
** Started on  Mon Nov  2 09:58:39 2015 guillaume sagot
** Last update Wed Nov 25 15:09:24 2015 Guillaume SAGOT
*/

#include "printf.h"

int		my_printf(const char *format, ...)
{
  t_count	count;
  va_list	ap;
  flag		*flag_ptr;

  init_flags(&count, &flag_ptr);
  va_start(ap, format);
  while (format[count.i] != '\0')
  {
    if (format[count.i] == '%')
    {
      count.i++;
      read_flags(format, &count, flag_ptr, ap);
    }
    else
    {
      my_putchar(format[count.i]);
      count.nb_char++;
    }
    count.i++;
  }
  va_end(ap);
  return (count.nb_char);
}
