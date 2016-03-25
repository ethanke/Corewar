/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/sousa_v/Rendu/Piscine_C/Piscine_C_J08/ex_04
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Wed Oct  7 18:11:14 2015 victor sousa
** Last update Fri Mar 25 10:40:41 2016 Victor Sousa
*/

#include "corewar.h"

int	is_validchar(char c)
{
  if (c != ' ')
    return (1);
  else
    return (0);
}

int	wordcounter(char *str)
{
  int	i;
  int	counter;

  i = 0;
  counter = 0;
  while (str[i])
    {
      if (is_validchar(str[i]))
	{
	  counter++;
	  while (str[i] && is_validchar(str[i]))
	    i++;
	}
      else
	i++;
    }
  return (counter);
}

int	charcounter(char *str, int depart)
{
  int	counter;

  counter = 0;
  while (is_validchar(str[depart + counter]))
    counter++;
  return (counter);
}

char	**my_str_to_wordtab(char *str)
{
  char	**output_tab;
  int	wordcount;
  int	charcount;
  int	runningvar;
  int	i;

  output_tab = xmalloc(sizeof(char *) * (wordcounter(str) + 1));
  wordcount = 0;
  runningvar = 0;
  while (wordcount < wordcounter(str))
    {
      while (!is_validchar(str[runningvar]))
	runningvar++;
      charcount = charcounter(str, runningvar);
      output_tab[wordcount] = xmalloc(sizeof(char)
				     * (charcount + 1));
      i = 0;
      while (i < charcount)
	output_tab[wordcount][i++] = str[runningvar++];
      output_tab[wordcount++][i] = '\0';
    }
  output_tab[wordcount] = '\0';
  return (output_tab);
}
