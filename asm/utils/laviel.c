
/*
** my_str_to_wordtab.c for  in /Users/ethankerdelhue/Documents/Shared/PSU_2015_tetris/utils/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Tue Mar  8 12:44:52 2016 Ethan Kerdelhue
** Last update Wed Mar 16 16:22:43 2016 Ethan Kerdelhue
*/

#include "asm.h"

char* 	my_strdup(char* str)
{
  int 	len;
  char* dup;

  len = my_strlen(str) + 1;
  dup = malloc(len);
  if(dup == NULL)
    return (NULL);
  dup = my_strcpy(dup, str);
  dup[len - 1] = '\0';
  return (dup);
}

int	my_count_word(char *s)
{
  int	i;
  int	cpt;

  i = 0;
  cpt = 0;
  while (s[i] != '\0')
    {
      if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')
	  || (s[i] >= '0' && s[i] <= '9') ||
	  (s[i] == (LABEL_CHAR) || (s[i] == DIRECT_CHAR)))
	{
	  cpt = cpt + 1;
	  while (s[i] && ((s[i] >= 'a' && s[i] <= 'z')
			  || (s[i] >= 'A' && s[i] <= 'Z')
			  || (s[i] >= '0' && s[i] <= '9')
			  || (s[i] == (LABEL_CHAR) || (s[i] == DIRECT_CHAR)
			      || (s[i] == '-'))))
	    i = i + 1;
	}
      i = i + 1;
    }
  return (cpt);
}

int	my_count_char(char *s, int *i)
{
  int	cpt;

  cpt = 0;
  while (s[*i] && ((s[*i] >= 'a' && s[*i] <= 'z')
		  || (s[*i] >= 'A' && s[*i] <= 'Z')
		  || (s[*i] >= '0' && s[*i] <= '9')
		  || (s[*i] == (LABEL_CHAR)) || (s[*i] == DIRECT_CHAR) ||
		   (s[*i] == '-')))
    {
      cpt = cpt + 1;
      *i = *i + 1;
    }
  return (cpt);
}

char	**my_str_to_wordtab(char *str)
{
  int	i;
  int	n;
  int	word;
  char	**tab;

  i = 0;
  n = 0;
  word = my_count_word(my_strdup(str));
  tab = (char **)malloc(sizeof(char *) * word);
  while (str[i] && word > 0)
    {
      if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')
	  || (str[i] >= '0' && str[i] <= '9') ||
	  (str[i] == LABEL_CHAR) || (str[i] == DIRECT_CHAR) || (str[i] == '-'))
	{
	  tab[n] = my_strdup(str + i);
	  tab[n][my_count_char(str, &i)] = '\0';
	  n = n + 1;
	  word = word - 1;
	}
      i = i + 1;
    }
  tab[my_count_word(my_strdup(str))] = NULL;
  return (tab);
}
