/*
** write_cor_file.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/asm/writing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Wed Mar 16 23:13:51 2016 Ethan Kerdelhue
** Last update Tue Mar 22 23:43:54 2016 Ethan Kerdelhue
*/

#include "asm.h"

void		put_param(int nbr, int bit, int fd)
{
  int		i;
  int		dec;
  unsigned char	result;

  i = 0;
  dec = (bit - 1) * 8;
  while (i < bit)
    {
      result = nbr >> (dec);
      write(fd, &result, 1);
      i++;
      dec -= 8;
    }
}

int	get_mnemonique_nb(char *str)
{
  int	i;

  i = 0;
  while (op_tab[i].mnemonique)
    {
      if (my_strcmp(op_tab[i].mnemonique, str) == 0)
	return (i + 1);
      i++;
    }
  return (i + 1);
}

void	write_cor(t_cor *corfile)
{
  t_corline	*tmp;

  tmp = corfile->first_line->next;
  while (tmp != NULL)
    {
      write_instr(get_mnemonique_nb(tmp->instruction),
		  corfile->fd, tmp->tab_args);
      tmp = tmp->next;
    }
}
