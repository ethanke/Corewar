/*
** check.c for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/corewar/src/funct/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Fri Mar 11 00:11:32 2016 Gaëtan Léandre
** Last update Sun Mar 13 11:55:33 2016 Gaëtan Léandre
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
  return (-1);
}

int		check_reg(int reg)
{
  if (reg < 1 || reg > REG_NUMBER)
    return (-1);
  return (reg);
}

int		check_mult_args(unsigned char *arena, int fun, int pos, int siz)
{
  if (siz > 0 && (check_arg(fun, 0, arena[pos]) == -1
		  || (arena[pos] == T_REG &&
		      check_reg(take_param(arena, pos + 1, REG_SIZE)) == -1)))
    return (-1);
  pos = circle(pos, octet_to_read(arena[pos]) + 1);
  if (siz > 1 && (check_arg(fun, 1, arena[pos]) == -1
		  || (arena[pos] == T_REG &&
		      check_reg(take_param(arena, pos + 1, REG_SIZE)) == -1)))
    return (-1);
  pos = circle(pos, octet_to_read(arena[pos]) + 1);
  if (siz > 2 && (check_arg(fun, 2, arena[pos]) == -1
		  || (arena[pos] == T_REG &&
		      check_reg(take_param(arena, pos + 1, REG_SIZE)) == -1)))
    return (-1);
  return (0);
}
