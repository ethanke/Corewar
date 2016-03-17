/*
** color.c for corewar in /Users/sousa_v/Shared/rendu/cpe/Coreware_temp/bonus/src/utils/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Thu Mar 17 02:33:27 2016 Victor Sousa
** Last update Thu Mar 17 02:33:45 2016 Victor Sousa
*/

#include	"corewar.h"

unsigned int		pick_color(int id)
{
  if (id == 0)
    return (0xFFFF0000);
  if (id == 1)
    return (0xFF0FF000);
  if (id == 2)
    return (0xFF0000FF);
  if (id == 3)
    return (0xFFFF00FF);
  return (0xFF000000);
}
