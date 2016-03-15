/*
** oct_verif.c for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/corewar/src/utils/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Mon Mar 14 18:26:51 2016 Gaëtan Léandre
** Last update Tue Mar 15 17:34:11 2016 Gaëtan Léandre
*/

#include	"corewar.h"

char		who_are_u(unsigned char param, int to_read)
{
  int		pos;
  char		result;

  pos = 7 - ((to_read - 1) * 2);
  result = 2 * ((param >> pos) & 1);
  pos--;
  result = result + ((param >> pos) & 1);
  return (result);
}

int		octet_to_read(unsigned char param, int to_read)
{
  char arg;

  arg = who_are_u(param, to_read);
  if (arg == T_REG)
    return (1);
  else if (arg == T_DIR)
    return (4);
  else if (arg == T_IND - 1)
    return (2);
  return (-1);
}

int		octet_to_r(char arg)
{
  if (arg == T_REG)
    return (1);
  else if (arg == T_DIR)
    return (4);
  else if (arg == T_IND - 1)
    return (2);
  return (-1);
}

int		place_to_jump(unsigned char arg, char place)
{
  int		tmp;
  char		i;

  i = 1;
  tmp = 0;
  while (i <= place)
    {
      tmp = tmp + octet_to_read(arg, i);
      i++;
    }
  return (tmp);
}
