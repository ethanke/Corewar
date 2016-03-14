/*
** read_file.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/asm/src/parsing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Mon Mar  7 01:56:39 2016 Ethan Kerdelhue
** Last update Mon Mar 14 05:25:13 2016 Ethan Kerdelhue
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

int	parse_header(char **tab, t_cor *corfile)
{
  t_header	*header;

  header = malloc(sizeof(t_header));
  my_memset(header, sizeof(t_header), 0);
  header->magic = COREWAR_EXEC_MAGIC;
  checkName(tab[0], header);
  checkComment(tab[1], header);
  header->prog_size = 0;
  open_corfile(corfile);
  write_header(header, corfile);
  return (0);
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
