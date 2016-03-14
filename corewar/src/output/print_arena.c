/*
** print_arena.c for corewar in /Users/sousa_v/Shared/rendu/cpe/Coreware_temp/corewar/src/output/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Mon Mar 14 17:06:23 2016 Victor Sousa
** Last update Mon Mar 14 18:12:34 2016 Victor Sousa
*/

#include		"corewar.h"

void			print_start()
{
  int			i;

  i = -1;
  my_printf("|");
  while (++i < 128)
    my_printf("-");
  my_printf("|\n|");
}

void			print_end()
{
  int			i;

  i = -1;
  while (++i < 128)
    my_printf("-");
  my_printf("|\n");
}

void			print_arena_proprio(t_arena *arena)
{
  int			i;
  int			j;

  j = 1;
  i = 0;
  print_start();
  while (++i <= MEM_SIZE)
    {
      if (arena->proprio[i - 1] == -1)
	my_printf(" ");
      else if (arena->proprio[i - 1] == 0)
	my_printf("#1%d", arena->proprio[i - 1]);
      else if (arena->proprio[i - 1] == 1)
	my_printf("#2%d", arena->proprio[i - 1]);
      else if (arena->proprio[i - 1] == 2)
	my_printf("#3%d", arena->proprio[i - 1]);
      else if (arena->proprio[i - 1] == 3)
	my_printf("#4%d", arena->proprio[i - 1]);
      if (i % (128 * j) == 0)
	{
	  j++;
	  my_printf("|\n|");
	}
    }
  print_end();
}
