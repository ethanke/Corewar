/*
** instructions_errors.c for  in /home/sagot/rendu/Corewar/asm/list_instruction/
**
** Made by Guillaume SAGOT
** Login   <sagot_g@epitech.eu>
**
** Started on  Sun Feb 28 03:03:27 2016 Guillaume SAGOT
** Last update Mon Feb 29 23:52:02 2016 Guillaume SAGOT
*/

#include "assembly.h"

void		live_checkError(t_system *sys, int *values)
{
  if (values[1] != 0 || values[0] == 0)
    printError(sys, "[ERROR] => \"LIVE\" instruction -> [:(BAD parameters)]\n");
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

void		addition_checkError(t_system *sys, int *values)
{
  if (values[2] == 0)
    printError(sys, "[ERROR] => \"ADD\" instruction -> [:( BAD parameters)]\n");
  else if (values[1] != 1 || values[2] != 1 || values[3] != 1)
    printError(sys, "[ERROR] => \"ADD\" instruction -> [REGISTER] necessary\n");
}

void		substraction_checkError(t_system *sys, int *values)
{
  if (values[2] == 0)
    printError(sys, "[ERROR] => \"SUB\" instruction -> [:( BAD parameters)]\n");
  else if (values[1] != 1 || values[2] != 1 || values[3] != 1)
    printError(sys, "[ERROR] => \"SUB\" instruction -> [REGISTER] necessary\n");
}

void		and_checkError(t_system *sys, int *values)
{
  if (values[2] != 1)
    printError(sys, "[ERROR] => \"AND\" instruction -> DRAM necessary\n");
  else if (values[3] == 0)
    printError(sys, "[ERROR] => \"SUB\" instruction -> [:( BAD parameters)]\n");
}

void		or_checkError(t_system *sys, int *values)
{
  if (values[3] != 1)
    printError(sys, "[ERROR] => \"OR\" instruction -> [:( BAD parameters)]\n");
  else if ((values[1] || values[2] || values[3]) == 0)
    printError(sys, "[ERROR] => \"XOR\" instruction -> [REGISTER] necessary\n");
}

void		xor_checkError(t_system *sys, int *values)
{
  if (values[3] != 1)
    printError(sys, "[ERROR] => \"XOR\" instruction -> [:( BAD parameters)]\n");
  else if ((values[1] || values[2] || values[3]) == 0)
    printError(sys, "[ERROR] => \"XOR\" instruction -> [REGISTER] necessary\n");
}

void		jump_if_zero_checkError(t_system *sys, int *values)
{
  if (values[0] == 1)
    aff_error(sys, "[ERROR] => \"ZJMP\" instruction -> [:( BAD parameters)]\n");
  else if (values[1] != 0)
    aff_error"[ERROR] => \"ZJMP\" instruction -> DRAM necessary\n");
}

void 		ldi_checkError(t_system *sys, int *values)
{
  if (values[0] != 2 && values[0] != 3)
    printError(sys, "[ERROR] => \"LDI\" instruction -> [REGISTER] necessary\n");
  else if (values[1] != 2 && values[0] != 3)
    printError(sys, "[ERROR] => \"LDI\" instruction -> [REGISTER] necessary\n");
}

void		 sti_checkError(t_system *sys, int *values)
{
  if (values[2] == 0 && values[3] == 0)
  printError(sys, "[ERROR] => \"STI\" instruction -> [:( BAD parameters)]\n");
}

void		fork_checkError(t_system *sys, int *values)
{
  if (values[1] == 0)
    printError(sys, "[ERROR] => \"FORK\" instruction -> [: BAD parameters)]\n");
  else if  (values[0] == 1)
}

void		lld_checkError(t_system *sys, int *values)
{
  if (values[0] == 0 && values[1] == 0 && values[2] != 0)
    printError(sys, "[ERROR] => \"LLD\" instruction -> [:( BAD parameters)]\n");
  else if (values[0] > 1)
    printError(sys, "[ERROR] => \"LLD\" instruction -> [REGISTER] necessary\n")
}

void		lldi_checkError(t_system *sys, int *values)
{
  if (values[0] == 0 && values[1] == 0 && values[2] != 0)
    printError(sys, "[ERROR] => \"LLDI\" instruction -> [:(BAD parameters)]\n");
  else if (values[0] > 1)
    printError(sys, "[ERROR] => \"LLDI\" instruction ->[REGISTER] necessary\n");
}

void		lfork_checkError(t_system *sys, int *values)
{
  if (values[1] == 0)
    printError(sys, "[ERROR] => \"LFORK\" instruction -> [ BAD parameters)]\n");
  else if (values[0] == 1)
    printError(sys, "[ERROR] => \"LFORK\" instruction -> [INDEX] parameters\n");
}

void		aff_checkError(t_system *sys, int * values)
{
  if (values[1] != 0)
    printError(sys, "[ERROR] => \"AFF\" instruction -> [:( BAD parameters)]\n");
  else if (values[0] != 1)
    printError(sys, "[ERROR] => \"AFF\" instruction -> [REGISTER] necessary\n");
}
