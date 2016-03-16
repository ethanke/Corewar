/*
** my_putchar_error.c for corewar in /Users/sousa_v/Shared/rendu/cpe/Corewar_temp/corewar/src/output/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Mon Mar  7 00:16:37 2016 Victor Sousa
** Last update Mon Mar  7 00:16:57 2016 Victor Sousa
*/

#include	"corewar.h"

void		my_putchar_error(char c)
{
  write(2, &c, 1);
}
