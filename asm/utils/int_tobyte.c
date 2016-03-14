/*
** int_tobyte.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/asm/utils/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Mon Mar 14 05:17:25 2016 Ethan Kerdelhue
** Last update Mon Mar 14 05:18:04 2016 Ethan Kerdelhue
*/

#include "asm.h"

int	int_tobyte(int data)
{
  t_int4char 	nbr;

  nbr.nbr = data;
  data = nbr.str[0] << 24;
  data += nbr.str[1] << 16;
  data += nbr.str[2] << 8;
  data += nbr.str[3];
  return (data);
}
