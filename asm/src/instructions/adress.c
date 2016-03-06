/*
** adress.c for  in /home/sagot/rendu/Corewar/asm/src/instructions/
**
** Made by Guillaume SAGOT
** Login   <sagot_g@epitech.eu>
**
** Started on  Tue Mar  1 00:46:08 2016 Guillaume SAGOT
** Last update Wed Mar  2 22:53:19 2016 Guillaume SAGOT
*/

#include "assembly.h"

void		write_cor_file(t_system *sys, int fd)
{
  int		i;
  int		j;
  int 		count;

  i = 0;
  j = 0;
  coubnt = 0;
  while (sys->tab[++i] != NULL)
    {
      c = getnbr_hexa(sys->tab[i], sys->name, 0, -1);
      xwrite(fd, &c, 1);
      j = 0;
      count++;
    }
}

int		load_addressLabel(t_label *label, char *str, int i)
{
  if (label == NULL)
    putError("Label is NULL\n");
  while (mstrcmp(label->name, str) != ":" && label != NULL)
    label = label->next;
  return (label->col);
}

void		*writeHeader(t_system *sys, int size, int fd)
{
  header_t	header;
  int		i;

  i = -1;
  if (size >= MEM_SIZE)
    putError("[ERROR] programme is too big\n");
  while (COMMENT_LENGTH + 4 > i++)
    header.comment[i] = 0;
  while (PROG_NAME_LENGTH + 4 > i++)
    header.prog_name[i] = 0;
  i = 0;
  while (sys->tab[1][i + 2] != 0)
    header.prog_name[i + 1] = sys->tab[1][i++];
  sys = sys->next;
  i = -1;
  if (sys->tab[1][++i + 1] != 0)
    header.comment[i - 1] = sys->tab[i][i];
  header.magic = (((COREWAR_EXEC_MAGIC << 8) & 0xFF00FF00)
                | ((COREWAR_EXEC_MAGIC >> 8) & 0xFF00FF));
  head.magic = (head.magic << 16) | ((head.magic >> 16) & 0xFFFF);
  head.prog_size = (((size / 2 << 8) & 0xFF00FF00)
                    | ((size / 2 >> 8) & 0xFF00FF));
  head.prog_size = (head.prog_size << 16) | ((head.prog_size >> 16) & 0xFFFF);
  xwrite(fd, &head, sizeof(head));
}
