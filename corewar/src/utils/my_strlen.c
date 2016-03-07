/*
** my_strlen.c for corewar in /Users/sousa_v/Shared/rendu/cpe/Coreware_temp/corewar/src/utils/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Mon Mar  7 01:24:38 2016 Victor Sousa
** Last update Mon Mar  7 01:25:55 2016 Victor Sousa
*/

#include	"corewar.h"

int		my_strlen(char *str)
{
  int		i;

  i = -1;
  while (str[++i]);
  return (i);
}
