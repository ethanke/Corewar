/*
** write_cor_file.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/asm/writing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Wed Mar 16 23:13:51 2016 Ethan Kerdelhue
** Last update Thu Mar 17 05:33:41 2016 Ethan Kerdelhue
*/

#include "asm.h"

char *my_strcat(char *dest, char *src)
{
  int len;
  int i;

  len = my_strlen(dest);
  i = 0;
  while(src[i])
    {
      dest[len + i] = src[i];
		i = i + 1;
    }
  dest[len + i] = '\0';
  return (dest);
}

char		set_octet(char a, char b, char c, int fd)
{
  unsigned char		result;

  result = 0;
  printf("A -> %d B -> %d C -> %d\n", a, b, c);
  result = result | (a << 6);
  result = result | (b << 4);
  result = result | (c << 2);
  printf("PARAM BYTE - > %d\n", result);
  write(fd, &result, 1);
  return (result);
}

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

void	write_args_wpb(int fd, t_corarg *args)
{
  int	i;

  i = 0;
  while (args[i].type != -3)
    {
      if (args[i].type == T_REG)
	put_param(my_getnbr(args[i].value), 1, fd);
      else if (args[i].type == T_DIR)
	put_param(my_getnbr(args[i].value), 4, fd);
      else if (args[i].type == T_IND)
	put_param(my_getnbr(args[i].value), 2, fd);
      i++;
    }
}

void	write_args(int fd, t_corarg *args)
{
  int	i;
  char	str[3];

  i = 0;
  while (i < 3 && args[i].type != -3)
    {
      printf("TYPE -> %d\n", args[i].type);
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
  i = 0;
  while (args[i].type != -3)
    {
      if (args[i].type == T_REG)
	put_param(my_getnbr(args[i].value), 1, fd);
      else if (args[i].type == T_DIR)
	put_param(my_getnbr(args[i].value), 4, fd);
      else if (args[i].type == T_IND)
	put_param(my_getnbr(args[i].value), 2, fd);
      i++;
    }
}

void	write_instr(int nbr, int fd, t_corarg *args)
{
  printf("NBR INSTR - > %d\n", nbr);
  put_param(nbr, 1, fd);
  if (nbr != 1 && nbr != 9 && nbr != 12 && nbr != 15)
    write_args(fd, args);
  else
    write_args_wpb(fd, args);
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
  puts(tmp->instruction);
  while (tmp != NULL)
    {
      write_instr(get_mnemonique_nb(tmp->instruction), corfile->fd, tmp->tab_args);
      tmp = tmp->next;
    }
}
