/*
** checkName.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/ethan/parsing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Fri Mar 11 18:36:36 2016 Ethan Kerdelhue
** Last update Sun Mar 13 17:07:19 2016 Ethan Kerdelhue
*/

 #include "asm.h"

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
    putError("[HEADER] Error line 1 : '34' not found, syntax error");
  else if (pos_2 == 0)
    putError("[HEADER] Error line 1 : missing '34' for .name, syntax error");
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
  new = malloc(PROG_NAME_LENGTH + 1);
  my_memset(new, PROG_NAME_LENGTH, 0);
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
  return (new);
}

char	*checkName(char *str)
{
  checkInstru(str);
  checkQuote(str);
  return (getName(str));
}
