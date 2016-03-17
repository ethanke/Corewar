/*
** int_tobyte.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/asm/utils/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Mon Mar 14 05:17:25 2016 Ethan Kerdelhue
** Last update Thu Mar 17 00:14:09 2016 Ethan Kerdelhue
*/

#include "asm.h"

int	int_to4byte(int data)
{
  t_int4char 	nbr;

  nbr.nbr = data;
  data = nbr.str[0] << 24;
  data += nbr.str[1] << 16;
  data += nbr.str[2] << 8;
  data += nbr.str[3];
  return (data);
}

int	int_to2byte(int data)
{
  t_int4char 	nbr;

  nbr.nbr = data;
  data = nbr.str[0] << 8;
  data += nbr.str[1];
  return (data);
}

int	int_to1byte(int data)
{
  t_int4char 	nbr;

  nbr.nbr = data;
  data = nbr.str[0];
  return (data);
}
