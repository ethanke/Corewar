/*
** instructions_errors.c for  in /home/sagot/rendu/Corewar/asm/list_instruction/
**
** Made by Guillaume SAGOT
** Login   <sagot_g@epitech.eu>
**
** Started on  Sun Feb 28 03:03:27 2016 Guillaume SAGOT
** Last update Sun Feb 28 03:46:34 2016 Guillaume SAGOT
*/

#include "corewar.h"

void		live_checkError(t_system *sys, int *values)
{
  if (values[1] != 0 || values[0] == 0)
    printError(sys, "[ERROR] => \"LIVE\" instruction -> [:( BAD parameters)]\n");
  else if (values[1] > 1)
    printError(sys, "[ERROR] => \"LIVE\" instruction -> [INDEX] necessary\n")
}

void		load_checkError(t_system *sys, int values)
{
  if (values[0] == 0 && values[1] == 0 && values[2] != 0)
    printError(sys, "[ERROR] => \"LD\" instruction -> [:( BAD parameters)]\n");
  else if (values[0] > 1)
     printError(sys, "[ERROR] => \"LD\" instruction -> [REGISTER] necessary\n")
}

void		store_checkError(t_system *sys, int *values)
{
  if (values[0] != 1 || (values[1] != 1 && values[1] != 3))
    printError(sys, "[ERROR] => \"ST\" instruction,-> [:( BAD parameters)]\n");
  else if (values[0] == 0 && values[1] == 0)
    printError(sys, "[ERROR] => \"ST\" instruction -> [REGISTER] necessary\n")
}

void		sti_checkError(t_system *sys, int *values)
{
  if (values[2] == 0)
    printError(sys, "[ERROR] => \"STI\" instruction -> [:( BAD parameters)]\n");
}
