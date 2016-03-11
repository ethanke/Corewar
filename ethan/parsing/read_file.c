/*
** read_file.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/asm/src/parsing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Mon Mar  7 01:56:39 2016 Ethan Kerdelhue
** Last update Fri Mar 11 18:30:06 2016 Ethan Kerdelhue
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

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
      i++;
  return (i);
}

void	putError(char *str)
{
  write(1, str, my_strlen(str));
  exit(-1);
}

/*
char	*checkName(char	*str, char flag_n, char flag_g)
{
  int	i;
  int	g_1;
  int	g_2;

  i = -1;
  g_2 = 0;
   while (str[++i] != '\0')
     {
      if (str[i] == '.' && str[i + 1] == 'n' && str[i + 2] == 'a' && str[i + 3]
	  == 'm' && str[i + 4] == 'e')
	flag_n = 1;
      if (str[i] == 34)
	{
	  g_1 = i;
	  while (str[++i] != '\0')
	    (g_2) = (str[i] == 34) ? (i) : (g_2);
	  (flag_g) = ((g_2 != 0) ? (1) : (flag_g));
	}
    }
  return (((flag_n == 1) && (flag_g == 1)) ? (getName(str, g_1, g_2)) : (NULL));
}
*/

/*
Quote :
S'il n'y a pas de .name Code error : -1
S'il ny a pas 2 * " Code error : 1
S'il n'y a du texte après ou avant les " autre que .name Code error : 2
*/

char	checkInstru(char *str)
{
  int	i;

  i = 0;

  while (str[i] != '\0')
    {
      if (str[i] == '.' && str[i + 1] == 'n' && str[i + 2] == 'a' && str[i + 3]
	== 'm' && str[i + 4] == 'e')
	return (0);
      i++;
    }
  putError("[HEADER] Error line 1 : .name don't found or wrong");
  return (0);
}

void	checkAdv(int pos_1, int pos_2, char *str)
{
  int	i;

  i = pos_2 + 1;
  (void) pos_1;
  while (str[i] != '\0')
    {
      if (str[i] != ' ')
	{
	  my_putstr("[HEADER] Error line 1 : Unknown characters ");
	  my_putstr("--> ");
	  my_putchar(str[i]);
	  putError(", Compile failed\0");
	}
      i++;
    }
}

void	checkQuote(char *str)
{
  int	i;
  int	pos_1;
  int	pos_2;


  i = -1;
  pos_1 = 0;
  pos_2 = 0;
  while (str[++i] != '\0')
    {
      if (str[i] == 34)
	{
	  if (pos_1 == 0)
	    pos_1 = i;
	  else if (pos_2 == 0)
	    pos_2 = i;
	}
    }
  if (pos_1 == 0)
    putError("[HEADER] Error line 1 : '32' not found, syntax error");
  else if (pos_2 == 0)
    putError("[HEADER] Error line 1 : missing '32' for .name, syntax error");
  else
    checkAdv(pos_1, pos_2, str);
}

char	*getName(char *str)
{
  char	*new;
  int	i;
  int	j;
  char	store;

  i = 0;
  j = 0;
  store = 2;
  new = malloc(my_strlen(str));
  while (str[i] != '\0')
    {
      if (store == 1 && str[i] != 34)
	{
	  new[j] = str[i];
	  j++;
	}
      if (str[i] == 34)
	store -= 1;
      i++;
    }
  new[j] = '\0';
  return (new);
}

char	*checkName(char *str)
{
  checkInstru(str);
  checkQuote(str);
  return (getName(str));
}

int	parse_header(char **tab)
{
  char	*header[2];

  header[0] = malloc(my_strlen(checkName(tab[0])));
  header[0] = checkName(tab[0]);
  puts(header[0]);
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
