/*
** parseArguments.c for  in /home/sagot/rendu/Corewar/asm/parsing/
**
** Made by Guillaume SAGOT
** Login   <sagot_g@epitech.eu>
**
** Started on  Mon Mar 14 14:33:10 2016 Guillaume SAGOT
** Last update Mon Mar 14 16:14:48 2016 Guillaume SAGOT
*/

#include "assembly.h"

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

int		parseOptions(int ac, char *av[])
{
 while (ac > 1)
    {
      if ((my_strcmp(av[2], "-dump") != 1) || (my_strcmp(av[4], "-n") != 1)
	  || (my_strcmp(av[6], "-a") != 1))
	{
	  msgError("[USAGE]: [-dump nbr_cycle] [[-n prog_number]"
		   "[-a load_adress] prog_name\n");
	  exit(EXIT_FAILURE);
	}
    }
  return (0);
}
