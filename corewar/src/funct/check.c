/*
** check.c for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/corewar/src/funct/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Fri Mar 11 00:11:32 2016 Gaëtan Léandre
** Last update Wed Mar 16 21:48:02 2016 Gaëtan Léandre
*/

#include	"corewar.h"

int		check_arg(int funct, int pos, char arg)
{
  char		def;

  def = op_tab[funct].type[pos];
  if (T_LAB == arg && def / T_LAB == 1)
    return (1);
  def %= T_LAB;
  if (T_IND - 1 == arg && def / (T_IND) == 1)
    return (1);
  def %= T_IND;
  if (T_DIR == arg && def / T_DIR == 1)
    return (1);
  def %= T_DIR;
  if (T_REG == arg && def / T_REG == 1)
    return (1);
  return (-1);
}

int		test_oct(unsigned char param, int funct, int size)
{
  unsigned char	cur;
  int		pos;
  int		result;

  cur = 0;
  pos = 7;
  while (cur < size)
    {
      result = 2 * ((param >> pos) & 1);
      pos--;
      result = result + ((param >> pos) & 1);
      if (check_arg(funct, cur, result) == -1)
	return (-1);
      cur++;
      pos--;
    }
  return (1);
}

int		check_reg(int reg)
{
  if (reg < 1 || reg > REG_NUMBER)
    return (-1);
  return (reg);
}

int		check_mult_args(unsigned char *arena, int fun, int pos, int siz)
{
  char		arg;
  char		tmp;
  int		turn;

  arg = arena[pos];
  if (test_oct(arg, fun, siz) == -1)
    return (-1);
  turn = 1;
  pos = circle(pos, 1);
  while (turn <= siz)
    {
      tmp = who_are_u(arg, turn);
      if (tmp == T_REG)
	{
	  if (check_reg(arena[pos]) == -1)
	    return (-1);
	}
      pos = circle(pos, octet_to_r(tmp));
      turn++;
    }
  return (0);
}
