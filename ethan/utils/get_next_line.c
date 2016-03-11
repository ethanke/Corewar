/*
** get_next_line.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/ethan/utils/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Mon Mar  7 02:27:30 2016 Ethan Kerdelhue
** Last update Mon Mar  7 02:31:31 2016 Ethan Kerdelhue
*/

#include "get_next_line.h"

int	my_strlen_back(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str[i] != '\n')
    i++;
  return (i);
}

char	*withnt_back(char *stock)
{
  int	i;
  int	j;
  int	size;
  char	*new;

  size = 0;
  while (stock[size])
    size++;
  i = 0;
  while (stock[i] != '\0' && stock[i] != '\n')
    i++;
  i++;
  size = size - i;
  if (size == 0)
    return (NULL);
  if ((new = malloc(size + 1)) == NULL)
    return (NULL);
  j = 0;
  while (stock[i])
    new[j++] = stock[i++];
  new[j] = stock[i];
  return (new);
}

int	add_end(t_text *text, char *stock)
{
  int	i;
  int	j;
  int	size;
  char	*new;

  size = my_strlen_back(text->result) + my_strlen_back(stock);
  i = -1;
  j = 0;
  if (size == 0)
    new = text->result;
  else
    {
      if ((new = malloc(size + 1)) == NULL)
	return (-1);
      while (text->result[++i])
	new[i] = text->result[i];
      while (stock[j] != '\0' && stock[j] != '\n')
	new[i++] = stock[j++];
      new[i] = '\0';
      free(text->result);
    }
  text->i = stock[j] == '\n' ? 1 : 0;
  text->result = new;
  text->stock = withnt_back(stock);
  return (0);
}

char	*get_next_line(const int fd)
{
  char		iread[READ_SIZE + 1];
  static char	*stock = NULL;
  t_text	text;
  int		beread;

  text.i = 0;
  beread = 1;
  if ((text.result = malloc(sizeof(char))) == NULL)
    return (NULL);
  text.result[0] = '\0';
  if (stock != NULL)
    {
      add_end(&text, stock);
      stock = text.stock;
    }
  while (text.i == 0 && (beread = read(fd, iread, READ_SIZE)) != 0)
    {
      iread[beread] = '\0';
      add_end(&text, iread);
      stock = text.stock;
    }
  if (text.result[0] == '\0' && beread == 0)
    return (NULL);
  return (text.result);
}
