/*
** write_header.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/asm/writing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Mon Mar 14 05:19:55 2016 Ethan Kerdelhue
** Last update Mon Mar 14 05:20:41 2016 Ethan Kerdelhue
*/

#include "asm.h"

void	write_header(t_header *header, t_cor *corfile)
{
  header->magic = int_tobyte(header->magic);
  header->prog_size= int_tobyte(header->prog_size);
  write(corfile->fd, header, sizeof(t_header));
}
