/*
** get_next_line.h for get_next_line in /home/leandr_g/rendu/Janvier_2016/CPE_2015_getnextline
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Mon Jan  4 15:51:07 2016 Gaëtan Léandre
** Last update Tue Mar 15 19:17:11 2016 Ethan Kerdelhue
*/

#ifndef READ_SIZE
# define READ_SIZE (1)
#endif /* !READ_SIZE */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#include <stdlib.h>
#include <unistd.h>

typedef struct		s_text
{
  int	i;
  char	*result;
  char	*stock;
}			t_text;

char	*get_next_line(const int fd);

#endif /* !GET_NEXT_LINE*/
