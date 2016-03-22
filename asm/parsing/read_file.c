/*
** read_file.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/asm/src/parsing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Mon Mar  7 01:56:39 2016 Ethan Kerdelhue
** Last update Tue Mar 22 20:33:17 2016 Ethan Kerdelhue
*/

#include "asm.h"

int	get_prog_size(t_cor *corfile)
{
  t_corline	*tmp;

  tmp = corfile->first_line;
  while (tmp->next != NULL)
    tmp = tmp->next;
  return (tmp->mempos);
}

int	parse_header(t_cor *corfile)
{
  t_header	*header;

  header = malloc(sizeof(t_header));
  my_memset(header, sizeof(t_header), 0);
  header->magic = COREWAR_EXEC_MAGIC;
  checkName(corfile->tab[0], header);
  checkComment(corfile->tab[1], header);
  header->prog_size = get_prog_size(corfile);
  open_corfile(corfile);
  write_header(header, corfile);
  return (0);
}

char                    **convert_file_in_double_etoile_fdp_de_merde(char *path)
{
  int                   fd;
  char                  c;
  char                  *file1d;
  int                   i;
  char                  **file;

  if ((fd = open(path, O_RDONLY)) == -1)
    return (NULL);
  if ((file1d = malloc(sizeof(char) * 2)) == NULL)
    return (NULL);
  i = 0;
  while (read(fd, &c, 1) > 0)
    {
      file1d[i] = c;
      file1d[i + 1] = 0;
      file1d = realloc(file1d, sizeof(char) * (my_strlen(file1d) + 2));
      i++;
    }
  if ((file = my_str_to_wordtab(file1d, "\n")) == NULL)
    return (NULL);
  free(file1d);
  return (file);
}

int	read_file(char	*file)
{
  t_cor	*corfile;
  int	fd;
  char	**tab;

  tab = convert_file_in_double_etoile_fdp_de_merde(file);
  if ((fd = open(file, O_RDONLY)) == -1)
    return (-1);
  corfile = xmalloc(sizeof(t_cor));
  corfile->name = getCorName(file);
  corfile->tab = tab;
  parse_instr(corfile);
  parse_header(corfile);
  write_cor(corfile);
  close(corfile->fd);
  return (0);
}

int	main(int ac, char **av)
{
  (void) ac;
  if (av[1])
    read_file(av[1]);

  return (0);
}
