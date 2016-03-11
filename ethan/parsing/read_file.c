/*
** read_file.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/asm/src/parsing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Mon Mar  7 01:56:39 2016 Ethan Kerdelhue
** Last update Fri Mar 11 18:52:01 2016 Ethan Kerdelhue
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

int	parse_header(char **tab)
{
  char	*header[2];

  header[0] = malloc(my_strlen(checkName(tab[0])));
  header[0] = checkName(tab[0]);
  header[1] = malloc(my_strlen(checkComment(tab[1])));
  header[1] = checkComment(tab[1]);
  puts(header[0]);
  puts(header[1]);
  return (0);
}

int	read_file(char	*file)
{
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
  parse_header(tab);
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
