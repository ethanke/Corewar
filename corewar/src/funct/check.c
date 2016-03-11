/*
** check.c for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/corewar/src/funct/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Fri Mar 11 00:11:32 2016 Gaëtan Léandre
** Last update Fri Mar 11 02:30:25 2016 Gaëtan Léandre
*/

#include	"corewar.h"

int		check_arg(int funct, int pos, char arg)
{
  char		def;

  def = op_tab[funct].type[pos];
  if (T_LAB == arg && def / T_LAB == 1)
    return (1);
  else if (T_IND == arg && def / T_IND == 1)
    return (1);
  else if (T_DIR == arg && def / T_DIR == 1)
    return (1);
  else if (T_REG == arg && def / T_REG == 1)
    return (1);
  return (-1);
}

int		octet_to_read(char arg)
{
  if (arg == T_REG || arg == T_DIR)
    return (4);
  else if (arg == T_IND)
    return (2);
}

int		check_reg(int reg)
{
  if (reg < 1 || reg > REG_NUMBER)
    return (-1).
  return (reg);
}
