/*
** flags_one.c for  in /home/sagot_g/rendu/PSU_2015_my_printf
**
** Made by guillaume sagot
** Login   <sagot_g@epitech.net>
**
** Started on  Mon Nov  2 16:19:38 2015 guillaume sagot
** Last update Sun Nov 08 18:28:58 2015 Guillaume SAGOT
*/

#include "printf.h"

int		flags_s(va_list ap)
{
  char		*str;

  str = va_arg(ap, char*);
  my_putstr(str);
  return (my_strlen(str));
}

int		flags_c(va_list ap)
{
  my_putchar(va_arg(ap, int));
  return (1);
}

int		flags_d(va_list ap)
{
  return (my_put_nbr(va_arg(ap, int)));
}

int		flags_o(va_list ap)
{
  return (my_put_unsigned_int_base(va_arg(ap, unsigned int), "01234567"));
}

int		flags_x(va_list ap)
{
  return (my_put_unsigned_int_base(va_arg(ap, unsigned int),
				  "0123456789abcdef"));
}
