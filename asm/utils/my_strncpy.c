/*
** my_strncpy.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/asm/utils/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Mon Mar 14 03:08:54 2016 Ethan Kerdelhue
** Last update Tue Mar 22 19:02:50 2016 Ethan Kerdelhue
*/

#include "asm.h"

char			*my_strncpy(char *dest, char *src, int n)
{
  int 	i;

  i = 0;
  while (n > 0 && *(src + i))
    {
      *(dest + i) = *(src + i);
      ++i;
      --n;
    }
  if (n > 0)
    *(dest + i) = '\0';
  return (dest);
 }

 char			*my_strcpy(char *dest, char *src)
 {
   int 	i;

   i = 0;
   while(src[i])
     {
       dest[i] = src[i];
       i = i + 1;
     }
   dest[i] = '\0';
   return dest;
 }

 char		*my_itoa(int nb)
 {
   int		len;
   char		*str;
   int		tmp;

   tmp = nb;
   len = 0;
   while (tmp > 0)
     {
       tmp = tmp / 10;
       len++;
     }
   if ((str = malloc(sizeof(char) * (len + 1))) == NULL)
     return (0);
   str[len] = '\0';
   while (len--)
     {
       str[len] = nb % 10  + '0';
       nb /= 10;
     }
   return (str);
 }

 int	my_intlen(int val)
 {
   int	i;

   i = 0;
   while (val > 0)
     {
       val = val / 10;
       i = i + 1;
     }
   return (i);
 }
