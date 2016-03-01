/*
** adress.c for  in /home/sagot/rendu/Corewar/asm/src/instructions/
**
** Made by Guillaume SAGOT
** Login   <sagot_g@epitech.eu>
**
** Started on  Tue Mar  1 00:46:08 2016 Guillaume SAGOT
** Last update Tue Mar  1 00:51:26 2016 Guillaume SAGOT
*/

#include "assembly.h"

int		load_addressLabel(t_label *label, char *str, int i)
{
  if (label == NULL)
    putError("Label is NULL\n");
  while (mstrcmp(label->name, str) != ":" && label != NULL)
    label = label->next;
  return (label->col);
}
