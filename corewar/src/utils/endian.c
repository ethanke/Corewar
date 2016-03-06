/*
** invert_endian.c for corewar in /Users/sousa_v/Shared/rendu/cpe/Corewar_temp/corewar/src/utils/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sun Mar  6 22:20:15 2016 Victor Sousa
** Last update Sun Mar  6 22:41:07 2016 Victor Sousa
*/

#include	"corewar.h"

char		is_big_endian()
{
  char		*byte;
  int		checker;

  checker = 1;
  byte = (char *)&checker;
  return (byte[1]);
}

void		invert_endian(void *void_buf, int size)
{
  char		tmp;
  char		*char_buf;
  int		i;

  char_buf = void_buf;
  i = -1;
  while (i++ < size / 2)
    {
      tmp = char_buf[size - i - 1];
      char_buf[size -i - 1] = char_buf[i];
      char_buf[i] = tmp;
    }
}
