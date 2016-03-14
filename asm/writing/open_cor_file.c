/*
** open_cor_file.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/asm/writing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Mon Mar 14 05:21:01 2016 Ethan Kerdelhue
** Last update Mon Mar 14 05:22:20 2016 Ethan Kerdelhue
*/

#include "asm.h"

void	open_corfile(t_cor *corfile)
{
  if ((corfile->fd = open(corfile->name, O_WRONLY | O_CREAT | O_TRUNC,
			  S_IRUSR | S_IWUSR)) == -1)
    {
      my_putstr("[FILE] Failed to create ");
      my_putstr(corfile->name);
      putError(" file, check your folders rights");
    }
  my_putstr("[FILE] ");
  my_putstr(corfile->name);
  my_putstr(" as been created !");
}

char	*getCorName(char *str)
{
  int	i;
  int	j;
  char	*new;

  j = my_strlen(str);
  i = 0;
  new = malloc(my_strlen(str) + 4);
  while (str[j] != '/' && j != 0)
    j--;
  if (str[j] == '/')
    j += 1;
  while (str[j] != '.')
    {
      new[i] = str[j];
      i++;
      j++;
    }
  new[i] = '.';
  new[i + 1] = 'c';
  new[i + 2] = 'o';
  new[i + 3] = 'r';
  return (new);
}
