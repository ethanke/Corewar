/*
** tab_instruction.c for  in /home/sagot/Downloads/corewar/asm/list_instruction/
**
** Made by Guillaume SAGOT
** Login   <sagot_g@epitech.eu>
**
** Started on  Tue Feb  2 11:26:01 2016 Guillaume SAGOT
** Last update Tue Feb  2 11:53:23 2016 Guillaume SAGOT
*/

#include "corewar.h"

void 		wich_tabulation(int tab_instruction(t_system*))
{
    void	*wich_tabulation[16] = {
      wich_tabulation[0] = &live_instruction;
      wich_tabulation[1] = &load_instruction;
      wich_tabulation[2] = &store_instruction;
      wich_tabulation[3] = &addition_instruction;
      wich_tabulation[4] = &substraction_instruction;
      wich_tabulation[5] = &and_instruction;
      wich_tabulation[6] = &or_instruction;
      wich_tabulation[7] = &xor_instruction;
      wich_tabulation[8] = &jump_if_zero_instruction;
      wich_tabulation[9] = &load_index_instruction;
      wich_tabulation[10] = &store_index_instruction;
      wich_tabulation[11] = &fork_instruction;
      wich_tabulation[12] = &long_load_instruction;
      wich_tabulation[13] = &long_load_index_instruction;
      wich_tabulation[14] = &long_fork_instruction;
      wich_tabulation[15] = &aff_instruction;
      wich_tabulation[16] = NULL;
    }
}

int		tab_parse(char *str)
{
  char		**tab;
  int		i;

  i = 0;
  tab = xmalloc(sizeof(t_system*));

  i = 0;
  while ()
}
