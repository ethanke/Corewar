/*
** instructions_errors.c for  in /home/sagot/rendu/Corewar/asm/list_instruction/
**
** Made by Guillaume SAGOT
** Login   <sagot_g@epitech.eu>
**
** Started on  Sun Feb 28 03:03:27 2016 Guillaume SAGOT
** Last update Wed Mar 16 20:12:50 2016 Guillaume SAGOT
*/

#include "assembly.h"

void		live_checkError(t_corargs *value)
{
  if (valeu[1].type != 0)
    putError(value, "[ERROR] => \"LIVE\" instruction [BAD parameters)]\n");
  else if (value[1].type == T_REG)
    putError(value, "[ERROR] => \"LIVE\" instruction [INDEX] necessary\n");
}

void		load_checkError(t_corargs *value)
{
  if (value[1].type == 0 && value[2].type != 0)
    putError(value, "[ERROR] => \"LD\" instruction [ BAD parameters)]\n");
  else if (type[0] == T_REG)
     putError(value, "[ERROR] => \"LD\" instruction [REGISTER] necessary\n");
}

void		store_checkError(t_corargs *value)
{
  if ((value[1].type != T_REG && value[1].type != 3))
    putError(value, "[ERROR] => \"ST\" instruction,[ BAD parameters)]\n");
  else if (value[1].type == 0)
    putError(value, "[ERROR] => \"ST\" instruction [REGISTER] necessary\n");
}

void		addition_checkError(t_corargs *value)
{
  if (value[2].type == 0)
    putError(value, "[ERROR] => \"ADD\" instruction [ BAD parameters)]\n");
  else if (value[1].type != T_REG || value[2].type != T_REG || value[3].type != T_REG)
    putError(value, "[ERROR] => \"ADD\" instruction [REGISTER] necessary\n");
}

void		substraction_checkError(t_corargs *value)
{
  if (value[2].type == 0)
    putError(value, "[ERROR] => \"SUB\" instruction [ BAD parameters)]\n");
  else if (value[1].type != T_REG || value[2].type != T_REG || value[3].type != T_REG)
    putError(value, "[ERROR] => \"SUB\" instruction [REGISTER] necessary\n");
}

void		and_checkError(t_corargs *value)
{
  if (value[2].type != T_REG)
    putError(value, "[ERROR] => \"AND\" instruction -> DRAM necessary\n");
  else if (value[3].type == 0)
    putError(value, "[ERROR] => \"AND\" instruction [ BAD parameters)]\n");
}

void		or_checkError(t_corargs *value)
{
  if (value[3].type != T_REG)
    putError(value, "[ERROR] => \"OR\" instruction [ BAD parameters)]\n");
  else if ((value[1].type || value[2].type || value[3].type) == 0)
    putError(value, "[ERROR] => \"OR\" instruction [REGISTER] necessary\n");
}

void		xor_checkError(t_corargs *value)
{
  if (value[3].type != T_REG)
    putError(value, "[ERROR] => \"XOR\" instruction [ BAD parameters)]\n");
  else if ((value[1].type || value[2].type || value[3].type) == 0)
    putError(value, "[ERROR] => \"XOR\" instruction [REGISTER] necessary\n");
}

void		jump_if_zero_checkError(t_corargs *value)
{
  if (value[1].type < 1)
    putError(value, "[ERROR] => \"ZJMP\" instruction [ BAD parameters)]\n");
  else if (value[1].type != 0)
    putError(value, "[ERROR] => \"ZJMP\" instruction -> DRAM necessary\n");
}

void 		ldi_checkError(t_corargs *value)
{
  if (value[1].type !T_DIR && value[2].type != 3)
    putError(value, "[ERROR] => \"LDI\" instruction [REGISTER] necessary\n");
  else if (value[1].type !T_DIR && type[0] != 3)
    putError(value, "[ERROR] => \"LDI\" instruction [REGISTER] necessary\n");
}

void		sti_checkError(t_corargs *value)
{
  if (value[2].type == 0 && value[3].type == 0)
  putError(value, "[ERROR] => \"STI\" instruction [ BAD parameters)]\n");
}

void		fork_checkError(t_corargs *value)
{
  if (value[1].type == 0)
    putError(value, "[ERROR] => \"FORK\" instruction [: BAD parameters)]\n");
  else if  (type[0] == T_REG)
    putError(value, "[ERROR] => \"FORK\" instruction [: BAD parameters)]\n");

}

void		lld_checkError(t_corargs *value)
{
  if (value[1].type == 0 && value[2].type != 0)
    putError(value, "[ERROR] => \"LLD\" instruction [ BAD parameters)]\n");
  else if (type[0] == T_REG)
    putError(value, "[ERROR] => \"LLD\" instruction [REGISTER] necessary\n");
}

void		lldi_checkError(t_corargs *value)
{
  if (value[1].type == 0 && value[2].type != 0)
    putError(value, "[ERROR] => \"LLDI\" instruction [BAD parameters)]\n");
  else if (type[0] > T_REG)
    putError(value, "[ERROR] => \"LLDI\" instruction ->[REGISTER] necessary\n");
}

void		lfork_checkError(t_corargs *value)
{
  if (value[1].type == 0)
    putError(value, "[ERROR] => \"LFORK\" instruction [ BAD parameters)]\n");
  else if (type[0] == T_REG)
    putError(value, "[ERROR] => \"LFORK\" instruction [INDEX] parameters\n");
}

void		aff_checkError(t_corargs *value, int * type)
{
  if (value[1].type != 0)
    putError(value, "[ERROR] => \"AFF\" instruction [ BAD parameters)]\n");
  else if (type[0] != T_REG)
    putError(value, "[ERROR] => \"AFF\" instruction [REGISTER] necessary\n");
}
