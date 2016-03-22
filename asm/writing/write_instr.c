/*
** write_instr.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/asm/writing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Tue Mar 22 23:30:29 2016 Ethan Kerdelhue
** Last update Tue Mar 22 23:30:58 2016 Ethan Kerdelhue
*/

#include "asm.h"

void	write_instr(int nbr, int fd, t_corarg *args)
{
  put_param(nbr, 1, fd); /* Instruction print */
  if (nbr != 1 && nbr != 9 && nbr != 12 && nbr != 15)
    write_args(fd, args);
  else
    write_args_wpb(fd, args);
}
