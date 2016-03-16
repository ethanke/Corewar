/*
** checkLabel.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/asm/parsing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Mon Mar 14 06:18:17 2016 Ethan Kerdelhue
** Last update Wed Mar 16 00:12:03 2016 Ethan Kerdelhue
*/

#include "asm.h"

char	checkLabelchar(char c, char *label_char)
{
  int	i;

  i = 0;
  while (label_char[i] != LABEL_CHAR)
    {
      if (label_char[i] != c)
	return (1);
      i++;
    }
  return (1);
}

char	*checkLabel(char *name)
{
  int	i;

  i = 0;
  while (name[i] != '\0')
    {
      if (checkLabelchar(name[i], LABEL_CHARS) != 1)
	{
	  my_putstr("[FILE] Error : Label ");
	  my_putstr(name);
	  my_putstr(" is not valid\n");
	  my_putstr("Valid char for label : ");
	  putError(LABEL_CHARS);
	}
      i++;
    }
  return (name);
}

char	*line_is_label(char *args)
{
  char	flag;

  flag = 0;
  if (args[my_strlen(args) - 1] == LABEL_CHAR)
    flag = 1;
  else
    return (NULL);
  if (flag == 1)
    {
      return (checkLabel(args));
    }
  return (NULL);
}
