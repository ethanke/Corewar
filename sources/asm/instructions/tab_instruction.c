/*
** tab_instruction.c for  in /home/sagot/Downloads/assembly/asm/list_instruction/
**
** Made by Guillaume SAGOT
** Login   <sagot_g@epitech.eu>
**
** Started on  Tue Feb  2 11:26:01 2016 Guillaume SAGOT
** Last update Mon Feb 29 16:27:00 2016 Guillaume SAGOT
*/

#include "assembly.h"

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
