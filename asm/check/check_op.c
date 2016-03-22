/*
** checkOp.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/asm/parsing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Mon Mar 14 16:47:16 2016 Ethan Kerdelhue
** Last update Wed Mar 16 00:29:22 2016 Ethan Kerdelhue
*/

#include "asm.h"

op_t	checkOp(char *mnemonic)
{
  int	i;

  i = 0;
  while (op_tab[i].mnemonique != 0)
    {
      if (my_strcmp(op_tab[i].mnemonique, mnemonic) == 0)
	return (op_tab[i]);
      i++;
    }
  my_putstr("[FILE] Error : ");
  my_putstr(mnemonic);
  putError(" no match in op.c\0");
  return (op_tab[i]);
}
