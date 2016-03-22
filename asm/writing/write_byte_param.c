/*
** write_byte_param.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/asm/writing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Tue Mar 22 23:34:42 2016 Ethan Kerdelhue
** Last update Tue Mar 22 23:44:30 2016 Ethan Kerdelhue
*/

#include "asm.h"

char		set_octet(char a, char b, char c, int fd)
{
  unsigned char		result;

  result = 0;
  result = result | (a << 6);
  result = result | (b << 4);
  result = result | (c << 2);
  write(fd, &result, 1);
  return (result);
}

void	write_byte_param(int fd, t_corarg *args)
{
  char		str[3];
  int		i;

  i = 0;
  while (i < 3 && args[i].type != -3)
    {
      if (args[i].type == T_REG)
	str[i] = 1;
      else if (args[i].type == T_DIR)
	str[i] = 2;
      else if (args[i].type == T_IND)
	str[i] = 3;
      else
	str[i] = 0;
      i++;
    }
  while (i < 3)
    str[i++] = 0;
  set_octet(str[0], str[1], str[2], fd);
}
