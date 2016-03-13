/*
** read_file.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/asm/src/parsing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Mon Mar  7 01:56:39 2016 Ethan Kerdelhue
** Last update Sun Mar 13 17:30:11 2016 Ethan Kerdelhue
*/

#include "asm.h"

void	print_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      printf("%s\n", tab[i]);

      i++;
    }
}

void    *my_memset(void *s, size_t n, int c)
{
  size_t        i;
  char          *d;

  d = s;
  i = 0;
  while (i < n)
    {
      *d++ = c;
      i++;
    }
  return (s);
}

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

void	write_header(t_header *header, t_cor *corfile)
{
  t_int4char 	magic_nbr;
  t_int4char	prog_size;

  magic_nbr.nbr = header->magic;
  header->magic = magic_nbr.str[0] >> 24;
  header->magic += magic_nbr.str[1] >> 16;
  header->magic += magic_nbr.str[2] >> 8;
  header->magic += magic_nbr.str[3];
  magic_nbr.nbr = header->prog_size;
  header->prog_size = prog_size.str[0] >> 24;
  header->prog_size += prog_size.str[1] >> 16;
  header->prog_size += prog_size.str[2] >> 8;
  header->prog_size += prog_size.str[3];
  write(corfile->fd, &header, sizeof(t_header));
  close(corfile->fd);
}

void	store_header(t_header *header, char **tab, t_cor *corfile)
{
  header->prog_name = malloc(PROG_NAME_LENGTH + 2);
  header->comment = malloc(COMMENT_LENGTH + 2);
  my_memset(header, sizeof(t_header), 0);
  header->magic = COREWAR_EXEC_MAGIC;
  header->prog_name = tab[0];
  header->comment = tab[1];
  header->prog_size = 0;
  write_header(header, corfile);
}

int	parse_header(char **tab, t_cor *corfile)
{
  char		*head[2];
  t_header	header;

  head[0] = malloc(PROG_NAME_LENGTH + 1);
  head[0] = checkName(tab[0]);
  head[1] = malloc(COMMENT_LENGTH + 1);
  head[1] = checkComment(tab[1]);
  puts(head[0]);
  puts(head[1]);
  open_corfile(corfile);
  store_header(&header, tab, corfile);
  return (0);
}

char	*getCorName(char *str)
{
  int	i;
  int	j;
  char	*new;

  puts(str);
  my_putchar('\n');
  j = my_strlen(str);
  i = 0;
  while (str[j] != '/' || str[j])
    j--;
  new = malloc(my_strlen(str) + 4);
  return (new);
}

int	read_file(char	*file)
{
  t_cor	*corfile;
  int	fd;
  char	**tab;
  int	i;

  i = -1;
  if ((fd = open(file, O_RDONLY)) == -1)
    return (-1);
  if ((tab = malloc(sizeof(char **) * 49)) == NULL)
    return (-1);
  tab[48] = NULL;
  while ((tab[++i] = (char *) get_next_line(fd)) != NULL);
  corfile = malloc(sizeof(t_cor));
  corfile->name = getCorName(file);
  parse_header(tab, corfile);
  i = -1;
  while (tab[++i])
    free(tab[i]);
  free(tab);
  close(fd);
  return (0);
}

int	main(int ac, char **av)
{
  (void) ac;
  if (av[1])
    read_file(av[1]);
  return (0);
}
