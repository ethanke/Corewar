/*
** parseArguments.c for  in /home/sagot/rendu/Corewar/asm/parsing/
**
** Made by Guillaume SAGOT
** Login   <sagot_g@epitech.eu>
**
** Started on  Mon Mar 14 14:33:10 2016 Guillaume SAGOT
** Last update Tue Mar 22 22:47:50 2016 Ethan Kerdelhue
*/

#include "asm.h"

void		checkExtension(char **str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (my_strncmp(&str[i][my_strlen(str[i] - 2)], ".s", 2) != 0)
	msgError("[BAD ARGUMENT]: need file '.s'\n");
      i++;
    }
}
