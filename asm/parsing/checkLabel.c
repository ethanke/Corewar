/*
** checkLabel.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/asm/parsing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Mon Mar 14 06:18:17 2016 Ethan Kerdelhue
** Last update Mon Mar 14 07:04:34 2016 Ethan Kerdelhue
*/

#include "asm.h"

char	checkLabelchar(char c, char *label_char)
{
  int	i;

  i = 0;
  while (label_char[i] != '\0')
    {
      if (label_char[i] == c)
	return (1);
      i++;
    }
  return (0);
}

char	*checkLabel(char *name)
{
  int	i;

  i = 0;
  while (name[i] != '\0')
    {
      if (!(checkLabelchar(name[i], LABEL_CHARS) == 1))
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
