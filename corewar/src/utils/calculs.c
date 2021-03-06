/*
** calculs.c for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/corewar/src/utils/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Mon Mar  7 03:31:21 2016 Gaëtan Léandre
** Last update Tue Mar 15 17:53:49 2016 Gaëtan Léandre
*/

#include "corewar.h"

int		mod(int nbr, int modulo)
{
  nbr = nbr % modulo;
  if (nbr < 0)
    nbr = modulo + nbr;
  return (nbr);
}

int		circle(int pos, int incr)
{
  pos = pos + incr;
  pos = mod(pos, MEM_SIZE);
  return (pos);
}

t_choix		make_choix(int pc, char modu, char place)
{
  t_choix	result;

  result.pc = pc;
  result.modu = modu;
  result.place = place;
  return (result);
}
