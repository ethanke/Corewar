/*
** my_putchar.c for corewar in /Users/sousa_v/Shared/rendu/cpe/Corewar_temp/corewar/src/output/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Mon Mar  7 00:10:05 2016 Victor Sousa
** Last update Mon Mar  7 00:10:35 2016 Victor Sousa
*/

#include	"corewar.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}
