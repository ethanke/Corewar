/*
** library.c for  in /home/sagot/rendu/Corewar/asm/src/utils/
**
** Made by Guillaume SAGOT
** Login   <sagot_g@epitech.eu>
**
** Started on  Thu Mar  3 21:12:37 2016 Guillaume SAGOT
** Last update Sat Mar  5 00:32:29 2016 Guillaume SAGOT
*/

#include "assembly.h"

int     	mstrcmp(char *s1, char *s2)
{
  int   	i;

  i = 0;
  while (s1[i] == s2[i])
    {
      i = i + 1;
      if (s1[i] == 0 && s2[i] == 0)
        return (0);
    }
  return (s1[i] - s2[i]);
}

char		*mstrrchr(const char *s, int c)
{
  size_t	size;
  char		chr;
  char		*ptr;

  size = 0;
  chr = c;
  ptr = NULL;
  if (chr == '\0')
    return ((char *)s + my_strlen(s));
  while (s[i] != '\0')
    {
      if (s[i] == c)
	ptr = (char *)s + i;
      i += 1;
    }
  return (ptr);
}

int		my_check_neg(char *str)
{
  int		i;
  int		neg;

  neg = 0;
  i = 0;
  while ((str[i] == '+' || str[i] == '-') && str[i] != '\0')
    {
      if (str[i] == '-')
	neg++;
      i++;
    }
  if (neg % 2 == 0)
    return (1);
  return (-1);
}

int		my_getnbr_base(char *str, char *base)
{
  int		negative;
  int		nb;
  int		lenght;
  int		i;
  int		j;

  lenght = my_strlen(base);
  nb = 0;
  i = 0;
  if (my_checkerrors(str, base))
    return (0);
  negative = my_check_neg(str);
  while (str[i] != '\0')
    {
      j = 0;
      while (j < lenght && base[j] != str[i])
	j++;
      nb = nb * lenght + j;
      i++;
    }
  return (negative * nb);
}

char		*convert_base(char *nbr, char *base_from, char *base_to)
{
  int		i;
  int		nb;
  char 		*res;
  i = 0;
  res = malloc(sizeof(char) * 300);
  nb = my_getnbr_base(nbr, base_from);
  while (nb > 0)
    {
      res[i] = base_to[nb % my_strlen(base_to)];
      nb = nb / my_strlen(base_to);
      i = i + 1;
    }
  res[i] = '\0';
  res = my_revstr(res);
  return (res);
}
