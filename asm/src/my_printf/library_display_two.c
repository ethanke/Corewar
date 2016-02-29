/*
** library_display_two.c for  in /home/sagot_g/rendu/PSU_2015_my_printf
**
** Made by guillaume sagot
** Login   <sagot_g@epitech.net>
**
** Started on  Wed Nov  4 19:24:00 2015 guillaume sagot
** Last update Fri Nov 13 09:23:49 2015 Guillaume SAGOT
*/

#include "printf.h"

int		my_put_nbr(int nb)
{
  if (nb < 0)
    {
      nb = -nb;
      my_putchar('-');
    }
  if (nb > 0)
    {
      my_put_nbr(nb / 10);
      my_putchar(nb % 10 + 48);
    }
  return (0);
}

int		my_put_float(double nb, int p)
{
  my_put_nbr(nb);
  my_putchar('.');
  nb > 0 ? my_put_nbr((nb - (int)nb) * p) : my_put_nbr((-nb - (int) - nb) * p);
  return (nb);
}

int             my_show_wordtab(char **tab)
{
  int           len;
  int           i;
  int           char_print;

  i = 0;
  char_print = 0;
  len = my_strlen_tabs(tab);
  while (i < len)
    {
      my_putstr(tab[i]);
      char_print += my_strlen(tab[i]) + 1;
      my_putchar('\n');
      i++;
    }
  return (char_print);
}

int             my_put_unsigned_int(unsigned int nb)
{
  unsigned int  i;
  int   	printable_char;

  printable_char = 0;
  i = nb;
  if (nb > 9)
    {
      i = nb % 10;
      printable_char += my_put_unsigned_int(nb / 10);
    }
  my_putchar(i + '0');
  return (printable_char + 1);
}
