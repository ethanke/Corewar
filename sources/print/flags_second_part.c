/*
** flags_second_part.c for  in /home/sagot_g/rendu/PSU_2015_my_printf/sources
**
** Made by guillaume sagot
** Login   <sagot_g@epitech.net>
**
** Started on  Mon Nov  2 23:19:10 2015 guillaume sagot
** Last update Wed Nov  4 19:20:59 2015 guillaume sagot
*/

#include "printf.h"

int		flags_u(va_list ap)
{
  return (my_put_unsigned_int(va_arg(ap, unsigned int)));
}

int		flags_p(va_list ap)
{
  my_putstr("0x");
  return (my_put_unsigned_long_int_base(va_arg(ap, unsigned long int)
					, "0123456789abcedef") + 2);
}

int		flags_b(va_list ap)
{
  return (my_put_unsigned_int_base(va_arg(ap, int), "01"));
}

int		flags_X(va_list ap)
{
  return (my_put_unsigned_int_base(va_arg(ap, int), "0123456789ABCDEF"));
}

int		flags_S(va_list ap)
{
  char		*str;
  int		printable_char;
  int		i;

  i = 0;
  printable_char = 0;
  str = va_arg(ap, char *);
  while (str[i] != '\0')
  {
    if (my_str_isprintable(str))
    {
      my_putchar(str[i]);
      printable_char++;
    }
    else
    {
      my_putchar('\\');
      my_put_unsigned_int_base(str[i], "01234567");
      printable_char = printable_char + 4;
    }
    i++;
  }
  return (printable_char);
}
