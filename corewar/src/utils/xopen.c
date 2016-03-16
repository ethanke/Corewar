/*
** xopen.c for corewar in /Users/sousa_v/Shared/rendu/cpe/Coreware_temp/corewar/src/utils/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Tue Mar 15 18:07:59 2016 Victor Sousa
** Last update Tue Mar 15 18:09:39 2016 Victor Sousa
*/

#include		"corewar.h"

int			xopen(char *path)
{
  int			fd;

  if ((fd = open(path, O_RDONLY)) < 0)
    {
      my_printf("File %s not accessible\n", path);
      exit(1);
    }
  return (fd);
}
