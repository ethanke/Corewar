/*
** get_next_line.c for get_next_line in /home/sousa_v/CPE_2015_getnextline
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Thu Jan  7 03:11:04 2016 victor sousa
** Last update Fri Mar 25 10:12:44 2016 Victor Sousa
*/

#include	"corewar.h"

char		*get_next_line(const int fd)
{
  char		*output;
  char		c;
  int		i;
  int		ret;

  i = 0;
  output = xmalloc(sizeof(char) * 4096);
  output[i] = '\0';
  while ((ret = read(fd, &c, 1)) > 0)
    {
      if (c != 0)
	{
	  if (c == '\n')
	    {
	      output[i++] = ' ';
	      output[i++] = '\0';
	      return (output);
	    }
	  output[i++] = c;
	}
      else
	return (0);
    }

  return (0);
}
