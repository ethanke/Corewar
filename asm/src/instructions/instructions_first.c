/*
** list_instruction_first.c for  in /home/sagot/Downloads/corewar/asm/list_instruction/
**
** Made by Guillaume SAGOT
** Login   <sagot_g@epitech.eu>
**
** Started on  Thu Jan 28 14:24:21 2016 Guillaume SAGOT
** Last update Thu Mar 10 18:02:44 2016 Guillaume SAGOT
*/

#include "assembly.h"

void		live_instruction(t_system *sys)
{
  sys->instruction.control = 0x01;
  sys->instruction.i += 4;
  sys->instruction.instruction_check += -1;
  xwrite(sys->instruction.fd, &sys->instruction.c, 1);
  my_printf("instruction set -> LIVE\n");
  if (sys->instruction.str[sys->instruction.i] == ':')
    {
      sys->instruction.instruction_check = "1";
      my_printf("label: %s\n", sys->instruction.str[sys->instruction.i - 4]);
      while (sys->instruction.str[sys->instruction.i] != '%')
	(sys->instruction.i)++;
    }
  sys->instruction.base = sys->instruction.i;
}

void		load_instruction(t_system *sys)
{
  sys->instruction.control = 0x02;
  sys->instruction.i += 2;
  sys->instruction.instruction_check += 1;
  xwrite(sys->instruction.fd, &sys->instruction.c, 1);
  my_printf("instruction set -> LOAD\n");
  if (sys->instruction.str[sys->instruction.i] == ':')
    {
      sys->instruction.instruction_check = "1";
      my_printf("label: %s\n", sys->instruction.str[sys->instruction.i - 4]);
      while (sys->instruction.str[sys->instruction.i] != '%')
	(sys->instruction.ins)++;
    }
  sys->instruction.base = sys->instruction.i;
}

void		store_instruction(t_system *sys)
{
  sys->instruction.control = 0x03;
  sys->instruction.i += 2;
  sys->instruction.instruction_check += 1;
  xwrite(sys->instruction.fd, &sys->instruction.c, 1);
  my_printf("instruction set -> STORE\n");
  if (sys->instruction.str[sys->instruction.i] == ':')
    {
      sys->instruction.instruction_check = "1";
      my_printf("label: %s\n", sys->instruction.str[sys->instruction.i - 4]);
      while (sys->instruction.str[sys->instruction.i] != '%')
	(sys->instruction.i)++;
    }
  sys->instruction.base = sys->instruction.i;
}

void		addition_instruction(t_system *sys)
{
  sys->instruction.control = 0x04;
  sys->instruction.i += 3;
  sys->instruction.instruction_check += 2;
  xwrite(sys->instruction.fd, &sys->instruction.c, 1);
  my_printf("instruction set -> STORE\n");
  if (sys->instruction.str[sys->instruction.i] == ':')
    {
      sys->instruction.instruction_check = "2";
      my_printf("label: %s\n", sys->instruction.str[sys->instruction.i - 2]);
      while (sys->instruction.str[sys->instruction.i] != '%')
	(sys->instruction.i)++;
    }
  sys->instruction.base = sys->instruction.i;
}

void		substraction_instruction(t_system *sys)
{
  sys->instruction.control = 0x05;
  sys->instruction.i += 3;
  sys->instruction.instruction_check += 1;
  xwrite(sys->instruction.fd, &sys->instruction.c, 2);
  my_printf("instruction set -> STORE\n");
  if (sys->instruction.str[sys->instruction.i] == ':')
    {
      sys->instruction.instruction_check = "1";
      my_printf("label: %s\n", sys->instruction.str[sys->instruction.i - 4]);
      while (sys->instruction.str[sys->instruction.i] != '%')
	(sys->instruction.i)++;
    }
  sys->instruction.base = sys->instruction.i;
}

void		and_instruction(t_system *sys)
{
  sys->instruction.control = 0x06;
  sys->instruction.i += 3;
  sys->instruction.instruction_check += 1;
  xwrite(sys->instruction.fd, &sys->instruction.i, 1);
  my_printf("instruction set -> STORE\n");
  if (sys->instruction.str[sys->instruction.i] == ':')
    {
      sys->instruction.instruction_check = "1";
      my_printf("label: %s\n", sys->instruction.str[sys->instruction.i - 4]);
      while (sys->instruction.str[sys->instruction.i] != '%')
	(sys->instruction.i)++;
    }
  sys->instruction.base = sys->instruction.i;
}

void		or_instruction(t_system *sys)
{
  sys->instruction.control = 0x07;
  sys->instruction.i += 3;
  sys->instruction.instruction_check += 1;
  xwrite(sys->instruction.fd, &sys->instruction.c, 1);
  my_printf("instruction set -> OR\n");
  if (sys->instruction.str[sys->instruction.i] == ':')
    {
      sys->instruction.instruction_check = "1";
      my_printf("label: %s\n", sys->instruction.str[sys->instruction.i - 4]);
      while (sys->instruction.str[sys->instruction.i] != '%')
	(sys->instruction.i)++;
    }
  sys->instruction.base = sys->instruction.i;
}

void		xor_instruction(t_system *sys)
{
  sys->instruction.control = 0x08;
  sys->instruction.i += 3;
  sys->instruction.instruction_check += 1;
  xwrite(sys->instruction.fd, &sys->instruction.c, 1);
  my_printf("instruction set -> XOR\n");
  if (sys->instruction.str[sys->instruction.i] == ':')
    {
      sys->instruction.instruction_check = "1";
      my_printf("label: %s\n", sys->instruction.str[sys->instruction.i - 4]);
      while (sys->instruction.str[sys->instruction.i] != '%')
	(sys->instruction.i)++;
    }
  (sys->instruction.base = sys->instruction.i);
}

void		jump_if_zero_instruction(t_system *sys)
{
  sys->instruction.control = 0x09;
  sys->instruction.i += 1;
  sys->instruction.instruction_check += 1;
  xwrite(sys->instruction.fd, &sys->instruction.c, 1);
  my_printf("instruction set -> ZJMP\n");
  if (sys->instruction.str[sys->instruction.i] == ':')
    {
      sys->instruction.instruction_check = "0";
      my_printf("label: %s\n", sys->instruction.str[sys->instruction.i - 4]);
      while (sys->instruction.str[sys->instruction.i] != '%')
	(sys->instruction.i)++;
    }
  sys->instruction.base = sys->instruction.i;
}

void		load_index_instruction(t_system *sys)
{
  sys->instruction.control = 0x0a;
  sys->instruction.i += 3;
  sys->instruction.instruction_check += 1;
  xwrite(sys->instruction.fd, &sys->instruction.c, 1);
  my_printf("instruction set -> LDI\n");
  if (sys->instruction.str[sys->instruction.i] == ':')
    {
      sys->instruction.instruction_check = "1";
      my_printf("label: %s\n", sys->instruction.str[sys->instruction.i - 4]);
      while (sys->instruction.str[sys->instruction.i] != '%')
	(sys->instruction.i)++;
    }
  sys->instruction.base = sys->instruction.i;
}

void		store_index_instruction(t_system *sys)
{
  sys->instruction.control = 0x0b;
  sys->instruction.i += 3;
  sys->instruction.instruction_check += 1;
  xwrite(sys->instruction.fd, &sys->instruction.c, 1);
  my_printf("instruction set -> STI\n");
  if (sys->instruction.str[sys->instruction.i] == ':')
    {
      sys->instruction.instruction_check = "1";
      my_printf("label: %s\n", sys->instruction.str[sys->instruction.i - 4]);
      while (sys->instruction.str[sys->instruction.i] != '%')
	(sys->instruction.i)++;
    }
  sys->instruction.base = sys->instruction.i;
}

void		fork_instruction(t_system *sys)
{
  sys->instruction.control = 0x0c;
  sys->instruction.i += 1;
  sys->instruction.instruction_check += 1;
  xwrite(sys->instruction.fd, &sys->instruction.c, 1);
  my_printf("instruction set -> FORK\n");
  if (sys->instruction.str[sys->instruction.i] == ':')
    {
      sys->instruction.instruction_check = "1";
      my_printf("label: %s\n", sys->instruction.str[sys->instruction.i - 4]);
      while (sys->instruction.str[sys->instruction.i] != '%')
	(sys->instruction.i)++;
    }
  sys->instruction.base = sys->instruction.i;
}

void		long_load_instruction(t_system *sys)
{
  sys->instruction.control = 0x0d;
  sys->instruction.i += 1;
  sys->instruction.instruction_check += 1;
  xwrite(sys->instruction.fd, &sys->instruction.c, 1);
  my_printf("instruction set -> LLD\n");
  if (sys->instruction.str[sys->instruction.i] == ':')
    {
      sys->instruction.instruction_check = "1";
      my_printf("label: %s\n", sys->instruction.str[sys->instruction.i - 4]);
      while (sys->instruction.str[sys->instruction.i] != '%')
	(sys->instruction.i)++;
    }
  sys->instruction.base = sys->instruction.i;
}

void		long_load_index_instruction(t_system *sys)
{
  sys->instruction.control = 0x0e;
  sys->instruction.ins += 3;
  sys->instruction.instruction_check += 1;
  xwrite(sys->instruction.fd, &sys->instruction.c, 1);
  my_printf("instruction set -> LLDI\n");
  if (sys->instruction.str[sys->instruction.i] == ':')
    {
      sys->instruction.instruction_check = "1";
      my_printf("label: %s\n", sys->instruction.str[sys->instruction.i - 4]);
      while (sys->instruction.str[sys->instruction.i] != '%')
	(sys->instruction.i)++;
    }
  sys->instruction.base = sys->instruction.i;
}

void		long_fork_instruction(t_system *sys)
{
  sys->instruction.control = 0x0f;
  sys->instruction.i += 1;
  sys->instruction.instruction_check += 1;
  xwrite(sys->instruction.fd, &sys->instruction.c, 1);
  my_printf("instruction set -> LFORK\n");
  if (sys->instruction.str[sys->instruction.i] == ':')
    {
      sys->instruction.instruction_check = "1";
      my_printf("label: %s\n", sys->instruction.str[sys->instruction.i - 4]);
      while (sys->instruction.str[sys->instruction.i] != '%')
	(sys->instruction.i)++;
    }
  sys->instruction.base = sys->instruction.i;
}

void		aff_instruction(t_system *sys)
{
  sys->instruction.control = 0x10;
  sys->instruction.i += 1;
  sys->instruction.instruction_check += 1;
  xwrite(sys->instruction.fd, &sys->instruction.c, 1);
  my_printf("instruction set -> AFF\n");
  if (sys->instruction.str[sys->instruction.i] == ':')
    {
      sys->instruction.instruction_check = "1";
      my_printf("label: %s\n", sys->instruction.str[sys->instruction.i - 4]);
      while (sys->instruction.str[sys->instruction.i] != '%')
	(sys->instruction.i)++;
    }
  sys->instruction.base = sys->instruction.i;
}
