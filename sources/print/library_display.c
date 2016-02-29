/*
** library_display.c for  in /home/sagot_g/rendu/PSU_2015_my_printf
**
** Made by guillaume sagot
** Login   <sagot_g@epitech.net>
**
** Started on  Mon Nov  2 16:20:15 2015 guillaume sagot
** Last update Mon Nov 16 15:46:08 2015 Guillaume SAGOT
*/

#include "printf.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    write(1, &str[i++], 1);
}

char		*my_put_int(int nb)
{
  char		*str;

  str = malloc(sizeof(char) * 4);
  if (str == NULL)
    return (0);
  str[0] = (nb / 100) + '0';
  str[1] = ((nb - ((nb / 100 * 100 )) / 10) + '0');
  str[2] = ((nb % 10) + '0');
  return (str);
}

int		my_put_unsigned_int_base(unsigned int nb, char *base)
{
  unsigned int  i;
  unsigned int	len;
  int		printable_char;

  printable_char = 0;
  len = my_strlen(base);
  i = nb;
  if (nb < len - 1)
    {
      i = nb % len;
      printable_char += my_put_unsigned_int_base(nb / len, base);
    }
  my_putchar(base[i]);
  return (printable_char + 1);
}

int		my_put_unsigned_long_int_base(unsigned int nb, char *base)
{
  unsigned long i;
  unsigned long len;
  int		printable_char;

  i = nb;
  printable_char  = 0;
  len = my_strlen(base);
  if (nb > len - 1)
    {
      i = nb % len;
      printable_char += my_put_unsigned_long_int_base(nb / len, base);
    }
  my_putchar(base[i]);
  return (printable_char + 1);
}
