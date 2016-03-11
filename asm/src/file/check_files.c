/*
** check_files.c for  in /home/sagot/rendu/Corewar/asm/src/file/
**
** Made by Guillaume SAGOT
** Login   <sagot_g@epitech.eu>
**
** Started on  Thu Mar 10 22:09:44 2016 Guillaume SAGOT
** Last update Thu Mar 10 22:10:07 2016 Guillaume SAGOT
*/

#include "assembly.h"

void            check_ext(int ac, char **argv)
{
  int           i;

  i = 1;
  while (i < ac)
    {
      if (my_strncmp(&argv[i][my_strlen(argv[i]) - 2], ".s", 2) != 0)
        my_putstr("Warning : It's preferable to give *.s\n");
      i++;
    }
}
