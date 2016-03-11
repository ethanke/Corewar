/*
** checkComment.c for  in /Users/ethankerdelhue/Documents/Shared/Corewar/ethan/parsing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Fri Mar 11 18:42:55 2016 Ethan Kerdelhue
** Last update Fri Mar 11 18:50:50 2016 Ethan Kerdelhue
*/

#include "asm.h"

char	checkInstruC(char *str)
{
 int	i;

 i = 0;

 while (str[i] != '\0')
   {
     if (str[i] == '.' && str[i + 1] == 'c' && str[i + 2] == 'o' && str[i + 3]
       == 'm' && str[i + 4] == 'm' && str[i + 5] == 'e' && str[i + 6] == 'n'
	 && str[i + 7] == 't')
       return (0);
     i++;
   }
 putError("[HEADER] Error line 2 : .comment don't found or wrong");
 return (0);
}

void	checkAdvC(int pos_1, int pos_2, char *str)
{
 int	i;

 i = pos_2 + 1;
 (void) pos_1;
 while (str[i] != '\0')
   {
     if (str[i] != ' ')
       {
         my_putstr("[HEADER] Error line 2 : Unknown characters ");
         my_putstr("--> ");
         my_putchar(str[i]);
         putError(", Compile failed\0");
       }
     i++;
   }
}

void	CheckQuoteC(char *str)
{
 int	i;
 int	pos_1;
 int	pos_2;


 i = -1;
 pos_1 = 0;
 pos_2 = 0;
 while (str[++i] != '\0')
   {
     if (str[i] == 34)
       {
         if (pos_1 == 0)
           pos_1 = i;
         else if (pos_2 == 0)
           pos_2 = i;
       }
   }
 if (pos_1 == 0)
   putError("[HEADER] Error line 1 : '32' not found, syntax error");
 else if (pos_2 == 0)
   putError("[HEADER] Error line 1 : missing '32' for .Comment, syntax error");
 else
   checkAdvC(pos_1, pos_2, str);
}

char	*getComment(char *str)
{
 char	*new;
 int	i;
 int	j;
 char	store;

 i = 0;
 j = 0;
 store = 2;
 new = malloc(my_strlen(str));
 while (str[i] != '\0')
   {
     if (store == 1 && str[i] != 34)
       {
         new[j] = str[i];
         j++;
       }
     if (str[i] == 34)
       store -= 1;
     i++;
   }
 new[j] = '\0';
 return (new);
}

char	*checkComment(char *str)
{
 checkInstruC(str);
 CheckQuoteC(str);
 return (getComment(str));
}
