/*
** get_instruct.c for corewar in /Users/sousa_v/Shared/rendu/cpe/Coreware_temp/corewar/src/loading/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sun Mar 13 13:03:48 2016 Victor Sousa
** Last update Sun Mar 13 13:43:52 2016 Victor Sousa
*/

#include		"corewar.h"

char			*get_instruct(int fd, int size)
{
  char			*instruction;

  my_printf("%d\n", size);
  instruction = xmalloc(size);
  if ((read(fd, instruction, size)) < 0)
    my_putstr_error("couldn't read one of the requested champion\n", 1);
  return (instruction);
}
