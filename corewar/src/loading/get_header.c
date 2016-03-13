/*
** get_header.c for corewar in /Users/sousa_v/Shared/rendu/cpe/Coreware_temp/corewar/src/loading/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sun Mar 13 12:23:25 2016 Victor Sousa
** Last update Sun Mar 13 13:09:20 2016 Victor Sousa
*/

#include		"corewar.h"

header_t		get_header(int fd)
{
  header_t		header;

  if (read(fd, &header, sizeof(header_t)) < 0)
    my_putstr_error("couldn't read one of the requested champion\n", 1);
  return (header);
}
