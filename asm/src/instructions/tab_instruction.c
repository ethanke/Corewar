/*
** tab_instruction.c for  in /home/sagot/Downloads/assembly/asm/list_instruction/
**
** Made by Guillaume SAGOT
** Login   <sagot_g@epitech.eu>
**
** Started on  Tue Feb  2 11:26:01 2016 Guillaume SAGOT
** Last update Tue Mar  8 19:15:58 2016 Guillaume SAGOT
*/

#include "assembly.h"

void			initError(void*(checkError[16]))
{
  checkError[0] = &live_checkError;
  checkError[1] = &load_checkError;
  checkError[2] = &store_checkError;
  checkError[3] = &addition_checkError;
  checkError[4] = &substraction_checkError;
  checkError[5] = &and_checkError;
  checkError[6] = &or_checkError;
  checkError[7] = &xor_checkError;
  checkError[8] = &jump_if_zero_checkError;
  checkError[9] = &ldi_checkError;
  checkError[10] = &sti_checkError;
  checkError[11] = &fork_checkError;
  checkError[12] = &lld_checkError;
  checkError[13] = &lldi_checkError;
  checkError[14] = &lfork_checkError;
  checkError[15] = &aff_checkError;
}

t_system		*initInstructions()
{
  char			**tab;

  tab = xmalloc(17 * sizeof(char*));
  tab[0] = "live";
  tab[1] = "ld";
  tab[2] = "st";
  tab[3] = "add";
  tab[4] = "sub";
  tab[5] = "and";
  tab[6] = "or";
  tab[7] = "xor";
  tab[8] = "zmp";
  tab[9] = "ldi";
  tab[10] = "sti";
  tab[11] = "fork";
  tab[12] = "lldi";
  tab[13] = "lldi";
  tab[14] = "lfork";
  tab[15] = "aff";
  tab[16] = NULL;
}
